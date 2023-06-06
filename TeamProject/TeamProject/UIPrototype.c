
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
        printf("\n1. 날짜순 2. 금액순 3. 보기 >> ");
        scanf("%d", &subNum);

        switch (subNum)
        {
        case 1:
            printf("\n날짜순 on\n");
            break;
        case 2:
            printf("\n금액순 on\n");
            break;
        case 3:
            printf("\n보기로 이동\n");
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
        printf("\n1.보기 변환 2. 내용 추가 3. 내용 수정 4. 내용 삭제 5. 종료 >> ");
        scanf("%d", &mainNum);

        switch (mainNum)
        {
        case 1:
            system("cls");
            print_subMenu();
            break;
        case 2:
            printf("\n내용 추가 메뉴 선택\n");
            break;
        case 3:
            printf("\n내용 수정 메뉴 선택\n");
            break;
        case 4:
            printf("\n내용 삭제 메뉴 선택\n");
            break;
        case 5:
            printf("\n종료 선택\n");
            exit(1);
            break;
        }
    }
    
}

void draw_todo()
{
    int i, j;

    gotoxy(0, 0);
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
    

    for (i = 1; i <= 10; i++)
    {
        gotoxy(0, i);
        printf("□");
        gotoxy(94, i);
        printf("□");
    }

    gotoxy(0, 11);
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
}

int main()
{

    system("cls");

    draw_todo();
    print_mainMenu();
	return 0;
}
