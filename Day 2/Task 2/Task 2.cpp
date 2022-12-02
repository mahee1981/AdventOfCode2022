#include <iostream>
#include <fstream>
#include <map>


struct Node {
    char element;
    Node* winsOver;
    Node* losesTo;
};

int main()
{
    //Rock = A, Paper = B, Scissors = C
    std::map<char, int> elementScore{ {'A', 1}, {'B', 2}, {'C', 3} };
    std::map<char, int> battleOutcomeScore{ {'X', 0 }, {'Y', 3}, {'Z', 6} };

    //creating a doubly linked list
    Node* head = nullptr, * previous = nullptr;
    for (auto it = elementScore.begin(); it != elementScore.end(); it++) {
        Node* current = new Node{ it->first, nullptr, nullptr };

        if (!head)
            head = current;
        else {
            previous->winsOver = current;
            current->losesTo = previous;
        }
        previous = current;
    }
    //linking the last and first element and making it ciruclar
    previous->winsOver = head;
    head->losesTo = previous;


    std::ifstream fhandle("day_2_1.txt");
    char elfElement, battleOutcome;
    int totalScore = 0;

    while (fhandle >> elfElement >> battleOutcome) {
        totalScore += battleOutcomeScore[battleOutcome];
        
        Node* search = head;
        while (search->element != elfElement)
            search = search->winsOver;
        
        if (battleOutcome == 'X')
            totalScore += elementScore[search->losesTo->element];

        else if (battleOutcome == 'Y')
            totalScore += elementScore[search->element];

        else if (battleOutcome == 'Z') {
            totalScore += elementScore[search->winsOver->element];
        }
    }
    std::cout << "Total score according to the strategy guide: " << totalScore;


    //memory cleanup
    Node* next = head;
    while (true) {
        Node* temp = next;
        next = next->winsOver;
        delete temp;
        if (!next || next == head)
            break;
    }

    return 0;
}

