import re

elementScore = {
	'A' : 1, 
	'B' : 2, 
	'C' : 3 
}

battleOutcomeScore = {
	'X' : 0,
	'Y' : 3,
	'Z' : 6
}

# key = elfElement, values = playerElement according to battle outcome
# key wins over value[0], key loses to value[1]
# might be interesting to refactor with a doubly linked circular list to improve code readability
elementRelations = {

	'A' : ['C', 'B'],
	'B' : ['A', 'C'],
	'C' : ['B', 'A']
}


totalScore = 0

fhandle = open("day_2_1.txt")

for line in fhandle:
	line = line.rstrip()

	battleElements = re.search("([ABC]) ([XYZ])", line)
	elfElement, battleOutcome = battleElements.group(1), battleElements.group(2)

	#add the score for battle outcome
	totalScore += battleOutcomeScore[battleOutcome]


	if(battleOutcome == 'X'):
		totalScore += elementScore[elementRelations[elfElement][0]]

	elif(battleOutcome == 'Y'):
		totalScore += elementScore[elfElement]

	elif(battleOutcome == 'Z'):
		totalScore += elementScore[elementRelations[elfElement][1]]

print(f"Total score according to the strategy guide: {totalScore}")
fhandle.close()