#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int data;
	printf("\n 정수를 하나 입력하세요. >> ");
	scanf("%d", &data);

	while (data)
	{
		printf("\n\t이진수: ");
		for (int c = 31; c >= 0; c--)
			printf("%c", ((data >> c) & 1) ? '1' : '0');
		printf("\n");

		printf("\n\t팔진수: ");
		int temp = data;
		int octal = 0;
		int i = 1;
		while (temp)
		{
			
			int rem = temp % 8;
			temp /= 8;
			octal += rem * i;
			i *= 10;
		}
		printf("%32d", octal);
		printf("%8o\n", data);

		
		int digits = 1;
		temp = data;
		while (temp /= 16)
			digits++;

		temp = data;
		printf("\n\t16진수: ");

		int tad = 1;
		for (int i = 1; i < digits; i++)
			tad *= 16;

		printf("%*s", 32 - digits, " ");
		while (digits)
		{
			int out = temp / tad;
			if (out < 10)
				printf("%d", out);
			else
				printf("%c", out + 55);

			temp -= tad * out;;
			tad /= 16;
			digits--;
		}
		printf("%8X\n", data);
		printf("\n");

		printf("\n 정수를 하나 입력하세요. >> ");
		scanf("%d", &data);
	}
	printf("종료합니다.\n");

	return 0;
}