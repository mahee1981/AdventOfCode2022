#pragma once
#include <utility>
#include <vector>
#include <ostream>

class Rope {
    std::vector<std::pair<int, int>> ropeNodes;
    static bool AreCoupled(const std::pair<int, int>& head, const std::pair<int, int>& tail);
public:

    explicit Rope(int size);
    const std::pair<int, int>& HeadPosition() const { return ropeNodes[0]; }
    const std::pair<int, int>& TailPosition() const { return ropeNodes[ropeNodes.size() - 1]; }
    void Move(char direction);
    friend std::ostream& operator<<(std::ostream& stream, const Rope& rope);
};