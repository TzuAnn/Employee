#include<iostream>
#include"Date.h"
using namespace std;
Date::Date(int m, int d, int y)
{
    if ( m > 0 && m <= monthsPerYear )
    {
        month = m;
    }
    else
    {
        month = 1;
        cout << "Invalid month(" <<m << ")set to 1" <<endl;
    }
    year = y;
    day = checkDay(d);
    cout << "Date object constructer for date ";
    print();
    cout <<endl;
}
void Date::print() const
{
    cout << month << "/" << day << "/" << year;
}
bool Date::checkdate(Date &a) const
{
    if ( a.year == 1900 && a.month == 1 && a.day == 1 )
    {
        return true;
    }
    if ( a.year > year )
    {
        return true;
        // a is bigger
    }
    if ( a.year == year )
    {
        if ( a.month > month )
        {
            return true;
            // a is bigger
        }
        if ( a.month == month )
        {
            if ( a.day > day )
            {
                return true;
                // a is bigger
            }
        }
    }
    return false;
}
Date::~Date()
{
    cout << "Date object destructor ";
    print();
    cout << endl;
}
int Date::checkDay( int testday ) const
{
    static const int daysPerMonth[monthsPerYear+1] =
    {
        0,31,28,31,30,31,30,31,31,30,31,30,31
    };
    if ( testday > 0 && testday <= daysPerMonth[month])
    return testday;

    if ( testday == 2 && testday == 29 && ( year % 400 == 0  || (year % 4 == 0 && year % 100 != 0)))
        return testday;

        cout << "invalid day ("<<testday<<")set to 1 "<<endl;
        return 1;
    
}