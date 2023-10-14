#include "includeme.h"
#include "lexer.h"


void init_lexer(Lexer* lexer, char* src)
{
    lexer->index = 0;
    lexer->src = src;
}

char get_current(Lexer* lexer)
{
    char* src = lexer->src;
    char current_char = *(src + lexer->index);
    return current_char;
}

void advance(Lexer* lexer)
{
    lexer->index++;
}

char next_char(Lexer* lexer)
{
    char* src = lexer->src;
    char current_char = *(src + lexer->index);
    advance(lexer);
    return current_char;
}

void add_token(Token* current, Token newToken)
{
    if (current == NULL)
    {
        printf("Error, current is NULL");
        return;
    }
    *current = newToken;
    current++;
}

// return an array of Token{s}
Token* tokenize(Lexer* lexer)
{
    int token_size = 5;
    Token* head = (Token*)malloc(sizeof(Token) * token_size);
    Token* current = head;

    while(1)
    {
        char current_char = next_char(lexer);

        if (current_char == '\0')
        {
            break;
        }

        if (isspace(current_char))
        {
            advance(lexer);
        }

        if (isdigit(current_char))
        {
            int start = lexer->index - 1;
            while (isdigit(get_current(lexer)))
            {
                advance(lexer);
            }
            advance(lexer);
            int text_length = lexer->index - start;

            char* text_head = (char*) malloc(text_length * sizeof(char));

            if (text_head == NULL)
            {
                free(text_head);
                printf("Insfficient memory for text_head");
                continue;
            }

            char* text_current = text_head;
            for (int i = 0; i < text_length; i++)
            {
                if (text_current == NULL)
                {
                    break;
                }
                
                *text_current = *(lexer->src + start + i);
                text_current++;
            }

            Token token = { .kind = NUMBER, .text = text_head };
            *current = token;
            current++;
        }
    }

    current--;
    current = NULL;

    return head;
}
