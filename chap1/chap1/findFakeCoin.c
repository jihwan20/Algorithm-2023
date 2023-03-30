#include <stdio.h>

int find_FakeCoin() {
    int coins[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 };            // ��¥ ���� 9���� ��¥ ���� 1��
    int n = 10;                                                  // ��ü ������ ��
    int dummy1 = 0, dummy2 = n - 1;                              // ������ ���� ���ʰ� ������ �ε���
    int mid = (dummy1 + dummy2) / 2;                             // �߾Ӱ��� pivot���� ����

    while (dummy2 >= dummy1) {                                   // dummy1�� dummy2���� �۰ų� ���� ���� �ݺ�
        if (coins[mid] == 0) {                                   // mid ������ ��¥ ������ ���
            printf("��¥ ������ %d��° �����Դϴ�.", mid + 1);   // mid ��ġ ���
            break;
        }
        else if (coins[mid] == 1) {                              // mid ������ ��¥ ������ ���
            dummy1 = mid + 1;                                    // ���� �κ����� ����
        }
        else {                                                   // mid ������ ���� ���
            dummy2 = mid - 1;                                    // ������ �κ����� ����
        }
        mid = (dummy1 + dummy2) / 2;                             // ���ο� mid ���
    }
    return 0;
}

int main() {
    find_FakeCoin();
    return 0;
}