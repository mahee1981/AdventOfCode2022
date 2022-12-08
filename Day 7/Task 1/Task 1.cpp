#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Folder.hpp"

int main()
{
    std::ifstream fhandle("..\\day_7_1.txt");
    std::string terminalCommand;
    Folder* folderTree = nullptr;
    bool listingFolder = false;
    int totalWeightsBelow100k = 0;

    while (true) {
        
        if (listingFolder)
            listingFolder = false;
        else 
            std::getline(fhandle, terminalCommand);

        if (!fhandle && !fhandle.eof())
            break;
        
        if (fhandle.eof() || terminalCommand == "$ cd ..") {

            while (folderTree) {
                if(folderTree->GetWeight() < 100000)
                    totalWeightsBelow100k += folderTree->GetWeight();
                folderTree->PropagateWeightBackwards();
                folderTree = folderTree->EraseAndMoveUp();

                if (fhandle) // false only at eof
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
                    if(folderTree)
                        folderTree->AddWeight(weight);
                }
            }
        }
        else
            folderTree = new Folder(folderTree);
    }
    folderTree->DeleteFolderTree();
    std::cout << "Sum of weigths below 100k size: " << totalWeightsBelow100k;
}
