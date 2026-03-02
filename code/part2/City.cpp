#include "City.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <stack>
using namespace std;

City::City(string name)
{
    CityName = name;
}

string City::getnameCity()
{
    return CityName;
}

std::vector<std::string> City::FillInVectorSameArea(const std::string &cityName)
{
    std::vector<std::string> areaVector;

    std::ifstream file("FarmerInformation.csv");
    if (!file.is_open())
    {
        std::cerr << "Error opening file FarmerInformation.csv" << std::endl;
        return areaVector;
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

            // Check if the city matches the given cityName
            if (city == cityName)
            {
                areaVector.push_back(area);
            }
        }
    }
    file.close();
    return areaVector;
}

Farmer *City::findWinnerCity(const std::string &cityName, AvlTree *product)
{
    std::stack<Farmer *> winnerStack;

    std::vector<std::string> areasOfCity = FillInVectorSameArea(cityName);

    // Check if there are no areas in the city or the product is nullptr
    if (areasOfCity.empty() || product == nullptr)
    {
        return nullptr;
    }

    Farmer *cityWinner = nullptr;

    Area obj;
    // Iterate through each area in the city
    for (const std::string &areaName : areasOfCity)
    {
        // Find the winner for the current area
        Farmer *areaWinner = obj.findWinnerArea(product, areaName);

        // Check if there is a winner in the current area for the given category
        if (areaWinner != nullptr)
        {
            // Compare with the current city winner
            if (cityWinner == nullptr || (areaWinner->GetSales() > cityWinner->GetSales() &&
                                          areaWinner->GetMonthlyStat().GetMonthlyWaterConsumption() < cityWinner->GetMonthlyStat().GetMonthlyWaterConsumption()))
            {
                cityWinner = areaWinner;
            }
            else if (areaWinner->GetSales() == cityWinner->GetSales() &&
                     areaWinner->GetMonthlyStat().GetMonthlyWaterConsumption() == cityWinner->GetMonthlyStat().GetMonthlyWaterConsumption())
            {
                if (areaWinner->GetMonthlyStat().GetMonthlyElectricityConsumption() < cityWinner->GetMonthlyStat().GetMonthlyElectricityConsumption())
                {
                    cityWinner = areaWinner;
                }
                else if (areaWinner->GetMonthlyStat().GetMonthlyElectricityConsumption() == cityWinner->GetMonthlyStat().GetMonthlyElectricityConsumption())
                {
                    if (obj.expertReport(*areaWinner) < obj.expertReport(*cityWinner))
                    {
                        cityWinner = areaWinner;
                    }
                }
            }
        }
    }

    return cityWinner;
}

void City::PrintPesticides(string CityName, AvlTree *Product)
{
    vector<string> areas = FillInVectorSameArea(CityName);

    Area obj;
    for (string &area : areas)
    {
        obj.PrintPinalitiesFarmersArea(Product, area);
    }
}
void City::PrintPinalitiesFarmersCity(string cityName, AvlTree *product)
{
    PrintPesticides(cityName, product);
}

bool City::isCityNameExists(const std::string &name) const
{
    ifstream file("Farmerlocation.csv");

    if (!file.is_open())
    {
        cerr << "Error opening file FarmerLocation.csv." << endl;
        return false; // Error opening file
    }

    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        string columnValue;

        // Assuming the area name is in the first column
        if (iss >> columnValue && columnValue == name)
        {
            // Name exists in the file
            file.close();
            return true;
        }
    }

    // Name not found in the file
    file.close();
    return false;
}

void City::setnameCity(std::string name)
{
    if (!isCityNameExists(name))
    {
        CityName = name;
        std::cout << "Name area '" << CityName << "' set successfully." << std::endl;
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
