import re

def overlapping_ranges(firstInterval, secondInterval):
    if secondInterval[1] >= firstInterval[0] and secondInterval[0] <= firstInterval[1]:
        return True
    elif firstInterval[1] >= secondInterval[0] and firstInterval[0] <= secondInterval[1]:
        return  True
    return False


num_of_overlapping = 0

with open("day_4_1.txt") as fhandle:
    for line in fhandle:
        line = line.rstrip()
        ranges = re.findall("([0-9]+)\-([0-9]+)", line)
        if ranges is not None:
            ranges = [(int(x), int(y)) for x, y in ranges]

            if overlapping_ranges(ranges[0], ranges[1]):
                num_of_overlapping += 1

print('Number of assignment pairs where one range fully contains the other: ', num_of_overlapping)


