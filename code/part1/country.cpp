#include "Country.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <set>

using namespace std;

void Country::printFarmer(BinarySearchTree *Product)
{
    Product->GetFarmer().PrintInformation();
}

std::vector<std::string> Country::FillInVector()
{
    std::vector<std::string> wilayaVector;
    std::set<std::string> uniqueWilayas; // Keep track of unique wilayas

    std::ifstream file("FarmerInformation.csv");
    if (!file.is_open())
    {
        std::cerr << "Error opening file FarmerInformation.csv" << std::endl;
        return wilayaVector;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string id, name, age, gender, landId, wilaya, city, area;

        // Read each column from the CSV line
        if (std::getline(iss, id, ',') && std::getline(iss, name, ',') &&
            std::getline(iss, age, ',') && std::getline(iss, gender, ',') &&
            std::getline(iss, landId, ',') && std::getline(iss, wilaya, ',') &&
            std::getline(iss, city, ',') && std::getline(iss, area, ','))
        {
            // Check if the wilaya is not already in the set
            if (uniqueWilayas.insert(wilaya).second)
            {
                // If not, push it into the vector
                wilayaVector.push_back(wilaya);
            }
        }
    }
    file.close();
    return wilayaVector;
}

Farmer *Country::findWinnerCountry(BinarySearchTree *product)
{
    std::stack<Farmer *> winnerStack;

    std::vector<std::string> WilayaCountry = FillInVector();

    // Check if there are no areas in the city or the product is nullptr
    if (WilayaCountry.empty() || product == nullptr)
    {
        return nullptr;
    }

    Farmer *CountryWinner = nullptr;

    // Iterate through each city in the wilaya
    Wilaya obj;
    for (const std::string &wilayaName : WilayaCountry)
    {
        // Find the winner for the current city
        Farmer *WilayaWinner = obj.findWinnerWilaya(wilayaName, product);

        // Compare with the current city winner
        if (WilayaWinner != nullptr &&
            (CountryWinner == nullptr || (WilayaWinner->GetSales() > CountryWinner->GetSales() &&
                                          WilayaWinner->GetMonthlyStat().GetMonthlyWaterConsumption() < CountryWinner->GetMonthlyStat().GetMonthlyWaterConsumption())))
        {
            CountryWinner = WilayaWinner;
        }
        else if (WilayaWinner != nullptr && WilayaWinner->GetSales() == CountryWinner->GetSales() &&
                 WilayaWinner->GetMonthlyStat().GetMonthlyWaterConsumption() == CountryWinner->GetMonthlyStat().GetMonthlyWaterConsumption() &&
                 WilayaWinner->GetMonthlyStat().GetMonthlyElectricityConsumption() < CountryWinner->GetMonthlyStat().GetMonthlyElectricityConsumption())
        {
            CountryWinner = WilayaWinner;
        }
    }

    // Debug prints
    if (CountryWinner != nullptr)
    {
        std::cout << "Country Winner: " << CountryWinner->GetId() << " " << CountryWinner->GetName() << std::endl;
    }
    else
    {
        std::cout << "No country winner found." << std::endl;
    }

    return CountryWinner;
}

void Country::PrintPinalitiesFarmersCountry(BinarySearchTree *Product)
{
    vector<string> wilayas = FillInVector();

    Wilaya obj;
    for (string &wilaya : wilayas)
    {
        obj.PrintPinalitiesFarmersWilaya(wilaya, Product);
    }
}
/*Area::~Area()
{
    //dtor
}
*/
