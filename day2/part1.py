with open("input.txt", "r") as file:
    lines = file.readlines()

MAX_RED = 12
MAX_GREEN = 13
MAX_BLUE = 14

id_sum = 0;

for line in lines:
    tokens = line.replace("\n", "").replace("Game ", "").replace(",", "").replace(";", "").replace(":", "").split(" ")

    id = int(tokens.pop(0))
    valid = True

    while len(tokens) > 0:
        number = int(tokens.pop(0))
        color = tokens.pop(0)

        if color == "red":
            if number > MAX_RED:
                valid = False
        elif color == "green":
            if number > MAX_GREEN:
                valid = False
        elif color == "blue":
            if number > MAX_BLUE:
                valid = False
        
    if valid:
        id_sum += id
    
print(id_sum)
