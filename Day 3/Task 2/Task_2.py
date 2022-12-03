def ItemPriority(item):
    if (item.isupper()):
        return ord(item) - ord('A') + 27

    return ord(item) - ord('a') + 1


fhandle = open("day_3_1.txt")

prioritySum = 0
backpacks = list()
numLinesRead = 0

for line in fhandle:
    backpacks.append(line.rstrip())
    numLinesRead = numLinesRead + 1
    if numLinesRead < 3:
        continue

    numLinesRead = 0

    for i in range(len(backpacks[0])):
        if backpacks[1].find(backpacks[0][i]) != -1 and backpacks[2].find(backpacks[0][i]) != -1:
            prioritySum += ItemPriority(backpacks[0][i])
            break
    backpacks = list()



print(prioritySum)
