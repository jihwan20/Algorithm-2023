#include <stdio.h>

// �Ž������� �����ϴ� ������ ������ �����ϴ� ����ü
typedef struct CoinCount {
    int n500; // 500�� ������ ����
    int n100; // 100�� ������ ����
    int n50; // 50�� ������ ����
    int n10; // 10�� ������ ����
} CoinCount;

int cost; // �Ž�����

// �Ž������� ����ϴ� �Լ�
CoinCount calNCoin(int cost) {
    CoinCount count = { 0, 0, 0, 0 }; // ����ü �ʱ�ȭ

    // 500�� ���� ���� ���
    count.n500 = cost / 500;
    cost = cost % 500;

    // 100�� ���� ���� ���
    count.n100 = cost / 100;
    cost = cost % 100;

    // 50�� ���� ���� ���
    count.n50 = cost / 50;
    cost = cost % 50;

    // 10�� ���� ���� ���
    count.n10 = cost / 10;
    cost = cost % 10;

    return count;
}

int main()
{
    printf("�Ž������� �Է��ϼ���.\n");
    scanf("%d", &cost);                             // �Ž����� �Է�
    CoinCount count = calNCoin(cost);       // �ش� �Լ��� �Է°� ����
    printf("500�� ���� ����: %d\n", count.n500);// 500�� ������ ����
    printf("100�� ���� ����: %d\n", count.n100);// 100�� ������ ����
    printf("50�� ���� ����: %d\n", count.n50);  // 50�� ������ ����
    printf("10�� ���� ����: %d\n", count.n10);  // 10�� ������ ����

    return 0;

}