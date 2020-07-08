// wl-1-enum-switch.c
// Word counting program with Switch, Typedef and Enum
// Gaspar Habif
// 20200708

#include <stdio.h>
#include <stdbool.h>

typedef bool State;

int main()
{
    int c, nl, nw, nc;

    s = OUT;
    nl = nw = nc = 0;

    while ((c = getchar()) != EOF)
    {
        ++nc;
        switch (c)
        {
        case '\n':
            ++nl;
            s = OUT;
            break;
        case ' ':
        case '\t':
            s = OUT;
            break;

        default:
            ++nw;
            s = IN;
            break;
        }
    }
IN:
    printf("Algo");
OUT:
    printf("Otro algo");

    printf("Lines: %d \nWords: %d \nCharacters: %d\n", nl, nw, nc);
}