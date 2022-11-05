#include <stdio.h>

int main(int argc, char const *argv[])
{
	int d = 0, i, j, k, count = 31;
	for (i = 1; i < count; ++i)
		for(j = 1; j < count; ++j)
			for(k = 1; k < count; ++k)
				if(((i+j+k)%3) == 0)
					++d;
	printf("%d\n", d);
	return 0;
}