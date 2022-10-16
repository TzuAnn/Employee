#ifndef DATE_H
#define DATE_H
class Date
{
    public:
    static const int monthsPerYear = 12; // number of months in a year
    Date( int = 1, int = 1, int = 1900 ); // default constructor
    void print() const; // print date in month/day/year format
    bool checkdate(Date &) const;
    ~Date(); // provided to confirm destruction order
    private:
    int month; // 1-12 (January-December)
    int day; // 1-31 based on month
    int year; // any year
    // utility function to check if day is proper for month and year
    int checkDay( int ) const;
}; // end class Date
#endif