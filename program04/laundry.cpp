/*
SUDIP GHALE, 
CSE-1325-003
HW-04, Problem #03
DATE-10/19/2018
*/
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
/*
this program has four classes for person, Machines, User, and the Laundromat
*/

class Person //Person class has only first name and the last name variable
{
public:
  string fN, lN;

};

class User : public Person// user class is publicly inheritated from perssonclass
{
public:
  string iD;
  float balance, amtDeter;
public:
  User(string a, string b, string c, float d, float e)// one constructor
  {
    fN=a;
    lN=b;
    iD=c;
    balance=d;
    amtDeter=e;
  }
};

class Machines // It has four public variables
{
public:
  int number;
  bool avail;
  float price, deter;

  Machines(int n, float p , float d) // one constructor
  {
    number=n;
    if(n>=0)
       avail=true;
    else avail=false;
    price=p;
    deter=d;
  }
};

class Laundromat // it has one constructor and several functions
{
public:
  vector<Machines> allMachines;
  vector<User> allUsers;

  Laundromat()
  {
    cout<<"~~~WELCOME TO LAUNDROMAT~~~"<<endl;

  }
  void readMachine(string fileName) // this fucn read in Machines file and save in the vetor
  {
    ifstream inFile;
    int i, num;

    cout<<"Laundromat Machine's into reading in:\n"<<endl;
    inFile.open(fileName);
    if(!inFile.is_open())
    {
      cout<<"No files with this name. Exiting!!!.\n"<<endl;
      exit(0);
    }

      inFile>>num;
      Machines m1(num, 0.50, 2.0);
      allMachines.push_back(m1);

      inFile>>num;
      Machines m2(num, 0.35, 1.5);
      allMachines.push_back(m2);

      inFile>>num;
      Machines m3(num, 25, 1.0);
      allMachines.push_back(m3);




  }
  void readUsers(string fileName) // this fun read the user file and saves in the vector
  {
    ifstream inFile;
    string fN, lN, iD;
    float balance, deter;

    cout<<"\nReading in all registered users info... \n"<<'\n';
    inFile.open(fileName);
    if(!inFile.is_open())
    {
      cout<<"No files with this name. Exiting...\n"<<endl;
      exit(1);
    }

   while(!inFile.eof())
    {
     inFile>>fN>>lN>>iD>>balance>>deter;

     User u1(fN,lN,iD,balance,deter);
     allUsers.push_back(u1);

    }



  }

  void printAvailable() // this fun just prints the available machines
  {
    cout<<"***AVAILABLE***"<<endl;
    cout<<"Fast Machines: "<<allMachines[0].number<<endl;
    cout<<"Slow Machines: "<<allMachines[1].number<<endl;
    cout<<"Very Slow Machines: "<<allMachines[2].number<<endl;

  }



};


void takeUser(Laundromat &L1)// this fun takes in the users
{
  string iD, ans;
  int i, found=-1, yes=1;

  while(iD!="exit")// runs until enters exit
  {
    cout<<"Please enter your ID:\n"<<'\n';
    cin>>iD;

    for(i=0 ; i <L1.allUsers.size() ; i++) // looking for the ID
    {
     if(iD==L1.allUsers[i].iD)
        {
          found=i; // sets the index value
        }

    }

    if(found!=-1)// executes only if the id is found
    {
      iD.erase(0,1);// get rid of the first letter in the id , D
/*thre conditions for different customers, but all it does it print the available machines to the customers
and promt  for their choice. then it discoutn the corrospinding used valances and print the remaining.*/
      if(stoi(iD)<=500) // meaning it is discount user
      {
        cout<<"Welcome discount member."<<endl<<"1) Start a loundry load(start)"<<endl;
        cout<<"2)Finish a laundry load(load)"<<endl;
        cin>>ans;
        if(ans=="start")
        {
          cout<<"Slow Machines:"<<L1.allMachines[1].number<<endl;
          cout<<"Very slow machines"<<L1.allMachines[2].number<<endl;
          cout<<"Which machine would you like to use?\n"<<endl;
          while(yes==1)
          {
            cin>>ans;
            if(ans=="slow")
            {
              if(L1.allMachines[1].number==0)
                 {
                   cout<<"~Sorry, Not available. Enter again\n"<<endl;
                  }
              else
              {
                cout<<"~Ok, using 35 cents and putting 1.5 oz of detergent"<<endl;
                L1.allUsers[i].balance-=0.35;
                L1.allUsers[i].amtDeter-=1.5;
                cout<<"Loading machine...."<<endl;
                cout<<"You currently have:"<<L1.allUsers[i].balance<<"cents and"<<L1.allUsers[i].amtDeter<<"oz of detergent left"<<endl;
                yes=0;

              }

            }
            else
            {
              if(L1.allMachines[2].number==0)
                 {
                   cout<<"~Sorry, Not available. Enter again\n"<<endl;
                  }
              else
              {
                cout<<"~Ok, using 25 cents and putting 1 oz of detergent"<<endl;
                L1.allUsers[i].balance-=0.25;
                L1.allUsers[i].amtDeter-=1;
                cout<<"Loading machine...."<<endl;
                cout<<"You currently have:"<<L1.allUsers[i].balance<<"cents and"<<L1.allUsers[i].amtDeter<<"oz of detergent left"<<endl;
                yes=0;

              }

            }

          }

        }
        else cout<<"Finishing a laundry load"<<endl;


      }
      else if(stoi(iD)<901 && stoi(iD)>500) // meaning the regular users
      {
        cout<<"Welcome Regular member."<<endl<<"1) Start a loundry load(start)"<<endl;
        cout<<"2)Finish a laundry load(load)"<<endl;
        cin>>ans;
        if(ans=="start")
        {
          cout<<"Slow Machines:"<<L1.allMachines[1].number<<endl;
          cout<<"Fast machines"<<L1.allMachines[0].number<<endl;
          cout<<"Which machine would you like to use?\n"<<endl;
          while(yes==1)
          {
            cin>>ans;
            if(ans=="slow")
            {
              if(L1.allMachines[1].number==0)
                 {
                   cout<<"~Sorry, Not available. Enter again\n"<<endl;
                  }
              else
              {
                cout<<"~Ok, using 35 cents and putting 1.5 oz of detergent"<<endl;
                L1.allUsers[i].balance-=0.35;
                L1.allUsers[i].amtDeter-=1.5;
                cout<<"Loading machine...."<<endl;
                cout<<"You currently have:"<<L1.allUsers[i].balance<<"cents and"<<L1.allUsers[i].amtDeter<<"oz of detergent left"<<endl;
                yes=0;

              }

            }
            else
            {
              if(L1.allMachines[0].number==0)
                 {
                   cout<<"~Sorry, Not available. Enter again\n"<<endl;
                  }
              else
              {
                cout<<"~Ok, using 50 cents and putting 2 oz of detergent"<<endl;
                L1.allUsers[i].balance-=0.50;
                L1.allUsers[i].amtDeter-=2;
                cout<<"Loading machine...."<<endl;
                cout<<"You currently have:"<<L1.allUsers[i].balance<<"cents and"<<L1.allUsers[i].amtDeter<<"oz of detergent left"<<endl;
                yes=0;

              }

            }

          }

        }
        else cout<<"Finishing a laundry load"<<endl;


      }
      else /// assuming the elite users
      {
        cout<<"Welcome Elite member."<<endl<<"1) Start a loundry load(start)"<<endl;
        cout<<"2)Finish a laundry load(load)"<<endl;
        cin>>ans;
        if(ans=="start")
        {
          cout<<"Slow Machines:"<<L1.allMachines[1].number<<endl;
          cout<<"Very slow machines"<<L1.allMachines[2].number<<endl;
          cout<<"Fast machines"<<L1.allMachines[0].number<<endl;


          cout<<"Which machine would you like to use?\n"<<endl;
          while(yes==1)
          {
            cin>>ans;
            if(ans=="slow")
            {
              if(L1.allMachines[1].number==0)
                 {
                   cout<<"~Sorry, Not available. Enter again\n"<<endl;
                  }
              else
              {
                cout<<"~Ok, using 35 cents and putting 1.5 oz of detergent"<<endl;
                L1.allUsers[i].balance-=0.35;
                L1.allUsers[i].amtDeter-=1.5;
                cout<<"Loading machine...."<<endl;
                cout<<"You currently have:"<<L1.allUsers[i].balance<<"cents and"<<L1.allUsers[i].amtDeter<<"oz of detergent left"<<endl;
                yes=0;

              }

            }
            else if (ans=="very slow")
            {
              if(L1.allMachines[2].number==0)
                 {
                   cout<<"~Sorry, Not available. Enter again\n"<<endl;
                  }
              else
              {
                cout<<"~Ok, using 25 cents and putting 1 oz of detergent"<<endl;
                L1.allUsers[i].balance-=0.25;
                L1.allUsers[i].amtDeter-=1;
                cout<<"Loading machine...."<<endl;
                cout<<"You currently have:"<<L1.allUsers[i].balance<<"cents and"<<L1.allUsers[i].amtDeter<<"oz of detergent left"<<endl;
                yes=0;

              }

            }
            else
            {
              if(L1.allMachines[0].number==0)
                 {
                   cout<<"~Sorry, Not available. Enter again\n"<<endl;
                  }
              else
              {
                cout<<"~Ok, using 50 cents and putting 2 oz of detergent"<<endl;
                L1.allUsers[i].balance-=0.50;
                L1.allUsers[i].amtDeter-=2;
                cout<<"Loading machine...."<<endl;
                cout<<"You currently have:"<<L1.allUsers[i].balance<<"cents and"<<L1.allUsers[i].amtDeter<<"oz of detergent left"<<endl;
                yes=0;

              }

            }

          }

        }
        else cout<<"Finishing a laundry load"<<endl;


      }




    }
    else if(iD=="exit")// break if entered exit
    {
      cout<<"Exiting....."<<endl;
      break;

    }
    else// ask to enter again
      cout<<"Sorry, ID not registered...try agian"<<endl;



  }

}
/*
simple main fn, has only one obj laundrymat ,which call all the funcions in it*/

int main(int argc, char ** argv)
{
  if(argc!=3)
  {
    cout<<"Wrong input: ex: program name machineFilename userFilename"<<endl;
    exit(1);
  }

  Laundromat L1;
  L1.readMachine(argv[1]);
  L1.printAvailable();
  L1.readUsers(argv[2]);
  takeUser(L1);


  return 0;
}
