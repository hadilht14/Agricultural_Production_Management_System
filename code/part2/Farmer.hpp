#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "MonthlyReport.hpp"
using namespace std;

// Farmer class
class Farmer
{
private:
    int ID;
    string name;
    int age;
    string wilaya;
    string city;
    string area;
    string gender;
    int LandId;

    int counter = 0;
    MonthlyReport MonthlyStats;

public:
    // FarmerID,LastName,Age,Gender,LandID,Area,City,Wilaya
    Farmer(int farmer_id, string L_name, int ag, string gen, int L_ID, string wi, string ci, string ar)
    {
        ID = farmer_id;
        name = L_name;
        age = ag;
        gender = gen;
        LandId = L_ID;
        wilaya = wi;
        city = ci;
        area = ar;
    };

    string GetArea()
    {
        return area;
    }
    string GetWilaya()
    {
        return wilaya;
    }
    string GetCity()
    {
        return city;
    }

    MonthlyReport GetMonthlyStat()
    {
        return MonthlyStats;
    }

    Farmer(const Farmer &copy) : name(copy.name), ID(copy.ID), age(copy.age), gender(copy.gender), LandId(copy.LandId), wilaya(copy.wilaya), city(copy.city), area(copy.area)
    {
    }

    void SetPesticide(int pest)
    {
        MonthlyStats.SetPesticide(pest);
    }

    int GetPesticide()
    {
        MonthlyStats.GetPesticide();
    }

    string GetName()
    {
        return name;
    }

    int GetId()
    {
        return ID;
    }

    double SetSales(double sales)
    {
        MonthlyStats.SetSales(sales);
    }

    double GetSales()
    {
        return MonthlyStats.GetSales();
    }

    Farmer(){};

    ~Farmer(){};

    void InsertInformation()
    {
        cout << "Insert name: ";
        cin >> name;

        cout << "Insert National ID: ";
        cin >> ID;
        while (ID <= 0)
        {
            cerr << "enter valid ID." << endl;
            cin >> ID;
        }

        cout << "Insert Gender (Male/Female):";
        cin >> gender;
        transform(gender.begin(), gender.end(), gender.begin(), ::tolower);

        while (gender != "male" && gender != "female")
        {
            cerr << "Enter as instructed (Male/Female)." << endl;
            cin >> gender;
        }

        cout << "Insert age: ";
        cin >> age;
        while (age < 18)
        {
            cerr << "enter valid age (<18)." << endl;
            cin >> age;
        }

        cout << "Insert total number of helpers: ";
        MonthlyStats.SetHelpers();

        cout << "Insert ID of land: ";
        cin >> LandId;
        while (LandId <= 0)
        {
            cerr << "enter valid Land ID." << endl;
            cin >> LandId;
        }

        cout << "Enter location:" << endl;
        cout << "Wilaya: ";
        cin >> wilaya;
        cout << "City: ";
        cin >> city;
        cout << "Area:";
        cin >> area;

        if (!isFarmerIdExists(ID))
        {
            WriteToFile();
        }
    };

    void WriteToFile() const
    {
        ofstream file("FarmerInformation.csv", ios::app);

        if (!file.is_open())
        {
            cerr << "Error opening file." << endl;
            return; // Error opening file
        }

        cout << endl;
        file << ID << "," << name << "," << age << "," << gender << "," << LandId << "," << wilaya << "," << city << "," << area << "\n";

        file.close();
        file.open("FarmerInformation.csv", ios::app);
    }

    int GetLandId()
    {
        return LandId;
    }

    void PrintInformation()
    {
        cout << "Information of farmer from " << area << ", " << city << " wilaya of " << wilaya << endl;
        cout << "Name: " << name << endl;
        cout << "National ID: " << ID << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "ID of the land: " << LandId << endl;
    };

    // void PrintInformation(int f_id)
    // {
    //     ifstream farmer_file("FarmerInformation.csv");
    //     string line1;
    //     while (getline(farmer_file, line1))
    //     {
    //         vector<string> tokens = split(line1, ',');
    //         if (tokens.size() == 8)
    //         {
    //             int id = stoi(tokens[0]);
    //             string name = tokens[1];
    //             int age = stoi(tokens[2]);
    //             string gender = tokens[3];
    //             int landID = stoi(tokens[4]);
    //             string wilaya = tokens[5];
    //             string city = tokens[6];
    //             string area = tokens[7];

    //             if (f_id == id)
    //             {
    //                 cout << "Information of farmer from " << area << ", " << city << " wilaya of " << wilaya << endl;
    //                 cout << "Name: " << name << endl;
    //                 cout << "National ID: " << ID << endl;
    //                 cout << "Age: " << age << endl;
    //                 cout << "Gender: " << gender << endl;
    //                 cout << "Total Number Of Help: " << MonthlyStats.GetHelpers() << endl;
    //                 cout << "ID of the land: " << LandId << endl;

    //                 MonthlyStats.PrintProductSalesList();
    //                 cout << "This month's electricity consumption: " << MonthlyStats.GetMonthlyElectricityConsumption() << " KW." << endl;
    //                 cout << "This month's water consumption: " << MonthlyStats.GetMonthlyWaterConsumption() << " cubic meter." << endl;
    //             }
    //             else
    //             {
    //                 std::cout << "Farmer with ID " << ID << " does not exist in the file.\n";
    //             }
    //         }
    //     }
    // };

    int GetCounter()
    {
        return counter;
    }

    bool isFarmerIdExists(int farmer_id) const
    {
        ifstream file("FarmerInformation.csv");

        if (!file.is_open())
        {
            cerr << "Error opening file FarmerInformation.csv " << endl;
            return false; // Error opening file
        }

        while (file >> farmer_id)
        {
            if (farmer_id == ID)
            {
                return true; // Farmer ID already exists
            }

            // Skip the rest of the line
            file.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        file.close();
        return false; // Farmer ID not found
    }
};
