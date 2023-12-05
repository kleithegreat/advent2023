with open("input.txt", "r") as file:
    lines = file.readlines()

power_sum = 0

for line in lines:
    tokens = line.replace("\n", "").replace("Game ", "").replace(",", "").replace(";", "").replace(":", "").split(" ")
    tokens.pop(0)
    
    max_red = 0
    max_green = 0
    max_blue = 0

    while len(tokens) > 0:
        number = int(tokens.pop(0))
        color = tokens.pop(0)

        if color == "red":
            if number > max_red:
                max_red = number
        elif color == "green":
            if number > max_green:
                max_green = number
        elif color == "blue":
            if number > max_blue:
                max_blue = number

    power = max_red * max_green * max_blue
    power_sum += power

print(power_sum)
