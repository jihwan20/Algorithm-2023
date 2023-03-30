#include <stdio.h>

int find_FakeCoin() {
    int coins[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 };            // 진짜 동전 9개와 가짜 동전 1개
    int n = 10;                                                  // 전체 동전의 수
    int dummy1 = 0, dummy2 = n - 1;                              // 동전을 나눌 왼쪽과 오른쪽 인덱스
    int mid = (dummy1 + dummy2) / 2;                             // 중앙값을 pivot으로 설정

    while (dummy2 >= dummy1) {                                   // dummy1이 dummy2보다 작거나 같은 동안 반복
        if (coins[mid] == 0) {                                   // mid 동전이 가짜 동전인 경우
            printf("가짜 동전은 %d번째 동전입니다.", mid + 1);   // mid 위치 출력
            break;
        }
        else if (coins[mid] == 1) {                              // mid 동전이 진짜 동전인 경우
            dummy1 = mid + 1;                                    // 왼쪽 부분집합 제거
        }
        else {                                                   // mid 동전이 없는 경우
            dummy2 = mid - 1;                                    // 오른쪽 부분집합 제거
        }
        mid = (dummy1 + dummy2) / 2;                             // 새로운 mid 계산
    }
    return 0;
}

int main() {
    find_FakeCoin();
    return 0;
}