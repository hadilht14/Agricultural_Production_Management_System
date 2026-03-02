#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
    Date(){};
    void SetDate(int y = 1, int m = 1, int d = 1990)
    {
        if (m >= 1 && m <= 12)
        {
            month = m;
        }
        else
        {
            cout << "enter again" << endl;
        }
        if (d >= 1 && d <= 31)
        {
            day = d;
        }
        else
        {
            cout << "enter again" << endl;
        }

        year = y;
    };
    void set_day(int d = 1)
    {
        cout << "enter the day" << endl;
        cin >> d;
        if (d >= 1 && d <= 31)
        {
            day = d;
        }
        else
            cout << "please enter the appropriate value \n"
                 << endl;
    };
    void set_month(int m = 1)
    {
        month = m;
    };
    void set_year(int y = 1990)
    {
        year = y;
    };
    int get_day()
    {
        return day;
    };
    int get_month()
    {
        return month;
    };
    int get_year()
    {
        return year;
    };
    void print()
    {
        cout << day << "-" << month << "-" << year << endl;
    };
    bool IsLeapYear()
    {
        if ((year % 4 == 0 || year % 400 == 0) && year % 100 != 0)
        {
            return 1;
        }
        else if (year % 100 == 0)
        {
            return 0;
        }
        else if (year % 400 == 0)
        {
            return 1;
        }
        else
            return 0;
    };
    int monthDays()
    {
        if (!IsLeapYear())
        {
            if (month == 2)
                return 28;
            else if (month == 4 || month == 6 || month == 9 || month == 11)
                return 30;
            else
                return 31;
        }
        else
        {
            if (month == 2)
                return 29;
            else if (month == 4 || month == 6 || month == 9 || month == 11)
                return 30;
            else
                return 31;
        }
    };
    Date nextDay()
    {
        int month_day = monthDays();
        // cout<<"month_day "<<month_day<<endl;
        if (month == 2 && day == 28)
        {
            if (!IsLeapYear())
            {
                day = 1;
                month += 1;
            }
            else
            {
                day = 29;
            }
        }

        else if (month == 2 && day == 29)
        {
            day = 1;
            month += 1;
        }
        else if (month == 12 && day == 31)
        {
            month = 1;
            day = 1;
            ++year;
        }
        else if (month_day == 30 && day == 30)
        {
            day = 1;
            month += 1;
        }
        else if (month_day == 31 && day == 31)
        {
            day = 1;
            month += 1;
        }

        else
        {
            if (month == 2 && day > 29)
            {
                cout << "error" << endl;
            }
            else if (month_day == 30 && day > 30)
            {
                cout << "error" << endl;
            }
            else if (month_day == 31 && day > 31)
            {
                cout << "error" << endl;
            }
            else
            {
                day += 1;
            }
        }
        print();
    };

private:
    int day;
    int month;
    int year;
    double Sales;
};