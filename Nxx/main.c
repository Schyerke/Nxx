#include "includeme.h"
#include "lexer.h"

int main()
{
	char src[200];
	printf("> ");
	fgets(src, 200, stdin);

	Lexer* lexer = (Lexer*)malloc(sizeof(Lexer));

	if (!lexer)
	{
		printf("Insufficient memory for Lexer.");
		free(lexer);
		return;
	}

	init_lexer(lexer, src);
	Token* head = tokenize(lexer);
	Token* current = head;

	while (current != NULL)
	{
		Token token = *current;		
		char* text_h = token.text;

		while (text_h != NULL && *text_h != '\0')
		{
			printf("%c", *text_h);
			text_h++;
		}
		printf("\n");
		current++;
	}

	return 0;
}