/*
Sudip Ghale (1001557881)
Cse1325-003
HW03: program 01 chilli.cpp
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

/* there are three class in this program*/

/* Person is the first class, it has two variable for name and the size of the customer and
one constructor*/
class Person{
public:
    string fName;
    string sizeC;
    Person(string n, string s)
    {
        fName=n;
        sizeC=s;
    }


};

/* Customer is the second class, it has vector variable.
it has one constructor and one add_Customer funtion*/
class Customers{
public:
    vector< Person> cList;
    Customers ()
    {

    }
    void add_Customer(Person p)
    {
        cList.push_back(p);
    }



};

/* Chili is the third class, it has cups int variable. it has one constructor.
and one function , subChili which returns int value depending upon the size of the cup passed*/
class Chili{
public:
    int cups;

    Chili (int batches)
    {
        cups=4*batches;
    }

    int subChili(string sizeC)
    {

        if(sizeC=="Grande"|| sizeC=="grande")
        {
            return 4;
        }
        if(sizeC=="Tall"|| sizeC=="tall")
        {
            return 3;
        }
        if(sizeC=="Short"|| sizeC=="short")
        {
            return 2;
        }
        if(sizeC=="Small"|| sizeC=="small")
        {
            return 1;
        }

    }


};

/* the main has command argument to read the inFile*/
int main(int argc, char ** argv)
{
    int ans, i=0;
    string answer="go";
    ifstream inFile;
    string fName, sizeC;

    Customers c1;

    cout<<endl<<"***Welcome Louise***"<<endl<<endl;
    inFile.open(argv[1]);

    if(!inFile.is_open()) /* prints error message if file is not opened*/
    {
        cout<<"Unable to open file :"<<argv[1]<<endl;
        exit(1);
    }

    while(!inFile.eof())/* reads in the line and creates the person then add to the customer vectoer*/
    {
        inFile>>fName>>sizeC;
        Person p1(fName, sizeC);
        c1.add_Customer(p1);

    }
    cout<<"Checking today's customers done...."<<endl<<endl;
    cout<<"How many batches of your famous chili are you making today ???"<<endl;
    cin>>ans;

    Chili ch1(ans);
    cout<<endl<<"Starting orders....."<<endl<<endl;

    while(answer!="quit")/*the loop runs until the user enter quit*/
    {
        cout<<"Customer "<<i+1<<": "<<c1.cList[i].fName<<"'s order is "<<c1.cList[i].sizeC<<endl;
       if(ch1.cups >= ch1.subChili(c1.cList[i].sizeC))/* if statement runs only if the available chilli is greater thean or equal to cup of the order*/
       {
            ch1.cups-=ch1.subChili(c1.cList[i].sizeC);
            i++;
           if(ch1.cups>=2)
            cout<<"Order served. Still got lots of Chili."<<endl;
           else
            cout<<"Order served. Not much chili left."<<endl;

           cout<<endl<<"Continue with the orders or take a break enter('continue' or 'break')???"<<endl;
           cin>>answer;
/* if break is entered then it prints that its on break then continue taking the reamining orders*/
        if (answer=="break"|| answer=="Break")
        {
            cout<<"OK! taking break, enter any letter to continue taking orders"<<endl;
	    cin>>answer;
	    if(answer!="c")
	        {

	       	}
	     continue;
        }
	else
	   continue;


    }
    else
    /* sorry message if not enoough chili and ask to make more chili */
        cout<<"Sorry, not enough chili. Would you like to make more chili???"<<endl;
        cin >>answer;

        if (answer=="batch"||answer=="yes")
        {
            cout<<"How many more batches you would like to make???"<<endl;
            cin>> ans;
            Chili ch2(ans);
            ch1.cups+=ch2.cups;
        }

    }



}
