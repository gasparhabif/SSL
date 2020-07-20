// wl-1-enum-switch.c
// Word counting program with Switch, Typedef and Enum
// Gaspar Habif
// 20200708

#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

void countElements(int);

int main()
{
    countElements(OUT);
}

void countElements(int state)
{
    int c;
    if ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c = '\t')
        {
            if (state == IN)
                putchar('\n');
            countElements(OUT);
        }
        else
        {
            putchar(c);
            countElements(IN);
        }
    }

    return;
}