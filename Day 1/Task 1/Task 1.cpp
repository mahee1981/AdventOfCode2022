#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main()
{
	std::fstream fhandle("day_1_1.txt", std::ios::in);
	
	int max_calories = 0, calories = 0;
	int i = 0;
	std::stringstream buffer;
	std::string str;

	while (true) {
		std::getline(fhandle, str);
		if (fhandle && str != "") {
			buffer << str;
			int num;
			buffer >> num;
			buffer.ignore(10000, '\n');
			buffer.clear();
			calories += num;
		}
		else {
			if (calories > max_calories)
				max_calories = calories;
			calories = 0;

			if (!fhandle)
				break;
		}
	}
	std::cout << "The maximum total number of calories an elf is carrying is " << max_calories;
	
	
}

