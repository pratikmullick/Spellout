'''
Spellout program. This program spells out any integer number into words.
Copyright 2023 Pratik Mullick.
'''

# Global variables
uniques = ["zero","one","two","three","four","five","six","seven","eight",
           "nine","ten","eleven","twelve","thirteen", "fifteen"]

base = ["twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]

magnitude = ["hundred","thousand","million","billion","trillion"]


def base_wording(number):
    # Spells out the base, from 0 to 99.
    # Returns string output
    output = ""
    if number < 13:                                         # If number < 13, select from uniques array
        output = uniques[number]
    elif number == 15:                                      # Exception for 15
        output = uniques[14]
    elif number <= 19:                                      # If number is 14 or less than 19, add "teen" suffix
        digit = number % 10
        output = uniques[digit] + "teen"

    if number >= 20:                                        # If number is greater than 20, split tens and ones.
        tens = number // 10                                 # Add from base array for tens and uniques array for ones.
        output += (base[tens - 2] + " ")
        if number % 10 > 0:                                 # If number is divisible by 10, then just show from base array.
            units = number % 10
            output += uniques[units]

    return output

def huns_wording(number):
    # Spells out hundreds values
    # Returns string output
    output = ""
    huns = number // 100                                    # Split hundreds digit 
    if number % 100 == 0:                                   # If number is divisible by 100
        output += (uniques[huns] + " hundred")              # Get uniques array value and the word the hundred.
    elif number > 100:                                      # For numbers greater than 100 and less than 999
        output += (uniques[huns] + " hundred and ")         # Get uniques array value and the phrase "hundred and"
        rem = number % 100                                  # Make get the remaining after removing hundreds digit
        if rem > 0:
            output += base_wording(rem)                     # Run base_wording function using the remaining value
    else:
        output += base_wording(number)                      # For numbers less than 100, run base_wording.

    return output

def spellout(number, i=11):
    # Spells out word. Uses the aforementioned functions
    # Returns string output
    output = ""
    while i >= 0:                                           # Starting a loop from i (power) to 0.
        if number % (10 ** i) != number:                        # If the remainder of the number when divided by power of
            num = 0                                             # 10 is not itself (if it is itself, then power is larger;
            group = i // 3                                      # set group, (3 digits corresponding to each magnitude).
            num += (number // (10 ** i)) * (10 ** (i % 3))      # Get 3-digit pairs corresponding to magnitude, summed up.
            if i % 3 == 0:                                      # If i is at magnitude marker
                output += (huns_wording(num) + " ")                 # get words for 3 digit pair,
                if group > 0:                                       # If group is either 1 or 2
                    output += (magnitude[group] + " ")                  # Output the magnitude word.
                rem = number - num * (10 ** i)                      # Get the remaining values
                number = rem                                        # Set number to remaining value. In next pass will set
                                                                    # to num
        if i >= 0:                                              # Decrement i if it is positive.
            i -= 1

    return output

if __name__ == "__main__":
    number = int(input("Enter a positive integer: "))
    print(spellout(number).capitalize())
