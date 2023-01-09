height = int(input("Enter the height of the pyramid: "))

for row in range(1, height + 1):
    for space in range(height - row):
        print(" ", end="")
    for block in range(row * 2 - 1):
        print("#", end="")
    print()
