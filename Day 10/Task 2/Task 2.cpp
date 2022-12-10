#include <iostream>
#include <fstream>
#include <string>

#define numOfKeyCycles 6

bool InRangeOfSprite(int pixelPosition, int spritePosition) {

	for (int i = spritePosition - 1; i <= spritePosition + 1; i++) {
		if (pixelPosition == i)
			return true;
	}
	return false;
}

void DrawCharacter(int cycleCounter, int sprite) {

	if (InRangeOfSprite((cycleCounter - 1) % 40, sprite))
		std::cout << "#";
	else
		std::cout << ".";
}

int main()
{
	int cycleCounter = 1;
	std::ifstream fhandle("..\\day_10_1.txt");

	std::string instruction;
	int X = 1;
	constexpr int keyCycles[numOfKeyCycles] = { 40, 80, 120, 160, 200, 240 };

	int currentKeyCycle = 0;

	while (std::getline(fhandle, instruction)) {

		std::string keyword = instruction.substr(0, 4);

		DrawCharacter(cycleCounter, X);
		
		if (currentKeyCycle < numOfKeyCycles && cycleCounter == keyCycles[currentKeyCycle]) {
			std::cout << "\n";
			currentKeyCycle++;
		} 
		//instruction executed
		cycleCounter++;

		if (keyword == "addx") {
			DrawCharacter(cycleCounter, X);
			X += std::stoi(instruction.substr(5));

			if (currentKeyCycle < numOfKeyCycles && cycleCounter == keyCycles[currentKeyCycle]) {
				std::cout << "\n";
				currentKeyCycle++;
			}
			//instruction executed
			cycleCounter++;
		}
	}



}

