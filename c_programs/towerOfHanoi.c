#include<stdio.h>

int towerOfHanoiWithThreeTowers(int disks, char s, char d, char a){
	static int count = 0;
	if(disks == 1){
		printf("==>>Move disk from %c tower to %c tower.\n", s, d);
		count++;
	}
	else if(disks > 1){
		towerOfHanoiWithThreeTowers(disks-1, s, a, d);
		printf("==>>Move disk from %c tower to %c tower.\n", s, d);
		count++;
		towerOfHanoiWithThreeTowers(disks-1, a, d, s);
	}
	return count;
}

int main(void){

	char tower1 = 'a';
	char tower2 = 'b';
	char tower3 = 'c';

	printf("Steps to solve the tower of hanoi with %d disks are as follows: \n", 2);
	int count = towerOfHanoiWithThreeTowers(20, tower1, tower2, tower3);

	printf("%d\n", count);
	
	return 0;
}