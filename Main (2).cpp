#include<iostream>
#include<string>
using namespace std;

// BASE CLASS
class PERSON
{
public:
    string name;
    int id;

    void input()
    {
        cout<<"Enter Name=";
        cin>>name;
        cout<<"Enter ID=";
        cin>>id;
    }
};

// INHERITANCE
class PATIENT : public PERSON
{
public:
    string disease;

    void getDisease()
    {
        cout<<"Enter Disease=";
        cin>>disease;
    }
};

// SECOND LEVEL INHERITANCE
class BILL : public PATIENT
{
public:
    int amount;

    BILL()
    {
        amount = 0;
    }

    void calculate()
    {
        cout<<"Enter Bill Amount=";
        cin>>amount;
    }

    // DISPLAY FUNCTION
    void display()
    {
        cout<<"\n--- PATIENT REPORT ---"<<endl;
        cout<<"Name="<<name<<endl;
        cout<<"ID="<<id<<endl;
        cout<<"Disease="<<disease<<endl;
        cout<<"Amount="<<amount<<endl;
    }

    // OVERLOADED FUNCTION
    void display(string msg)
    {
        cout<<msg<<endl;
    }
};

// MAIN FUNCTION (IMPORTANT FIX)
int main()
{
    BILL p[2];

    int i;

    for(i=0;i<2;i++)
    {
        cout<<"\nPatient "<<i+1<<endl;

        p[i].input();
        p[i].getDisease();
        p[i].calculate();

        // EXCEPTION HANDLING
        try
        {
            if(p[i].amount < 0)
                throw p[i].amount;
        }
        catch(int x)
        {
            cout<<"Invalid Amount Entered"<<endl;
            p[i].amount = 0;
        }

        // CONDITION
        if(p[i].amount > 5000)
            cout<<"High Bill"<<endl;
        else
            cout<<"Normal Bill"<<endl;
    }

    // OUTPUT
    for(i=0;i<2;i++)
    {
        p[i].display();
    }

    return 0;
}