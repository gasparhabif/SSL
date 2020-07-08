// wl-1-enum-switch.c
// Word counting program with Switch, Typedef and Enum
// Gaspar Habif
// 20200708

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

void countElements(int);
int nl, nw, nc;

int main()
{
    nl = nw = nc = 0;
    countElements(OUT);
    printf("Lines: %d \nWords: %d \nCharacters: %d\n", nl, nw, nc);
}

void countElements(int state)
{
    int c;
    if ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c = '\t')
            countElements(OUT);
        else if (state == OUT)
        {
            ++nw;
            countElements(IN);
        }
    }

    return;
}