/*******************************************************************
    This is the implementation file for the Check class. For more 
information about the class see check.h.
    Students are expected to implement some of the functions shown 
below.
	John Dolan	Ohio University		September 2019
******************************************************************/
#include "check.h"
#include"checkbook.h"

using namespace std;

Check::Check(Date d, string p, int num,double amt)
{
	checknum = num;
	date = d;
	payto = p;
	amount = amt;
}

// INPUT AND OUTPUT FUNCTIONS
void Check::write_check(std::istream& ins)
{    
    string line;

    if(&ins == &cin)
    {
        cout << "Please enter the check number for this check: ";
        ins >> checknum;
        cout << endl;
        cout << "Please enter the date of the check: ";
        ins >> date;
        cout << endl;
        cout << "Please enter the name of the person the check is being paid to: ";
        getline(ins, line);
        getline(ins, payto);
        cout << endl;
        cout << "Please enter the amount that the check is being written: $";
        ins >> amount;
        cout << endl;

        cout << checknum << " : " << date << " : " << payto << " : " << amount << endl;
    }else
    {
        ins >> checknum;
        ins >> date;
        getline(ins, line);
        getline(ins, payto);
        ins >> amount;
        cout << checknum << " : " << date << " : " << payto << " : " << amount << endl;
    }
    
    /* You are to write the implementation of this function to read 
    from the keyboard or a file. Remember to use getline to read the 
    payto.  */

}

void Check::output(std::ostream& outs)const
{
    if (&outs == &cout){
        outs << "Checknumber: " << get_num() << endl;
        outs << "Date: " << get_date() << endl;
        outs << "Who the check is made out for: " << get_payto() << endl;
        outs << "The amount the check is written for: $" << get_amount() << endl;
    } else {
        outs << get_num() << endl;
        outs << get_date() << endl;
        outs << get_payto() << endl;
        outs << get_amount();
    }
    /* You are to write the implementation of this function to write 
    to the monitor or to a file. Remember not to put labels into the 
    file.*/
}

ostream& operator << (ostream& outs, const Check& c)
{
    c.output(outs);
    return outs;
}

istream& operator >> (istream& ins, Check& c)
{
    c.write_check(ins);
    return ins;
}
