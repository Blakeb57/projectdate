/***********************************************************************
	The implementation file for the date class including the 
	implementation of overloaded insertion and extraction and
	comparison operators.
	John Dolan			September 2005
		OHIO UNIVERSITY SCHOOL OF EECS
*************************************************************************/

#include "date.h"

using namespace std;

//DEFAULT CONSTRUCTOR   
Date::Date()
{
    day = month = year = 1;

    //PERMISSABLE DAYS FOR EACH MONTH ARE LOADED INTO AN ARRAY
    daysallowed[0] = 0;
    daysallowed[1] = 31;
    daysallowed[2] = 29;
    daysallowed[3] = 31;
    daysallowed[4] = 30;
    daysallowed[5] = 31;
    daysallowed[6] = 30;
    daysallowed[7] = 31;
    daysallowed[8] = 31;
    daysallowed[9] = 30;
    daysallowed[10] = 31;
    daysallowed[11] = 30;
    daysallowed[12] = 31;
}

//CONSTRUCTOR THAT TAKES THREE ARGUMENTS
Date::Date(int d, int m, int y): day(d), month(m), year(y)
{
    //PERMISSABLE DAYS FOR EACH MONTH ARE LOADED INTO AN ARRAY
	 daysallowed[0] = 0;
	 daysallowed[1] = 31;
	 daysallowed[2] = 29;
	 daysallowed[3] = 31;
	 daysallowed[4] = 30;
	 daysallowed[5] = 31;
	 daysallowed[6] = 30;
	 daysallowed[7] = 31;
	 daysallowed[8] = 31;
	 daysallowed[9] = 30;
	 daysallowed[10] = 31;
	 daysallowed[11] = 30;
	 daysallowed[12] = 31;
}

//OUTPUT OPERATOR, OVERLOADED AS A FRIEND FUNCTION
ostream& operator << (ostream& outs, Date d)
{
    outs << d.month << '/' << d.day << '/' << d.year;
    return outs;
}

//INPUT OPERATOR, OVERLOADED AS A FRIEND
istream& operator >> (istream& ins, Date d)
{
    bool flag = false;
    string junk;

    ins >> d.month;

    //IF AN INVALID MONTH IS DETECTED THROW A bad_month
    if(d.month < 1 || d.month > 12)
    {
        getline(ins, junk); //EAT THE REST OF THE LINE
        throw(bad_month(d.month);
    }

    if(ins.eof()) return ins;
    if(ins.peek() == '/') ins.ignore();

    ins >> d.year;
    return ins;
}

//RETURN WHETHER OR NOT d1 IS GREATER THAN d2
bool operator > (const Date& d1, const Date& d2)
{
    if(d1.year != d2.year)
    {
        return (d1.year > d2.year);
    }else if(d1.month != d2.month)
    {
        return (d1.month > d2.month);
    }else
    {
        return (d1.day > d2.day);
    }
}

//RETURN WHETHER OR NOT D1 IS LESS THAN D2
bool operator < (const Date& d1, const Date& d2)
{
    if(d1.year != d2.year)
    {
        return (d1.year < d2.year);
    }else if(d1.month != d2.month)
    {
        return (d1.month < d2.month);
    }else
    {
        return (d1.day < d2.day);
    }
}

//RETURN WHETHER OR NOT d1 EQUALS d2
bool operator == (const Date& d1, const Date& d2)
{
    return (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day);
}

//RETURN WHETHER OR NOT d1 IS NOT EQUAL TO d2
bool operator != (const Date& d1, const Date& d2)
{
    return (!(d1.year == d2.year && d1.month == d2.month && d1.day == d2.day));
}

//RETURN WHETHER OR NOT d1 IS LESS THAN OR EQUAL TO d2
bool operator <= (const Date& d1, const Date& d2)
{
    return (d1 == d2 || d1 < d2);
}

//RETURN WHETHER OR NOT d1 IS GREATER THAN OR EQUAL TO d2
bool operator >= (const Date& d1, const Date& d2)
{
    return (d1 == d2 || d1 > d2);
}