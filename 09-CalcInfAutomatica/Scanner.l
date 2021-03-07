%{
    #include "Scanner.h"
%}

NUMS    [0-9]
IDS     [a-zA-Z][a-zA-Z]*

%option noyywrap
%%

{NUMS}+              {
                        yylval.number=atoi(yytext);
                        return NUMBER;
                    }
{IDS}               {
                        strcpy(yylval.string, yytext);   
                        return IDENTIFICATOR;
                    }

"("                 return OP_PARENTHESIS;
")"                 return CL_PARENTHESIS;
"+"                 return ADDITION;
"*"                 return PRODUCT;
"="                 return ASSIGNATION;
"\n"                return END;
[ ]+
.                   {
                        ThrowLexicalException();
                        return -1;
                    }
%%


// Funciones Publicas

int GetNextToken() 
{
    // -1 is not a valid token => if not overwritten by yylex() token won't be shown.
    int t = -1;
    if(!GetError()){
        t = yylex();
        PrintToken(t);
    }
    return t;
}

void PrintToken(int t)
{
    if (t != END && t != -1)
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
    default:
        return "[Token no Detectado]";
    }
}