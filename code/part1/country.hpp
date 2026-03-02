#pragma once
#include <iostream>
#include "Wilaya.hpp"

class Country
{
public:
    Country(){};
    void printFarmer(BinarySearchTree *Product); // call the print in class farmer
    void PrintPinalitiesFarmersCountry(BinarySearchTree *Product);
    std::vector<std::string> FillInVector();
    Farmer *findWinnerCountry(BinarySearchTree *product);


private:
    std::string CountryName;
    Area area;
    std::vector<Wilaya> Wilayas;
    Farmer *winnerCountry;
};
