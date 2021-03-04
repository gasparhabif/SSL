%{
    #include "Scanner.h"
%}

NUMS    [0-9]
IDS     [a-zA-Z][a-zA-Z]*

%option noyywrap
%%

{NUMS}+              {
                        AddStringToBuffer(yytext);
                        return NUMBER;
                    }
{IDS}               {
                        AddStringToBuffer(yytext);
                        return IDENTIFICATOR;
                    }

"("                 return OP_PARENTHESIS;
")"                 return CL_PARENTHESIS;
"+"                 return ADDITION;
"*"                 return PRODUCT;
"="                 return ASSIGNATION;
"\n"                return END;
.                   {
                        ThrowLexicalException();
                        return INITIAL;
                    }
%%


// Funciones Publicas

int GetNextToken() 
{
    int t = INITIAL;
    t = yylex();
    // If its not a valid token the value won't be overwritten,
    // it's value will still be INITIAL and Lexical Exception will be shown.
    // if(t != INITIAL) 
    PrintToken(t);
    return t;
}

void PrintToken(int t)
{
    if (t != END && t != INITIAL)
    {
        char *tokenValue = TokenToString(t);
        printf("%s(Scanner)%s Token encontrado: %s%s \n", MAGENTA_BOLD, WHITE, WHITE_BOLD, tokenValue);
    }
}

char *TokenToString(int t)
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
    case INITIAL:
        return "Inicial";
    default:
        return "[Token no Detectado]";
    }
}