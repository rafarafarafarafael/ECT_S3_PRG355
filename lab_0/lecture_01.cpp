/*
Problem 1: Character Frequency
1. Write a C program that asks the user to enter a lowercase phrase (up to 200 characters).
Your program should:

Count the frequency of each letter (a to z).
Store letters in one char array, and their corresponding counts in a parallel integer array.
In alphabetical order, print only the letters that appear in the phrase along with
their counts (any other characters are ignored).

Example Run
Enter a phrase: programming in c!
Letter frequencies:
c:1
g:2
i:2
m:2
n:2
o:1
p:1
r:2

Hint:
Use two parallel arrays:
char letters[26] = {'a', 'b', 'c', ..., 'z'};
int counts[26] = {0};

Traverse the phrase character by character and if it's a letter,
increment the corresponding counts[index].
At the end, loop through both arrays and print letters with counts[i] > 0.
*/

#include <cstdio>
#include <cstring>
#define STRING_SIZE 200

int main(){
	char myString[STRING_SIZE + 1];

	printf("Please enter a string:\n");
	return 0;
}