from sys import argv
from cs50 import get_string

def shift(c):
    if c.islower():
        i = ord(c) - ord("a")
    if c.isupper():
        i = ord(c) - ord("A")
    return i


if __name__ == "__main__":

    if len(argv) != 2:
        print(f"enter a key")
        exit(1)

    k = argv[1]

    for s in k:
        if s.isnumeric():
            print(f"Only Letters")
            exit(1)

    if s.isalpha():
        P = get_string("Enter Plaintext: ")
        print("ciphertext: ", end='')

        i = 0
        j = 0

        for i in range(len(P)):

            if P[i].isalpha():

                if ord(P[i]) >= 65 and ord(P[i]) <= 90:
                    c = ord(P[i]) + shift(k[j])
                    if c > 90:
                        c = c - 26
                        d = chr(c)
                    else:
                        d = chr(c)

                if ord(P[i]) >= 97 and ord(P[i]) <= 122:
                    c = ord(P[i]) + shift(k[j])
                    if c > 122:
                        c = c - 26
                        d = chr(c)
                    else:
                        d = chr(c)

                print(f"{d}", end='')


            if not P[i].isalpha():
                print(f"{P[i]}", end='')
                j = j-1

            i = i+1
            j = j+1

            if j >= len(k):
                j = 0

        print(f"")



