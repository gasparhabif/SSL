%{
    #include "Parser.h"
    
    static void PrintResult(int result);
    static int yylex(void);
    static void yyerror(char const *s);
    void CleanYylex(void);
%}

%union 
{
  int number;
  char string[100];
}

%token <number> NUMBER
%token <string> IDENTIFICATOR ADDITION PRODUCT OP_PARENTHESIS CL_PARENTHESIS ASSIGNATION
%token <string> END 0

%type <string> runProgram program
%type <number> sentenceList sentence expresion term factor
%start runProgram

%%

runProgram: program;

program: sentenceList END; 

sentenceList: sentence
            | sentenceList sentence            
            ;

sentence: IDENTIFICATOR ASSIGNATION expresion { AddMemoryBlock($1, $3); }
        | expresion { PrintResult($1); }
        ;
        
expresion: term { $$ = $1; }
         | expresion ADDITION term { $$ = $1 + $3; }
         ;

term: factor { $$ = $1; }
    | term PRODUCT factor { $$ = $1 * $3; }
    ;

factor: IDENTIFICATOR { $$ = GetMemoryValue($1); }
      | NUMBER { $$ = $1; }
      | OP_PARENTHESIS expresion CL_PARENTHESIS { $$ = $2; }
      ;

%%



void yyerror(char const *s) {
    ThrowSintacticalException(s);
}

int yylex() {
    return GetNextToken();
}

void RunProgram(void) {
    printf("Ingrese la expresión a evaluar: \n");
    switch(yyparse()){
    case 0:
    case 1:
      break;
    default:
      ThrowSintacticalException("Indefinido");
      break;
    }
    CleanGlobalVariables();
    RunProgram();
}

static void PrintResult(int result)
{
    if (!GetError())
    {
        PrintMemory();
        printf("%s(Parser)", BLUE_BOLD);
        printf("%s La expresión es Válida\n", GREEN);
        printf("%s(Calc)%s El resultado de la expresión es: %s%i\n", CYAN_BOLD, WHITE_BOLD, CYAN_BOLD, result);
    }
}

static void CleanGlobalVariables(void)
{
    // Reset console colors.
    printf("\n\e[0m");
    SetError(false);
}

void CleanYylex(void) {
    int t = -1;
    // Get tokens and ignore it's result until END is recieved 
    while (t != 0)
      t = yylex();
    CleanGlobalVariables();
}