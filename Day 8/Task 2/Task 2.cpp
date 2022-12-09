#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//using a class could be better suited for this maybe
typedef std::vector<std::vector<int>> Matrix;

int ScoreBelow(const Matrix& forest, const int row, const int col);

int ScoreAbove(const Matrix& forest, const int row, const int col);

int ScoreLeft(const Matrix& forest, const int row, const int col);

int ScoreRight(const Matrix& forest, const int row, const int col);

int main()
{

    Matrix forest;
    std::ifstream fhandle("..\\day_8_1.txt");
    std::string row;

    while (std::getline(fhandle, row)) {

        std::vector<int> treeRow;
        treeRow.reserve(row.length());

        for (auto it = row.begin(); it != row.end(); it++)
            treeRow.push_back(*it - '0');

        forest.emplace_back(std::move(treeRow));
    }

    int maxScenicScore = 0;
    for (int i = 0; i < forest.size(); i++)
        for (int j = 0; j < forest.at(i).size(); j++) {
            int scenicScore = ScoreBelow(forest, i, j) * ScoreAbove(forest, i, j) * ScoreLeft(forest, i, j) * ScoreRight(forest, i, j);
            if (scenicScore > maxScenicScore)
                maxScenicScore = scenicScore;
        }
    std::cout << "The highest scenic score possible for any tree is: " << maxScenicScore;

}


int ScoreBelow(const Matrix& forest, const int row, const int col) {

    if (!(row >= 0 && row < forest.size()) || !(col >= 0 && col < forest.at(0).size()))
        throw std::range_error("Coordinates out of range");

    int scoreBelow = 0;

    for (int i = row + 1; i < forest.size(); i++) {

        scoreBelow++;
        if (forest.at(row).at(col) <= forest.at(i).at(col))
            break;
    }
    return scoreBelow;
}

int ScoreAbove(const Matrix& forest, const int row, const int col) {

    if (!(row >= 0 && row < forest.size()) || !(col >= 0 && col < forest.at(0).size()))
        throw std::range_error("Coordinates out of range");

    int scoreAbove = 0;

    for (int i = row - 1; i >= 0; i--) {
        scoreAbove++;
        if (forest.at(row).at(col) <= forest.at(i).at(col)) 
            break;
       
    }
    return scoreAbove;
}

int ScoreLeft(const Matrix& forest, const int row, const int col) {

    if (!(row >= 0 && row < forest.size()) || !(col >= 0 && col < forest.at(0).size()))
        throw std::range_error("Coordinates out of range");

    int scoreLeft = 0;

    for (int j = col - 1; j >= 0; j--) {
        scoreLeft++;
        if (forest.at(row).at(col) <= forest.at(row).at(j))
            break;
    }
    return scoreLeft;
}

int ScoreRight(const Matrix& forest, const int row, const int col) {

    if (!(col >= 0 && row < forest.size()) || !(col >= 0 && col < forest.at(0).size()))
        throw std::range_error("Coordinates out of range");

    int scoreRight = 0;

    for (int j = col + 1; j < forest.at(0).size(); j++) {
        scoreRight++;
        if (forest.at(row).at(col) <= forest.at(row).at(j))
            break;
        
    }
    return scoreRight;
}