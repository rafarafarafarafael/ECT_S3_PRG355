/*
2. Ask the user to enter a single sentence (up to 100 characters).
Your program should split the sentence into words (separated by spaces).
Reverse each word in-place using pointers.
Print the modified sentence.

Example:
Enter a phrase: hello world C programming

Output:
olleh dlrow C gnimmargorp

Hint:
Use the strtok( ) to tokenize the sentence by spaces (strtok( ) is found in <cstring>
Write a helper function:
void reverse_word(char *word) that swaps characters using pointers.
Remember that strings in C are null-terminated.

How the strtok( ) function works:
strtok( ) is a standard C library function used to split a string into tokens
(substrings), based on a set of delimiters (like spaces, commas, tabs, etc.).

First call:
You pass the original string and a delimiter list.
strtok( ) finds the first token, replaces the delimiter with \0, and returns
a pointer to the token.

Subsequent calls:
You call strtok(NULL, delimiters). This continues scanning the same string from
where it left off.

Termination:
When no more tokens are found, strtok( ) returns NULL.

Important notes:
strtok( ) modifies the original string (by inserting \0 terminators).

Example: Splitting a Sentence into Words
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>

void ReverseWord(char *word);


int main(){
	char myString[] = "Hello world C programming !";
	char *token;
	int count;

	printf("%s\n", myString);

	token = strtok(myString, " ");
	while(NULL != token){
		ReverseWord(token);
		printf("%s ", token);
		token = strtok(NULL, " ");
		if(NULL == token) printf("\n");
	}
	
	return 0;
}

void ReverseWord(char *word){
	// 01234 
	// hello
	// 43210
	int  nextIndex, count = 0, wordLength = strlen(word);
	char nextChar;

	for(count = 0; count < wordLength/2; count++){
		nextIndex = wordLength - (1 + count);
		nextChar = *(word + nextIndex);
		*(word + nextIndex) = *(word + count);
		*(word + count) = nextChar;
	}
}