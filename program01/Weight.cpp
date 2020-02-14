
/*
SUDIP GHALE
HW-01, PROGRAM1
09-04-2918
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <iomanip>



using namespace std;

//the printInfo function compares the unit and convert to other else prints not enough info.

void printInfo(vector<string>s)
{
    if(s[2].compare("kilos")==0||s[2].compare("Kilos")==0)
    {
        double wt=atof(s[1].c_str())*2.20462;

        cout<<"Hi "<<s[0]<<"-you weight "<<setprecision(1)<<fixed<<wt<<" pounds."<<endl;
    }
    else if(s[2].compare("pounds")==0||s[2].compare("Pounds")==0)
    {
        double wt=atof(s[1].c_str())/2.20462;

        cout<<"Hi "<<s[0]<<"-you weight "<<setprecision(1)<<fixed<<wt<<" kilos."<<endl;
    }
    else
        cout<<"Not enough info to convert."<<endl;

}

int main()
{

    int check=1;

//used while loop to keep running until the user enter exit.
    while(check)
    {
        // vector string is created with line provided by the user using stringstream.
    vector<string> tokens;
    string userIn;
    string temp;
    char deli= ' ';

    cout<<"Please enter your name and weight."<<endl;
    getline(cin, userIn);// input receive from user and stored in userIn.

    if(userIn.compare("exit")!=0)// runs iff userIn is other than exit.
    {

    stringstream str(userIn);
//vector string is created using the loop
    while(getline(str,temp,deli))
    {
        tokens.push_back(temp);

    }

    printInfo(tokens);// now the vector string is passed in function to print the info.
    }
    else
    {
        cout<<"Exiting..."<<endl;// exiting will print if user enter exit and break out of the loop.
        check=0;
        break;

    }



    }
}
