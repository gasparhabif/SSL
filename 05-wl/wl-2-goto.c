// wl-2-goto.c
// Word counting program with Goto
// Gaspar Habif
// 20200708

#include <stdio.h>

int main()
{
    int c;

LOOP:
    if ((c = getchar()) != EOF)
    {
        if (c == '\n' || c == ' ' || c == '\t')
            goto OUT;
        goto IN;
    }
    putchar('\n');
    goto EXIT;

IN:
    putchar(c);
    goto LOOP;
OUT:
    putchar('\n');
    goto LOOP;
EXIT:
    return 0;
}