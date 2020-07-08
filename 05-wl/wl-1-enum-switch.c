// wl-1-enum-switch.c
// Word counting program with Switch, Typedef and Enum
// Gaspar Habif
// 20200708

#include <stdio.h>
#include <stdbool.h>

typedef bool State;
enum State
{
    IN,
    OUT
};

int main()
{
    State s;
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
            ++nw;
            s = OUT;
            break;
        case ' ':
        case '\t':
            ++nw;
            s = OUT;
            break;

        default:
            s = IN;
            break;
        }
    }

    printf("Lines: %d \nWords: %d \nCharacters: %d\n", nl, nw, nc);
}