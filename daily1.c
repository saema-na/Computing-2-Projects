#include <stdio.h>

//function that returns a pointer value
 char * reverse(char *word);

int main(int argc, char* argv[]) {

	char word[] = "Happy Birthday!\n";

	printf("%s\n", word);
	reverse(word);
	printf("%s\n", word);
	printf("%s\n", reverse(word));
	printf("%s\n", word);
	return 0;
}

	char* reverse(char *word) {
		int i = 0;
		int j = 0;
		int length = 0;
		char temp;

		//Loop to define string length
		for (i = 0; word[i] != '\0'; i++) 
		{
			length = length + 1;
		}

		i = 0;

		//loop that swaps characters with use of a temp variable
		for (i = length - 1; i >= length/2; i--) 
		{
			temp = word[j];
			word[j] = word[i];
			word[i] = temp;
			j++;
		}
		return word;
} 