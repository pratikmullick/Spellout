uniques = ["zero","one","two","three","four","five","six","seven","eight",
           "nine","ten","eleven","twelve","thirteen", "fifteen"]

base = ["twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"]

magnitude = ["hundred","thousand","million","billion","trillion"]

def base_wording(number):
    output = ""
    if number < 13:
        output = uniques[number]
    elif number == 15:
        output = uniques[14]
    elif number <= 19:
        digit = number % 10
        output = uniques[digit] + "teen"

    if number >= 20:
        tens = number // 10
        output += (base[tens - 2] + " ")
        if number % 10 > 0:
            units = number % 10
            output += uniques[units]

    return output

def huns_wording(number):
    output = ""
    huns = number // 100
    if number % 100 == 0:
        output += (uniques[huns] + " hundred")
    elif number > 100:
        output += (uniques[huns] + " hundred and ")
        rem = number % 100
        if rem > 0:
            output += base_wording(rem)
    else:
        output += base_wording(number)

    return output

def spellout(number, i=11):
    output = ""
    while i >= 0:
        if number % (10 ** i) != number:
            num = 0
            group = i // 3
            num += (number // (10 ** i)) * (10 ** (i % 3))
            if i % 3 == 0:
                output += (huns_wording(num) + " ")
                if group > 0:
                    output += (magnitude[group] + " ")
                rem = number - num * (10 ** i)
                number = rem

        if i >= 0:
            i -= 1

    return output

if __name__ == "__main__":
    number = int(input("Enter a positive integer: "))
    print(spellout(number).capitalize())
