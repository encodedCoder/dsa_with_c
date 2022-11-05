#include<stdio.h>

int marks[6];

int main(void)
{
    int i, temp;
    printf("Students are: 10");
    printf("Enter Marks of students: Range[0:5]\n");
    for(i = 0; i <= 2; i++){
        printf("Enter marks for student i: ");
        scanf("%d", &temp);
        marks[temp]++;
    }
    printf("Frequencies of marks are: \n");
    for(i = 0; i <= 2; i++){
        printf("Frequency of %d mark(s): %d", i, marks[i]);
    }
    return 0;
}