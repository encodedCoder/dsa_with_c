#include <stdio.h>

int isValidBinaryNumber(int num){
	int remainder;
	while(num != 0){
		remainder = num%10;
		if(remainder == 0)
			num /= 10;
		else if (remainder ==1)
			num /= 10;
		else
			return 0;
	}
	return 1;
}

int convertBinaryToDecimal(int num){
	int sum, powerT=1;
	sum = num%10;
	num /= 10;

	while(num != 0){
		sum += ((num%10) * (powerT *= 2));
		num /= 10;
	}
	return sum;
}

void main(){
	int num;
	printf("Enter a binary number: ");
	scanf("%d", &num);

	if(isValidBinaryNumber(num))
		printf("Decimal equivalent of %d is: %d\n", num, convertBinaryToDecimal(num));
	else
		printf("Conversion failed.\nERR-TYPE: Invalid binary number.\nSOLUTION: Enter valid binary number.");
}