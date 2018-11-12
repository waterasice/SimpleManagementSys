#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <iostream>
#include <string>
#include <list>
#include<conio.h>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using namespace std;

#define Random(low,up) (rand()%(up-low+1)) + low - 1
typedef struct
{
    string  name;
    int     numberRes;
    int     bookedNumber;
    int     price;
    string  time;
} tickets;

typedef struct
{
    string  usrName;
    string  usrAddress;
    string  ticketName;
    int     numberBook;
    int     price;
    string  bookingCode;
    string  time;
} bookings;

list<tickets> ticketsList;
list<bookings> bookingsList;


string  pLogName;

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
void showTickets()
{
    list<tickets>::iterator ticketsListIterator;
    cout    << "name" << "\t"
        << "Remaining"<< "\t"
        << "booked" << "\t"
        << "price" << "\t"
        << "time" <<endl;
    for (ticketsListIterator=ticketsList.begin();
            ticketsListIterator!=ticketsList.end();
            ++ticketsListIterator)
    {
            cout<< (*ticketsListIterator).name << "\t"
                << (*ticketsListIterator).numberRes << "\t\t"
                << (*ticketsListIterator).bookedNumber << "\t"
                << (*ticketsListIterator).price << "\t"
                << (*ticketsListIterator).time  << endl;
    }
}

void showBookings()
{
    list<bookings>::iterator bookingsListIterator;
    cout    << "\nusrName" << "\t"
            << "usrAddress"<< "\t"
            << "ticketName" << "\t"
            << "numberBook" << "\t"
            << "price" << "\t"
            << "bookingCode" << "\t"
            << "time" <<endl;
    for (bookingsListIterator=bookingsList.begin();
            bookingsListIterator!=bookingsList.end();
            ++bookingsListIterator)
    {
            cout<< (*bookingsListIterator).usrName << "\t"
                << (*bookingsListIterator).usrAddress << "\t\t"
                << (*bookingsListIterator).ticketName << "\t\t"
                << (*bookingsListIterator).numberBook << "\t\t"
                << (*bookingsListIterator).price      <<"\t"
                << (*bookingsListIterator).bookingCode << "\t"
                << (*bookingsListIterator).time  << endl;
    }
}

int loginAdministrator()
{
    string password;
    cout << "please input password :"<<endl;
    cout<<"input password:";
    char ch;
    while((ch=getch())!='\r')
    {
        password+=ch;
        cout<<"*";
    }
    cout << endl;
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
        //system("clear");
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
    system("cls");
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

    const char *pLog = pLogName.c_str();
    ofstream log;
    log.open(pLog, ios::out | ios::app );
    if (log.is_open())
    {
        log <<getDateTime()<< "----add event successful\n";
        log <<getDateTime()<< "----add ticket name  "<<newTicket.name<<"\n";
        log <<getDateTime()<< "----add ticket number  "<<newTicket.numberRes<<"\n";
        log <<getDateTime()<< "----add ticket price  "<<newTicket.price<<"\n";
        log.close();
    }
    showTickets();
    return 0;
}

int updateEvent()
{
    //system("clear");
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

    const char *pLog = pLogName.c_str();
    ofstream log;
    log.open(pLog, ios::out | ios::app );
    if (log.is_open())
    {
        log <<getDateTime()<< "----update event successful\n";
        log <<getDateTime()<< "----update ticket name  "<<newTicket.name<<"\n";
        log <<getDateTime()<< "----update ticket number  "<<newTicket.numberRes<<"\n";
        log <<getDateTime()<< "----update ticket price  "<<newTicket.price<<"\n";
        log.close();
    }
    showTickets();
    return 0;
}

int deleteEvent()
{
    system("cls");
    showTickets();
    const char *pLog = pLogName.c_str();
    ofstream log;
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

            log.open(pLog, ios::out | ios::app );
            if (log.is_open())
            {
                log <<getDateTime()<< "----delete event successful\n";
                log <<getDateTime()<< "----delete ticket name  "<<delTicket<<"\n";

                log.close();
            }
            showTickets();
            return 0;
        }

    }

    cout<<"\ndelete event failed , ticket is not exist\n"<<endl;
    return -1;
}

int bookEvent()
{
    cout<<"**************************************************************************"<<endl;
    cout<<"******                      TICKETS MENU                            ******"<<endl;
    cout<<"**************************************************************************"<<endl;
    showTickets();

    srand(time(NULL));

    tickets newTicket;
    int price=0;
    string dateStr;
    cout<<"\nchoose one ticket name you want to book\n"<<endl;
    cin>>newTicket.name;
    cout<<"\ninput number you want to book\n"<<endl;
    cin>>newTicket.bookedNumber;

    list<tickets>::iterator ticketsListIterator;

    for (ticketsListIterator=ticketsList.begin();
            ticketsListIterator!=ticketsList.end();
            ++ticketsListIterator)
        {
            if((*ticketsListIterator).name == newTicket.name)
            {
                price = (*ticketsListIterator).price;
                while((*ticketsListIterator).numberRes < newTicket.bookedNumber)
                {
                   cout<<"\nno enough tickets ,Maximum are "<<(*ticketsListIterator).numberRes<<endl;
                   cout<<" please reinput number\n"<<endl;
                   cin>>newTicket.bookedNumber;
                }
                (*ticketsListIterator).numberRes-=newTicket.bookedNumber;
                (*ticketsListIterator).bookedNumber+=newTicket.bookedNumber;
                break;
            }
        }

    bookings newBookings;

    newBookings.ticketName=newTicket.name;
    newBookings.numberBook=newTicket.bookedNumber;
    cout<<"\n please input your name :\n"<<endl;
    cin>>newBookings.usrName;
    cout<<"\n please input addres\n"<<endl;
    cin>>newBookings.usrAddress;
    dateStr = getDateTime();
    string bookDate;
    char* bookRand;
    bookRand =(char*)malloc(20*sizeof(char));
    bookDate =dateStr.substr(0,4)+dateStr.substr(5,2)+dateStr.substr(8,2);
    sprintf(bookRand,"%d",Random(10000,99999));
    newBookings.bookingCode = bookDate+bookRand;
    newBookings.price = price *newTicket.bookedNumber;
    cout<<"\n the bookingCode is :   "<<newBookings.bookingCode<<
       "!!!  very important , you d better writer it down !!!  "<<endl;
    cout <<"\n the price is :  "<< newBookings.price<<endl;
    newBookings.time = getDateTime();
    bookingsList.push_back(newBookings);

    const char *pLog = pLogName.c_str();
    ofstream log;
    log.open(pLog, ios::out | ios::app );
    if (log.is_open())
    {
        log <<getDateTime()<< "----book event successful\n";
        log <<getDateTime()<< "----book ticket usrName  "<<newBookings.usrName<<"\n";
        log <<getDateTime()<< "----book ticket usrAddress  "<<newBookings.usrAddress<<"\n";
        log <<getDateTime()<< "----book ticket bookedNumber  "<<newBookings.numberBook<<"\n";
        log <<getDateTime()<< "----book ticket price  "<<newBookings.price<<"\n";
        log <<getDateTime()<< "----book ticket bookingCode  "<<newBookings.bookingCode<<"\n";
        log.close();
    }
    return 1;
}

int cancelBookEvent()
{
    const char *pLog = pLogName.c_str();
    ofstream log;
    log.open(pLog, ios::out | ios::app );
    system("cls");
    if (bookingsList.empty())
    {
        cout << "\n there are no bookings"<<endl;
        if (log.is_open())
        {
            log <<getDateTime()<< "----cancel book event fail ,there are no bookings\n";
            log.close();
        }
        return 1;
    }
    cout << "\n you must input right booking code if you want to cancel a book !"<<endl;

    string cancelBooking;
    cout<<"\ninput your bookingcode :"<<endl;
    cin>>cancelBooking;

    int number;
    string ticketName;
    list<bookings>::iterator bookingsListIterator;
    for (bookingsListIterator=bookingsList.begin();
            bookingsListIterator!=bookingsList.end();
            ++bookingsListIterator)
    {
        if((*bookingsListIterator).bookingCode == cancelBooking)
        {
            ticketName = (*bookingsListIterator).ticketName;
            number = (*bookingsListIterator).numberBook;
            bookingsList.erase(bookingsListIterator);
            cout<<"\n cancel a book successful \n"<<endl;
        }
    }

    list<tickets>::iterator ticketsListIterator;
    for (ticketsListIterator=ticketsList.begin();
            ticketsListIterator!=ticketsList.end();
            ++ticketsListIterator)
    {
        if((*ticketsListIterator).name == ticketName)
        {
            (*ticketsListIterator).numberRes+= number;
            (*ticketsListIterator).bookedNumber-=number;
            showTickets();
            break;
        }

    }

    if (log.is_open())
    {
        log <<getDateTime()<< "----cancel book event successful\n";
        log <<getDateTime()<< "----cancelbook ticket bookingCode\n"<<cancelBooking;
        log.close();
    }
    return 1;
}
int operationEvent()
{
    int choose;
    if(Admin())
    {
        system("cls");
        const char *pLog = pLogName.c_str();
        ofstream log;
        log.open(pLog, ios::out | ios::app );
        if (log.is_open())
        {
            log <<getDateTime()<< "----administrator login successful\n";
            log.close();
        }
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
    //system("clear");
    return 0;
}

int userOperationEvent()
{
    int step = 0;
    cout<<"\n Choose from 1, 2 or 3 :\n"<<endl;
    cout<<"1.book ticket \n"<<endl;
    cout<<"2.concel a book \n"<<endl;
    cout<<"3.back\n"<<endl;
    cin>>step;
    switch (step)
    {
        case 1:
                {
                    //system("clear");
                    cout<<"\n start to book \n"<<endl;
                    bookEvent();
                    break;
                }
        case 2:
                {
                    cout<<"\n cancel a book \n"<<endl;
                    cancelBookEvent();
                    break;
                }
        case 3:
                {
                    return -1;
                }
    }
    return 1;
}

int LogInfo()
{
    //system("clear");
    cout<<"************************************************************************"<<endl;
    cout<<"*                 Welcome to Event management system                   *"<<endl;
    cout<<"************************************************************************"<<endl;
    return 1;
}

int main()
{
    string logName;
    string fi;
    logName = getDateTime();
    logName=logName.substr(0,4)+logName.substr(5,2)+logName.substr(8,2);
    fi=".log";
    logName+=fi;
    pLogName = logName;
    const char *pLog = logName.c_str();
    ofstream log;
    log.open(pLog, ios::out | ios::app );
    if (log.is_open())
    {
        log << getDateTime()<< "----initTickets\n";
        log << getDateTime()<<"----LogInfo\n";
        log.close();
    }
    int step;
    initTickets();
    LogInfo();
    do
    {
        cout<<"\n Choose from 1, 2 or 3 :\n"<<endl;
        cout<<"1.Manage it as a administrator\n"<<endl;
        cout<<"2.I am a user\n"<<endl;
        cin>>step;

        switch (step)
        {
            case 1:
                    {
                        system("cls");
                        cout<<"\n start to login \n"<<endl;
                        while(operationEvent()){}
                        break;
                    }
            case 2:
                    {
                        while(-1 !=userOperationEvent()){}
                        step=1;
                        break;
                    }
        }
    }while(step>0 && step<3);

    log.close();
    return 0;
}
