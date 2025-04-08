#include <stdio.h>

int fibanocci(int n)
{
	if (n==0)
		return 0;
	else if (n==1)
		return 1;
	else
		return fibanocci(n-1)+fibanocci(n-2);
}

int main()
{
	int n,i;
	printf("Enter the number of terms : ");
	scanf("%d",&n);

	printf("Fibonacci Series : ");
	for (i=0; i<n; i++)
	{
		printf("%d ",fibanocci(i));
	}
	printf("\n");
	return 0;
}
