/*
SUDIP GHALE
CSE 1325-003
HW-02: PROBLEM 02

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
the class rider has two constructors one with the name and height and one with only height.
*/
class Rider
{
    string rName;
    int rHeight;

public:
    Rider(string name, int height)
    {
        this->rName=name;
        this->rHeight=height;
    }

    Rider(int height)
    {
        this->rHeight=height;
    }
};

/*
the Ride class has two vector funtion to add rides and add riders. it also compare if height is more than the\
min height for the ride and print the related message to the rider
*/

class Ride
{
    vector<int>allRides;
    vector<Rider> allRider;

public:
    void addRides(int minH)
    {
        allRides.push_back(minH);
    }

    void add_line(Rider r)
    {
        allRider.push_back(r);

        if(allRides[0]<45)
        {
            cout<<"Adding rider to line."<<endl;
        }
        else
        {
            cout<<"Sorry, can't add rider - too short"<<endl;
        }
    }
};

/*
this class has one constructor number of riders and gets the  minimum height for the specific ride.
it also has to helper function to print to users and to get  ride funtion to return the ride number.
*/
class Amusement_park
{
    int numRides;

    void printRides(int i)
    {
        cout<<"Ride "<<i<<"- "<<"Enter minimum ride height and ride name:"<<endl;
    }

public:
    Amusement_park(int num)
    {
        this->numRides=num;
        Ride r1;

        cout<<"~~~Amusement Park Info~~~"<<endl;
        for(int i=0; i<num; i++)
        {
            int height;
            string name;

            printRides(i+1);
            cin>>height>>name;
            r1.addRides(height);
        }
        cout<<"\n\n"<<endl;

    }

    Ride get_ride(int n)
    {
      Ride r1;
        return r1;
    }

};

/*
main created two rider variable, and two amusement part variable
*/
int	main()
{
				Rider	r1("Yaris",	45);	//name,	height	in	inches
				Rider	r2(49);	//height	in	inches
				Amusement_park	a1(3);	//3	is	the	number	of	rides	in	the	amusement	park
			//	a1.get_ride(1).add_line(r1);		//add	a	rider	to	the	line	of	a	ride
				Amusement_park	a2(2);	//2	is	the	number	of	rides	in	the	amusement	park
			//	a2.get_ride(1).add_line(r2);	//add	a	rider	to	the	line	of	a	ride
				return	0;
}
