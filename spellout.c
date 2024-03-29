/*
 * Author: Pratik Mullick. Copyright 2024.
 * Description: A program spelling out any integer number into words.
 * Version: 1.0
 * License: GNU General Public License v3.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* CURRENT VERSION WITH MALLOC SHOULD HAVE MEMORY LEAKS? */

/* Default Values */
#define MAG_MAX 11

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

/* Function Prototypes */
char * base_wording(int number);
char * huns_wording(int number);
char * spellout(long long number, int i);

char * base_wording(int number)
/* Spells out the base, from 0 to 99 */
{
    int digit, units, tens;
    char * teen = (char *) malloc(10 * sizeof(char));
    char * ten_w = (char *) malloc(10 * sizeof(char));
    char * output = (char *) malloc(20 * sizeof(char));

    if (number <= 13)
        strcpy(output, uniques[number]);
    else if (number == 15)
        strcpy(output, uniques[14]);
    else if (number == 18)
        strcpy(output, uniques[15]);
    else if (number <= 19)  {
        digit = number % 10;
        strcpy(teen, uniques[digit]);
        strcpy(output, strcat(teen, "teen"));
    }
    if (number >= 20)   {
        tens = number / 10;
        strcpy(ten_w, base[tens - 2]);
        strcat(ten_w, " ");
        strcpy(output, ten_w);
        if (number % 10 > 0)    {
            units = number % 10;
            strcat(output, uniques[units]);
        }
    }
    free(teen);
    free(ten_w);
    return output;

}

char * huns_wording(int number)
/* Spells out between 0 to 999. Uses base_wording function */
{
    char * hun_w = (char *) malloc(20 * sizeof(char));
    char * output = (char *) malloc(50 * sizeof(char));
    
    int rem;
    int huns = number / 100;

    if (number % 100 == 0)  {
        strcpy(hun_w, uniques[huns]);
        strcat(hun_w, " hundred");
        strcpy(output, hun_w);
    } else if (number > 100)    {
        strcpy(hun_w, uniques[huns]);
        strcat(hun_w, " hundred and ");
        strcpy(output, hun_w);
        rem = number % 100;
        if (rem > 0)
            strcat(output, base_wording(rem));
    } else  {
        strcpy(output, base_wording(number));
    }
    free(hun_w);
    return output;
}

char * spellout(long long number, int i)
/* Spells out a number to its constituent words. Uses functions mentioned above */
{
    int k, num, group;
    long long rem;

    char * mag_w = (char *) malloc(50 * sizeof(char));
    char * grp_w = (char *) malloc(50 * sizeof(char));
    char * output = (char *) malloc(200 * sizeof(char));

    /* Initialize all output chars as NULL */
    for (k = 0; k < 200; k++)
        output[k] = '\0';

    while (i >= 0)  {
        if (number % (long long) (pow(10, i)) != number)   {
            num = 0;
            group = i / 3;
            num += (int) ((number / pow(10, i)) * pow(10, i % 3));
            if (i % 3 == 0) {
                strcpy(grp_w, huns_wording(num));
                strcat(grp_w, " ");
                strcat(output, grp_w);
                if (group > 0)  {
                    strcpy(mag_w, magnitude[group]);
                    strcat(output, mag_w);
                    strcat(output, " ");
                }
                rem = (long long) (number - num * pow(10, i));
                number = rem;
            }
        }
        if (i >= 0)
            --i;
    }
    free(mag_w);
    free(grp_w);
    return output;
}

int main(void)
{
    long long entry;

    printf("Enter a number: ");
    (void) scanf("%lld", &entry);

    printf("%s\n", spellout(entry, MAG_MAX));

    return 0;
}
