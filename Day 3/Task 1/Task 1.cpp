#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

int main()
{
	std::ifstream fhandle("day_3_1.txt");
	std::string content;
	int prioritySum = 0;

	while (std::getline(fhandle, content)) {
		std::size_t half_length = content.length() / 2;
		auto it = std::find_first_of(content.begin(), content.begin() + half_length, content.begin() + half_length, content.end());
		
		if (std::isupper(*it))
			prioritySum += *it - 'A' + 27;
		else
			prioritySum += *it - 'a' + 1;


	}
	
	std::cout << "The sum of the priorites of items that appear in both compartments of the rucksack is: " << prioritySum;



	


}
