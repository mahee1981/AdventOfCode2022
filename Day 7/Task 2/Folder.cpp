#include "Folder.hpp"

void Folder::PropagateWeightBackwards() {
    if (this->parent)
        this->parent->cumulativeWeight += this->cumulativeWeight;

}
Folder* Folder::EraseAndMoveUp() {
    Folder* parent = this->parent;
    delete this;
    return parent;
}
void Folder::DeleteFolderTree() {
    Folder* current = this;
    while (current) {
        Folder* temp = current;
        current = current->parent;
        delete temp;
    }
}