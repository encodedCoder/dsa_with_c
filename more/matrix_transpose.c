#include <stdio.h>

int main(int argc, char const *argv[])
{
	int matrix[][4] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

	// print matrix
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j)
			printf("%2d ", matrix[i][j]);
		printf("\n");
	} printf("\n");

	// transpose matrix
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if(i > j){
				int temp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = temp;
			}
		}
	}

	// print matrix
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 4; ++j)
			printf("%2d ", matrix[i][j]);
		printf("\n");
	}

	return 0;
}
