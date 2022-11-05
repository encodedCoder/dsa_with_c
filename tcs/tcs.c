// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// void myfunc(char** param){
// 	++param;
// }
// int main(){
// 	char* string = (char*)malloc(64);
// 	strcpy(string, "hello_World");
// 	myfunc(&string);
// 	myfunc(&string);
// 	printf("%s\n", string);
// 	// ignore memory leak
// 	return 0;
// }


// #include <stdio.h>
// void main()
// {
// 	// int k = 5;
// 	// int *p = &k;
// 	// int **m = &p;
// 	// printf("%d%d%d\n", k, *p, **p);
// }


// #include<stdio.h>
// int main()
// {
// 	int a[5] = {5, 1, 15, 20, 25};
// 	int i, j, m;
// 	i = ++a[1];
// 	j = a[1]++;
// 	 m = a[i++];
// 	printf("%d, %d, %d", i, j, m);
// 	return 0;
// }


// #include <stdio.h>
// void main(){
// 	int a = 10, x;
// 	x = a-- + ++a;
// 	printf("%d", x);
// }


// #include <stdio.h>
// main()
// {
// // int a=10,x=20;
// // a=a++ + 10; // a = 10+10 first a is increment to 11 but overwritten by 20
// // x=x++ + ++a; // x = 20 + 21 a is incremented first from 20 to 21
// // printf("%d,%d",a,x);
// printf("%%%%\n");
// printf("%a\n");
// }


// #include <stdio.h>
// void main()
// {
// printf("\n ks");
// printf("\b mi \a");
// printf("\r ha \n");
// }


// #include <stdio.h>
// void main(){
// 	int i=10,j=2,k=0,m;
// 	m=++i&&++j&&++k;
// 	printf("%d %d %d %d",i,j,k,m);
// }


// #include <stdio.h>
// void main(){
// 	int a=10,*p;
// 	int *vp;
// 	p = &a;
// 	vp = p;
// 	printf("%d", *p);
// 	printf("%d", *vp);
// }


// #include <stdio.h>
// void main(){
// 	char *str= "face",b;
// 	printf("%d",-2[str]);
// }


// #include <stdio.h>
// void main(){
// 	printf("%d\n",printf("FACE"));
// 	printf("\n",printf("Third "),printf("Second "),printf("First "));
// 	printf("%f%f%f\n",printf("Third "),printf("Second "),printf("First "));
// 	printf("%d%d%d\n",printf("Third "),printf("Second "),printf("First "));
// }


// #include <stdio.h>
// void main(){
// 	int a=2000;
// 	printf("%6d",a);
// }


// #include <stdio.h>
// void main(){
// 	int x,a=10;
// 	x=a==10?printf("hai\t"):printf("hello\n");
// 	printf("%d",x);
// }


// #include <stdio.h>
// int main(void){
// 	http://prepinsta.com/ //valid specification ​​ ​​http://
// 	printf("Hello, World !!!\n");
// 	return 0;
// }


// #include <stdio.h>
// int main(){
// 	signed char i=0;
// 	for(; i >= 0; i++)
// 	printf("%d\n", i);
// 	getchar();
// 	return 0;
// }


// #include <stdio.h>
// void main(){
// 	int a[][2] = {{1,2},{3,4},{5,6}};
// 	printf("%d",a[1][1]);
// }


// #include <stdio.h>
// void main()
// {
// 	int arr2D[3][3]={1,2,3,4,5,6};
// 	printf("%d\n", ((arr2D == *arr2D) && (*arr2D == arr2D[0])) );
// }


// #include <stdio.h>
// void main(){
// 	char a= 'a',*p;
// 	p=&a;
// 	printf("%d,%d",sizeof(*p) , sizeof(p));
// }


// #include <stdio.h>
// void main(){
// 	int i=10, j=20;
// 	int *p,*q;
// 	*p=i;
// 	q=&j;
// 	printf("%d,%d",*p,*q);
// }


// #include <stdio.h>
// void main(){
// 	int i=7;
// 	printf("%d",i++*i++); // 7*8
// }


// #include <stdio.h>
// float sub(float, float);
// int main(){
// 	float a = 4.5, b = 3.2, c;
// 	c = sub(a, b);
// 	printf("c = %f\n", c);
// 	return 0;
// }
// float sub(float a, float b){
// 	return (a - b);	
// }


// #include <stdio.h>
// struct student{
// 	int stuid;
// 	char stuname[5];
// }s1;
// void main(){
// 	struct student s1;
// 	printf("%d, %s",s1.stuid,s1.stuname);
// }


// #include <stdio.h>
// struct birthdate
// {
// 	int date;
// 	int month;
// 	int year;
// };
// main(){
// 	struct student{
// 		int stuid;
// 		char stuname[20];
// 		struct birthdate dob;
// 	}s1={1234, "abcde"};
// 	printf("size of s1: %d\n",sizeof(s1));//sizeof(int)+sizeof(stuname)+sizeof(birthdate)
// 	printf("sizeof int: %d\n",sizeof(int));
// 	// printf("sizeof stu:%d\n",sizeof(stuname));
// 	// printf("sizeof bir:%d\n",sizeof(birthdate));
// }


// #include<stdio.h>
// int main(){
// 	float a=2.15529;
// 	printf("%2.1f\n", a);//rounds decimal value to next higher digit
// 	printf("%.2f\n", 5.21846);
// 	return 0;
// }