/* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
enum yytokentype
{
    NUMBER = 258,
    INITIAL = 259,
    IDENTIFICATOR = 260,
    ADDITION = 261,
    PRODUCT = 262,
    OP_PARENTHESIS = 263,
    CL_PARENTHESIS = 264,
    ASSIGNATION = 265,
    END = 266
};

/* Tokens.  */
#define NUMBER 258
#define INITIAL 259
#define IDENTIFICATOR 260
#define ADDITION 261
#define PRODUCT 262
#define OP_PARENTHESIS 263
#define CL_PARENTHESIS 264
#define ASSIGNATION 265
#define END 266