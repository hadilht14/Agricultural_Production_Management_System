#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include "Country.hpp"
using namespace std;
using namespace chrono;

vector<string> split(const string &s, char delimiter)
{
    vector<string> tokens;
    istringstream tokenStream(s);
    string token;
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

int stringToInt(const string &s)
{
    stringstream ss(s);
    int result;
    ss >> result;
    if (ss.fail() || !ss.eof())
    {
        throw invalid_argument("Invalid integer: " + s);
    }
    return result;
}

double stringToDouble(const string &s)
{
    stringstream ss(s);
    double result;
    ss >> result;
    if (ss.fail() || !ss.eof())
    {
        throw invalid_argument("Invalid double: " + s);
    }
    return result;
}

void PrintAllSalesFarmers(string category, int y, int m)
{
    ifstream farmer_file("FarmerInformation.csv");
    ifstream monthly_file("MonthlyReport.csv");
    vector<Farmer> list;
    vector<MonthlyReport> list2;

    if (!farmer_file.is_open() || !monthly_file.is_open())
    {
        cerr << "Error opening file." << endl;
        return;
    }

    string line1;

    while (getline(farmer_file, line1))
    {
        vector<string> tokens = split(line1, ',');
        if (tokens.size() == 8)
        {
            int id = stoi(tokens[0]);
            std::cout << "Farmer ID: " << id << endl;
            string name = tokens[1];
            std::cout << "Farmer name: " << name << endl;
            int age = stoi(tokens[2]);
            std::cout << "Farmer age: " << age << endl;
            string gender = tokens[3];
            std::cout << "Farmer gender: " << gender << endl;
            int landID = stoi(tokens[4]);
            std::cout << "Farmer LandID: " << landID << endl;
            string wilaya = tokens[5];
            std::cout << "Farmer wilaya: " << wilaya << endl;
            string city = tokens[6];
            std::cout << "Farmer city: " << city << endl;
            string area = tokens[7];
            std::cout << "Farmer area: " << area << endl;
            Farmer test(id, name, age, gender, landID, wilaya, city, area);
            list.push_back(test);

            monthly_file.clear();
            monthly_file.seekg(0, ios::beg);

            string line2;
            while (getline(monthly_file, line2))
            {

                vector<string> tokens = split(line2, ',');
                if (tokens.size() == 16)
                {
                    int Monthlyid = stringToInt(tokens[0]);
                    int month = stringToInt(tokens[14]);
                    int year = stringToInt(tokens[15]);

                    if (Monthlyid == id)
                    {

                        int NumHelpers = stringToInt(tokens[1]);
                        if (month == m && year == y)
                        {
                            std::cout << "Farmer number of helpers: " << NumHelpers << endl;
                        }

                        int ProducesFruits = stringToInt(tokens[2]);
                        double SalesFruits = stringToDouble(tokens[7]);
                        if (ProducesFruits == 1 && (category == "fruits" || category == "Fruits") && month == m && year == y)
                        {
                            cout << "Farmer fruits sales: " << SalesFruits << "DZDA" << endl;
                        }

                        int ProducesVegetables = stringToInt(tokens[3]);
                        double SalesVegetables = stringToDouble(tokens[8]);
                        if (ProducesVegetables == 1 && (category == "vegetables" || category == "Vegtables") && month == m && year == y)
                        {
                            cout << "Farmer vegetables sales: " << SalesVegetables << "DZDA" << endl;
                        }

                        int ProducesCereals = stringToInt(tokens[4]);
                        double SalesCereals = stringToDouble(tokens[9]);
                        if (ProducesCereals == 1 && (category == "cereals" || category == "Cereals") && month == m && year == y)
                        {
                            cout << "Farmer cereals sales: " << SalesCereals << "DZDA" << endl;
                        }

                        int ProducesDates = stringToInt(tokens[5]);
                        double SalesDates = stringToDouble(tokens[10]);
                        if (ProducesDates == 1 && (category == "dates" || category == "Dates") && month == m && year == y)
                        {
                            cout << "Farmer dates sales: " << SalesDates << "DZDA" << endl;
                        }

                        int ProducesOlives = stringToInt(tokens[6]);
                        double SalesOlives = stringToDouble(tokens[11]);
                        if (ProducesOlives == 1 && (category == "olives" || category == "Olives") && month == m && year == y)
                        {
                            cout << "Farmer olives sales: " << SalesOlives << "DZDA" << endl;
                        }

                        double WaterCons = stringToDouble(tokens[12]);
                        if (month == m && year == y)
                        {
                            cout << "Farmer water consumption: " << WaterCons << "cubic meter" << endl;
                        }

                        double ElectricityCons = stringToDouble(tokens[13]);
                        if (month == m && year == y)
                        {
                            cout << "Farmer electricity consumption: " << ElectricityCons << "KW (kilowatt)" << endl;
                        }

                        cout << endl;

                        MonthlyReport monthTest(Monthlyid, NumHelpers, ProducesFruits, ProducesVegetables, ProducesCereals, ProducesDates, ProducesOlives, SalesFruits, SalesVegetables, SalesCereals, SalesDates, SalesOlives, WaterCons, ElectricityCons, month, year);
                        list2.push_back(monthTest);
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        else
        {
            cerr << "Error parsing lines." << endl;
        }
    }

    monthly_file.close();
    farmer_file.close();
}

void PrintAllSalesFarmers(int y, int m)
{
    ifstream farmer_file("FarmerInformation.csv");
    ifstream monthly_file("MonthlyReport.csv");
    vector<Farmer> list;
    vector<MonthlyReport> list2;

    if (!farmer_file.is_open() || !monthly_file.is_open())
    {
        cerr << "Error opening file." << endl;
        return;
    }

    string line1;

    while (getline(farmer_file, line1))
    {
        vector<string> tokens = split(line1, ',');
        if (tokens.size() == 8)
        {
            int id = stoi(tokens[0]);
            std::cout << "Farmer ID: " << id << endl;
            string name = tokens[1];
            std::cout << "Farmer name: " << name << endl;
            int age = stoi(tokens[2]);
            std::cout << "Farmer age: " << age << endl;
            string gender = tokens[3];
            std::cout << "Farmer gender: " << gender << endl;
            int landID = stoi(tokens[4]);
            std::cout << "Farmer LandID: " << landID << endl;
            string wilaya = tokens[5];
            std::cout << "Farmer wilaya: " << wilaya << endl;
            string city = tokens[6];
            std::cout << "Farmer city: " << city << endl;
            string area = tokens[7];
            std::cout << "Farmer area: " << area << endl;
            Farmer test(id, name, age, gender, landID, wilaya, city, area);
            list.push_back(test);

            monthly_file.clear();
            monthly_file.seekg(0, ios::beg);

            string line2;
            while (getline(monthly_file, line2))
            {

                vector<string> tokens = split(line2, ',');
                if (tokens.size() == 16)
                {
                    int Monthlyid = stringToInt(tokens[0]);
                    int month = stringToInt(tokens[14]);
                    int year = stringToInt(tokens[15]);

                    if (Monthlyid == id)
                    {
                        if (month == m && year == y)
                        {
                            cout << "Stats of " << month << "/" << year << ":" << endl;
                            int NumHelpers = stringToInt(tokens[1]);

                            std::cout << "Farmer number of helpers: " << NumHelpers << endl;

                            int ProducesFruits = stringToInt(tokens[2]);
                            double SalesFruits = stringToDouble(tokens[7]);
                            if (ProducesFruits == 1)
                            {
                                cout << "Farmer fruits sales: " << SalesFruits << "DZDA" << endl;
                            }

                            int ProducesVegetables = stringToInt(tokens[3]);
                            double SalesVegetables = stringToDouble(tokens[8]);
                            if (ProducesVegetables == 1)
                            {
                                cout << "Farmer vegetables sales: " << SalesVegetables << "DZDA" << endl;
                            }

                            int ProducesCereals = stringToInt(tokens[4]);
                            double SalesCereals = stringToDouble(tokens[9]);
                            if (ProducesCereals == 1)
                            {
                                cout << "Farmer cereals sales: " << SalesCereals << "DZDA" << endl;
                            }

                            int ProducesDates = stringToInt(tokens[5]);
                            double SalesDates = stringToDouble(tokens[10]);
                            if (ProducesDates == 1)
                            {
                                cout << "Farmer dates sales: " << SalesDates << "DZDA" << endl;
                            }

                            int ProducesOlives = stringToInt(tokens[6]);
                            double SalesOlives = stringToDouble(tokens[11]);
                            if (ProducesOlives == 1)
                            {
                                cout << "Farmer olives sales: " << SalesOlives << "DZDA" << endl;
                            }

                            double WaterCons = stringToDouble(tokens[12]);

                            cout << "Farmer water consumption: " << WaterCons << "cubic meter" << endl;

                            double ElectricityCons = stringToDouble(tokens[13]);

                            cout << "Farmer electricity consumption: " << ElectricityCons << "KW (kilowatt)" << endl;

                            cout << endl;

                            MonthlyReport monthTest(Monthlyid, NumHelpers, ProducesFruits, ProducesVegetables, ProducesCereals, ProducesDates, ProducesOlives, SalesFruits, SalesVegetables, SalesCereals, SalesDates, SalesOlives, WaterCons, ElectricityCons, month, year);
                            list2.push_back(monthTest);
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
            }
        }
        else
        {
            cerr << "Error parsing lines." << endl;
        }
    }

    monthly_file.close();
    farmer_file.close();
}

void FarmerInterface()
{
    Farmer FTest;
    int choice;
    char access;
    bool exit = false;
    int ExitContinue;
    char returnToMyprofile;
    string line1;

    while (!exit)
    {
        std::cout << "WELCOME dear Farmer" << endl;
        std::cout << "1.Login(I have already an account)" << endl;
        std::cout << "2.Sign up( don't have an account)" << endl;
        std::cout << "Please, choose one page!" << endl;
        std::cin >> choice;

        if (choice == 1) // access to his account
        {

            std::cout << "a.My profile" << endl;
            std::cout << "b.Update my additional Data" << endl;
            std::cout << "Please, choose one action!" << endl;
            std::cin >> access;
            access = tolower(access);
            ifstream farmer_file("FarmerInformation.csv");
            vector<string> tokens;
            if (access == 'a') // printfarmer
            {

                std::cout << "My profile" << endl;
                int f_id;
                std::cout << "enter your id " << endl;
                std::cin >> f_id;

                while (getline(farmer_file, line1))
                {
                    tokens = split(line1, ',');
                    if (tokens.size() == 8)
                    {
                        string name = tokens[1];
                        int id = stoi(tokens[0]);
                        int age = stoi(tokens[2]);
                        string gender = tokens[3];
                        int landID = stoi(tokens[4]);
                        string wilaya = tokens[5];
                        string city = tokens[6];
                        string area = tokens[7];
                        if (f_id == id)
                        {
                            std::cout << "Information of farmer from " << area << ", " << city << " wilaya of " << wilaya << endl;
                            std::cout << "Name: " << name << endl;
                            std::cout << "National ID: " << id << endl;
                            std::cout << "Age: " << age << endl;
                            std::cout << "Gender: " << gender << endl;
                        }
                        // function print
                        std::cout << "-------------------------------------------------------------------------------------------" << endl;
                        std::cout << "would you want to update your additional information(Y/y->yes)or(N/n->no)" << endl;
                        std::cin >> returnToMyprofile;
                        if (returnToMyprofile == 'y' || returnToMyprofile == 'Y')
                            access = 'b';
                        else
                        {
                            break;
                        }
                    }
                    if (access = 'b') // we need setters to ask the use to fill out this information monthly
                    {
                        std::cout << "Update my additional Data" << endl;
                        std::cout << "updating sales" << endl;
                        FTest.GetMonthlyStat().SetMonthlySales();
                        std::cout << "updating consumption" << endl;
                        FTest.GetMonthlyStat().SetConsumptions();
                        std::cout << "updating productSales" << endl;
                        FTest.GetMonthlyStat().SetProductSales();
                    }
                    else
                    {
                        break;
                    }
                }
            }
            farmer_file.close();
        }
        else if (choice == 2) // check if the farmer already exist
        {

            // create a new account

            FTest.InsertInformation();

            // we need to implement a function that verifie whether he exist yet or not
            // if he exist send msg "you are already resigter "
            // if not we insert all his info and send msg "success"
            // std::cout<<"1.Login(I have already an account)"<<endl;
        }
        else
        {
            break;
        }

        std::cout << "1.continue searching in the farmer page" << endl;
        std::cout << "2.exit from the farmer page" << endl;
        std::cout << "-------------------------------------------------------------------------------------------" << endl;
        std::cin >> ExitContinue;
        if (ExitContinue != 1) // if he enter any other number it will exit
        {
            exit = true;
        }
    }
}

// function to search for a farmer by his id in a file
void searchFarmerById(int targetId)
{
    std::ifstream file("FarmerInformation.csv");

    if (!file.is_open())
    {
        std::cerr << "Error opening file FarmerInformation.csv " << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line))
    {
        std::istringstream iss(line);
        std::string token;

        // Read the first token (ID)
        if (std::getline(iss, token, ','))
        {
            int id = std::stoi(token);

            if (id == targetId)
            {
                // Found the farmer, print information
                std::cout << "ID: " << id << std::endl;

                // Read and print the rest of the information
                while (std::getline(iss, token, ','))
                {
                    std::cout << token << std::endl;
                }

                // You can add additional processing or just return here if only the first match is needed
                return;
            }
        }
    }

    // Farmer with the given ID not found
    std::cout << "Farmer with ID " << targetId << " not found." << std::endl;
}

AvlTree *CheckCategory(string category)
{
    if (category == "cereals" || category == "Cereals")
    {
        return Cereals;
    }
    else if (category == "Fruits" || category == "fruits")
    {
        return Fruits;
    }
    else if (category == "Vegetables" || category == "vegetables")
    {
        return Vegetables;
    }
    else if (category == "Olives" || category == "olives")
    {
        return Olives;
    }
    else if (category == "dates" || category == "Dates")
    {
        return Dates;
    }
    else
    {
        return nullptr;
    }
}

void AdminPage()
{

    bool exit = false;
    int action;
    int ExitContinue;
    string category;
    int option;
    bool exitAccounts = false;
    Country obj;

    int month, year;
    cout << "enter month: ";
    std::cin >> month;
    cout << "enter year: ";
    std::cin >> year;

    while (!exit)
    {
        std::cout << "WELCOME, to the dashbord" << endl;
        std::cout << "1.See all farmer's accounts" << endl;
        std::cout << "2.Check on all sales of all farmers" << endl;
        std::cout << "3.See winners in the given(Area/ City/ Wilaya) " << endl;
        std::cout << "4.Penalities" << endl;
        std::cout << "5.Prize winner (Country winner)" << endl;
        std::cout << "6.Search of a specific farmer" << endl;
        std::cout << "Enter an option : ";
        std::cin >> action;
        switch (action)
        {
        case 1: // See all farmer's accounts
            std::cout << "Enter the category of the farmers you want to display [Cereals, Vegetables, Fruits, Dates, Olives] :" << endl;
            cin >> category;
            for (int i = 0; i < category.length(); ++i)
            {
                category[i] = tolower(category[i]);
            }
            while (!exitAccounts)
            {
                if (category == "cereals" || category == "vegetables" || category == "fruits" || category == "dates" || category == "olives")
                {
                    std::cout << "Choose an option" << endl;
                    std::cout << "1.Area" << endl;
                    std::cout << "2.City" << endl;
                    std::cout << "3.Wilaya" << endl;
                    std::cin >> option;

                    if (option == 1)
                    {
                        string areaName;
                        std::cout << "enter the area you want to display its farmers" << endl;
                        std::cin >> areaName;
                        AvlTree *target = CheckCategory(category);
                        target->PrintFarmerByArea(areaName, year, month);
                    }
                    else if (option == 2)
                    {
                        string cityName;
                        std::cout << "enter the city you want to display its farmers" << endl;
                        std::cin >> cityName;
                        AvlTree *target = CheckCategory(category);
                        target->PrintFarmerByCity(cityName, year, month);
                    }
                    else if (option == 3)
                    {
                        // call the function of print all farmers of the wilaya class passing category
                        string wilayaName;
                        std::cout << "enter the wilaya you want to display its farmers" << endl;
                        std::cin >> wilayaName;
                        AvlTree *target = CheckCategory(category);
                        target->PrintFarmerByWilaya(wilayaName, year, month);
                    }
                    else if (option == 4)
                    {
                        // call the function of print all farmers of the country class passing category
                        PrintAllSalesFarmers(category, year, month);
                    }
                    else
                    {
                        std::cout << "the character you have just enter doesn't match any option" << endl;
                    }
                }
                else
                {
                    cerr << "the category you have just enter doesn't match any of the categories we manage" << endl;
                    exitAccounts = true;
                }
            }
            std::cout << "1.continue, Do want to see All farmer's account in an other level ?" << endl;
            std::cout << "2.switch to an other action" << endl;
            cin >> ExitContinue;
            if (ExitContinue != 1) // if he enter any other number it will exit
            {
                exitAccounts = true;
            }
        case 2: // Check on all sales of all farmers
            PrintAllSalesFarmers(year, month);
            break;
        case 3: // See winners in the given(Area/ City/ Wilaya)
            std::cout << "Enter the category of the winner you want to display [Cereals, Vegetables, Fruits, Dates, Olives] :" << endl;
            cin >> category;
            for (int i = 0; i < category.length(); ++i)
            {
                category[i] = tolower(category[i]);
            }
            int optionLocation1;
            std::cout << "enter the location that you are looking for its winner, Area  or  City or Wilaya" << endl;
            std::cout << "1.Area" << endl;
            std::cout << "2.City" << endl;
            std::cout << "3.Wilaya" << endl;
            std::cin >> optionLocation1;

            if (optionLocation1 == 1)
            {
                string areaName;
                std::cout << "enter the area you want to display its winner" << endl;
                cin >> areaName; // check if it exist
                Area area_obj;
                Farmer *area_winner = area_obj.findWinnerArea(CheckCategory(category), areaName);
                cout << "Winner of " << areaName << " is: Farmer " << area_winner->GetId() << " " << area_winner->GetName() << endl;
            }
            else if (optionLocation1 == 2)
            {
                string cityName;
                std::cout << "enter the city you want to display its winner" << endl;
                cin >> cityName; // check if it exist
                City C2_obj;
                Farmer *city_winner = C2_obj.findWinnerCity(cityName, CheckCategory(category));
                cout << "Winner of " << cityName << " is: Farmer " << city_winner->GetId() << " " << city_winner->GetName() << endl;
            }
            else if (optionLocation1 == 3)
            {
                string wilayaName;
                std::cout << "enter the wilaya you want to display its winner" << endl;
                cin >> wilayaName; // check if it exist
                Wilaya W2_obj;
                Farmer *wilaya_winner = W2_obj.findWinnerWilaya(wilayaName, CheckCategory(category));
                cout << "Winner of " << wilayaName << " is: Farmer " << wilaya_winner->GetId() << " " << wilaya_winner->GetName() << endl;
            }
            else
            {
                break;
            }
            break;

        case 4: // Penalities

            std::cout << "Enter the category of the farmers you want to display [Cereals, Vegetables, Fruits, Dates, Olives] :" << endl;
            cin >> category;
            for (int i = 0; i < category.length(); ++i)
            {
                category[i] = tolower(category[i]);
            }
            int optionLocation;
            std::cout << "enter the location that you are looking for (Area/City/Wilaya):" << endl;
            std::cout << "1.Area" << endl;
            std::cout << "2.City" << endl;
            std::cout << "3.Wilaya" << endl;
            std::cout << "4.Country" << endl;
            cin >> optionLocation;

            if (optionLocation == 1)
            {
                string areaName;
                std::cout << "enter the area you want to display its record of penalities:" << endl;
                cin >> areaName; // check if it exist
                Area A3_obj;
                cout << "---------List of pinalities of " << areaName << " :----------" << endl;
                A3_obj.PrintPinalitiesFarmersArea(CheckCategory(category), areaName);
            }
            else if (optionLocation == 2)
            {
                string cityName;
                std::cout << "enter the city you want to display its record of penalities:" << endl;
                cin >> cityName; // check if it exist
                City C3_obj;
                cout << "---------List of pinalities of " << cityName << " :----------" << endl;
                C3_obj.PrintPinalitiesFarmersCity(cityName, CheckCategory(category));
            }
            else if (optionLocation == 3)
            {
                string wilayaName;
                std::cout << "enter the wilaya you want to display its record of penalities:" << endl;
                cin >> wilayaName; // check if it exist
                Wilaya W3_obj;
                cout << "---------List of pinalities of " << wilayaName << " :----------" << endl;
                W3_obj.PrintPinalitiesFarmersWilaya(wilayaName, CheckCategory(category));
            }
            else if (optionLocation == 4)
            {

                obj.PrintPinalitiesFarmersCountry(CheckCategory(category));
            }
            else
            {
                break;
            }
            break;
        case 5:
            std::cout << "Enter the category of the winner you want to display [Cereals, Vegetables, Fruits, Dates, Olives] :" << endl;
            cin >> category;
            for (int i = 0; i < category.length(); ++i)
            {
                category[i] = tolower(category[i]);
            }

            obj.findWinnerCountry(CheckCategory(category));

            break;
        case 6: // Search of a specific farmer in file
            Farmer foundFarmer;

            // Search by ID
            int targetId;
            std::cout << "Enter farmer ID to search: ";
            cin >> targetId;

            searchFarmerById(targetId);

            break;
        }

        std::cout << "1.continue searching in the farmer page" << endl;
        std::cout << "2.exit from the farmer page" << endl;
        cin >> ExitContinue;
        if (ExitContinue != 1) // if he enter any other number it will exit
        {
            exit = true;
        }
    }
}

int main()
{

    auto start = high_resolution_clock::now(); // Record the start time

    ifstream farmer_file("FarmerInformation.csv");
    ifstream monthly_file("MonthlyReport.csv");
    vector<Farmer> list;
    vector<MonthlyReport> list2;

    AvlTree TREE;

    if (!farmer_file.is_open() || !monthly_file.is_open())
    {
        cerr << "Error opening file." << endl;
        return 1;
    }

    std::cout << "file opened" << endl;

    int targetYear, targetMonth;
    cout << "Enter target year: ";
    cin >> targetYear;
    cout << "Enter target month: ";
    cin >> targetMonth;

    string line1;

    // READING FARMER AND MONTHLY FILE TO INSERT INTO THE BINARY SEARCH TREE
    while (getline(farmer_file, line1))
    {
        vector<string> tokens = split(line1, ',');
        if (tokens.size() == 8)
        {
            int id = stoi(tokens[0]);
            string name = tokens[1];
            int age = stoi(tokens[2]);
            string gender = tokens[3];
            int landID = stoi(tokens[4]);
            string wilaya = tokens[5];
            string city = tokens[6];
            string area = tokens[7];
            Farmer test(id, name, age, gender, landID, wilaya, city, area);
            list.push_back(test);

            monthly_file.clear();
            monthly_file.seekg(0, ios::beg);

            string line2;
            while (getline(monthly_file, line2))
            {

                vector<string> tokens = split(line2, ',');
                if (tokens.size() == 16)
                {
                    int Monthlyid = stringToInt(tokens[0]);
                    int month = stringToInt(tokens[14]);
                    int year = stringToInt(tokens[15]);

                    if (year == targetYear && month == targetMonth)
                    {

                        if (Monthlyid == id)
                        {

                            int NumHelpers = stringToInt(tokens[1]);

                            int ProducesFruits = stringToInt(tokens[2]);
                            double SalesFruits = stringToDouble(tokens[7]);

                            int ProducesVegetables = stringToInt(tokens[3]);
                            double SalesVegetables = stringToDouble(tokens[8]);

                            int ProducesCereals = stringToInt(tokens[4]);
                            double SalesCereals = stringToDouble(tokens[9]);

                            int ProducesDates = stringToInt(tokens[5]);
                            double SalesDates = stringToDouble(tokens[10]);

                            int ProducesOlives = stringToInt(tokens[6]);
                            double SalesOlives = stringToDouble(tokens[11]);

                            double WaterCons = stringToDouble(tokens[12]);
                            double ElectricityCons = stringToDouble(tokens[13]);
                            MonthlyReport monthTest(Monthlyid, NumHelpers, ProducesFruits, ProducesVegetables, ProducesCereals, ProducesDates, ProducesOlives, SalesFruits, SalesVegetables, SalesCereals, SalesDates, SalesOlives, WaterCons, ElectricityCons, month, year);

                            if (ProducesFruits == 1)
                            {
                                monthTest.SetProduct("Fruits");
                                monthTest.SetSales(SalesFruits);
                                Fruits->insert(test);
                            }

                            else if (ProducesVegetables == 1)
                            {
                                monthTest.SetProduct("Vegetables");
                                monthTest.SetSales(SalesVegetables);
                                Vegetables->insert(test);
                            }

                            else if (ProducesCereals == 1)
                            {
                                monthTest.SetProduct("Cereals");
                                monthTest.SetSales(SalesCereals);
                                Cereals->insert(test);
                            }

                            else if (ProducesDates == 1)
                            {
                                monthTest.SetProduct("Dates");
                                monthTest.SetSales(SalesDates);
                                Dates->insert(test);
                            }

                            else if (ProducesOlives == 1)
                            {
                                monthTest.SetProduct("Olives");
                                monthTest.SetSales(SalesOlives);
                                Olives->insert(test);
                            }
                            else
                            {
                                continue;
                            }

                            list2.push_back(monthTest);
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
        else
        {
            cerr << "Error parsing lines." << endl;
        }
    }

    monthly_file.close();
    farmer_file.close();

    // START
    bool exit = false;
    int choicePage;
    int ExitContinue;
    string category;
    Country obj;

    while (!exit)
    {
        std::cout << "-------------------WELCOME TO THE AGRICULTURAL PRODUCTION MANAGEMENT SYSTEM-------------------" << endl;
        std::cout << "" << endl;
        std::cout << "1.Home page" << endl;
        std::cout << "2.Farmer Interface" << endl;
        std::cout << "3.Admin page(APMS)" << endl;
        std::cout << "Please choose one page!" << endl;
        std::cin >> choicePage;
        switch (choicePage)
        {
        case 1: // HOME PAGE
            std::cout << "-----Home page-----" << endl;
            cout << "Enter the category you wish to know its winner (cereals/fruits/vegetables/dates/olives): ";
            std::cin >> category;
            std::cout << "the winner of the country is: " << endl;
            obj.findWinnerCountry(CheckCategory(category));
            cout << endl;
            break;
        case 2: // FARMER INTRFACE
            std::cout << "-----Farmer Interface-----" << endl;
            FarmerInterface();
            cout << endl;
            break;
        case 3: // ADMIN PAGE
            std::cout << "-----Admin page(APMS)-----" << endl;
            AdminPage();
            cout << endl;
            break;
        default:
            break;
        }
        cout << endl;
        std::cout << "1.continue" << endl;
        std::cout << "2.log out" << endl;
        cout << endl;
        std::cin >> ExitContinue;
        if (ExitContinue != 1) // if he enter any other number it will exit
        {
            exit = true;
        }
    }

    auto stop = high_resolution_clock::now();                  // Record the stop time
    auto duration = duration_cast<milliseconds>(stop - start); // Calculate the duration in milliseconds

    cout << "Program execution time: " << duration.count() << " milliseconds" << endl;

    return 0;
}
