#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/tinyexpr.h"

#define TRUE 1

void trim(char input[], char destination[]);

int main()
{
    char c_exp[18] = "1 2 3 4 5 6 7 8 9";
    char expressions[4] = "+- ";
    char cexpTmp[25];
    int index[8];
    char c[9];

    int j = 1;

    for (int i = 0; i < 8; i++)
    {
        c[i] = '+';
        index[i] = 0;
    }

    for (int i = 0; i < 24; i++)
    {
        cexpTmp[i] = '\0';
    }

    while (TRUE)
    {
        trim(c_exp, cexpTmp);
        if (te_interp(cexpTmp, 0) == 100)
        {
            printf("%s = 100\n", cexpTmp);
        }

        int k = sizeof(index) / sizeof(index[0]) - 1;
        for (; k >= 0; k--)
        {
            index[k] += 1;
            if (index[k] < 3)
            {
                c[k] = expressions[index[k]];
                break;
            }

            index[k] = 0;
            c[k] = expressions[index[k]];
        }

        for (int i = 0; i < 8; i++)
        {
            if (j >= 17)
                break;

            c_exp[j] = c[i];

            j += 2;
        }

        j = 1;

        if (k < 0)
            break;
    }

    return 0;
}

void trim(char input[], char destination[])
{
    for (int i = 0; i < strlen(input); i++)
    {
        destination[i] = input[i];
    }

    for (int i = 0; i < 18; i++)
    {
        if (isspace(destination[i]))
        {
            for (int j = i; j < strlen(destination); j++)
            {
                if (j == (strlen(destination) - 1))
                {
                    memmove(&destination[strlen(destination) - 1], &destination[strlen(destination)], strlen(destination) - (strlen(destination) - 1));
                }

                destination[j] = destination[j + 1];
            }
        }
    }

    for (int i = 0; i < 18; i++)
    {
        if (destination[i] == '\377')
        {
            for (int j = i; j < 17; j++)
                memmove(&destination[j], &destination[j + 1], strlen(destination) - j);
        }
    }
}
