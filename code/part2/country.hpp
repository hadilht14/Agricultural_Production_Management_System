#pragma once
#include <iostream>
#include "Wilaya.hpp"

class Country
{
public:
    Country(){};
    void printFarmer(AvlTree *Product); // call the print in class farmer
    void PrintPinalitiesFarmersCountry(AvlTree *Product);
    std::vector<std::string> FillInVector();
    Farmer *findWinnerCountry(AvlTree *product);


private:
    std::string CountryName;
    Area area;
    std::vector<Wilaya> Wilayas;
    Farmer *winnerCountry;
};
