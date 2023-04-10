#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h"

// �� ����� ����ð��� �����ϴ� �Լ�
void testEuclid(int n) {
    int testCases[n][2];
    int i, gcd1, gcd2;
    clock_t startTime, endTime;
    double recursiveTime, repetitiveTime;

    // testCases �迭 �ʱ�ȭ
    for (i = 0; i < n; i++) {
        testCases[i][0] = rand();
        testCases[i][1] = rand();
    }

    // ����� ����� ����ð� ����
    startTime = clock();
    for (i = 0; i < n; i++) {
        gcd1 = recursiveEuclid(testCases[i][0], testCases[i][1]);
    }
    endTime = clock();
    recursiveTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // �ݺ��� ����� ����ð� ����
    startTime = clock();
    for (i = 0; i < N; i++) {
        gcd2 = repetitiveEuclid(testCases[i][0], testCases[i][1]);
    }
    endTime = clock();
    repetitiveTime = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    // �� ������� ����� �ִ������� ������ �˻�
    for (i = 0; i < N; i++) {
        if (recursiveEuclid(testCases[i][0], testCases[i][1]) != repetitiveEuclid(testCases[i][0], testCases[i][1])) {
            printf("ERROR: gcds are not same\n");
            return;
        }
    }

    // ����ð� ���
    printf("Recursive Euclid time: %.5f sec\n", recursiveTime);
    printf("Repetitive Euclid time: %.5f sec\n", repetitiveTime);
}