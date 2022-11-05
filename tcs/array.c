#include <stdio.h>
int main(int argc, char const *argv[])
{
	char arr[6] = {10, 20, 30, 40, 50, 60};
	char *ptr = (char*)(&arr + 1);
	printf("%d%d\n", *(arr+1), *(ptr-1));
	printf("%d\n", sizeof(arr));
	return 0;
}




/*What is the source of this question? When you are sending questions from other sources 
(other than that from our practice questions, test series and previous year questions), 
then you need to send us the exact source from where you got this question, 
the solution given over there, your workings for this questions and the exact doubt in this question. 
These days we are getting unwanted questions which are wrong. 

So, maintain this decorum from now on while you are sending questions from outside our course .

Thanks*/