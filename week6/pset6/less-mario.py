from cs50 import *

while True:
    number = get_int("Height:")
    if number >= 1 and number <= 8:
        break

for i in range(number):
    print((number - 1 - i) *  " ", end="")
    print((i + 1) * "#")
