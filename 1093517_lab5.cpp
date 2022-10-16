#include<iostream>
#include<string>
#include"Date.cpp"
#include"Date.h"
using namespace std;
class Employee
{
public:
Employee( const string &, const string &, const Date &, const Date &, Date &, int );
void print() const;
Employee &eDismiss(Date &);
Employee &increaseSalary(int);
~Employee(); // provided to confirm destruction order
private:
string firstName; // composition: member object
string lastName; // composition: member object
const Date birthDate; // composition: member object
Date hireDate; // composition: member object
Date dismissDate;
int monSalary;
}; // end class Employee
Employee::Employee( const string &first, const string &last, const Date &dateOfBirth, const Date &dateOfHire,Date &dismissOfDate, int monOfSalary )
    :firstName (first),
    lastName (last),
    birthDate (dateOfBirth),
    hireDate(dateOfHire),
    dismissDate(dismissOfDate)
{
    monSalary = monOfSalary;
    cout << "Employee object constructor " <<firstName<< ' ' << lastName << ' ' << "Monthly paid " << monSalary <<endl;
    if ( !birthDate.checkdate(hireDate) )
    {
        cout << firstName << " " << lastName << " with inconsistent dates! " <<endl;
    }
    else if ( !hireDate.checkdate(dismissDate) )
    {
        cout << firstName << " " << lastName << " with inconsistent dates! " <<endl;
    }
}
void Employee::print() const
{
    cout << firstName << " " << lastName << "Hired:";
    hireDate.print();
    cout << " Birthday: ";
    birthDate.print();
    cout << " Monthly pay: ";
    cout << monSalary <<"   ";
    cout << "Dismissing: ";
    dismissDate.print();
    cout << endl;
}
Employee &Employee::eDismiss(Date &dateOfdismiss)
{
    if(!dismissDate.checkdate(dateOfdismiss))
    {
        cout << firstName << " " << lastName << " with inconsistent dates! " << endl;
    }
    dismissDate = dateOfdismiss;
    return *this;
}
Employee &Employee::increaseSalary(int x)
{
    monSalary += x;
    return *this;
}
Employee::~Employee()
{
    cout << "Employee object destructor:" << firstName << " " << lastName << endl;
}
int main()
{

Date birth( 3, 24, 1961 );
Date hire( 4, 12, 1998 );
Date dismiss(2, 28, 2021);
Date zero;
Employee manager1( "Tom", "Crouse", birth, hire, zero, 66000 );
cout << endl;
manager1.print();
manager1.increaseSalary(2000).print();
manager1.eDismiss(dismiss).print();
cout << "\nTest Date constructor with invalid values:\n";
Date lastDayOff( 14, 35, 1994 ); // invalid month and day
cout << endl;
cout <<endl;

Date birth1( 1, 1, 1968 );
Date hire1( 1, 1, 1994 );
Date dismiss1(3, 28, 1990);
Employee E1( "Mary", "Hunton", birth1, hire1, dismiss1, 45000 );
cout << endl;
Date dismiss2(3,28, 2000);
E1.eDismiss(dismiss2).print();
E1.increaseSalary(-2000).print();
} // end main