#include <iostream>
#include <fstream>
#include <vector>
#include <string>

//using a class could be better suited for this maybe
typedef std::vector<std::vector<int>> Matrix;

bool IsVisibleBelow(const Matrix& forest, const int row, const int col);

bool IsVisibleAbove(const Matrix& forest, const int row, const int col);

bool IsVisibleFromLeft(const Matrix& forest, const int row, const int col);

bool IsVisibleFromRight(const Matrix& forest, const int row, const int col);

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

    int numVisibleTrees = 0;
    for (int i = 0; i < forest.size(); i++)
        for (int j = 0; j < forest.at(i).size(); j++) {

            if (IsVisibleAbove(forest, i, j) || IsVisibleBelow(forest, i, j) || IsVisibleFromLeft(forest, i, j) || IsVisibleFromRight(forest, i, j))
                numVisibleTrees++;
        }
    std::cout << "Number of trees visible from outside the grid: " << numVisibleTrees;

}


bool IsVisibleBelow(const Matrix& forest, const int row, const int col) {

    if (!(row >= 0 && row < forest.size()) || !(col >= 0 && col < forest.at(0).size()))
        throw std::range_error("Coordinates out of range");

    bool visibleBelow = true;

    for (int i = row + 1; i < forest.size(); i++) {
        if (forest.at(row).at(col) <= forest.at(i).at(col)) {
            visibleBelow = false;
            break;
        }
    }
    return visibleBelow;
}

bool IsVisibleAbove(const Matrix& forest, const int row, const int col) {

    if (!(row >= 0 && row < forest.size()) || !(col >= 0 && col < forest.at(0).size()))
        throw std::range_error("Coordinates out of range");

    bool visibleAbove = true;

    for (int i = row - 1; i >= 0; i--) {
        if (forest.at(row).at(col) <= forest.at(i).at(col)) {
            visibleAbove = false;
            break;
        }
    }
    return visibleAbove;
}

bool IsVisibleFromLeft(const Matrix& forest, const int row, const int col) {

    if (!(row >= 0 && row < forest.size()) || !(col >= 0 && col < forest.at(0).size()))
        throw std::range_error("Coordinates out of range");

    bool visibleFromLeft = true;

    for (int j = col - 1; j >= 0; j--) {
        if (forest.at(row).at(col) <= forest.at(row).at(j)) {
            visibleFromLeft = false;
            break;
        }
    }
    return visibleFromLeft;
}

bool IsVisibleFromRight(const Matrix& forest, const int row, const int col) {

    if (!(col >= 0 && row < forest.size()) || !(col >= 0 && col < forest.at(0).size()))
        throw std::range_error("Coordinates out of range");

    bool visibleFromRight = true;

    for (int j = col + 1; j < forest.at(0).size(); j++) {
        if (forest.at(row).at(col) <= forest.at(row).at(j)) {
            visibleFromRight = false;
            break;
        }
    }
    return visibleFromRight;
}