
#include <Windows.h>
#include <conio.h>
#include <stdio.h>

gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void print_subMenu()
{
    int subNum;
    while (1)
    {
        printf("\n1. ��¥�� 2. �ݾ׼� 3. ���� >> ");
        scanf("%d", &subNum);

        switch (subNum)
        {
        case 1:
            printf("��¥�� on\n");
            break;
        case 2:
            printf("�ݾ׼� on\n");
            break;
        case 3:
            print_mainMenu();
            break;
        }
    }
}

void print_mainMenu()
{
    int mainNum;
    while (1)
    {
        printf("\n1.���� ��ȯ 2. ���� �߰� 3. ���� ���� 4. ���� ���� 5. ���� >> ");
        scanf("%d", &mainNum);

        switch (mainNum)
        {
        case 1:
            print_subMenu();
            break;
        case 2:
            printf("���� �߰� �޴� ����");
            break;
        case 3:
            printf("���� ���� �޴� ����");
            break;
        case 4:
            printf("���� ���� �޴� ����");
            break;
        case 5:
            printf("���� ����");
            exit(1);
            break;
        }
    }
    
}

int main()
{
    system("cls");

    gotoxy(0, 0);
    printf("�������������������������������������������������\n");

    gotoxy(0, 1);
    printf("��");

    gotoxy(94, 1);
    printf("��");

    gotoxy(0, 2);
    printf("��");

    gotoxy(94, 2);
    printf("��");

    gotoxy(0, 3);
    printf("��");

    gotoxy(94, 3);
    printf("��");

    gotoxy(0, 4);
    printf("��");

    gotoxy(94, 4);
    printf("��");

    gotoxy(0, 5);
    printf("��");

    gotoxy(94, 5);
    printf("��");

    gotoxy(0, 6);
    printf("��");

    gotoxy(94, 6);
    printf("��");

    gotoxy(0, 7);
    printf("��");

    gotoxy(94, 7);
    printf("��");

    gotoxy(0, 8);
    printf("��");

    gotoxy(94, 8);
    printf("��");

    gotoxy(0, 9);
    printf("��");

    gotoxy(94, 9);
    printf("��");

    gotoxy(0, 10);
    printf("��");

    gotoxy(94, 10);
    printf("��");

    gotoxy(0, 11);
    printf("�������������������������������������������������\n");
    print_mainMenu();
	return 0;
}
