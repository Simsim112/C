#include <stdio.h>

//ÆÑÅä¸®¾ó Àç±Í·Î ±¸Çö 
int fac(int i)
{
	if (i <= 0)
		return 1;
	else
		return i * fac(i-1);
}

int main() 
{
	//int res = 1;
	//for (int i = 4; i >= 1; i--)
	//{
	//	res *= i;
	//}
	//printf("%d", res);

	printf("%d", fac(10));
	return 0;
}