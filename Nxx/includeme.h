#pragma once

#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef enum syntax_kind
{
    NUMBER,
    LITERAL
} SyntaxKind;

typedef struct token
{
    SyntaxKind kind;
    char* text;
} Token;

typedef struct lexer
{
    int index;
    char* src;
} Lexer;