number = int(input("Credit Card Number: "))

soma, soma1, x = 0, 0, 0
y = number

while number > 0:
    ult = int(number % 10)
    x += 1
    if x % 2 != 0:
        soma += ult

    else:
        mult = ult * 2

        if mult > 9:
            soma1 += (mult % 10) + (mult // 10)

        else:
            soma1 += mult

    number = number // 10

total = soma1 + soma
ultimo_digito = (total % 10)
z = y // pow(10, 15)
i = y // pow(10, 14)
w = y // pow(10, 12)
a = y // pow(10, 13)

if (ultimo_digito == 0) and ((x == 16) or (x == 13)) and ((z == 4) or (w == 4)):
    print("VISA")

elif (ultimo_digito == 0) and (x == 15) and ((a == 34) or (a == 37)):
    print("AMEX")

elif (ultimo_digito == 0) and (x == 16) and ((i == 51) or (i == 52) or (i == 53) or (i == 54) or (i == 55)):
    print("MASTERCARD")

else:
    print("INVALID")
