/*******************************************************************
//   This class, Date, is designed for the storage of dates.
	It expects to receive all dates in the m/d/y format, and it 
	outputs them in the same format. There are no restrictions on
	the year, but if the momth entered falls outside the normal 
	bounds a bad_month exception is thrown. The input operator also
	checks the day entered against a list of permissable days in each
	month, and throws a bad_day exception if the day is outside 
	acceptable bounds. There is no mechanism for leap years so all
	Februaries are allowed 29 days. A full set of comparison operators
	is included with the class.
		John Dolan			September 2005
			OHIO UNIVERSITY SCHOOL OF EECS
******************************************************************/

#include <iostream>
#include <ctype.h>

#ifndef DATE
#define DATE
// AN EXCEPTION IF THE DATE ENTERED IS INVALID FOR THE MONTH

class bad_day
{
    public:
        bad_day(){monthnum = daynum = 0;}
        bad_day(int m, int d){monthnum = m, daynum = d;}
        void msg(){std::cerr << monthnum << " had no day " << daynum << std::endl;}

    private:
        int monthnum, daynum;
};

//AN EXCEPTIONFOR AN INVALID MONTH NUMBER
class bad_month
{
    public:
        bad_month(){monthnum = 0;}
        bad_month(int m){monthnum = m;}
        void msg(){std::cerr << monthnum << " is an invalid month number. \n";}

    private:
        int monthnum;
};

//A SIMPLE CLASS FOR HOLDING DATES
class Date
{
    public:
        Date();
        Date(int d, int m, int y);

        //OUTPUTS THE DATE
        friend std::ostream& operator << (std::ostream& outs, Date d);
        //INPUTS THE DDATE
        friend std::istream& operator >> (std::istream& ins, Date& d);

        /**************************************************
        COMPARSION OPERATORS
        **************************************************/
       friend bool operator > (const Date& d1, const Date& d2);
       friend bool operator < (const Date& d1, const Date& d2);
       friend bool operator == (const Date& d1, const Date& d2);
       friend bool operator != (const Date& d1, const Date& d2);
       friend bool operator <= (const Date& d1, const Date& d2);
       friend bool operator >= (const Date& d1, const Date& d2);

    private:
        int day;
        int month;
        int year;
        int daysallowed[13];
};

#endif