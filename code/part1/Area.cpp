#include "Area.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <stack>
using namespace std;

Area::Area(string name)
{
    nameArea = name;
}

string Area::getnameArea() const
{
    return nameArea;
}

double Area::salesAfterPenalities(Farmer f)
{
    int level_pecticides = expertReport(f);
    double newSales = (f.GetSales()) * ((f.GetSales()) - (level_pecticides * 10));
    f.SetSales(newSales);
    return newSales;
}

int Area::expertReport(Farmer f)
{
    int level_pesticides = rand() % 4;
    f.GetMonthlyStat().SetPesticide(level_pesticides);
    return level_pesticides;
}

void Area::PrintPinalitiesFarmersArea(BinarySearchTree *product, string areaName)
{
    PrintPesticides(product->GetRoot(), areaName);
}

void Area::PrintPesticides(BinarySearchTree::BinaryNode *root, string areaName)
{
    if (root == nullptr)
    {
        return;
    }


    PrintPesticides(root->GetLeftNode(), areaName);

    if (root->GetFarmerNode().GetArea() == areaName)
    {
        int pest = expertReport(root->GetFarmerNode());
        cout << "Farmer in Area: " << areaName << endl;
        root->GetFarmerNode().PrintInformation();
        cout << "Level of pesticides applied: " << pest << endl;
    }

    PrintPesticides(root->GetRightNode(), areaName);
}

Farmer *Area::findWinnerArea(BinarySearchTree *product, string areaName)
{
    BinarySearchTree::BinaryNode *tree = product->GetRoot();
    return findWinner(tree, areaName);
}

Farmer *Area::findWinner(BinarySearchTree::BinaryNode *root, const string &areaName)
{
    std::stack<Farmer> winnerStack;

    if (root == nullptr)
    {
        cout << "No farmers in " << areaName << "." << endl;
        return nullptr;
    }

    findWinnerHelper(root, areaName, winnerStack);

    // Check if winnerStack is not empty
    if (!winnerStack.empty())
    {
        return new Farmer(winnerStack.top()); // Return a copy of the top farmer
    }
    else
    {
        return nullptr; // or handle appropriately
    }
}

// Helper function for recursive traversal
void Area::findWinnerHelper(BinarySearchTree::BinaryNode *root, const string &areaName, std::stack<Farmer> &winnerStack)
{
    if (root == nullptr)
    {
        return;
    }

    findWinnerHelper(root->GetLeftNode(), areaName, winnerStack);

    if (root->GetFarmerNode().GetArea() == areaName)
    {
        if (winnerStack.empty() ||
            (root->GetFarmerNode().GetSales() > winnerStack.top().GetSales()) ||
            (root->GetFarmerNode().GetSales() == winnerStack.top().GetSales() &&
             root->GetFarmerNode().GetMonthlyStat().GetMonthlyWaterConsumption() < winnerStack.top().GetMonthlyStat().GetMonthlyWaterConsumption()) ||
            // Add more criteria if needed
            // ...
            (root->GetFarmerNode().GetMonthlyStat().GetMonthlyElectricityConsumption() == winnerStack.top().GetMonthlyStat().GetMonthlyElectricityConsumption() &&
             expertReport(root->GetFarmerNode()) < expertReport(winnerStack.top())))
        {
            winnerStack.push(root->GetFarmerNode());
        }
    }

    findWinnerHelper(root->GetRightNode(), areaName, winnerStack);
}

bool Area::isAreaNameExists(const std::string &name) const
{
    ifstream file("FarmerInformation.csv");

    if (!file.is_open())
    {
        cerr << "Error opening file FarmerLocation.csv." << endl;
        return false; // Error opening file
    }

    std::string line;

    // Read and process data rows
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string value;

        // Extract values in the row
        std::vector<std::string> values;
        while (std::getline(ss, value, ','))
        {
            values.push_back(value);
        }

        // Check if the last value matches the targetValue
        if (!values.empty() && values.back() == name)
        {
            file.close();
            return true;
        }
    }

    // Name not found in the file
    file.close();
    return false;
}

void Area::setnameArea(std::string name)
{
    if (!isAreaNameExists(name))
    {
        nameArea = name;
        std::cout << "Name area '" << nameArea << "' set successfully." << std::endl;
    }
    else
    {
        std::cout << "Name area '" << name << "' already exists in the file. Setting name aborted." << std::endl;
    }
}

/*Area::~Area()
{
    //dtor
}
*/
