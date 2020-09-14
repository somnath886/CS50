from cs50 import get_string
from sys import argv


def main():

    if len(argv) != 2:
        print(f"Usage: python bleep.py dictionary")
        exit(1)

    file = open(argv[1])
    words = set()
    for line in file:
        words.add(line.strip().lower())

    P = get_string("What message would you like to censor?\n")
    C = ""

    for word in P.split():
        if word.lower() in words:
            C += "*" * len(word) + " "
        else:
            C += word + " "
    print(f"{C}")



if __name__ == "__main__":
    main()
