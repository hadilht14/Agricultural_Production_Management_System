#pragma once
#include <iostream>
#include <vector>
#include "Area.hpp"

class City
{
public:
    City(std::string = "");
    std::string getnameCity();
    void printFarmersCity();
    void PrintPinalitiesFarmersCity(string cityName, BinarySearchTree *product);
    Farmer *findWinnerCity(const std::string &cityName, BinarySearchTree *product);
    Area GetArea()
    {
        return area;
    }

    void setnameCity(std::string name);
    bool isCityNameExists(const std::string &name) const;
    std::vector<std::string> FillInVectorSameArea(const std::string &cityName);

private:
    std::string CityName;
    Area area;
    std::vector<Area> Areas;
    Farmer winnerCity;
    BinarySearchTree *Product;
    void PrintPesticides(string CityName, BinarySearchTree *Product);
    Farmer *findWinner(vector<string> &areas, const std::string &CityName, BinarySearchTree *product);
};
