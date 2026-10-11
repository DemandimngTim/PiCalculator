#include "input.h"

#include <iostream>


using namespace std;



int get_int()
{
    string input;

    getline(cin,input);


    try
    {
        return stoi(input);
    }
    catch(...)
    {
        return -1;
    }
}



string get_string()
{
    string s;
    getline(cin,s);

    return s;
}



bool get_yes_no()
{
    string s;

    getline(cin,s);


    return s=="y" ||
           s=="Y" ||
           s=="yes" ||
           s=="YES";
}
