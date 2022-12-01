#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>

int main()
{
	std::fstream fhandle("day_1_1.txt", std::ios::in);

	int calories = 0;
	int i = 0;
	std::stringstream buffer;
	std::string str;
	std::tuple<int, int, int> top3{ 0,0,0 };

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
			if (calories > std::get<0>(top3)) {
				std::get<2>(top3) = std::get<1>(top3);
				std::get<1>(top3) = std::get<0>(top3);
				std::get<0>(top3) = calories;
			}
			else if (calories > std::get<1>(top3)) {
				std::get<2>(top3) = std::get<1>(top3);
				std::get<1>(top3) = calories;
			}
			else if (calories > std::get<2>(top3)) {
				std::get<2>(top3) = calories;
			}

			calories = 0;
			if (!fhandle) break;
		}
	}
	std::cout << "The top 3 elves with maximum number of calories: " << std::get<0>(top3) << ", " 
		<< std::get<1>(top3) << " and " << std::get<2>(top3) << ", which is "
		<< std::get<0>(top3) + std::get<1>(top3) + std::get<2>(top3) << " in total";


}

