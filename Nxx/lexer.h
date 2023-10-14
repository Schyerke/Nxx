#pragma once

#include "includeme.h"

void hello();
void init_lexer(Lexer* lexer, char* src);
char get_current(Lexer* lexer);
void advance(Lexer* lexer);
Token* tokenize(Lexer* lexer);
