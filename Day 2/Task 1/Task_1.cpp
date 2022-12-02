#include <iostream>
#include <fstream>
#include <map>


struct Node {
    char element;
    Node* beatenBy;
};

int main()
{
    //Rock = X, Paper = Y, Scissors = Z
    std::map<char, int> playerElementScore{ {'X', 1}, {'Y', 2}, {'Z', 3} };
    std::map<char, char> elfToPlayerNotation{ {'A', 'X' }, {'B', 'Y'}, {'C', 'Z'} };


    //creating a singly linked list
    Node* head = nullptr, *previous = nullptr;
    for (auto it = playerElementScore.begin(); it != playerElementScore.end(); it++) {
        Node* current = new Node{ it->first, nullptr};

        if (!head)
            head = current;
        else 
            previous->beatenBy = current;
        previous = current;
    }
    //linking the last and first element and making it ciruclar
    previous->beatenBy = head;


    std::ifstream fhandle("day_2_1.txt");
    char elfElement, playerElement;
    int totalScore = 0;

    while (fhandle >> elfElement >> playerElement) {
        elfElement = elfToPlayerNotation[elfElement];

        totalScore += playerElementScore[playerElement];

        if (elfElement == playerElement)
            totalScore += 3;
        else {
            Node* search = head;
            while (true) {
                if (search->element == playerElement) {
                    if (search->beatenBy->element != elfElement)
                        totalScore += 6;
                    break;

                }
                search = search->beatenBy;

            }
        }
    }
    std::cout << "Total score according to the strategy guide: " << totalScore;


    //memory cleanup
    Node* next = head;
    while(true){
        Node* temp = next;
        next = next->beatenBy;
        delete temp;
        if (!next || next == head)
            break;
    }

    return 0;
}

