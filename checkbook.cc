#include "checkbook.h"

using namespace std;

//CONSTRUCTORS
Checkbook::Checkbook()
{
    next = 2;
    balance = 0;
    used = 0;
}

Checkbook Checkbook::operator + (const Checkbook& b1)const
{
    Checkbook tmp;
    tmp.balance = balance + b1.balance;
    return tmp;
}

void Checkbook::load_from_file(std::istream& ins)
{
    string line;
    Check tmp;

    while(!ins.eof())
    {
        tmp.write_check(ins);
        Checks[used] = tmp;
        used++;
    }
}

void Checkbook::deposit(std::istream& ins)
{
    string line;
    Check tmp;
    getline(ins, line);
}