from Stack import Stack
import re

def read_crates(file_data):
    max_stack_index = int(file_data[-1].split()[-1])
    stack_of_crates = [Stack([]) for i in range(max_stack_index)]

    for i, line in enumerate(reversed(file_data)):
        if i == 0:
            continue

        for j in range(max_stack_index):

            if line[4*j+1].isalpha():
                stack_of_crates[j].push(line[4*j+1])

    return stack_of_crates

file_data = list()
with open(r"..\day_5_1.txt") as fhandle:
    for line in fhandle:
        #get rid of the \n only
        line = line[:-1]

        if line == '':
            break
        file_data.append(line)
    stack_of_crates = read_crates(file_data)

    regex_pattern = "move ([0-9]+) from ([0-9]+) to ([0-9]+)"
    for line in fhandle:
        line = line[:-1]
        instruction_params = re.search(regex_pattern, line)
        num_of_moves, stack_to_pop, stack_to_push = tuple(int(param) for param in instruction_params.groups())

        for i in range(num_of_moves):
            stack_of_crates[stack_to_push-1].push(stack_of_crates[stack_to_pop-1].top())
            stack_of_crates[stack_to_pop-1].pop()

    print("The crates that are on top of each stack are: ")
    for stack in stack_of_crates:
        print(f"[{stack.top()}] ", end = '')

