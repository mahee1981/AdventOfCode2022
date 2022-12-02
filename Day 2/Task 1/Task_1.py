import re

elementScore = {
	'A' : 1, 
	'B' : 2, 
	'C' : 3 
}

playerToElfNotation = {
	'X' : 'A',
	'Y' : 'B',
	'Z' : 'C'
}

losesTo = {
	'A' : 'B',
	'B' : 'C',
	'C' : 'A'
}
totalScore = 0

fhandle = open("day_2_1.txt")

for line in fhandle:
	line = line.rstrip()

	battleElements = re.search("([ABC]) ([XYZ])", line)
	elfElement, playerElement = battleElements.group(1), playerToElfNotation[battleElements.group(2)]

	#add the score for element choice
	totalScore += elementScore[playerElement]

	#add result according to battle outcome
	if(elfElement == playerElement):
		totalScore += 3

	elif(playerElement == losesTo[elfElement]):
		totalScore += 6

print(f"Total score according to the strategy guide: {totalScore}")
fhandle.close()