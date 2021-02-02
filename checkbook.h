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

        //OPERATORS
        Checkbook operator + (const Checkbook& b1)const;

        //SETTERS
        void load_from_file(std::istream& ins);                 //opens a user's file and reads in the info
        void show_all(std::ostream& outs)const;                 //shows all checks written
        void deposit(std::istream& ins);                        //takes in the amount of $ depositted
        void save(std::ostream& outs)const;                     //saves all changes to user's account after ending of program
        void remove(const std::istream& rmnum);                 //removes a check that has been cancelled
        void number_sort();                                     //sorts by the number a check has
        void payto_sort();                                      //sorts alphabetically for who to pay the check/ checks to
        void date_sort();                                       //sorts by the date of the check
        void show(const Check& target);                         //finds all checks written to a certain individual
        void average();                                         //finds the average of all checks written

        //ACCESSORS
        int get_balance() const{return balance;}          //holds the total amount of $ in the checking account

    private:
        double balance;
        int next;
        size_t used;
        Check Checks[CAPACITY];
        Check amount;

};

#endif