#include "Rope.hpp"
#include <iostream>


Rope::Rope(int size = 2) {
    if (size < 2)
        throw std::domain_error("Unable to create a rope of specified size!");
    ropeNodes.resize(size, { 0,0 });
}

void Rope::Move(char direction) {
    
    switch (direction) {
    case 'R':
        ropeNodes[0].first++;
        break;
    case 'L':
        ropeNodes[0].first--;
        break;
    case 'U':
        ropeNodes[0].second++;
        break;
    case 'D':
        ropeNodes[0].second--;
        break;
    }
    
    for (int i = 1; i < ropeNodes.size(); i++) {
        if (!AreCoupled(ropeNodes[i - 1], ropeNodes[i])) {
            int delta_x = ropeNodes[i - 1].first - ropeNodes[i].first;
            int delta_y = ropeNodes[i - 1].second - ropeNodes[i].second;

            if (std::abs(delta_y) == 2)
                delta_y < 0 ? delta_y++ : delta_y--;

            if (std::abs(delta_x) == 2)
                delta_x < 0 ? delta_x++ : delta_x--;

            ropeNodes[i].first += delta_x;
            ropeNodes[i].second += delta_y;
        }
    }

}
bool Rope::AreCoupled(const std::pair<int, int>& head, const std::pair<int, int>& tail) {
    int x_diff = std::abs(head.first - tail.first);
    int y_diff = std::abs(head.second - tail.second);

    return x_diff <= 1 && y_diff <= 1;
}

std::ostream& operator<<(std::ostream& stream, const Rope& rope) {
    stream << "\tHead position: (" << rope.HeadPosition().first << ", " << rope.HeadPosition().second << ")" << std::endl;
    stream << "\tTail position: (" << rope.TailPosition().first << ", " << rope.TailPosition().second << ")" << std::endl;

    return stream;
}
