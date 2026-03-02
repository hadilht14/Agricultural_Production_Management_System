#ifndef AREA_HPP
#define AREA_HPP
#include <string>
#include <vector>
#include <stack>
#include "AVLTree.hpp"

class Area
{

public:
    Area(std::string = "");          // constryctor
    std::string getnameArea() const; // geter;
    int expertReport(Farmer);
    double salesAfterPenalities(Farmer);
    void PrintPinalitiesFarmersArea(AvlTree *product, string areaName);
    Farmer *findWinnerArea(AvlTree *product, string areaName);
    Farmer *findWinner(AvlTree::AvlNode *root, const string &areaName);

    bool isAreaNameExists(const std::string &name) const;
    void setnameArea(std::string name);

private:
    std::string nameArea;
    Farmer winner;
    void PrintPesticides(AvlTree *, std::string);

    void findWinnerHelper(AvlTree::AvlNode *root, const string &areaName, std::stack<Farmer> &winnerStack);
};

#endif // AREA_HPP
