from cs50 import *

while True:
    number = get_int("Height:")
    if number >= 1 and number <= 8:
        break

for i in range(1, number + 1):
    for j in range(1, number + 1):
        if j > (number - i):
            print("#", end="")
        else:
            print(" ", end="")
        if j == number:
            print(" ", "#" * i, end="")
    print()
