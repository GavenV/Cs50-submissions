def get_change(amount, denominations):
    coins = 0
    for coin in denominations:
        while amount >= coin:
            amount -= coin
            coins += 1
    return coins

amount = int(input("Enter the amount of change: "))
denominations = [1, 5, 10, 25]

print(f"The minimum number of coins required to give {amount} cents in change is {get_change(amount, denominations)}.")
