%{
    #include "Parser.h"
    
    static void PrintResult();
    static int yylex(void);
    static void yyerror(char const *s);
%}

%union 
{
  int number;
  char* string;
}

%token <number> NUMBER
%token <string> INITIAL
%token <string> IDENTIFICATOR
%token <string> ADDITION
%token <string> PRODUCT
%token <string> OP_PARENTHESIS
%token <string> CL_PARENTHESIS
%token <string> ASSIGNATION
%token <string> END

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

program: INITIAL sentenceList END;

sentenceList: sentence
            | sentenceList sentence
            ;

sentence: IDENTIFICATOR ASSIGNATION expresion { AddToMemory($1); }
        | expresion { PrintResult(); }
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
      return;
    case 1:
      return;
    default:
      ThrowSintacticalException("Error indefinido");
      return;
    }
    PrintResult();
    CleanGlobalVariables();
    RunScan();
}

static void PrintResult()
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
    result = 0;
    SetError(false);
}