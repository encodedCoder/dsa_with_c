//  #include <stdio.h>
// void foo( int n)
// {
//        if(n==0) return ;
//        else if(n%2==0)
//        {
//               foo(n/2);
//               printf("%d ",n%2);
//        }
//        else if(n%2==1)
//        {
//               printf("%d ",n%2);
//               foo(n/2);
//        }
// }
// main(){
//        foo(62);
// }


#include<stdio.h>

int * fun()

{

   int q = 10;

   int *p;

   p = &q;

   return p;

}    

int main()

{

  int *res;

   res= fun();

printf("%d", *res);

return 0;

}