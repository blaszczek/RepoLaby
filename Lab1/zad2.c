#include<stdio.h>

int main()
{
	char z;
	z = getchar();
	while (z!=EOF);
	{
		printf("%c", z);
	z = getchar();
	}
	return 0;
}
