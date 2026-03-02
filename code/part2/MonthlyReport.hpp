#pragma once
#include <iostream>
#include <algorithm>
#include "Date.hpp"
using namespace std;

// monthly report class where monthly statistics are kept
class MonthlyReport
{
private:
    Date report_date;
    int Farmer_ID;
    double Sales;
    string productName[5];
    int ProductNum;
    int helpers;
    double WaterConsumption;
    double ElectricityConsumption;
    int pesticide;
    int ProducesFruits;
    int ProducesVegetables;
    int ProducesCereals;
    int ProducesDates;
    int ProducesOlives;
    double SalesFruits;
    double SalesVegetables;
    double SalesCereals;
    double SalesDates;
    double SalesOlives;

public:
    MonthlyReport(){};
    MonthlyReport(int id, int numhelp, int PF, int PV, int PC, int PD, int PO, double SF, double SV, double SC, double SD, double SO, double water, double elec, int mo, int yea)
    {
        Farmer_ID = id;
        helpers = numhelp;
        ProducesFruits = PF;
        ProducesVegetables = PV;
        ProducesCereals = PC;
        ProducesDates = PD;
        ProducesOlives = PO;
        SalesFruits = SF;
        SalesVegetables = SV;
        SalesCereals = SC;
        SalesDates = SD;
        SalesOlives = SO;
        report_date.set_month(mo);
        report_date.set_year(yea);
    };
    ~MonthlyReport(){};

    int GetMonth()
    {
        return report_date.get_month();
    }
    int GetYear()
    {
        return report_date.get_year();
    }

    void SetProduct(string product)
    {
        for (int i = 0; i < 5; i++ && productName[i] != "")
        {
            productName[i] = product;
        }
    }

    void SetPesticide(int pest)
    {
        pesticide = pest;
    }

    int GetPesticide()
    {
        return pesticide;
    }

    void SetHelpers()
    {
        cin >> helpers;
        while (helpers < 0)
        {
            cerr << "Enter valid number of helpers." << endl;
            cin >> helpers;
        }
    }

    void SetHelpers(int help)
    {
        helpers = help;
    }

    int GetHelpers()
    {
        return helpers;
    }

    string GetProductName()
    {
        // Iterate through the array and return the first matching product
        for (const auto &product : productName)
        {
            if (product == "Cereals" || product == "cereals" || product == "Vegetables" || product == "vegetables" || product == "Fruits" || product == "fruits" || product == "Olives" || product == "olives" || product == "Dates" || product == "dates")
            {
                return product;
            }
        }
    };

    void SetMonthlySales()
    {
        cin >> Sales;
        while (Sales < 0)
        {
            cin >> Sales;
        }
    };

    void SetSales(int sales)
    {
        Sales = sales;
    }

    double GetSales()
    {
        return Sales;
    };

    void SetWater(double water)
    {
        WaterConsumption = water;
    }

    void SetElectricity(double Electricity)
    {
        ElectricityConsumption = Electricity;
    }

    void SetDate(int m, int y)
    {
        report_date.set_month(m);
        report_date.set_year(y);
    }

    void SetConsumptions()
    {
        cout << "Enter this month's water consumption(in cubic meter): ";
        cin >> WaterConsumption;
        while (WaterConsumption < 0)
        {
            cout << "Enter valid values." << endl;
            cin >> WaterConsumption;
        }

        cout << "Enter this month's electricity(in kilo watt): ";
        cin >> ElectricityConsumption;
        while (ElectricityConsumption < 0)
        {
            cout << "Enter valid values." << endl;
            cin >> ElectricityConsumption;
        }
    };

    double GetMonthlyElectricityConsumption()
    {
        return ElectricityConsumption;
    };

    double GetMonthlyWaterConsumption()
    {
        return WaterConsumption;
    };

    int GetNumOfProducts() const
    {
        return ProductNum;
    }

    void SetProductSales()
    {
        cout << "Enter the number of products sold at your farm (1-5): ";
        cin >> ProductNum;
        while (ProductNum < 0 || ProductNum > 5)
        {
            cout << "Enter as instructed: ";
            cin >> ProductNum;
        }
        for (int i = 0; i < ProductNum; i++)
        {
            cout << "Enter product name (Cereals, Vegetables, Fruits, Dates, Olives): ";
            cin >> productName[i];
            transform(productName[i].begin(), productName[i].end(), productName[i].begin(), ::tolower);

            while (productName[i] != "cereals" && productName[i] != "vegetables" && productName[i] != "fruits" && productName[i] != "dates" && productName[i] != "olives")
            {
                cerr << "Enter as instructed (Cereals/Vegetables/Fruits/Dates/Olives)." << endl;
                cin >> productName[i];
            }

            cout << "Enter month and year of sales: " << endl;
            report_date.set_month();
            report_date.set_year();
            cout << "Enter sales of " << productName[i] << " in Algerian Dinar (DZDA) during  :";
            this->SetMonthlySales();
        }
    };

    void PrintProductSalesList()
    {
        for (int i = 0; i < ProductNum; i++)
        {
            cout << "Sales of " << productName[i] << "in Algerian Dinar(DZDA) : " << this->GetSales() << endl;
        }
    }

    void PrintAll()
    {
        cout << "Number of helpers: " << helpers << endl;
        PrintProductSalesList();
        cout << "Electricity Consumption: " << GetMonthlyElectricityConsumption() << "KW (kilowatt)." << endl;
        cout << "Water Consumption: " << GetMonthlyWaterConsumption() << "cubic meter." << endl;
    }
};
