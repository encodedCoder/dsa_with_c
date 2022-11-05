/*problem statement: we want to print 5 from array 'a'. 
Is following program going to print correct answer
If there is any error in the code then mention it 
and correct it to print the required result, if there is any?
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a[2][2] = {9, 2, 5, 8};
    int **p = &a;

    printf("%d", p[1][0]);

    return 0;
}
