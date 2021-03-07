%{
    #include "Parser.h"
    
    static void PrintResult(int result);
    static int yylex(void);
    static void yyerror(char const *s);
%}

%union 
{
  int number;
  char* string;
}

%token <number> NUMBER
%token <string> IDENTIFICATOR
%token <string> ADDITION
%token <string> PRODUCT
%token <string> OP_PARENTHESIS
%token <string> CL_PARENTHESIS
%token <string> ASSIGNATION
%token <string> END 0

%type <string> runScan
%type <string> program
%type <number> sentenceList
%type <number> sentence
%type <number> expresion
%type <number> term
%type <number> factor
%start runScan

%%

runScan: program;

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

void RunScan() {
    printf("Ingrese la expresión a evaluar: \n");
    switch(yyparse()){
    case 0:
    case 1:
      break;
    default:
      ThrowSintacticalException("Error indefinido");
      break;
    }
    CleanGlobalVariables();
    RunScan();
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

static void CleanGlobalVariables()
{
    // Reset console colors.
    printf("\n\e[0m");
    SetError(false);
}