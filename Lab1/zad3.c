#include<stdio.h>

void tablca(int tab[], int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d", tab[i++]);
	}
	
}

int main()
{
	int pom;
	int a=2;
	int tab1[5]={1, 2, 3, 4, 5};
	int tab2[5]={1, 2, 3, 4, 5};
	pom=a;
	tab1[a++]=0
	a=pom;
	tab2[++a]=0;
	tablica(tab1, 5);
	printf("\n");
	tablica(tab2, 5);

	int x=10;
	int y;
	int z;
	y=(x+=2);
	z=(x%3)+(x%4);
	printf("%d, %d, %d\n", x, y, z);

	return 0;
}
