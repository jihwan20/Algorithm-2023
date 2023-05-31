
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
        printf("\n1. 날짜순 2. 금액순 3. 보기 >> ");
        scanf("%d", &subNum);

        switch (subNum)
        {
        case 1:
            printf("날짜순 on\n");
            break;
        case 2:
            printf("금액순 on\n");
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
        printf("\n1.보기 변환 2. 내용 추가 3. 내용 수정 4. 내용 삭제 5. 종료 >> ");
        scanf("%d", &mainNum);

        switch (mainNum)
        {
        case 1:
            print_subMenu();
            break;
        case 2:
            printf("내용 추가 메뉴 선택");
            break;
        case 3:
            printf("내용 수정 메뉴 선택");
            break;
        case 4:
            printf("내용 삭제 메뉴 선택");
            break;
        case 5:
            printf("종료 선택");
            exit(1);
            break;
        }
    }
    
}

int main()
{
    system("cls");

    gotoxy(0, 0);
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");

    gotoxy(0, 1);
    printf("□");

    gotoxy(94, 1);
    printf("□");

    gotoxy(0, 2);
    printf("□");

    gotoxy(94, 2);
    printf("□");

    gotoxy(0, 3);
    printf("□");

    gotoxy(94, 3);
    printf("□");

    gotoxy(0, 4);
    printf("□");

    gotoxy(94, 4);
    printf("□");

    gotoxy(0, 5);
    printf("□");

    gotoxy(94, 5);
    printf("□");

    gotoxy(0, 6);
    printf("□");

    gotoxy(94, 6);
    printf("□");

    gotoxy(0, 7);
    printf("□");

    gotoxy(94, 7);
    printf("□");

    gotoxy(0, 8);
    printf("□");

    gotoxy(94, 8);
    printf("□");

    gotoxy(0, 9);
    printf("□");

    gotoxy(94, 9);
    printf("□");

    gotoxy(0, 10);
    printf("□");

    gotoxy(94, 10);
    printf("□");

    gotoxy(0, 11);
    printf("□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□□\n");
    print_mainMenu();
	return 0;
}
