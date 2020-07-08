// wl-2-goto.c
// Word counting program with Goto
// Gaspar Habif
// 20200708

#include <stdio.h>

int main()
{
    int c, nl, nw, nc;
    nl = nw = nc = 0;

LOOP:
    if ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
            goto NEW_LINE;
        if (c == ' ' || c == '\t')
            goto OUT;
        goto IN;
    }
    goto EXIT;

NEW_LINE:
    ++nl;
    goto OUT;
IN:
    goto LOOP;
OUT:
    ++nw;
    goto LOOP;
EXIT:
    printf("Lines: %d \nWords: %d \nCharacters: %d\n", nl, nw, nc);
}