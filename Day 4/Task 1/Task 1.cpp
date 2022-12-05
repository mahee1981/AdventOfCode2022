#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <utility>


//check if one of the two ranges contains the other
bool FullyInclusiveRanges(const std::pair<int, int> &firstInterval, const std::pair<int, int> &secondInterval) {
	if (secondInterval.first >= firstInterval.first && secondInterval.second <= firstInterval.second)
		return true;

	else if ((firstInterval.first >= secondInterval.first && firstInterval.second <= secondInterval.second))
		return true;

	return false;
}

int main()
{
	std::pair<int, int> firstInterval, secondInterval;
	std::ifstream fhandle("day_4_1.txt");

	std::string line;
	std::regex pattern("([0-9]+)\-([0-9]+),([0-9]+)\-([0-9]+)");
	std::smatch ranges; // match object containing the matched pattern and possible captures

	int numOfFullyInclusive = 0;
	while (std::getline(fhandle, line)) {
		if (std::regex_search(line, ranges, pattern)) {

			firstInterval = std::make_pair(std::stoi(ranges[1]), std::stoi(ranges[2]));
			secondInterval = std::make_pair(std::stoi(ranges[3]), std::stoi(ranges[4]));

			if (FullyInclusiveRanges(firstInterval, secondInterval))
				numOfFullyInclusive++;
			
		}
	}
	std::cout << "Number of assignment pairs where one range fully contains the other: " << numOfFullyInclusive;



}
