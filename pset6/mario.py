import cs50

height = input("height: ")

while height.isnumeric() == False:
    height = input("height: ")

height = int(height)

while height < 1 or height > 8:
    height = int(input("height: "))

for i in range(height):
    for j in range(height * 2 + 2):
        if (j + 1) < (height - i) or ((j + 1) <= height + 2 and (j + 1) > height):
            if (j + 1) > height + 3 + i:
                continue
            else:
                print(" ", end="")
        else:
            if ((j + 1) <= height and (j + 1) >= height - i) or ((j + 1) > height + 2 and (j + 1) <= height + 3 + i):
                print("#", end="")
    print("")
