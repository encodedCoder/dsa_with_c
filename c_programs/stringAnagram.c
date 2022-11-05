#include <stdio.h>

int anagram (char *a, char *b) {
	int count [128], j;
	for (j = 0; j < 128; j++) count[j] = 0;
	j = 0;
	while (a[j] && b[j]) {
		count[a[j]]++;
		count[b[j++]]--;
	}

	int flag = 0;
	for (j = 0; j < 128; j++){
		if (count [j]){
			return 0;
		}
	}
	return 1;
}


int main(void){
	char *s = "abcd";
	char *t = "bcad";

	printf("%d\n", anagram(s, t));
	
	return 0;
}