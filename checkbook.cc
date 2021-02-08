#include "checkbook.h"
#include "date.h"
#include <iostream>
#include <algorithm>
#include <array>
#include <bits/stdc++.h>

using namespace std;

//CONSTRUCTORS
Checkbook::Checkbook()
{
    next = 1;
    balance = 0;
    used = 0;
}

void Checkbook::load_from_file(std::istream& ins)
{
    string line;
    Check *tmp;
    ins >> balance;
    getline(ins, line);
    getline(ins, line);

    while(!ins.eof())
    {
        tmp = new Check;

        tmp -> write_check(ins);
        Checks[used] = tmp;
        used++;
        next++;
    }
}

void Checkbook::deposit(double depamount)
{
    for(std::size_t i = 0; i < used; ++i)
    {
        balance = balance + depamount;
        balance = balance - Checks[i]->get_amount();
    }
    cout << "Your currrent balance: $" << balance << endl;
}

void Checkbook::write_check(std::istream& ins)
{
    string line;
    Check *tmp;
    tmp = new Check;

    if(used < CAPACITY)
    {
        tmp -> set_check_num(used+1);
        tmp -> write_check(ins);
        Checks[used] = tmp;
        used++;
        next++;
    }else
    {
        cout << "Sorry, list capacity for number of checks allowed has been reached" << endl;
    }
}

void Checkbook::show_all(std::ostream& outs)
{
    for(std::size_t i = 0; i < used; ++i)
    {
        outs << *Checks[i] << endl;
    }
    outs << "Next available check number: " << next << endl;
}

void Checkbook::remove(int rmnum)
{
    int index = -1;

    for(std::size_t i = 0; i < used; ++i)
    {
        if(rmnum == Checks[i]->get_num())
        {
            index = i;
        }
    }

    if(index != -1)
    {
        used--;
        Checks[index] = Checks[used];
        next++;
    }else
    {
        cout << rmnum << "The check you were looking for was not found in the list. " << endl;
    }
    
}

void Checkbook::number_sort()
{
    bool done = false;
    Check *tmp;

    while(!done)
    {
        done = true;

        for(std::size_t j = used - 1; j > 0; --j)
        {
            if(Checks[j]->get_num() < Checks[j-1]->get_num())
            {
                done = false;
                tmp = Checks[j];
                Checks[j] = Checks[j-1];
                Checks[j-1] = tmp;
            }
        }
    }
}

void Checkbook::payto_sort()
{
    Check *tmp;
    bool done = false;

    while(!done)
    {
        done = true;
        for(std::size_t j = 1; j < used; ++j)
        {
            if(Checks[j]->get_payto() < Checks[j-1]->get_payto())
            {
                done = false;
                tmp = Checks[j];
                Checks[j] = Checks[j-1];
                Checks[j-1] = tmp;
            }
        }
    }
}

void Checkbook::date_sort()
{
    bool done = false;
    Check *tmp;

    while(!done)
    {
        done = true;

        for(std::size_t j = used - 1; j > 0; --j)
        {
            if(Checks[j]->get_date() < Checks[j-1]->get_date())
            {
                done = false;
                tmp = Checks[j];
                Checks[j] = Checks[j-1];
                Checks[j-1] = tmp;
            }
        }
    }
}

double Checkbook::average()
{
    double average = 0;

    for(std::size_t i = 0; i < used; ++i)
    {
        average =  average + Checks[i]->get_amount();
        average = average / used;
    }
    return average;
}

void Checkbook::show(std::string& payto_find)
{
    int total = 0;
    int index = -1;

    for(std::size_t i = 0; i < used; ++i)
    {
        if(payto_find == Checks[i] -> get_payto())
        {
            total += Checks[index]->get_amount();
            index = i;
            cout << *Checks[index] << endl;
            cout << "Total amount of all checks written to this name: $" << total << endl;
        }
    }

    if(index == -1)
    {
        cout << payto_find << "The check you were looking for was not found in the list. " << endl;
    }
}

void Checkbook::save(std::ostream& outs)const
{
    outs << balance << endl << endl;
    
    for(std::size_t i = 0; i < used; ++i)
    {
        if(i == used - 1)
        {
            outs << *Checks[i];
        }else
        {
            outs << *Checks[i] << endl;
        }
    }
}