class Stack:
    def __init__(self, init_list):
        self.__mem_list = init_list

    def pop(self):
        self.__mem_list.pop()

    def top(self):
        return self.__mem_list[-1]

    def push(self, element):
        self.__mem_list.append(element)

    def empty(self):
        if len(self.__mem_list) > 0:
            return False
        return True

    def __str__(self):
        return str(self.__mem_list)

