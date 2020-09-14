

from cs50 import get_int


while True:
    n = get_int("Positive number: ")
    if n > 0:
        break

for i in range(n):

    for j in range(n-i):
        print(" ", end="")
    for k in range(i+1):
        print("#", end="")
    print()
