#include <stdio.h>
#include <string.h>
#include "lib/tinyexpr.h"

void *trim(char input[], char destination[]);

int main() {

    return 0;
}

void *trim(char input[], char destination[])
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
