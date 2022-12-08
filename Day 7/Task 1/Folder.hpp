#pragma once
class Folder {
    int cumulativeWeight;
    Folder* parent;

public:
    explicit Folder(Folder* parent) : cumulativeWeight(0), parent(parent) {}
    void AddWeight(int weight) { cumulativeWeight += weight; }
    void PropagateWeightBackwards();
    int GetWeight() const { return cumulativeWeight; }
    Folder* EraseAndMoveUp();
    void DeleteFolderTree();
};