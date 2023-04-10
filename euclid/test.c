#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h"

// 두 방법의 실행시간을 측정하는 함수
void testEuclid(int n) {
    int testCases[n][2];
    int i, gcd1, gcd2;
    clock_t startTime, endTime;
    double recursiveTime, repetitiveTime;

    // testCases 배열 초기화
    for (i = 0; i < n; i++) {
        testCases[i][0] = rand();
        testCases[i][1] = rand();
    }

    // 재귀적 방법의 실행시간 측정
    startTime = clock();
    for (i = 0; i < n; i++) {
        gcd1 = recursiveEuclid(testCases[i][0], testCases[i][1]);
    }
    endTime = clock();
    recursiveTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // 반복적 방법의 실행시간 측정
    startTime = clock();
    for (i = 0; i < N; i++) {
        gcd2 = repetitiveEuclid(testCases[i][0], testCases[i][1]);
    }
    endTime = clock();
    repetitiveTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // 두 방법으로 계산한 최대공약수가 같은지 검사
    for (i = 0; i < N; i++) {
        if (recursiveEuclid(testCases[i][0], testCases[i][1]) != repetitiveEuclid(testCases[i][0], testCases[i][1])) {
            printf("ERROR: gcds are not same\n");
            return;
        }
    }

    // 실행시간 출력
    printf("Recursive Euclid time: %.5f sec\n", recursiveTime);
    printf("Repetitive Euclid time: %.5f sec\n", repetitiveTime);
}