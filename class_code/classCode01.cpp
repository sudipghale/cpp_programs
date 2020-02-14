#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Egg_cartoon
{
  int total_eggs;

public:
  int add_egg()
  {
    int ret=0;
    if(total_eggs==5)
    {
      cout<<"Cartoon full!"<<endl;
      ret=1;
    }
    else
    {
      total_eggs++;
    }
    return ret;


  }

};

class Market
{
public:
  void add_carton(Egg_cartoon e)
  {
    string answer;
    int check;

    while(check!=1)
    {
      cout<<"Did the chicken lay an egg?"<<endl;
      cin>>answer;

      if(answer=="yes")
      {
        check=e.add_egg();
      }


    }
  }


};

int main()
{
  Market m1;
  vector<Egg_cartoon> eggs(3);

  string answer="yes";
  int i=0;

  while(answer!="no"&& i<=2)
  {
    cout<<"Would you like to fill a cartoon?"<<endl;
    cin>>answer;

    if(answer=="yes")
    {
      m1.add_carton(eggs[i]);
      i++;
    }
  }

  if(i==3)
  {
    cout<<"All cattons are full!"<<endl;
  }
  else
  {
    cout<<"All cartons are not full!"<<i<<"cartons"<<endl;
  }


}
