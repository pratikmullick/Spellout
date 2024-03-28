#include <stdio.h>
#include <string.h>

// COMPILES UNDER CLANG W64, DOESN'T RUN

const char * uniques[] = {
                        "zero","one","two","three","four","five","six",
                        "seven","eight","nine","ten","eleven","twelve",
                        "thirteen","fifteen","eighteen"
                    };

const char * base[] = {
                        "twenty","thirty","forty","fifty","sixty","seventy",
                        "eighty","ninety"
                    };

const char * magnitude[] = {"hundred","thousand","million","billion","trillion"};

char * base_wording(int number) {
    // Spells out the base, from 0 to 99
    char * output = "";
    int digit, units, tens;

    if (number <= 13)
        strcpy(output, uniques[number]);
    else if (number == 15)
        strcpy(output, uniques[14]);
    else if (number == 18)
        strcpy(output, uniques[15]);
    else if (number <= 19)  {
        digit = number % 10;
        strcpy(output, strcat(uniques[digit], "teen"));
    }

    if (number >= 20)   {
        tens = number / 10;
        strcat(output, strcat(base[tens - 2], " "));
        if (number % 10 > 0)    {
            units = number % 10;
            strcat(output, uniques[units]);
        }
    }
    
    return output;
}
/*
char * huns_wording(int number) {
    // Spells out hundreds values
    char * output = "";
    char * base = "";
    int huns;
    int rem;

    huns = number / 100;
    if (number % 100 == 0)
        strcpy(output, strcat(uniques[huns], " hundred"));
    else if (number > 100)  {
        strcpy(output, strcat(uniques[huns], " hundred and "));
        rem = number % 100;
        // printf("Debug: %s\n", base_wording(rem));
    }

    return output;
}
*/

int main(void)
{
    int entry;

    printf("Enter a number: ");
    scanf_s("%d", &entry);

    printf("%s\n", base_wording(entry));

    return 0;
}
