
#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#define MAX_SIZE 10

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
            printf("\n��¥�� on\n");
            break;
        case 2:
            printf("\n�ݾ׼� on\n");
            break;
        case 3:
            printf("\n����� �̵�\n");
            system("cls");
            return;
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
            system("cls");
            print_subMenu();
            break;
        case 2:
            printf("\n���� �߰� �޴� ����\n");
            break;
        case 3:
            printf("\n���� ���� �޴� ����\n");
            break;
        case 4:
            printf("\n���� ���� �޴� ����\n");
            break;
        case 5:
            printf("\n���� ����\n");
            exit(1);
            break;
        }
    }
    
}

void draw_todo()
{
    int i, j;

    gotoxy(0, 0);
    printf("�������������������������������������������������\n");
    

    for (i = 1; i <= 10; i++)
    {
        gotoxy(0, i);
        printf("��");
        gotoxy(94, i);
        printf("��");
    }

    gotoxy(0, 11);
    printf("�������������������������������������������������\n");
}

int main()
{

    system("cls");

    draw_todo();
    print_mainMenu();
	return 0;
}
