lines = []
sum = 0;

with open("input.txt", "r") as inFile:
    lines = inFile.readlines()

for line in lines:
    for char in line:
        if char.isdigit():
            first = char
            break
    for char in reversed(line):
        if char.isdigit():
            last = char
            break
    
    codeString = first + last
    code = int(codeString)
    sum += code

print(sum)
