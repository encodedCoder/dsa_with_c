#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int i;
	for (i = 0; i < 10; ++i)
	{
		fork();
	}
	return 0;
}