#include <stdio.h>

// 거스름돈을 구성하는 동전의 개수를 저장하는 구조체
typedef struct CoinCount {
    int n500; // 500원 동전의 개수
    int n100; // 100원 동전의 개수
    int n50; // 50원 동전의 개수
    int n10; // 10원 동전의 개수
} CoinCount;

int cost; // 거스름돈

// 거스름돈을 계산하는 함수
CoinCount calNCoin(int cost) {
    CoinCount count = { 0, 0, 0, 0 }; // 구조체 초기화

    // 500원 동전 개수 계산
    count.n500 = cost / 500;
    cost = cost % 500;

    // 100원 동전 개수 계산
    count.n100 = cost / 100;
    cost = cost % 100;

    // 50원 동전 개수 계산
    count.n50 = cost / 50;
    cost = cost % 50;

    // 10원 동전 개수 계산
    count.n10 = cost / 10;
    cost = cost % 10;

    return count;
}

int main()
{
    printf("거스름돈을 입력하세요.\n");
    scanf("%d", &cost);                             // 거스름돈 입력
    CoinCount count = calNCoin(cost);       // 해당 함수에 입력값 적용
    printf("500원 동전 개수: %d\n", count.n500);// 500원 동전의 개수
    printf("100원 동전 개수: %d\n", count.n100);// 100원 동전의 개수
    printf("50원 동전 개수: %d\n", count.n50);  // 50원 동전의 개수
    printf("10원 동전 개수: %d\n", count.n10);  // 10원 동전의 개수

    return 0;

}