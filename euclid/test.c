#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "euclid.h"

int testEuclid2() {

	int n = 1000;
	int a, b; // ������ ����
	clock_t start, end;
	int rec_result, rep_result;
	double rec_time, rep_time;	// �� �Լ��� ����ð�

	// ������ �ſ� ū �� ���� �� N�� ����
	srand(time(NULL));
	printf("���� ��ȣ :\n");
	for (int i = 0; i < n; i++) {
		a = rand() % 100000000 + 1;
		b = rand() % 100000000 + 1;
		printf("%d %d\n", a, b);
	}
	printf("\n");

	// ����� ������� �� ���� �ִ����� ���
	start = clock(); // ���� �ð� ���� ����
	for (int i = 0; i < n; i++) {
		a = rand() % 100000000 + 1;
		b = rand() % 100000000 + 1;
		rec_result = recursiveEuclid(a, b);
	}
	end = clock(); // ���� �ð� ���� ����
	rec_time = (double)(end - start) / CLOCKS_PER_SEC;

	// �ݺ��� ������� �� ���� �ִ����� ���
	start = clock(); // ���� �ð� ���� ����
	for (int i = 0; i < n; i++) {
		a = rand() % 100000000 + 1;
		b = rand() % 100000000 + 1;
		rep_result = repetitiveEuclid(a, b);
	}
	end = clock(); // ���� �ð� ���� ����
	rep_time = (double)(end - start) / CLOCKS_PER_SEC;

	if (rec_result != rep_result) {
		printf("�� �Լ��� ������� �ٸ��ϴ�.");
	}
	else {
		// ��� ���
		printf("����� ��� ����� : %d, ����� ��� �ɸ� �ð�: %f sec\n", rec_result, rec_time);
		printf("�ݺ��� ��� ����� : %d, �ݺ��� ��� �ɸ� �ð�: %f sec\n", rep_result, rep_time);
	}
	return 0;
}


int testEuclid1() {
	int a = 24;
	int b = 14;
	int gcd_rec, gcd_rep; // �� �Լ��� �����

	gcd_rec = recursiveEuclid(a, b);
	gcd_rep = repetitiveEuclid(a, b);

	printf("����� ���(%d %d) : %d\n", a, b, gcd_rec);
	printf("�ݺ��� ���(%d %d) : %d\n", a, b, gcd_rep);

	return 0;
}
