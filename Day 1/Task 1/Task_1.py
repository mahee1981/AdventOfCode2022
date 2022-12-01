fhandle = open('day_1_1.txt')

calories = 0
max_calories = 0

for line in fhandle:

	line = line.rstrip()
	
	if line != '':
		calories += int(line)
	else:
		if calories > max_calories:
			max_calories = calories

		calories = 0

fhandle.close()
print(f"The maximum total number of calories an elf is carrying is {max_calories}")