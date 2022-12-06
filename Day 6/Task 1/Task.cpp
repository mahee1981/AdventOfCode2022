#include <iostream>
#include <fstream>
#include <deque>



int main()
{
	std::ifstream fhandle("..\\day_6_1.txt");
	//the solution is essentially the same for the second part except that the streamSize is 14
	constexpr int streamSize = 4;
	std::deque<char> serialInput(streamSize);

	for (int i = 0; i < serialInput.size() - 1; i++)
		fhandle >> serialInput[i];
	
	int numOfReads = streamSize - 1;
	char lastEntry;
	while (fhandle >> lastEntry) {
		serialInput.push_back(lastEntry);
		numOfReads++;

		bool hasDuplicateEntries = false;

		for (int i = 0; i < serialInput.size() && !hasDuplicateEntries; i++) {
			for (int j = i + 1; j < serialInput.size() && !hasDuplicateEntries; j++) {
				if (serialInput[i] == serialInput[j])
					hasDuplicateEntries = true;
			}
		}
		if (!hasDuplicateEntries)
			break;
		//discussion topic for code review
		while(serialInput.size() > streamSize-1)
			serialInput.pop_front();
		
		
	
	}
	std::cout << "Characters processed before the first start-of-packet marker is detected: " << numOfReads;

	
}

