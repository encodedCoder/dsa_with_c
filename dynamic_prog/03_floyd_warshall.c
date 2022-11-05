#include<stdio.h>

int a[4][4] =  {{0, 11, 1, 6}, 
                {11, 0, 7, 3}, 
                {1,  7, 0, 2}, 
                {6,  3, 2, 0}};

void floyd_warshall(void){
    int matrix_1[4][4] = {{0, 11, 1, 6}, 
                          {11, 0, 7, 3}, 
                          {1,  7, 0, 2}, 
                          {6,  3, 2, 0}};
    int matrix_2[4][4];

    int vertex_number, row_number, column_number, val_1, val_2;
    int (*prev)[4], (*curr)[4];
    for (vertex_number = 0; vertex_number < 4; vertex_number++)
    {
        if (vertex_number % 2 == 0)
        {
            prev = matrix_1;
            curr = matrix_2;
        } 
        else
        {
            prev = matrix_2;
            curr = matrix_1;
        }
               
        for (row_number = 0; row_number < 4; row_number++)
        {
            for (column_number = 0; column_number < 4; column_number++)
            {
                val_1 = prev[row_number][column_number];
                val_2 = prev[row_number][vertex_number] + prev[vertex_number][column_number];
                curr[row_number][column_number] = (val_1 <= val_2) ? val_1 : val_2;
            } 
        }
    }
    int i, j;
    for(i = 0; i < 4; ++i){
        for(j = 0; j < 4; ++j){
            printf("%3d ", matrix_1[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int i, j;
    for(i = 0; i < 4; ++i){
        for(j = 0; j < 4; ++j){
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    floyd_warshall();
    return 0;
}
