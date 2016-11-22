#include <stdio.h>

int main(void)
{
	int row = 10;
	int out = 2;

	for (int i = 0; i < row; i++)
	{
		int c;
		for (c = 0; c <= (row - i); c++)
			printf("  ");

		int star;
		for (c = 0; c <= i; c++)
		{
			while (1) {
				for (star = 2; star <= out - 1; star++)
				{
					if (out % star == 0)
						break;
				}
				if (out++ == star)
				{
					printf("%3d ", out - 1);
					break;
				}
			}
		}
		printf("\n");
	}
}

