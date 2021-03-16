%{
    #include "Scanner.h"
%}

NUMS    [0-9]
IDS     [a-zA-Z]

%option noyywrap
%%

{NUMS}+             {
                        AddStringToBuffer(yytext);
                        return NUMBER;
                    }
{IDS}+              {
                        AddStringToBuffer(yytext);
                        return IDENTIFICATOR;
                    }
"="                 return ASSIGNATION;
"("                 return OP_PARENTHESIS;
")"                 return CL_PARENTHESIS;
"+"                 return ADDITION;
"*"                 return PRODUCT;
"\n"                return END;
.                   {
                        ThrowLexicalException();
                        return -1;
                    }
%%


// Funciones Publicas

Token GetNextToken() 
{
    Token t = yylex();
    // If its not a valid token the value value will still 
    // be -1 and Lexical Exception will be shown.
    if(t != -1) 
        PrintToken(t, yytext);
    else
        ThrowLexicalException();

    return t;
}

static void PrintToken(Token t, char *value)
{
    if (t != END && t != -1)
    {
        char *tokenValue = TokenToString(t);
        printf("%s(Scanner)%s Token encontrado: %s%s", MAGENTA_BOLD, WHITE, WHITE_BOLD, tokenValue);
        if (t == NUMBER || t == IDENTIFICATOR)
            printf(" [%s]", value);
        printf("\n");
    }
}

char *TokenToString(Token t)
{
    switch (t)
    {
    case IDENTIFICATOR:
        return "Identificador";
    case NUMBER:
        return "Número";
    case ADDITION:
        return "Adición [+]";
    case PRODUCT:
        return "Producto [*]";
    case OP_PARENTHESIS:
        return "Apertura de Paréntesis '('";
    case CL_PARENTHESIS:
        return "Cierre de Paréntesis ')'";
    case END:
        return "Enter (EOF)";
    case ASSIGNATION:
        return "Asignación [=]";
    default:
        return "[Token no Detectado]";
    }
}