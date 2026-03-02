#ifndef AREA_HPP
#define AREA_HPP
#include <string>
#include <vector>
#include "BinarySearchTree.hpp"

class Area
{

public:
    Area(std::string = "");          // constryctor
    std::string getnameArea() const; // geter;
    int expertReport(Farmer f);
    double salesAfterPenalities(Farmer);
    Farmer *findWinnerArea(BinarySearchTree *product, string areaName);
    Farmer *findWinner(BinarySearchTree::BinaryNode *root, const string &areaName);
    void PrintPinalitiesFarmersArea(BinarySearchTree *product, string areaName);


    bool isAreaNameExists(const std::string &name) const;
    void setnameArea(std::string name);

private:
    std::string nameArea;
    Farmer winner;
    void PrintPesticides(BinarySearchTree::BinaryNode *root, string areaName);

    void findWinnerHelper(BinarySearchTree::BinaryNode *root, const string &areaName, std::stack<Farmer> &winnerStack);
};

#endif // AREA_HPP
