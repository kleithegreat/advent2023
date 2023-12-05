
digits = ['1','2','3','4','5','6','7','8','9','one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
digs = {'1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9, 'one':1, 'two':2, 'three':3, 'four':4, 'five':5, 'six':6, 'seven':7, 'eight':8,'nine':9}

dig1 = 0
dig2 = 0
sum = 0

with open('input.txt', 'r') as f:
    for line in f:
        line = line.strip()
        temp = []

        for i in range(len(line)):
            try:
                if line[i] in digits:
                    temp.append(line[i])
                elif line[i:i+3] in digits:
                    temp.append(line[i:i+3])
                elif line[i:i+4] in digits:
                    temp.append(line[i:i+4])
                elif line[i:i+5] in digits:
                    temp.append(line[i:i+5])
            except:
                pass

        dig1 = digs[temp[0]]
        dig2 = digs[temp[-1]]

        sum += dig1*10+dig2

print(sum)