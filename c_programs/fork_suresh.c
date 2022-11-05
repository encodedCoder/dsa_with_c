#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int id, a = 10;
	
	id = fork();

	if (id == 0)
	{
		a = a + 5;
		printf("%2d, %p\n", a, &a);
	}
	else if (id > 0)
	{
		a = a - 5;
		printf("%2d, %p\n", a, &a);
	}

	return 0;
}