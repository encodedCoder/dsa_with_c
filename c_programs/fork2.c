#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int id, a = 10, b = 0;
	int *address;
	id = fork();
	if(id > 0){
		printf("This is Parent process.\n");
		a -= 5;
		printf("%2d, %p\n", a, &a);
	}
	else if(id == 0){
		printf("\nThis is Child process.\n");
		address = &a;
		*address = 20;
		a += 5;
		printf("%2d, %p\n", a, &a);
	}
	printf("----%p\n", address);

	return 0;
}