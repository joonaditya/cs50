#importing everything from cs50 library
from cs50 import *

while True:
    balance = get_float("Change owed: ")
    if balance > 0:
        break

total = balance * 100
count = 0

#calculating number of coins
for x in [25, 10, 5, 1]:
    while total >= x:
        total -= x
        count += 1

print(count)
