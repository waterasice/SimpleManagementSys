#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <string>
#include <list>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using namespace std;

typedef struct  
{
    string name;
    int numberRes;     
    int bookedNumber;     
    int price;
    string time;
} tickets;

list<tickets> ticketsList;

char* getDateTime()  
{  
        static char nowtime[20];  
        time_t rawtime;  
        struct tm* ltime;  
        time(&rawtime);  
        ltime = localtime(&rawtime);  
        strftime(nowtime, 20, "%Y-%m-%d %H:%M:%S", ltime);  
        return nowtime;  
} 

void showTickets()
{
    list<tickets>::iterator ticketsListIterator;
    cout    << "ticket name" << "\t"
        << "ticket left"<< "\t"
        << "booked" << "\t\t"
        << "price" << "\t\t"
        << "time" <<endl;
    for (ticketsListIterator=ticketsList.begin();
            ticketsListIterator!=ticketsList.end();
            ++ticketsListIterator)
    {
            cout<< (*ticketsListIterator).name << "\t\t"
                << (*ticketsListIterator).numberRes << "\t\t" 
                << (*ticketsListIterator).bookedNumber << "\t\t"
                << (*ticketsListIterator).price << "\t\t"
                << (*ticketsListIterator).time  << endl;
    }
}

void initTickets()
{
    string curTime = getDateTime();
    tickets redTicket;
    tickets yellowTicket;
    tickets greenTicket;

    redTicket.name = "red";
    redTicket.numberRes = 30;
    redTicket.bookedNumber = 0;
    redTicket.price = 100;
    redTicket.time = curTime;

    yellowTicket.name = "yellow";
    yellowTicket.numberRes = 50;
    yellowTicket.bookedNumber = 0;
    yellowTicket.price = 80;
    yellowTicket.time = curTime;

    greenTicket.name = "green";
    greenTicket.numberRes = 100;
    greenTicket.bookedNumber = 0;
    greenTicket.price = 50;
    greenTicket.time = curTime;

    ticketsList.push_back(redTicket);
    ticketsList.push_back(yellowTicket);
    ticketsList.push_back(greenTicket);

}
int loginAdministrator() 
{   
    string password; 
    cout << "please input password :"<<endl;
    cin>> password;
    if (password == "123456")
    {
        return 1;
    }   
    return 0;
}

int Admin() 
{

    int choose;
    while (!loginAdministrator())
    {
        system("clear");
        cout<<"\n password error , reinput ( 1 or 2 )?:" <<endl;
        cout<<"1.Yes\n"<<endl;
        cout<<"2.No,exit\n"<<endl;
        cin >> choose ;
        if(2 == choose)
        {
            return 0;
        }
    }
    return 1;
}

int addEvent()
{
    system("clear");
    showTickets();
    tickets newTicket;
    newTicket.bookedNumber = 0;
    cout<<"please input ticket name:"<<endl;
    cin>>newTicket.name;
    cout<<"please input ticket number:"<<endl;
    cin>>newTicket.numberRes;
    cout<<"please input ticket price:"<<endl;
    cin>>newTicket.price;
    string curTime = getDateTime();
    newTicket.time = curTime;
    ticketsList.push_back(newTicket);
    cout<<"add event successful ! new tickets message :\n"<<endl;
    showTickets();
    return 0;
}

int updateEvent()
{
    system("clear");
    showTickets();
    tickets newTicket;
    newTicket.bookedNumber = 0;
    cout<<"\nchoose one ticket name you want update\n"<<endl;
    cin>>newTicket.name;

    list<tickets>::iterator ticketsListIterator;

    for (ticketsListIterator=ticketsList.begin();
            ticketsListIterator!=ticketsList.end();
            ++ticketsListIterator)
    {
        if((*ticketsListIterator).name == newTicket.name)
        {
            ticketsList.erase(ticketsListIterator);
            break;
        }
    }
    
    cout<<"please update ticket name :"<<endl;
    cin>>newTicket.name;
    cout<<"please update ticket number:"<<endl;
    cin>>newTicket.numberRes;
    cout<<"please update ticket price:"<<endl;
    cin>>newTicket.price;

    string curTime = getDateTime();
    newTicket.time = curTime;
    ticketsList.push_back(newTicket);
    cout<<"\nupdate event successful ! new tickets message :\n"<<endl;
    showTickets();
    return 0;
}

int deleteEvent()
{
    system("clear");
    showTickets();
    string delTicket;
    cout<<"\nchoose one ticket name you want delete\n"<<endl;
    cin>>delTicket;

    list<tickets>::iterator ticketsListIterator;

    for (ticketsListIterator=ticketsList.begin();
            ticketsListIterator!=ticketsList.end();
            ++ticketsListIterator)
    {
        if((*ticketsListIterator).name == delTicket)
        {
            ticketsList.erase(ticketsListIterator);
            cout<<"\ndelete event successful ! new tickets message :\n"<<endl;
            showTickets();
            return 0;
        }

    }

    cout<<"\ndelete event failed , ticket is not exist\n"<<endl;
    return -1;
}
int operationEvent() 
{
    int choose;
    if(Admin())
    {
        system("clear");
        cout<<"\n login successful \n"<<endl;
        do
        {
            cout<<"\n Choose from 1, 2, 3 or 4 :\n"<<endl;
            cout<<"1.add Event\n"<<endl;
            cout<<"2.updateEvent();\n"<<endl;
            cout<<"3.deleteEvent\n"<<endl;
            cout<<"4.exit management state\n"<<endl;
            cin>>choose;

            switch (choose) 
            {
                case 1: 
                        {
                            addEvent();
                            break;
                        }
                case 2: 
                        {
                            updateEvent();
                            break;
                        }
                case 3: 
                        {
                            deleteEvent();
                            break;
                        }
            }
        }while(choose>0 && choose<4);
    }
    system("clear");
    return 0;
}

void userOperationEvent() 
{
    cout<<"****************************************************************************************"<<endl;
    cout<<"******                                 TICKETS MENU                               ******"<<endl;
    cout<<"****************************************************************************************"<<endl;
    showTickets();
    return ;
}

int LogIn() 
{
    system("clear");
    cout<<"***********************************************************************************"<<endl;
    cout<<"*                      Welcome to Event management system                         *"<<endl;
    cout<<"***********************************************************************************"<<endl;
    return 1;
}

int main()
{
    int step;
    initTickets();   
    LogIn();
    do
    {      
        cout<<"\n Choose from 1, 2 or 3 :\n"<<endl;
        cout<<"1.Manage it as a administrator\n"<<endl;
        cout<<"2.I am a user\n"<<endl;
        cout<<"3.exit\n"<<endl;
        cin>>step;

        switch (step) 
        {
            case 1: 
                    {
                        system("clear");
                        cout<<"\n start to login \n"<<endl;
                        while(operationEvent());
                        break;
                    }
            case 2: 
                    {
                        userOperationEvent();
                        break;
                    }
            case 3: 
                    {
                        step = 4;
                        break;
                    }
        }
    }while(step>0 && step<4);
    
    system("clear");
    printf("\nThank you for your using, exiting...\n");
    printf("exit successful\n");

    return 0;
}