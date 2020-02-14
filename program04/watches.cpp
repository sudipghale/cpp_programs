/*
SUDIP GHALE
CSE-1325-003
HW-04, Problem #02
DATE-10/19/2018
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//base class watch has private price and its age
class Watch
{
  double price;
  int age;
public: // public material and get_price fun and the get_age fun
  string material;
  double get_price()
  {
    return price;
  }
  int get_age()
  {
    return age;
  }



};
// Designer is child class form base class Watch
class Designer: public Watch
{
public:
  void get_repaired(Designer &d) // fn to set the material of the watch
  {
    if(d.material=="gold")
    {
      cout<<"Your Repair cost is $ "<<d.get_price()/4<<endl;
    }
    if(d.material=="silver")
    {
      cout<<"Your Repair cost is $ "<<d.get_price()/4<<endl;
    }
  }


};

class NonDesigner: public Watch  // child class for NonDesigner , from the base class
{
  bool check;
public:
  void get_repaired(NonDesigner & nd) // fn to print the cost for the repair
  {
    if(check)
    {
      cout<<"Your repair is free of charge."<<endl;
    }
    else
    {
      cout<<"Your repair charge is $ "<<0.15*nd.get_price()<<endl;
    }
  }
};

class Antique : public Watch// child class Antique form the base class
{
public:
  void get_repaired(Antique & a) // public fn to print the repair price
  {
    cout<<"Your repair price is $"<<a.get_age()*0.5<<endl;
  }


};
class ABC_Watches // class ABC_Watches not linked to any classes
{
  vector<Watch> allWatches; // alll the watches are kept in a vector
public:
  ABC_Watches() // constructor to print welcome
  {
    cout<<"Welcome to ABC Watches"<<endl;

  }

};

int main () // main class
{



}
