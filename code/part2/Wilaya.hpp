#pragma once
#include <iostream>
#include "City.hpp"

class Wilaya
{
public:
    Wilaya(std::string = "");
    std::string getnameWilaya();
    void PrintPesticides(string wilayaName, AvlTree *product);
    Farmer *findWinnerWilaya(const std::string &WilayaName, AvlTree *product);
    Area getArea() { return area; }
    void setnameWilaya(std::string name);
    bool isWilayaNameExists(const std::string &name) const;
    std::vector<std::string> FillInVectorSameCity(const std::string &WilayaName);
    void PrintPinalitiesFarmersWilaya(string wilayaName, AvlTree *product);

private:
    Area area;
    std::string WilayaName;
    std::vector<City> cities;
    Farmer *winnerWilaya;
};
