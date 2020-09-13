#include <stdio.h>
#include "Scanner.h"

int main()
{

    Token token = END;
    while ((token = GetNextToken()) != END)
    {
        printf("t[%d]", token);
    }
    return 0;
}