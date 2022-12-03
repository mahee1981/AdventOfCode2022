#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>


int BadgePriority(char badge) {
	if (std::isupper(badge))
		return badge - 'A' + 27;
	return badge - 'a' + 1;
}

int main()
{
	std::ifstream fhandle("day_3_1.txt");
	int prioritySum = 0;
	while (true) {

		std::vector<std::string> backpacks(3);
		//read three inputs
		std::getline(fhandle, backpacks.at(0));
		std::getline(fhandle, backpacks.at(1));
		std::getline(fhandle, backpacks.at(2));

		if (!fhandle)
			break;

		bool badgeFound = false;

		for(int i = 0; i < backpacks[0].size() && !badgeFound; i++)
			for (int j = 0; j < backpacks[1].size() && !badgeFound; j++)
				if (backpacks[0].at(i) == backpacks[1].at(j)) {

					auto it = std::find(std::begin(backpacks[2]), std::end(backpacks[2]), backpacks[1].at(j));

					if (it != std::end(backpacks[2])) {
						badgeFound = true;
						prioritySum += BadgePriority(*it);
					}
				}
				
	}
	std::cout << "The sum of priorities of all badges of each three-Elf group is: " << prioritySum;

}

