#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>

COORD coord = { 0,0 };

void gotoxy(int x, int y)
{
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main(void)
{
	system("cls"); 
	gotoxy(20, 2);
	printf("[1] 비트 AND(&)");
	gotoxy(20, 4);
	printf("[2] 비트 OR(|) ");
	gotoxy(20, 6);
	printf("[3] 비트 XOR(^)");
	gotoxy(20, 8);
	printf("[4] 비트 COMPLEMENT(~)");
	gotoxy(20, 10);
	printf("[0] 종료(stop)\n");

	int select;
	gotoxy(10, 12);
	printf("위 연산 중 하나를 선택하세요. >> ___");
	gotoxy(44, 12);
	scanf("%d", &select);

	int x, y;
	switch (select)
	{
	case 1: case 2: case 3:
		gotoxy(10, 16);
		printf("비트 연산할 두 정수 입력 >> ");
		scanf("%d %d", &x, &y);
		gotoxy(10, 18);
		printf("    x =");
		gotoxy(20, 18);
		for (int c = 31; c >= 0; c--)
		{
			int k = x >> c;
			printf("%c", (k & 1) ? '1' : '0');
		}
		printf("%4d", x);

		gotoxy(10, 20);
		printf("    y =");
		gotoxy(20, 20);
		for (int c = 31; c >= 0; c--)
		{
			int k = y >> c;
			printf("%c", (k & 1) ? '1' : '0');
		}
		printf("%4d", y);

		gotoxy(10, 22);
		if (select == 1) {
			printf("x & y =");
			gotoxy(20, 22);
			for (int c = 31; c >= 0; c--)
			{
				int k = (x & y) >> c;
				printf("%c", (k & 1) ? '1' : '0');
			}
			printf("%4d\n", x & y);
		}
		else if (select == 2) {
			printf("x | y =");
			gotoxy(20, 22);
			for (int c = 31; c >= 0; c--)
			{
				int k = (x | y) >> c;
				printf("%c", (k & 1) ? '1' : '0');
			}
			printf("%4d\n", x | y);
		}
		else if (select == 3) {
			printf("x ^ y =");
			gotoxy(20, 22);
			for (int c = 31; c >= 0; c--)
			{
				int k = (x ^ y) >> c;
				printf("%c", (k & 1) ? '1' : '0');
			}
			printf("%4d\n", x ^ y);
		}
		break;

	case 4:
		gotoxy(10, 16);
		printf("비트 보수(~) 연산할 하나의 정수 입력 >> ");
		scanf("%d", &x);
		gotoxy(10, 18);
		printf("   x =");
		gotoxy(20, 18);
		for (int c = 31; c >= 0; c--)
		{
			int k = x >> c;
			printf("%c", (k & 1) ? '1' : '0');
		}

		gotoxy(10, 20);
		printf("  ~x =");
		gotoxy(20, 20);
		for (int c = 31; c >= 0; c--)
		{
			int k = ~x >> c;
			printf("%c", (k & 1) ? '1' : '0');
		}
		printf("%4d\n", ~x);
		break;

	case 0:
		printf("\n 프로그램을 종료합니다.\n");
		break;

	default:
		printf("1, 2, 3, 4, 0 중에서 다시 선택하세요.\n");
	}

	return 0;
}