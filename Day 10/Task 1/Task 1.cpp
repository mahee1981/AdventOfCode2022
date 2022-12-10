#include <iostream>
#include <fstream>
#include <string>

#define numOfKeyCycles 6


int main()
{
	//execution starts at first cycle
	int cycleCounter = 1;
	std::string instruction;
	int X = 1;

	std::ifstream fhandle("..\\day_10_1.txt");

	constexpr int keyCycles[numOfKeyCycles] = { 20, 60, 100, 140, 180, 220 };
	int valueForKeyCycles[numOfKeyCycles]{};
	int currentKeyCycle = 0;

	while (std::getline(fhandle, instruction)) {

		std::string keyword = instruction.substr(0, 4);
		//instruction executed
		cycleCounter++;
		if (currentKeyCycle < numOfKeyCycles && cycleCounter == keyCycles[currentKeyCycle]) {
			valueForKeyCycles[currentKeyCycle] = X;
			currentKeyCycle++;
		}
		if (keyword == "addx") {
			X += std::stoi(instruction.substr(5));
			//instruction executed
			cycleCounter++;
			if (currentKeyCycle < numOfKeyCycles && cycleCounter == keyCycles[currentKeyCycle]) {
				valueForKeyCycles[currentKeyCycle] = X;
				currentKeyCycle++;
			}
		}
	}
	int totalSignalStrength = 0;
	for (int i = 0; i < numOfKeyCycles; i++) {
		totalSignalStrength += valueForKeyCycles[i] * keyCycles[i];
	}
	std::cout << "Sum of six key signal strengths: " << totalSignalStrength;
	
	
}

