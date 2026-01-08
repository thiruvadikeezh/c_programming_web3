#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char word[] = "1234";

char r_word[128];

void word_reverser(void)
{
	int str_len = strlen(word);
	
	char temp[128];

	printf(" the first letter is %.3s\n", word);
	printf("\n the temp word is %s", word);

	for( int i = 0 ; i < str_len ; i++)
	{
		int rev = (str_len - 1) - i;
		temp[i] = word[rev];

	}
	temp[str_len] = '\0';

	strcpy(r_word, temp);

	printf("\n the temp word is %s\n", r_word);


}

int main()
{
	word_reverser();
	return 0;
}


