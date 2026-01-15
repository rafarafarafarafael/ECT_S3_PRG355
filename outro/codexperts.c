
int getLowestIndex(int numbers[]){
	int count, minIndex = 0, arraySize;
	arraySize = (int)(sizeof(numbers)/sizeof(int));
	for(count = 1; count < arraySize; count++){
		if(numbers[count] < numbers[minIndex]){
			minIndex = count;
		}
	}
	return minIndex;
}

const char* prtNumbers(char str[]){
	const int strSize = (int)(sizeof(str)/sizeof(char));
	char outStr[strSize];
	char curChar;
	int count, nextChar = 0;
	for(count = 0; count < strSize; count++){
		curChar = *(str+count);
		if(curChar >= '0' && curChar <= '9'){
			 outStr[nextChar++] = curChar;
		}
	}
	return outStr;
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
