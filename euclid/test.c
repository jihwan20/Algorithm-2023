#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h"

int testEuclid2() {

	int n = 1000;
	int a, b; // 임의의 숫자
	clock_t start, end;
	int rec_result, rep_result;
	double rec_time, rep_time;	// 각 함수의 실행시간

	// 랜덤한 매우 큰 두 수의 쌍 N개 생성
	srand(time(NULL));
	printf("랜덤 번호 :\n");
	for (int i = 0; i < n; i++) {
		a = rand() % 100000000 + 1;
		b = rand() % 100000000 + 1;
		printf("%d %d\n", a, b);
	}
	printf("\n");

	// 재귀적 방법으로 각 쌍의 최대공약수 계산
	start = clock(); // 수행 시간 측정 시작
	for (int i = 0; i < n; i++) {
		a = rand() % 100000000 + 1;
		b = rand() % 100000000 + 1;
		rec_result = recursiveEuclid(a, b);
	}
	end = clock(); // 수행 시간 측정 종료
	rec_time = (double)(end - start) / CLOCKS_PER_SEC;

	// 반복적 방법으로 각 쌍의 최대공약수 계산
	start = clock(); // 수행 시간 측정 시작
	for (int i = 0; i < n; i++) {
		a = rand() % 100000000 + 1;
		b = rand() % 100000000 + 1;
		rep_result = repetitiveEuclid(a, b);
	}
	end = clock(); // 수행 시간 측정 종료
	rep_time = (double)(end - start) / CLOCKS_PER_SEC;

	if (rec_result != rep_result) {
		printf("두 함수의 결과값이 다릅니다.");
	}
	else {
		// 결과 출력
		printf("재귀적 방법 결과값 : %d, 재귀적 방법 걸린 시간: %f sec\n", rec_result, rec_time);
		printf("반복적 방법 결과값 : %d, 반복적 방법 걸린 시간: %f sec\n", rep_result, rep_time);
	}
	return 0;
}


int testEuclid1() {
	int a = 24;
	int b = 14;
	int gcd_rec, gcd_rep; // 각 함수의 결과값

	gcd_rec = recursiveEuclid(a, b);
	gcd_rep = repetitiveEuclid(a, b);

	printf("재귀적 방법(%d %d) : %d\n", a, b, gcd_rec);
	printf("반복적 방법(%d %d) : %d\n", a, b, gcd_rep);

	return 0;
}
