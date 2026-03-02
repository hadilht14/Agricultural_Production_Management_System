#include "Wilaya.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <stack>
using namespace std;

Wilaya::Wilaya(string name)
{
    WilayaName = name;
}

string Wilaya::getnameWilaya()
{
    return WilayaName;
}
std::vector<std::string> Wilaya::FillInVectorSameCity(const std::string &WilayaName)
{
    std::vector<std::string> cityVector;

    std::ifstream file("FarmerInformation.csv");
    if (!file.is_open())
    {
        std::cerr << "Error opening file FarmerInformation.csv" << std::endl;
        return cityVector;
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
            if (wilaya == WilayaName)
            {
                cityVector.push_back(city);
            }
        }
    }
    file.close();
    return cityVector;
}

Farmer *Wilaya::findWinnerWilaya(const std::string &WilayaName, AvlTree *product)
{
    std::stack<Farmer *> winnerStack;

    std::vector<std::string> citiesOfWilaya = FillInVectorSameCity(WilayaName);

    // Check if there are no areas in the city or the product is nullptr
    if (citiesOfWilaya.empty() || product == nullptr)
    {
        return nullptr;
    }

    Farmer *wilayaWinner = nullptr;

    City obj;
    // Iterate through each city in the wilaya
    for (const std::string &cityName : citiesOfWilaya)
    {
        // Find the winner for the current city
        Farmer *cityWinner = obj.findWinnerCity(cityName, product);

        // Compare with the current city winner
        if (wilayaWinner == nullptr || (cityWinner->GetSales() > wilayaWinner->GetSales() &&
                                        cityWinner->GetMonthlyStat().GetMonthlyWaterConsumption() < wilayaWinner->GetMonthlyStat().GetMonthlyWaterConsumption()))
        {
            wilayaWinner = cityWinner;
        }
        else if (cityWinner->GetSales() == wilayaWinner->GetSales() &&
                 cityWinner->GetMonthlyStat().GetMonthlyWaterConsumption() == wilayaWinner->GetMonthlyStat().GetMonthlyWaterConsumption())
        {
            if (cityWinner->GetMonthlyStat().GetMonthlyElectricityConsumption() < wilayaWinner->GetMonthlyStat().GetMonthlyElectricityConsumption())
            {
                wilayaWinner = cityWinner;
            }
        }
    }

    return wilayaWinner;
}

void Wilaya::PrintPesticides(string wilayaName, AvlTree *product)
{
    vector<string> cities = FillInVectorSameCity(wilayaName);

    City obj;
    for (string &city : cities)
    {
        obj.PrintPinalitiesFarmersCity(city, product);
    }
}
void Wilaya::PrintPinalitiesFarmersWilaya(string wilayaName, AvlTree *product)
{
    PrintPesticides(wilayaName, product);
}

bool Wilaya::isWilayaNameExists(const std::string &name) const
{
    ifstream file("FarmerLocation.csv");

    if (!file.is_open())
    {
        cerr << "Error opening file FarmerLocation.csv " << endl;
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

void Wilaya::setnameWilaya(std::string name)
{
    if (!isWilayaNameExists(name))
    {
        WilayaName = name;
        std::cout << "Name area '" << WilayaName << "' set successfully." << std::endl;
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
