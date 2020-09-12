enum Tokens
{
    INITIAL = 0,
    IDENTIFICATOR,
    NUMBER,
    ADDITION,
    PRODUCT,
    END
};

typedef enum Tokens Token;

static Token CurrentToken = INITIAL;

Token GetNextToken();