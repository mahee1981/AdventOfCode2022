#include <iostream>
#include <fstream>
#include <utility>
#include <set>
#include "Rope.hpp"


int main()
{

    Rope bridgeRope(2);
    int numberOfPositionsVisited = 0;

    std::ifstream fhandle("..\\day_9_1.txt");
    char direction;
    int numOfSteps;

    std::set<std::pair<int, int>> uniqueTailPositions;

    while (fhandle >> direction >> numOfSteps) {
        
        for (int i = 1; i <= numOfSteps; i++) {
            bridgeRope.Move(direction);
            uniqueTailPositions.insert(bridgeRope.TailPosition());
        }
    }  
    std::cout << "Number of unique tail moves: " << uniqueTailPositions.size();

}

