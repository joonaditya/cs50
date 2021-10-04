from cs50 import *

number = get_int("Enter your credit card number: ")
digit1 = 0
digit2 = 0
odd = 0
even =0
num_digits = 0

while number > 0:
    digit2 = digit1
    digit1 = number % 10

    if num_digits % 2 == 0:
        even += digit1
    else:
        multiple = 2 * digit1
        odd += (multiple //10) + (multiple % 10)

    number //= 10
    num_digits += 1

valid = (even + odd) % 10 == 0
first_two_digits = (digit1 * 10) + digit2

if digit1 == 4 and num_digits >= 13 and num_digits <= 16 and valid:
    print("VISA")
elif first_two_digits >= 51 and first_two_digits <= 55 and num_digits == 16 and valid:
    print("MASTERCARD")
elif (first_two_digits == 34 or first_two_digits == 37) and num_digits == 15 and valid:
    print("AMEX")
else:
    print("INVALID")
