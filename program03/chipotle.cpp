/*
Sudip Ghale (1001557881)
Cse1325-003
HW03: program 02 chipotle.cpp
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/* there are three class in this program*/

/* this class has one variable and one constructor which ask the user to enter their choices and
at the end ask if the order is correct or not. it also has one getter funcion to get the amount*/
class Customer{
    float amout;

public:
    Customer(int num)
    {
        string ans, choiceA, choiceB,choiceC;

        cout<<"***Place you order***"<<endl<<"Burrito or Bowl???"<<endl;
        cin>>ans;
        if(ans=="burrito")
        {
            float price=7.99;
            amout=price;
            cout<<"Your total price will be $"<<price<<endl<<endl;
            cout<<"--Pick chicken, Tofu, or Steak !!!"<<endl;
            cin>>choiceA;
            cout<<"--Pick Cilantro-Lime	Brown, or Cilantro-Lime	White !!!"<<endl;
            cin>>choiceB;
            cout<<"--Pick Queso, Sour Cream, Fresh or Tomato Salsa !!!"<<endl;
            cin>>choiceC;
            cout<<endl<<"Conform your order (yes or no)???"<<endl<<"Burrito:"<<choiceA<<","<<choiceB<<","<<choiceC<<endl;

        }
    else
        {
            float price=9.99;
            amout=price;
            cout<<"Your total price will be $"<<price<<endl;
            cout<<"--Pick chicken, Tofu, or Steak !!!"<<endl;
            cin>>choiceA;
            cout<<"--Pick Cilantro-Lime	Brown, or  Cilantro-Lime White !!!"<<endl;
            cin>>choiceB;
            cout<<"--Pick Queso, Sour Cream,or  Fresh Tomato Salsa !!!"<<endl;
            cin>>choiceC;
            cout<<endl<<"Conform your order (yes or no)???"<<endl<<"Burrito:"<<choiceA<<","<<choiceB<<","<<choiceC<<endl;

        }

    }

    float get_amount()
    {
        return amout;
    }


};

/* Person is the first class, it has two variable for first name and the last name and
one constructor. it also has one getter function to get the first name of the driver*/
class Person{
string fName, lName;

public:
    Person(string fN, string lN)
    {
        fName=fN;
        lName=lN;
    }
    string get_fName()
    {
        return fName;
    }


};
/* Delivery class has Person vector variable to save drivers names. it also has one empty constructor.
it has one funcion to add drivers to the line and one getter funcion to get the name of the driver*/
class Delivery {
 vector<Person> drivers;

 public:
     Delivery()
     {

     }
      void set_Drivers(Person p1)
     {
         drivers.push_back(p1);
     }
     string get_driver(int i)
     {
         return drivers[i].get_fName();
     }





};
/* the main uses the command line argument to read the file.*/

int main(int argc, char ** argv)
{
    int ans=1, i, k=0;
    float total=0;
    ifstream inFile;
    string firstN, lastN;

    inFile.open(argv[1]);
    Delivery d1;

    if(!inFile.is_open())/* error message is printed if the file is not oppened */
    {
        cout<<"Unable to open file :"<<argv[0]<<endl;
        exit(1);
    }

    while(!inFile.eof())/* data is read from the file and creates the person and then added to the drivers list*/
    {
        inFile>>firstN>>lastN;
        Person p1(firstN,lastN);

        d1.set_Drivers(p1);
    }

    while (ans !=3)/* the loops run until the user press 3 which means exit*/
    {
        cout<<endl<<"~~Sammy's Delivery Service~~"<<endl<<"-------------------------------------"<<endl<<endl;
        cout<<"Pick from the following menu"<<endl<< "1. Customer"<<endl<<"2. Apply"<<endl<<"3. Exit"<<endl<<endl;
        cin>>ans;

        if(ans==1)/* 1 means its customer, the customer object is created and user is asked to conform the order if yes then driver in is printed*/
        {
            string answer;
            Customer c1(k);

            cin>>answer;
            if(answer=="yes"||answer=="Yes")
            {
                cout<<"OK, "<<d1.get_driver(k)<<" will be delivering your order. Thank YOU!!!"<<endl<<endl;
                k++;
            }




        }
        else if(ans==2)/* 2 is for to apply for driver positoin, info is asked and added to the driver list and print the name*/
        {
               cout<<" Please enter your Full Name:"<<endl;
                cin>>firstN>>lastN;
                Person p2(firstN, lastN);
                d1.set_Drivers(p2);
                cout<<"Newest delivery person is "<<firstN<<endl<<endl;

        }
        else if(ans==3)/* if 3 is enterd then total made through delivery is printed to the screen*/
        {
            cout<<"Exiting..........."<<endl;
	          cout<<"Total made $"<<5*k<<endl;
            break;
        }


    }





}
