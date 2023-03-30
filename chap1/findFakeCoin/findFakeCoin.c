#include <stdio.h>


int findFakeCoin(int coins[], int start, int end, int weight) {
    if (start == end) { // 검색 범위가 1개인 경우
        if (coins[start] == weight) {
            return -1; // 모든 동전이 진짜인 경우
        }
        else {
            return start; // 가짜 동전의 위치를 반환
        }
    }

    int mid = (start + end) / 2; // 검색 범위를 둘로 나누는 중간 인덱스
    int left_sum = 0, right_sum = 0;

    // 검색 범위를 둘로 나누어 각각의 합을 구함
    for (int i = start; i <= mid; i++) {
        left_sum += coins[i];
    }
    for (int i = mid + 1; i <= end; i++) {
        right_sum += coins[i];
    }

    if (left_sum < right_sum) { // 오른쪽에 가짜 동전이 있는 경우
        return findFakeCoin(coins, mid + 1, end, weight);
    }
    else if (left_sum > right_sum) { // 왼쪽에 가짜 동전이 있는 경우
        return findFakeCoin(coins, start, mid, weight);
    }
    else { // 두 부분합이 같은 경우
        // 중간 인덱스가 참조 동전의 위치인 경우
        if (mid == weight) {
            return mid + 1; // 오른쪽에 가짜 동전이 있는 것으로 처리
        }
        else if (mid < weight) { // 참조 동전이 더 오른쪽에 있는 경우
            return findFakeCoin(coins, mid + 1, end, weight);
        }
        else { // 참조 동전이 더 왼쪽에 있는 경우
            return findFakeCoin(coins, start, mid, weight);
        }
    }
}

int main() {
    int coins[10] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1 }; // 10개의 동전 배열 (9개는 진짜, 1개는 가짜)
    int n = 10; // 배열의 크기
    int weight = 6; // 참조 동전의 무게

    int fake_coin = findFakeCoin(coins, 0, n - 1, weight); // 가짜 동전의 인덱스 검색

    if (fake_coin == -1) {
        printf("모든 동전이 진짜입니다.\n");
    }
    else {
        printf("%d번째 동전이 가짜입니다.\n", fake_coin + 1);
    }

    return 0;
}
