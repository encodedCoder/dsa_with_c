#include <stdio.h>

int main(void){

	int a[5][6][7];
    printf("%d\n", a[1][2][3]);
    a[1][2][3] = 4;
//    printf("%d\n", (*((int*)a+59)));
    printf("%d", *(*(a[1]+2)+3));
	return 0;
}
