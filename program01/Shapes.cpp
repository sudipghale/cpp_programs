/*
CSE 1325-003
SUDIP GHALE
09-04-2018
HW-01, PROGRAM-02*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;


// all the below functions will print related information to the input shape.
void printTringle()
{
    cout<<"Area=(base*height)/2"<<endl;
}
void printSquare()
{
    cout<<"Area=length*length"<<endl;
    cout<<"Perimeter=4*length"<<endl;
}
void printRectangle()
{
    cout<<"Area=length*breath"<<endl;
    cout<<"Perimeter=2*(length+breath)"<<endl;
}
void printOther()
{
    cout<<"Sorry, information for this shape is not available."<<endl;
}
int main()
{
    string shape;
    int check=1;
    int count=0;

cout<<"*****\nShapes!\n*****"<<endl;
//using while loop to ask user shape continuously until they enter exit.
    while(check)
    {
            cout<<"Please enter the 2D shape."<<endl;
            cin>>shape;


            if (shape.compare("exit")==0)// check if user entered exit.
            {
                check=0;
                break;
            }
        else if(shape.compare("triangle")==0||shape.compare("Triangle")==0)// compare is the shape is a triangle.
            {
                printTringle();
                count++;

            }
         else if(shape.compare("square")==0||shape.compare("Square")==0)// compare if the shape is a square.
         {
             printSquare();
             count++;
         }
         else if(shape.compare("rectangle")==0||shape.compare("Rectangle")==0)// compare if the shape is a rectangle.
         {
             printRectangle();
             count++;
         }
         else// if non of the three shape is matched then print other function.
         {
             printOther();
             count++;
         }

    }
    cout<<count<<" shapes entered.\nExiting..."<<endl;// at end print the total shape entered.


}
