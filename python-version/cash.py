from cs50 import get_float

f = get_float("Change Owed: ")

x = round(f * 100)

coins = 0

while x >= 25:
    x = x-25
    coins = coins+1

while x >= 10:
    x = x-10
    coins = coins+1

while x >= 5:
    x = x-5
    coins = coins+1

while x >= 1:
    x = x-1
    coins = coins+1


print(f"Coins needed: {coins}")


