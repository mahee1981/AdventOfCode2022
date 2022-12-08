#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <sstream>
#include <algorithm>
#include "Folder.hpp"


int main()
{
    std::ifstream fhandle("..\\day_7_1.txt");
    std::string terminalCommand;
    Folder* folderTree = nullptr;
    std::list<int> weights;
    bool listingFolder = false;

    while (true) {

        if (listingFolder)
            listingFolder = false;
        else
            std::getline(fhandle, terminalCommand);

        if (!fhandle && !fhandle.eof())
            break;

        if (fhandle.eof() || terminalCommand == "$ cd ..") {
            
            
            while (folderTree) {  

                weights.push_back(folderTree->GetWeight());
                folderTree->PropagateWeightBackwards();
                folderTree = folderTree->EraseAndMoveUp();

                if (fhandle) //skipped only at the end
                    break;
            }
            if (!fhandle)
                break;
            
                
        }

        else if (terminalCommand == "$ ls") {
            listingFolder = true;
            while (std::getline(fhandle, terminalCommand)) {

                if (terminalCommand[0] == '$')
                    break;

                else if (std::isdigit(terminalCommand[0])) {
                    std::stringstream buffer;
                    buffer << terminalCommand;
                    int weight;
                    buffer >> weight;
                    folderTree->AddWeight(weight);
                }
            }
        }

        else
            folderTree = new Folder(folderTree);

    }
    folderTree->DeleteFolderTree();

    constexpr int totalMemory = 70000000, memoryRequired = 30000000;
    int totalAllocatedMemory = weights.back();
    int freeMemory = totalMemory - totalAllocatedMemory;
    int needToDeleteMemory = memoryRequired - freeMemory;
    
    auto acceptableValuesEnd = std::remove_if(weights.begin(), weights.end(), [needToDeleteMemory](const int weight) {return weight <= needToDeleteMemory; });
    auto it = std::min_element(weights.begin(), acceptableValuesEnd);
    std::cout << "Size of the folder that needs to be remove in order for update to be installed: " << *it;
    
    

}
