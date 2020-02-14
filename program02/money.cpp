/*
SUDIP GHALE
CSE 1325-003
HW-02: PROBLEM 03
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
This is the first class. it has  private helper function printGreetings to print the welcome message
in public it has one constructor to get amount and unit to convert if matched, provides the exchange.
also it has getter function to get the total ABC has exchanged.
*/
class ABC
{
    string manager, unit;
    double inAmount, outAmount, totalABC=0;

    void printGreetings(string name)
    {
        cout<<"Welcome to ABC Conversions. Please contact the manager "<<name<<" if you have any complaints."<<endl;
        cout<<"What currency are you converting to dollars and how much?"<<endl;

    }
public:

    ABC(string name)
    {
        manager=name;

        printGreetings(manager);
        cin>>inAmount>>unit;

        if(unit.compare("yen")==0)
        {
            outAmount=inAmount* 0.0089;
            cout<<"Here you go: $"<<outAmount<<"."<<endl;
            totalABC+=outAmount;
        }
        else
        {
            cout<<"We are very sorry, we do not have the "<<unit<<" currency here."<<endl;
        }
    }
    double get_totalABC()
    {
        return totalABC;
    }

};

/*
This is the second class. it has  private helper function printGreetings to print the welcome message
in public it has one constructor to get amount and unit to convert if matched, provides the exchange.
also it has getter function to get the total DEF has exchanged.
*/

class DEF
{
       string manager, unit;
    double inAmount, outAmount, totalDEF=0;


    void printGreetings(string name)
    {
        cout<<"\nWelcome to DEF Conversions. Please contact the manager "<<name<<" if you have any complaints."<<endl;
        cout<<"What currency are you converting to dollars and how much?"<<endl;

    }
    public:

    DEF(string name)
    {
        manager=name;

        printGreetings(manager);
        cin>>inAmount>>unit;

        if(unit.compare("dinar")==0)
        {
            outAmount=inAmount* 0.00084;
            cout<<"Here you go: $"<<outAmount<<"."<<endl;
            totalDEF+=outAmount;
        }
        else
        {
            cout<<"We are very sorry, we do not have the "<<unit<<" currency here."<<endl;
        }
    }

    double get_totalDEF()
    {
        return totalDEF;
    }
};

/*
In main first it gets the branch and the managers name then it calls the relevant branch based on  the Location of the traveler.
every time the Traveler gets the money exchanged the amount is added to totalDispenced variable which is printed at the end while exiting.

*/
int main()
{
    double totalDispenced=0;
    string where=" ";
    string branch, manager, branchB, managerB;

    cout<<"Enter name of exchange office and the manager:"<<endl;
    cin>>branch>>manager;
    cout<<"Enter name of exchange office and the manager:"<<endl;
    cin>>branchB>>managerB;

    while(where.compare("exit")!=0)
    {
        cout << "***********\n" <<"Hello traveler! Where are you in the airport(North ...)?\n\n"<< "*******"<<endl;
       cin>>where;

        if(where.compare("North")==0 || where.compare("East")==0)
        {
            ABC m1(manager);
            cout<<"\n"<<endl;
            totalDispenced+=m1.get_totalABC();
            break;
        }
        if(where.compare("West")==0 || where.compare("South")==0)
        {
            DEF m2(managerB);
            cout<<"\n"<<endl;
            totalDispenced+=m2.get_totalDEF();
            break;
        }
    }

        if(where.compare("exit")==0)
        {
            cout<<"$$$ Total dollars given out: $"<<totalDispenced<<"."<<endl;
            cout<<"Exiting....."<<endl;
        }
    return 0;
}
