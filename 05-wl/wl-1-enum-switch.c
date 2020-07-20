// wl-1-enum-switch.c
// Word counting program with Switch, Typedef and Enum
// Gaspar Habif
// 20200708

#include <stdio.h>
#include <stdbool.h>

typedef int State;
enum State
{
    IN,
    OUT
};

int main()
{
    State s;
    int c;

    s = OUT;

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case ' ':
        case '\t':
        case '\n':
        {
            switch (s)
            {
            case IN:
                s = OUT;
                putchar('\n');
                break;
            }
        }
        break;
        default:
            s = IN;
            putchar(c);
            break;
        }
    }
}