from cs50 import get_int

while True:
    rows = get_int("What is the Height?:")
    if rows >= 1 and rows <= 8:
        for length in range(1, rows + 1):
            # ## make the height count from 1. Stop at 0 and count backwards to make length and height
            # for height in range(rows + 1, 0, -1):
            print(" " * (rows - length) + "#" * length)
        break
    else:
        print("Invalid Input. Please put an integer between 1 and 8")
        continue