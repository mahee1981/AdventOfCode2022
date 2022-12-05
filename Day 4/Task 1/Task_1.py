import re

def fully_inclusive_ranges(firstInterval, secondInterval):
    if secondInterval[0] >= firstInterval[0] and secondInterval[1] <= firstInterval[1]:
        return True
    elif firstInterval[0] >= secondInterval[0] and firstInterval[1] <= secondInterval[1]:
        return  True
    return False


num_of_fully_inclusive = 0

with open("day_4_1.txt") as fhandle:
    for line in fhandle:
        line = line.rstrip()
        bounds = re.findall("([0-9]+)\-([0-9]+)", line)
        if bounds is not None:
            bounds = [(int(x), int(y)) for x, y in bounds]

            if fully_inclusive_ranges(bounds[0], bounds[1]):
                num_of_fully_inclusive += 1

print('Number of assignment pairs where one range fully contains the other: ', num_of_fully_inclusive)


