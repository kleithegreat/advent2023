with open('input.txt', 'r') as f:
    sum = 0
    digits = ['0','1','2','3','4','5','6','7','8','9']
    for line in f:
        line = line.strip()
        for i in range(len(line)):
            if line[i] in digits:
                dig1 = int(line[i])
                break
        for i in range(len(line)):
            if line[-i-1] in digits:
                dig2 = int(line[-i-1])
                break
        sum += dig1*10+dig2
print(sum)