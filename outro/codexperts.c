#include <stdio.h>
#include <stdlib.h>

int getLowestIndex(int numbers[], int arraySize);
int prtNumbers(char str[], const int strSize);
int isPrimeNumber(int number);

int main(){
	int intArray[] = {93, 567, 56, 87, 90, 23};
	int minIndex, myNumber = 4;
	char myString[] = "Here's a number for you: 23, 25";

	minIndex = getLowestIndex(intArray, (int)(sizeof(intArray)/sizeof(intArray[0])));
	printf("the lowest number is %d,\n", intArray[minIndex]);

	printf("The original string is: %s\nAnd we found the following numbers in it: %d\n", myString, prtNumbers(myString, (int)(sizeof(myString)/sizeof(char))));

	if(isPrimeNumber(myNumber)){
		printf("The number %d is prime.\n", myNumber);
	} else {
		printf("The number %d is not prime.\n", myNumber);
	}
	return 0;
}


int getLowestIndex(int numbers[], int arraySize){
	int count, minIndex = 0;
	// printf("arraySize: %d\nSize of int: %d\n", arraySize, (int)(sizeof(int)));
	for(count = 1; count < arraySize; count++){
		if(numbers[count] < numbers[minIndex]){
			minIndex = count;
		}
	}
	return minIndex;
}

int prtNumbers(char str[], int strSize){
	char* ptOutStr;
	char curChar;
	int count, nextChar = 0, outNum;

	ptOutStr = (char*)calloc(strSize, sizeof(char));
	if(NULL == ptOutStr){
		printf("Pointer allocation failed!\n");
		exit(1);
	}

	for(count = 0; count < strSize; count++){
		curChar = *(str+count);
		if(curChar >= '0' && curChar <= '9'){
			 ptOutStr[nextChar++] = curChar;
		}
	}
	
	outNum = atoi(ptOutStr);

	free(ptOutStr);
	return outNum;
}

int isPrimeNumber(int number){
	int divisors = 0, count;
	for(count = 1; count <= number; count++){
		if(number%count == 0){
			divisors++;
		}
	}
	return (int)(divisors <= 2);
}
