import cs50

# use a while loop to continually prompt user if conditions are not met
while True:
    # prompt user for money
    change = cs50.get_float("\nHow much money?\n")
    # invalid conditions
    if (change < 0) or (change == 0):
        print("Invalid input, please put a real value of change.", end="")
    if change > 0:
        break
        
c_round = round((change) * 100)
coins = 0

# subracting the value of coins from the rounded change
while c_round > 0:

    if c_round - 25 >= 0:
        c_round -= 25
        coins += 1

    elif c_round - 10 >= 0:
        c_round -= 10
        coins += 1

    elif c_round - 5 >= 0:
        c_round -= 5
        coins += 1

    elif c_round - 1 >= 0:
        c_round -= 1
        coins += 1

print(f"{coins} returned coins")
