def ItemPriority(item):
    if (item.isupper()):
        return ord(item) - ord('A') + 27

    return ord(item) - ord('a') + 1


fhandle = open("day_3_1.txt")

prioritySum = 0

for line in fhandle:
    line = line.rstrip()
    half_length = len(line) // 2

    for i in range(half_length):
        commonItemIndex = line.find(line[i], half_length, len(line))
        if commonItemIndex != -1:
            prioritySum += ItemPriority(line[commonItemIndex])
            break

print(prioritySum)

