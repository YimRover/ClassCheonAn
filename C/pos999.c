#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <limits.h>

#define MAX_PRODUCTS 100 // 물품등록  배열 매크로
#define INITIAL_BALANCE 390500 // 초기 잔고 390,500원 설정 매크로
#define MINUTE_WAGE 9800 // 시급 설정 매크로

typedef struct
{
    int id;
    char name[50];
    int price;
    int stock;
    time_t expire_at;
    int has_expiration;
    int age_restricted;
} Product; // 물품별 물품id,물품명,가격,갯수,유통기한,성인인증 여부 확인을 위한 구조체

typedef struct
{
    Product products[MAX_PRODUCTS];
    int count;
} Inventory; // 전체 상품 목록, 목록 갯수 확인

typedef struct
{
    long long balance;
    long long total_sales;
    long long total_refunds;
} Store; // 금고 잔고, 매출, 환불을 위한 구조체

typedef struct
{
    char name[50]; // 상품명
    int sold_quantity; // 판매 갯수
    int refunded_quantity; //환불 가능한 갯수
    int unit_price; //환불 금액을 위한 판매 금액
} Sale; // 환불을 실행하기 위한 구조체

typedef struct
{
    Sale sales[MAX_PRODUCTS];
    int count;
} SalesHistory; // 판매내역 구조체

typedef struct
{
    time_t login_time;
} Work; //로그인 시 로그인 시간을 기록하는 구조체

typedef struct
{
    Inventory inventory;
    Store store;
    Work work;
    SalesHistory sales_history;
} POS; // 위에 구조체를 소환해서 실행할 구조체


void original_csv(void)
{
    FILE * fp;
    char line [256];

    fp = fopen("original_products.csv", "r");
    if (fp == NULL)
    {
        printf ("파일을 열 수 없습니다.\r\n");
        return;
    }
    if (fgets(line, sizeof(line), fp) == NULL) // CSV 첫 번째 줄(제목) 건너뛰기
    {
        fclose(fp);
        return ;
    }
    printf("\r\n");
    printf("========================================================\r\n");
    printf(" ID   상품명          가격       재고     성인인증\r\n");
    printf("========================================================\r\n");

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        printf("%s", line);
    }
    fclose(fp);
}

int load_products(POS *pos)
{
    FILE *fp;
    char line[256];

    Product *product;

    fp = fopen("original_products.csv", "r");

    if (fp == NULL)
    {
        printf("CSV 파일을 열 수 없습니다.\n");
        return 0;
    }

    
    if (fgets(line, sizeof(line), fp) == NULL)
    {
        fclose(fp);
        return 0;
    }

    (*pos).inventory.count = 0;

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if ((*pos).inventory.count >= MAX_PRODUCTS)
        {
            break;
        }

        product = &(*pos).inventory.products[(*pos).inventory.count];

        if (sscanf(line, "%d,%49[^,],%d,%d,%d,%d",
           &(*product).id,
           (*product).name,
           &(*product).price,
           &(*product).stock,
           &(*product).age_restricted,
           &(*product).has_expiration) == 6)
            {
                if ((*product).has_expiration == 1)
                {
                (*product).expire_at = time(NULL) + 3600;
                }
                else
                {
                (*product).expire_at = 0;
                }
                ++(*pos).inventory.count;
            }
    }
    fclose(fp);
    printf("상품 불러오기 완료\r\n");
    printf("상품 개수 : %d개\r\n", (*pos).inventory.count);

    return 1;
}

void show_expiration(POS *pos)
{
    int i;
    int found = 0;
    time_t now = time(NULL);
    long long remaining_time;
    long long minutes;
    long long seconds;

    printf("\r\n");
    printf("========== 유통기한 확인 ==========\r\n");

    for (i = 0; i < (*pos).inventory.count; ++i)
    {
        if ((*pos).inventory.products[i].has_expiration == 1)
        {
            found = 1;

            remaining_time =
                (long long)difftime((*pos).inventory.products[i].expire_at, now);
            printf("\r\n");
            printf("상품명 : %s\r\n",
            (*pos).inventory.products[i].name);
            if (remaining_time > 0)
            {
                minutes = remaining_time / 60;
                seconds = remaining_time % 60;

                printf("남은 시간 : %lld분 %lld초\r\n",minutes, seconds);
                printf("상태 : 정상\r\n");
            }
            else
            {
                printf("남은 시간 : 0분 0초\r\n");
                printf("상태 : 유통기한 만료\r\n");
            }
        }
    }
    if (found == 0)
    {
        printf("유통기한 관리 대상 상품이 없습니다.\r\n");
    }
    printf("===================================\r\n");
}

int load_sales(POS *pos)
{
    FILE *fp;
    char line[256];
    Sale *sales;

    fp = fopen("sales.csv", "r");

    if (fp == NULL)
    {
        if (errno == ENOENT)
        {
            return 1; 
        }
        perror("sales.csv");
        return 0;
    }
    if (fgets(line, sizeof(line), fp) == NULL)
        {
            fclose(fp);
            return 0;
        }
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if ((*pos).sales_history.count >= MAX_PRODUCTS)
        {
            break;
        }
        sales = &(*pos).sales_history.sales[(*pos).sales_history.count];
        if (sscanf(line, "%49[^,],%d,%d,%d",
        (*sales) .name,
        &(*sales) .sold_quantity,
        &(*sales) .refunded_quantity,
        &(*sales) .unit_price)==4)
        {++(*pos).sales_history.count;}
    }
    fclose(fp);
    return 1;
}

void show_inventory(POS *pos)
{
    int i, j;
    int name_length ;

    printf("\r\n");
    printf("========== 재고 목록 ==========\r\n");

    for (i = 0; i < (*pos).inventory.count; ++i)
    {
        name_length = strlen((*pos).inventory.products[i].name);
        printf("ID : %-5d | 상품명 : %5s ",
               (*pos).inventory.products[i].id,
               (*pos).inventory.products[i].name);
                if (name_length == 3)
                {
                    printf("    ");
                }
                else if (name_length == 6)
                {
                    printf("  ");
                }
                printf ("| 가격 : %-5d | 갯 수 : %-3d",
               (*pos).inventory.products[i].price,
               (*pos).inventory.products[i].stock);
               for (j = 0; j < (*pos).inventory.products[i].stock; ++j)
               {
                    printf ("*");
               }
        printf ("\r\n");
    }

    printf("===============================\r\n");
}

void search_product(POS *pos)
{
    char search_name[50];
    int i;
    int found = -1;
    
    printf("상품명 입력 : ");
    if (scanf("%49s", search_name) != 1)
    {
        printf("잘못된 상품명입니다.\r\n");
        return;
    }

    for (i = 0; i < (*pos).inventory.count; ++i)
    {
        if (strcmp((*pos).inventory.products[i].name, search_name) == 0)
            {
                found = i;
                break;
            }
    }
    if (found == -1)
    {
        printf("검색 결과가 없습니다.\r\n");
        return;
    }
    printf("\r\n");
    printf("========== 검색 결과 ==========\r\n");
    printf("상품명 : %s\r\n",
           (*pos).inventory.products[found].name);

    printf("상품 가격 : %d원\r\n",
           (*pos).inventory.products[found].price);

    printf("현재 재고 : %d개\r\n",
           (*pos).inventory.products[found].stock);

    printf("성인인증 : %s\r\n",
           (*pos).inventory.products[found].age_restricted == 1
           ? "확인" : "확인X");

    printf("유통기한 관리 : %s\r\n",
           (*pos).inventory.products[found].has_expiration == 1
           ? "예" : "아니오");

    printf("================================\r\n");
}

void save_products(POS *pos)
{
    FILE *fp;
    int i;

    fp = fopen("products.csv", "w");

    if (fp == NULL)
    {
        printf("CSV 파일을 생성할 수 없습니다.\r\n");
        return;
    }

    fprintf(fp, "id,name,price,stock,age_restricted,has_expiration\r\n");

    for (i = 0; i < (*pos).inventory.count; ++i)
    {
        fprintf(fp, "%d,%s,%d,%d,%d,%d\r\n",
            (*pos).inventory.products[i].id,
            (*pos).inventory.products[i].name,
            (*pos).inventory.products[i].price,
            (*pos).inventory.products[i].stock,
            (*pos).inventory.products[i].age_restricted,
            (*pos).inventory.products[i].has_expiration);
    }

    fclose(fp);
}

void add_product(POS *pos)
{
    Product *product;
    int i, j;
    int duplicate;

    printf("\r\n");
    printf("========== 신규 상품 등록 ==========\r\n");
    if ((*pos).inventory.count >= MAX_PRODUCTS)
    {
        printf("상품 등록 공간이 부족합니다.\r\n");
        return;
    }
    printf("\r\n");
    printf("========== 현재 등록 상품 ==========\r\n");

    for (i = 0; i < (*pos).inventory.count; ++i)
    {
        printf("ID : %-5d | 상품명 : %s\r\n",
               (*pos).inventory.products[i].id,
               (*pos).inventory.products[i].name);
    }

    printf("====================================\r\n");
    printf("현재 등록 상품 : %d개\r\n", (*pos).inventory.count);
    printf("등록 가능한 상품 : %d개\r\n",
           MAX_PRODUCTS - (*pos).inventory.count);

    product = &(*pos).inventory.products[(*pos).inventory.count];

    while (1)  // 상품 ID 입력 및 중복 검사
    {
        printf("\r\n신규 상품 ID : ");

        if (scanf("%d", &(*product).id) != 1)
        {
            printf("잘못된 입력입니다.\r\n");
            return;
        }

        if ((*product).id <= 0)
        {
            printf("상품 ID는 1 이상이어야 합니다.\r\n");
            continue;
        }
        duplicate = 0;

        for (j = 0; j < (*pos).inventory.count; ++j)
        {
            if ((*pos).inventory.products[j].id == (*product).id)
            {
                duplicate = 1;
                break;
            }
        }

        if (duplicate == 1)
        {
            printf("이미 등록된 상품 ID입니다.\r\n");
            continue;
        }

        break;
    }
    while (1)// 상품명 입력 및 중복 검사
    {
        printf("신규 상품명 : ");

        if (scanf("%49s", (*product).name) != 1)
        {
            printf("잘못된 입력입니다.\r\n");
            return;
        }
        duplicate = 0;

        for (j = 0; j < (*pos).inventory.count; ++j)
        {
            if (strcmp((*pos).inventory.products[j].name,
                       (*product).name) == 0)
            {
                duplicate = 1;
                break;
            }
        }
        if (duplicate == 1)
        {
            printf("이미 등록된 상품명입니다.\r\n");
            continue;
        }

        break;
    }
    printf("상품 가격 : ");// 가격 입력

    if (scanf("%d", &(*product).price) != 1 ||
        (*product).price < 0)
    {
        printf("잘못된 가격입니다.\r\n");
        return;
    }

    // 재고 입력
    printf("초기 재고 : ");

    if (scanf("%d", &(*product).stock) != 1 ||
        (*product).stock < 0)
    {
        printf("잘못된 재고 수량입니다.\r\n");
        return;
    }

    // 성인인증 여부
    printf("성인인증 여부 (0: 아니오, 1: 예) : ");

    if (scanf("%d", &(*product).age_restricted) != 1 ||
        ((*product).age_restricted != 0 &&
         (*product).age_restricted != 1))
    {
        printf("잘못된 입력입니다.\r\n");
        return;
    }

    // 유통기한 관리 여부
    printf("유통기한 관리 여부 (0: 아니오, 1: 예) : ");

    if (scanf("%d", &(*product).has_expiration) != 1 ||
        ((*product).has_expiration != 0 &&
         (*product).has_expiration != 1))
    {
        printf("잘못된 입력입니다.\r\n");
        return;
    }

    // 유통기한 설정
    if ((*product).has_expiration == 1)
    {
        (*product).expire_at = time(NULL) + 3600;
    }
    else
    {
        (*product).expire_at = 0;
    }

    // 상품 등록 확정
    ++(*pos).inventory.count;

    // CSV 저장
    save_products(pos);

    printf("\r\n");
    printf("========== 상품 등록 완료 ==========\r\n");
    printf("상품 ID : %d\r\n", (*product).id);
    printf("상품명 : %s\r\n", (*product).name);
    printf("상품 가격 : %d원\r\n", (*product).price);
    printf("초기 재고 : %d개\r\n", (*product).stock);
    printf("====================================\r\n");
}

void delete_product(POS *pos)
{
    int i, j;
    int delete_id;
    int found = -1;
    int confirm;

    printf("\r\n");
    printf("========== 상품 삭제 ==========\r\n");

    if ((*pos).inventory.count == 0)
    {
        printf("등록된 상품이 없습니다.\r\n");
        return;
    }

    // 현재 등록된 상품 목록 출력
    for (i = 0; i < (*pos).inventory.count; ++i)
    {
        printf("ID : %-5d | 상품명 : %s\r\n",
               (*pos).inventory.products[i].id,
               (*pos).inventory.products[i].name);
    }

    printf("================================\r\n");

    // 삭제할 상품 ID 입력
    printf("삭제할 상품 ID : ");

    if (scanf("%d", &delete_id) != 1)
    {
        printf("잘못된 입력입니다.\r\n");
        return;
    }

    // 상품 ID 검색
    for (i = 0; i < (*pos).inventory.count; ++i)
    {
        if ((*pos).inventory.products[i].id == delete_id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("해당 상품 ID를 찾을 수 없습니다.\r\n");
        return;
    }

    // 삭제 전 확인
    printf("\r\n");
    printf("삭제할 상품 : %s\r\n",
           (*pos).inventory.products[found].name);

    printf("정말 삭제하시겠습니까? (1: 예, 0: 아니오) : ");

    if (scanf("%d", &confirm) != 1)
    {
        printf("잘못된 입력입니다.\r\n");
        return;
    }

    if (confirm != 1)
    {
        printf("상품 삭제를 취소했습니다.\r\n");
        return;
    }

    // 상품 배열 정리
    for (j = found; j < (*pos).inventory.count - 1; ++j)
    {
        (*pos).inventory.products[j] =
            (*pos).inventory.products[j + 1];
    }

    // 상품 개수 감소
    --(*pos).inventory.count;

    // 변경된 상품 목록 저장
    save_products(pos);

    printf("상품이 정상적으로 삭제되었습니다.\r\n");
}

void restock_product(POS *pos)
{
    int i;
    int product_id;
    int quantity;
    int found = -1;
    int previous_stock;

    printf("\r\n");
    printf("========== 상품 입고 ==========\r\n");

    if ((*pos).inventory.count == 0)
    {
        printf("등록된 상품이 없습니다.\r\n");
        return;
    }

    // 현재 상품 목록 출력
    for (i = 0; i < (*pos).inventory.count; ++i)
    {
        printf("ID : %-5d | 상품명 : %-10s | 현재 재고 : %d개\r\n",
               (*pos).inventory.products[i].id,
               (*pos).inventory.products[i].name,
               (*pos).inventory.products[i].stock);
    }

    printf("================================\r\n");

    // 입고할 상품 ID 입력
    printf("입고할 상품 ID : ");

    if (scanf("%d", &product_id) != 1)
    {
        printf("잘못된 상품 ID 입력입니다.\r\n");
        return;
    }

    // 상품 검색
    for (i = 0; i < (*pos).inventory.count; ++i)
    {
        if ((*pos).inventory.products[i].id == product_id)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("등록되지 않은 상품입니다.\r\n");
        return;
    }

    printf("\r\n");
    printf("상품명 : %s\r\n",
           (*pos).inventory.products[found].name);

    printf("현재 재고 : %d개\r\n",
           (*pos).inventory.products[found].stock);

    // 입고 수량 입력
    printf("입고 수량 : ");

    if (scanf("%d", &quantity) != 1)
    {
        printf("잘못된 입고 수량입니다.\r\n");
        return;
    }

    if (quantity <= 0)
    {
        printf("입고 수량은 1개 이상이어야 합니다.\r\n");
        return;
    }

    // 정수 오버플로 방지
    if ((*pos).inventory.products[found].stock > INT_MAX - quantity)
    {
        printf("입고 후 재고 수량이 허용 범위를 초과합니다.\r\n");
        return;
    }

    // 기존 재고 저장
    previous_stock = (*pos).inventory.products[found].stock;

    // 재고 증가
    (*pos).inventory.products[found].stock += quantity;

    // CSV 저장
    save_products(pos);

    printf("\r\n");
    printf("========== 입고 완료 ==========\r\n");

    printf("상품명 : %s\r\n",
           (*pos).inventory.products[found].name);

    printf("입고 수량 : %d개\r\n", quantity);

    printf("변경 전 재고 : %d개\r\n", previous_stock);

    printf("변경 후 재고 : %d개\r\n",
           (*pos).inventory.products[found].stock);

    printf("================================\r\n");
}

void save_sales(POS *pos)
{
    FILE *fp;
    int i;

    fp = fopen("sales.csv", "w");
    if (fp == NULL)
    {
        printf("CSV 파일을 생성할 수 없습니다.\r\n");
        return;
    }
    
    fprintf(fp, "name,sold_quantity,refunded_quantity,unit_price\r\n");

    for (i = 0; i < (*pos).sales_history.count; ++i)
    {
        fprintf(fp, "%s,%d,%d,%d\r\n",
                (*pos).sales_history.sales[i].name,
                (*pos).sales_history.sales[i].sold_quantity,
                (*pos).sales_history.sales[i].refunded_quantity,
                (*pos).sales_history.sales[i].unit_price);
    }

    fclose(fp);
}


void sell_product(POS *pos)
{
    char product_name[50];
    int quantity;
    int total_price;
    int i;
    int j;
    int received_cash;
    int change;
    int found = 0;

    show_inventory(pos);

    printf("상품을 입력하세요 : ");
    if (scanf("%49s", product_name) != 1)
    {
        printf("잘못된 상품번호 입력입니다.\n");
        return;
    }

    // 상품명 검색
    for (i = 0; i < (*pos).inventory.count; ++i)
    {
        if ((strcmp((*pos).inventory.products[i].name, product_name) == 0))
        {
            break;
        }
    }

    // 상품을 찾지 못한 경우
    if (i == (*pos).inventory.count)
    {
        printf("등록되지 않은 상품입니다.\n");
        return;
    }

    // 상품 정보 출력
    printf("상품명 : %s\r\n",
           (*pos).inventory.products[i].name);

    printf("상품 가격 : %d원\r\n",
           (*pos).inventory.products[i].price);

    // 구매 수량 입력
    printf("구매 수량을 입력하세요 : ");

    if (scanf("%d", &quantity) != 1)
    {
        printf("잘못된 구매 수량 입력입니다.\n");
        return;
    }

    // 재고 및 구매 수량 검사
    if (quantity > (*pos).inventory.products[i].stock || quantity <= 0)
    {
        printf("구매할 수 없는 수량입니다.\n");
        return;
    }

    // 성인 인증 대상 상품 확인
    if ((*pos).inventory.products[i].age_restricted == 1)
    {
        int birth_year;
        int current_year;
        int adult_check = 0;

        time_t now = time(NULL);
        struct tm *today = localtime(&now);

        if (today == NULL)
        {
            printf("현재 날짜를 확인할 수 없습니다.\n");
            return;
        }

        current_year = (*today).tm_year + 1900;

        printf("출생연도를 입력하세요 : ");

        if (scanf("%d", &birth_year) != 1)
        {
            printf("잘못된 출생연도 입력입니다.\n");
            return;
        }

        if (birth_year > 0 &&
            birth_year <= current_year &&
            current_year - birth_year >= 19)
        {
            adult_check = 1;
        }
        else
        {
            adult_check = 0;
        }

        if (adult_check == 0)
        {
            printf("성인 인증에 실패했습니다.\n");
            return;
        }
    }

    // 판매 금액 계산
    total_price = (*pos).inventory.products[i].price * quantity;
    // 결제 금액 출력
    printf("총 결제 금액 : %d원\r\n", total_price);
    // 고객이 지불한 현금 입력
    printf("받은 현금을 입력하세요 : ");
    if (scanf("%d", &received_cash) != 1)
    {
        printf("잘못된 현금 입력입니다.\r\n");
        return;
    }
    // 결제 금액 부족 여부 확인
    if (received_cash < total_price)
    {
        printf("결제 금액이 부족합니다.\r\n");
        return;
    }
    // 거스름돈 계산
    change = received_cash - total_price;
    printf("받은 현금 : %d원\r\n", received_cash);
    printf("거스름돈 : %d원\r\n", change);

    // 재고 차감
    (*pos).inventory.products[i].stock -= quantity;

    // 잔고 증가
    (*pos).store.balance += total_price;

    // 매출액 증가
    (*pos).store.total_sales += total_price;
    
    for (j = 0; j < (*pos).sales_history.count; ++j)
    {
        if (strcmp((*pos).sales_history.sales[j].name, product_name) == 0)
        {
            (*pos).sales_history.sales[j].sold_quantity += quantity;
            found = 1;
            break;
        }
    }


    if (found == 0)// 처음 판매하는 상품이면 새로운 판매 기록 추가
    {
        if ((*pos).sales_history.count < MAX_PRODUCTS)
        {
            strcpy((*pos).sales_history.sales[(*pos).sales_history.count].name,
               product_name);

            (*pos).sales_history.sales[(*pos).sales_history.count].sold_quantity = quantity;

            (*pos).sales_history.sales[(*pos).sales_history.count].refunded_quantity = 0;

            (*pos).sales_history.sales[(*pos).sales_history.count].unit_price =
            (*pos).inventory.products[i].price;

            ++(*pos).sales_history.count;
        }
    }
    printf ("\r\n");
    save_products(pos);// 변경된 데이터 CSV 저장
    save_sales(pos);

    // 판매 완료 메시지
    printf("========== 판매 완료 ==========\r\n");
    printf("상품명 : %s\r\n",
           (*pos).inventory.products[i].name);
    printf("구매 수량 : %d개\r\n", quantity);
    printf("총 결제 금액 : %d원\r\n", total_price);
    printf("받은 현금 : %d원\r\n", received_cash);
    printf("거스름돈 : %d원\r\n", change);
    printf("===============================\r\n");
}

void refund_product(POS *pos)
{
    int i;
    int j;
    int refundable_quantity;
    char product_name[50];
    int refund_quantity;
    int refund_price;
    int k;

    printf("\r\n");
    printf("========== 상품 환불 ==========\r\n");

    if ((*pos).sales_history.count == 0)
    {
        printf("판매 내역이 없습니다.\r\n");
        return;
    }

    printf("========== 판매 내역 ==========\r\n");

    for (i = 0; i < (*pos).sales_history.count; ++i) // 1. 판매 내역 출력
    {
        refundable_quantity =
            (*pos).sales_history.sales[i].sold_quantity
            - (*pos).sales_history.sales[i].refunded_quantity;

        printf("상품명 : %s | 판매 : %d개 | 환불 : %d개 | 환불 가능 : %d개\r\n",
               (*pos).sales_history.sales[i].name,
               (*pos).sales_history.sales[i].sold_quantity,
               (*pos).sales_history.sales[i].refunded_quantity,
               refundable_quantity);
    }

    printf("================================\r\n");
    printf("환불할 상품명을 입력하세요 : ");// 2. 환불할 상품명 입력

    if (scanf("%49s", product_name) != 1)
    {
        printf("잘못된 상품명 입력입니다.\r\n");
        return;
    }
    for (j = 0; j < (*pos).sales_history.count; ++j)// 2. 환불할 상품명 입력
    {
        if (strcmp((*pos).sales_history.sales[j].name, product_name) == 0)
        {
            break;
        }
    }
    if (j == (*pos).sales_history.count) // 4. 판매 기록이 없는 경우
    {
        printf("판매 기록이 없는 상품입니다.\r\n");
        return;
    }
    refundable_quantity =
    (*pos).sales_history.sales[j].sold_quantity
    - (*pos).sales_history.sales[j].refunded_quantity;
    if (refundable_quantity <= 0)
    {
        printf("환불 가능한 수량이 없습니다.\r\n");
        return;
    }
        printf("환불 가능 수량 : %d개\r\n", refundable_quantity);// 환불 수량 입력
        printf("환불할 수량을 입력하세요 : ");
    if (scanf("%d", &refund_quantity) != 1)
    {
        printf("잘못된 수량 입력입니다.\r\n");
        return;
    }
    if (refund_quantity <= 0 || refund_quantity > refundable_quantity)// 환불 수량 검증
    {
        printf("환불할 수 없는 수량입니다.\r\n");
        return;
    }
    printf("환불 요청 수량 : %d개\r\n", refund_quantity);
    refund_price = (*pos).sales_history.sales[j].unit_price * refund_quantity;
    printf("환불 예정 금액 : %d원\r\n", refund_price);

    for (k = 0; k < (*pos).inventory.count; ++k)// 재고 목록에서 환불 대상 상품 검색
    {
        if (strcmp((*pos).inventory.products[k].name, product_name) == 0)
        {
            break;
        }
    }
    if (k == (*pos).inventory.count) // 재고 목록에 상품이 없는 경우
    {
        printf("재고 목록에 없는 상품입니다.\r\n");
        return;
    }
    if ((*pos).store.balance < refund_price)
    {
        printf("금고 잔고가 부족하여 환불할 수 없습니다.\r\n");
        return;
    }
    (*pos).inventory.products[k].stock += refund_quantity; // 상품 재고 복구
    (*pos).store.balance -= refund_price; // 금고 잔고 차감
    (*pos).store.total_refunds += refund_price; // 총 환불액 증가
    (*pos).sales_history.sales[j].refunded_quantity += refund_quantity;// 환불 완료 수량 증가
    save_products(pos);// 변경된 데이터 CSV 저장
    save_sales(pos);
    printf("\r\n");
    printf("========== 환불 완료 ==========\r\n");
    printf("상품명 : %s\r\n", (*pos).sales_history.sales[j].name);
    printf("환불 수량 : %d개\r\n", refund_quantity);
    printf("환불 금액 : %d원\r\n", refund_price);
    printf("================================\r\n");
}

void show_sales(POS *pos)
{
    printf("\r\n");
    printf("========== 매출액 확인 ==========\r\n");
    printf("총 매출액 : %lld원\r\n",
           (*pos).store.total_sales);
    printf("=================================\r\n");
}

void work_menu(POS *pos)
{
    int choice;

    while (1)
    {
        printf("\r\n");
        printf("========== 업무 시작 ==========\r\n");
        printf(" [1] 상품 판매\r\n");
        printf(" [2] 상품 환불\r\n");
        printf(" [3] 입고 상품 등록\r\n");
        printf(" [4] 신규 상품 등록\r\n");
        printf(" [5] 등록 상품 삭제\r\n");
        printf(" [6] 상품 검색 \r\n");
        printf(" [0] 메인 메뉴로 돌아가기\r\n");
        printf("================================\r\n");
        printf(" 메뉴 선택 : ");

        if (scanf("%d", &choice) != 1)
        {
            int ch;

            printf("숫자를 입력해주세요.\r\n");

            while ((ch = getchar()) != '\n' && ch != EOF)
            {
            }

            if (ch == EOF)
            {
                return;
            }

            continue;
        }

        switch (choice)
        {
            case 1:
                sell_product(pos);
                break;

            case 2:
                refund_product(pos);
                break;
            case 3:
                restock_product(pos);
            break;
            case 4:
                add_product(pos);
            break;
            case 5:
                delete_product(pos);
            break;
            case 6:
                search_product(pos);
            break;
            case 0:
                return;

            default:
                printf("잘못된 메뉴 선택입니다.\r\n");
                break;
        }
    }
}

void calculate_wage(POS *pos)
{
    time_t logout_time;
    double work_seconds;
    double work_minutes;
    double total_wage;

    // 근무 종료시간 기록
    logout_time = time(NULL);

    // 총 근무시간 계산 (초 단위)
    work_seconds = difftime(logout_time, (*pos).work.login_time);

    if (work_seconds < 0)
    {
        printf("근무시간을 계산할 수 없습니다.\r\n");
        return;
    }

    // 초 단위를 분 단위로 변환
    work_minutes = work_seconds / 60.0;

    // 분당 급여 계산
    total_wage = work_minutes * MINUTE_WAGE;

    printf("\r\n");
    printf("========== 근무 정산 ==========\r\n");

    printf("총 근무시간 : %.2f분\r\n", work_minutes);

    printf("분당 급여 : %d원\r\n", MINUTE_WAGE);

    printf("총 지급 급여 : %.0f원\r\n", total_wage);

    printf("================================\r\n");
}

void main_menu(void) // 메인 메뉴 출력 함수
{
    printf("\r\n");
    printf("========================================\r\n");
    printf("              POS SYSTEM\r\n");
    printf("========================================\r\n");
    printf(" [1] 재고 체크\r\n");
    printf(" [2] 현재 잔고 체크\r\n");
    printf(" [3] 매출액 확인\r\n");
    printf(" [4] Expire 확인\r\n");
    printf(" [5] 업무 시작\r\n");
    printf(" [6] 프로그램 종료\r\n");
    printf("----------------------------------------\r\n");
    printf(" 메뉴 선택 : ");
}
void init_pos(POS *pos) // 구조체 POS로 접근해서 pos 운영 구조체
{
    (*pos).inventory.count = 0;
    (*pos).store.balance = INITIAL_BALANCE;
    (*pos).store.total_sales = 0;
    (*pos).store.total_refunds = 0;
    (*pos).work.login_time = time(NULL);
    (*pos).sales_history.count = 0;
}

void run_pos(POS *pos)
{
    int choice;

    while (1)
    {
        main_menu();

        if (scanf("%d", &choice) != 1)
        {
            printf("숫자를 입력해주세요.\r\n");

            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) // getchar로 "\n" 과 
            {
            }

            continue;
        }

        switch (choice)
        {
            case 1:
                printf("재고 체크\r\n");
                show_inventory(pos);
                break;

            case 2:
                printf("현재 잔고 : %lld원\r\n", (*pos).store.balance);
                break;

            case 3:
                printf("\r\n");
                printf("========== 매출 현황 ==========\r\n");
                printf("총 판매액 : %lld원\r\n",
                (*pos).store.total_sales);
                printf("총 환불액 : %lld원\r\n",
                (*pos).store.total_refunds);
                printf("순 매출액 : %lld원\r\n",
                (*pos).store.total_sales - (*pos).store.total_refunds);
                printf("===============================\r\n");
                break;

            case 4:
                show_expiration(pos);
                break;

            case 5:
                printf("업무 시작\r\n");
                work_menu(pos);
                break;

            case 6:
                calculate_wage(pos);
                (*pos).sales_history.count = 0;
                save_sales(pos);
                printf("프로그램 종료\r\n");
                return;

            default:
                printf("잘못된 입력입니다.\r\n");
                break;
        }
    }
}



int login () // 로그인 함수
{
    
    char saveid[7]= {'a','d','m','i','n',}; // 기본 ID 설정
    char savepassword[7] = {'a','d','m','i','n',}; // 기본 Password 설정
    char id[30]; // ID 입력 배열
    char password [30]; // Password 입력 배열
    int count, overflow ; 
    struct termios oldt, newt;
    
    if (tcgetattr(STDIN_FILENO, &oldt) == -1)
    {
        perror ("tcgetattr");
        return 0;
    }
    newt = oldt;
    newt.c_lflag &= ~(ECHO | ICANON);
    newt.c_cc[VMIN] = 1;
    newt.c_cc[VTIME] = 0;

    while (1)
    {
        count = 0;
        overflow = 0;
        printf ("%s\r\n", "LOGIN");
        printf ("%s\t", "ID :");
        fflush (stdout);
        while (1)
        {
            
            char ch;
            if (scanf ("%c", &ch) != 1)
            {
                tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
                return 0;
            }
            if (ch == '\n')
            { break; }
            ++ count ;
            if (count <= 20)
            {
                id[count -1] = ch;
            }
            else{ overflow = 1;}
        }
        if (count <= 20)
        {
            id[count] = '\0';
        }
        else
        {
            id[20] = '\0';
        }
        printf ("\r\n");
        if (overflow == 0)
        {break;}
        printf ("ERROR : ID는 20자 까지만 입력 가능합니다.\r\n");
    }
    while (1)
    {
        count = 0;
        overflow = 0;
        printf ("%s\t", "PASSWORD :");
        fflush (stdout);
        if (tcsetattr(STDIN_FILENO, TCSANOW, &newt) == -1)
        {
            perror ("tcsetattr");
            return 0;
        }
        while (1)
        {
            char ch;
            if (scanf ("%c", &ch) != 1)
            {
                tcsetattr(STDIN_FILENO,TCSANOW, &oldt);
                return 0;
            }
            if (ch == '\n')
            {break;}
            ++count;
            if (count <= 20)
            {
                password[count -1] = ch;
                printf ("*");
                fflush(stdout);
            }
            else{ overflow = 1;}
        }
        if (count <= 20)
        {
            password[count] = '\0';
        }
        else 
        {
            password[20] = '\0';
        }
        printf ("\r\n");
        if (overflow == 0)
        { break; }
        printf ("ERROR : 최대 20자까지 입력 가능합니다.\r\n");
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        if (strcmp (id, saveid) == 0 && strcmp (password, savepassword) == 0)
        {
            return 1;
        }
        else
        {
            printf ("%s\r\n", "LOGIN FAIL");
            return 0;
        }
}


int main()
{
    POS pos;
    struct tm *login_info;

    if (login() == 1)
    {
        printf("LOGIN SUCCESS\r\n");
        init_pos(&pos);
       login_info = localtime(&pos.work.login_time);
        if (login_info != NULL)
        {
            printf("\r\n");
            printf("========== 근무 시작 ==========\r\n");
            printf("로그인 시간 : %04d-%02d-%02d %02d:%02d:%02d\r\n",
                   (*login_info).tm_year + 1900,
                   (*login_info).tm_mon + 1,
                   (*login_info).tm_mday,
                   (*login_info).tm_hour,
                   (*login_info).tm_min,
                   (*login_info).tm_sec);
            printf("===============================\r\n");
        }
        else
        {
            printf("로그인 시간을 변환하지 못했습니다.\r\n");
            return 1;
        }

        if (load_products(&pos) == 0)
        {
            printf("상품 데이터를 불러오지 못했습니다.\r\n");
            return 1;
        }

        load_sales(&pos);
        run_pos(&pos);
    }

    return 0;
}