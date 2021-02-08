//This is the header file for a checkbook class. It loads the information from a user's file
//It then allows the user to write more checks out as long as the check count doesn't 
//exceed 200 checks. It also allows the file to be sorted by the check number,
//who the checks are paid to (alphabetically), and can be sorted by the date in which
//the checks were written. The average amount paid can also be calculated,
//checks can be removed from the file and money can be depositted into the users account.
//When the program is ended all changes are saved to the file as well.
//Blake Boehringer 2/7/21
#include <iostream>
#include <ctype.h>
#include <string>

#include "check.h"
#include "date.h"

#ifndef CHECKBOOK
#define CHECKBOOK
class Checkbook
{
    public:

        static const size_t CAPACITY = 200;

        //DEFAULT ARGUMENTS
        Checkbook();

        //SETTERS
        void load_from_file(std::istream& ins);                 //opens a user's file and reads in the info
        void show_all(std::ostream& outs);                      //shows all checks written
        void deposit(double bdepamount);                        //takes in the amount of $ depositted
        void save(std::ostream& outs)const;                     //saves all changes to user's account after ending of program
        void remove(int rmnum);                  //removes a check that has been cancelled
        void number_sort();                                     //sorts by the number a check has
        void payto_sort();                                      //sorts alphabetically for who to pay the check/ checks to
        void date_sort();                                       //sorts by the date of the check
        void show(std::string& payto_find);                         //finds all checks written to a certain individual
        double average();                                         //finds the average of all checks written
        void write_check(std::istream& ins);

        //ACCESSORS
        double get_balance() const{return balance;}          //holds the total amount of $ in the checking account

    private:
        double balance;
        int next;
        size_t used;
        Check *Checks[CAPACITY];

};

#endif