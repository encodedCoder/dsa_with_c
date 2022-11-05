// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
// 	int count = 0;
// 	int i, j, k, n = 100;
// 	for(i = 1; i <= n; i++)
// 		for(j = 1; j <= i; j++)
// 			for(k = 1; k<= 100; k++)
// 				count++;
// 	printf("%d\n", count);
// 	return 0;
// }


#include <stdio.h>
int main(int argc, char const *argv[])
{
	float count = 0;
	float i, j, k, n = 100;
	for(i = 1; i <= n; i++)
		for(j = 1; j <= i * i; j++)
			for(k = 1; k <= n/2; k++)
				count++;
	printf("%f\n", count);
	return 0;
}