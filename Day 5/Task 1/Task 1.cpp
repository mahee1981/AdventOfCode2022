#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <regex>


std::vector<std::stack<char>> ReadCrates(const std::vector<std::string>& fileData) {
	auto it = fileData.rbegin();
	
	std::stringstream buffer;
	buffer << *it++;
	int maxStackIndex;

	while (buffer >> maxStackIndex);

	std::vector<std::stack<char>> stackOfCrates(maxStackIndex);
	while (it != fileData.rend()) {

		for (int i = 0; i < maxStackIndex; i++) {
			if (std::isalpha(it->at(4 * i + 1)))
				stackOfCrates[i].push(it->at(4 * i + 1));
		}
		++it;
	}
	return stackOfCrates;

}


int main()
{
	std::ifstream fhandle("..\\day_5_1.txt");
	std::vector<std::string> fileData;
	std::string line;

	while (std::getline(fhandle, line), line != "")
		fileData.push_back(line);
	
	std::vector<std::stack<char>> stackOfCrates = ReadCrates(fileData);
	
	std::string moveInstruction;
	std::regex pattern("move ([0-9]+) from ([0-9]+) to ([0-9]+)");
	std::smatch instructionParams;

	while (std::getline(fhandle, moveInstruction)) {

		if (std::regex_search(moveInstruction, instructionParams, pattern)) {

			int numOfMoves = std::stoi(instructionParams[1]);
			int stackToPop = std::stoi(instructionParams[2]) - 1;
			int stackToPush = std::stoi(instructionParams[3]) - 1;

			for (int i = 0; i < numOfMoves; i++) {
				stackOfCrates[stackToPush].push(stackOfCrates[stackToPop].top());
				stackOfCrates[stackToPop].pop();
			}
		}
	}

	std::cout << "The crates that are on top of each stack are: ";
	for (auto it = stackOfCrates.begin(); it != stackOfCrates.end(); it++)
		std::cout << "[" << it->top() << "]" << " ";

}

