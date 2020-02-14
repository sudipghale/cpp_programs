/*
SUDIP GHALE, ID-1001557881
CSE-1325-003
HW-04, Problem #04
DATE-10/19/2018
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Person// person class with fn and ln
{
public:
  string firstName, lastName;


};
class Learner :public Person// child class formt the person classes
{
public:
  string TargerG, Language, start, available;
  float maxPay;

public:
Learner(string fN, string lN, string g,string l, string date, string avail)
{
  firstName=fN;
  lastName=lN;
  TargerG=g;
  Language=l;
  start=date;
  available=avail;

}

};

class Tutor : public Person// child class form the person class
{
public:
  string allLanguages;
  string gender,start, available;
  float maxPay;
  int maxNum;

  Tutor(string a, string b, string c ,string d ,string e, float m)
  {
    firstName=a;
    lastName=b;
    gender=c;
    allLanguages=d;
    start=e;
    maxPay=m;
  }
};
class ABC_Language // abc class with two vecorrs for the learners and the tutors
{
  vector<Learner> allLearners;
  vector<Tutor> allTutors;

public:
  ABC_Language()// constructor
  {
    string filename, data;
    ifstream inFile;
    string fN,lN,tG, l,start, avail;
    float max;

    cout<<"Welcome to the ABC Language Company"<<endl;
    cout<<"Enter the filename to open"<<endl;
    cin>>filename;

    while(filename!="exit")// loop intill entered exit
    {
      inFile.open(filename);

      while(!inFile.is_open())
      {
        cout<<"No file with that filename, enter again "<<endl;
        cin>>filename;
        inFile.open(filename);

      }
      cout<<"Reading in the Learners file"<<endl;
      getline(inFile, fN, ' ');
      getline(inFile, lN);
      getline(inFile, tG);
      getline(inFile, l);
      getline(inFile, start);
      getline(inFile, avail);

      Learner L1(fN,lN,tG,l,start, avail);
      allLearners.push_back(L1);

    }
    cout<<"all the learners file read in complete"<<endl;



  }
  void readTutors()// fun to read in all the tutors fromt the input
  {
    string answer;
    string fN, lN,g, s, a ;
    float m;
    cout<<"Register for the Tutor???"<<endl;
    cin>>answer;
    if(answer=="yes")
    {
      cout<<"Enter your full name gender language StartingDate availableDays MaxLearners Pay"<<endl;
      cin>>fN>>lN>>g>>s>>a>>m;
      Tutor t1(fN,lN,g,s,a,m);
      allTutors.push_back(t1);
    }
  }

};

int main()
{
  ABC_Language A1;
  A1.readTutors();


}
