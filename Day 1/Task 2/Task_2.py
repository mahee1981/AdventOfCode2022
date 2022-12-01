fhandle = open('day_1_1.txt')

calories = 0
top3 = [0, 0, 0]

for line in fhandle:

	line = line.rstrip()
	
	if line != '':
		calories += int(line)

	else:
		if calories > top3[0]:
			top3[1] = top3[2]
			top3[1] = top3[0]
			top3[0] = calories

		elif calories > top3[1]:
			top3[2] = top3[1]
			top3[1] = calories

		elif calories > top3[2]:
			top3[2] = calories

		calories = 0

fhandle.close()
print(f"The top 3 elves with maximum number of calories:  {top3[0]}, {top3[1]} and {top3[2]}, which is {sum(top3)}")