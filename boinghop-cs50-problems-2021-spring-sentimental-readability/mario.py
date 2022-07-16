from cs50 import get_int

while True:
    rows = get_int("What is the Height?:")
    if rows >= 1 and rows <= 8:
        ## length will iterate to print spaces for missing # and # for the length
        for length in range(1, rows + 1):
            print(" " * (rows - length) + "#" * length)
        break
    else:
        print("Invalid Input. Please put an integer between 1 and 8")
        continue