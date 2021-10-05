from csv import reader, DictReader
from sys import argv, exit

if len(argv) < 3:

    print("Usage:", "python dna.py data.csv sequence.txt")

    exit(1)

sequence = {}

def maximum(dna, STR):

    i = 0

    j = len(STR)

    max = 0;

    for x in range(len(dna)):

        if dna[i:j] == STR:

            temp = 0

            while dna[i:j] == STR:

                temp += 1

                i+= len(STR)

                j+= len(STR)

                if(temp > max):

                    max = temp
        else:

            i+=1

            j+=1

    return max


with open(argv[2], 'r') as file:

    dna = file.read()

with open(argv[1], "r") as pFile:

    pReader = reader(pFile)

    for row in pReader:

        header = row

        header.pop(0)

        for item in header:

            sequence[item] = 0

        break

for key in sequence:

    value = maximum(dna, key)

    sequence[key] = value

with open(argv[1], "r") as pFile:

    people = DictReader(pFile)

    for person in people:

        matches = 0

        for key in sequence:

            if int(person[key]) == sequence[key]:

                matches += 1

        if matches == len(sequence):

            print(person["name"])

            exit(0)

    print("No match")
