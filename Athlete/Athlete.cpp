/*
2018-12-12
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <list>
#include<conio.h>
#include <fstream>
#include"Athlete.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using namespace std;
ofstream outFile;
char* getDateTime();
int LogInfo();

int main()
{
    outFile.open("log.txt",ios::app);
    int step;
    LogInfo();
    Athlete ath;
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
                        while(ath.adminOperation()){}
                        break;
                    }
            case 2:
                    {
                        while(-1 !=ath.userOperation()){}
                        step=1;
                        break;
                    }
        }
    }while(step>0 && step<3);
    outFile.close();
    return 0;
}

void Athlete::displayAll()
{
    int indexShow = getDataIndex();
    cout <<" | "<<"name"
           <<" | "<<"gender"
             <<" | "<<"competion"
               <<" | "<<"phone number"
                 <<" | "<<"address"
                   <<" | "<<"finial result"
                     <<endl;
    for(int i = 0;i<=indexShow;i++)
    {
        cout <<" | "<<getNameN(i)<<
               " | "<<getGenderN(i)<<
               " | "<<getCompetitionN(i)<<
               " | "<<getPhoneNumberN(i)<<
               " | "<<getAddressN(i)<<
               " | "<<getFinialResultN(i)<<" | "<<endl;
    }
}

void Athlete::initSystem()
{
    string names[5] = {"Jack","Anny","Tom","Lucy","Ale"};
    string genders[5] = {"male","female","male","female","female"};
    string competitions[5] = {"math","english","math","computer","math"};
    string phoneNumbers[5] = {"35268477","35223437","35296477","73468477","86438477"};
    string addr[5] = {"h87","g17","k87","k12","a57"};
    string finialResults[5] = {"90","86","68","98","87"};
    for(int i =0;i<5;i++)
    {
        setNameN(names[i],i);
        setGenderN(genders[i],i);
        setCompetitionN(competitions[i],i);
        setPhoneNumberN(phoneNumbers[i],i);
        setAddressN(addr[i],i);
        setFinialResultN(finialResults[i],i);
        setDataIndex(i);
    }
}

int Athlete::loginAdministrator()
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

int Athlete::Admin()
{

    int choose;
    while (!loginAdministrator())
    {

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

void Athlete::add()
{
    system("cls");

    string nameA;
    string genderA;
    string competitionA;
    string phoneNumberA;
    string addressA;
    string finialResultA;

    cout << "Please enter the name : ";
    cin >> nameA;
    cout << "Please enter the gender : ";
    cin >> genderA;
    cout << "Please enter the competition : ";
    cin >> competitionA;
    cout << "Please enter the phoneNumber : ";
    cin >> phoneNumberA;
    cout << "Please enter the address : ";
    cin >> addressA;
    cout << "Please enter the finialResult : ";
    cin >> finialResultA;
    int indexA = getDataIndex();
    if(indexA >= 99)
    {
        outFile << getDateTime()<<"------add failed ,and the data is full,alrady  " << indexA <<"\n";
        return;
    }
    indexA++;
    setNameN( nameA, indexA);
    setGenderN( genderA, indexA);
    setCompetitionN( competitionA, indexA);
    setPhoneNumberN( phoneNumberA, indexA);
    setAddressN( addressA, indexA);
    setFinialResultN( finialResultA, indexA);
    setDataIndex(indexA);

    outFile << getDateTime()<<"---add success ,and the index is " << indexA <<"\n";

    return ;
}

void Athlete::update()
{
    system("cls");
    string nameU;
    cout << "Please enter the name you want to update: ";
    cin >> nameU;
    int indexU = serach(nameU);
    if(indexU == -1)
    {
        cout<<"no data! can not update!"<<endl;
        outFile<<getDateTime()<<"---no data! can not update!\n";
        return ;
    }
    else
    {

        string genderU;
        string competitionU;
        string phoneNumberU;
        string addressU;
        string finialResultU;

        cout << "Please enter the gender : ";
        cin >> genderU;
        cout << "Please enter the competition : ";
        cin >> competitionU;
        cout << "Please enter the phoneNumber : ";
        cin >> phoneNumberU;
        cout << "Please enter the address : ";
        cin >> addressU;
        cout << "Please enter the finialResult : ";
        cin >> finialResultU;

        setGenderN( genderU, indexU);
        setCompetitionN( competitionU, indexU);
        setPhoneNumberN( phoneNumberU, indexU);
        setAddressN( addressU, indexU);
        setFinialResultN( finialResultU, indexU);

        cout<<"update success!"<<endl;
        outFile<<getDateTime()<<"---update success!\n";
        return ;
    }
}

int Athlete::serach(string name)
{
    system("cls");
    int indexS = getDataIndex();
    if(indexS <= 0)
    {
        cout<<"no data! can not serach!"<<endl;
        outFile<<getDateTime()<<"---no data! can not serach!\n";
        return -1;
    }
    for(int i =0;i<indexS;i++)
    {
        if(getNameN(i) == name)
        {
            cout<<"serach success ! the data inex is " << i <<endl;
            outFile<<getDateTime()<<"---serach success ! the data inex is " << i <<"\n";
            return i;
        }
    }

    cout<<"can not find ! may the name is wrong or it is not exist!"<<endl;
    outFile<<getDateTime()<<"---can not find ! may the name is wrong or it is not exist!\n";
    return -1;
}

void Athlete::del()
{
    system("cls");
    string nameD;
    cout << "Please enter the name you want to delete: ";
    cin >> nameD;
    string empty = "";
    int indexD = serach(nameD);
    if(indexD == -1)
    {
        cout<<"no data! can not delete!"<<endl;
        outFile<<getDateTime()<<"---no data! can not delete!\n";
        return ;
    }
    else
    {
        setNameN(empty, indexD);
        setGenderN(empty, indexD);
        setCompetitionN( empty, indexD);
        setPhoneNumberN( empty, indexD);
        setAddressN( empty, indexD);
        setFinialResultN( empty, indexD);
        cout<<"delete success!"<<endl;
        outFile<<getDateTime()<<"---delete success!\n";
        return ;
    }
}

void Athlete::query()
{
    string nameQ;
    cout << "please input your name :";
    cin >> nameQ;
    int indexQ = serach(nameQ);
    if(indexQ == -1)
    {
        cout<<"name is not exist!"<<endl;
        outFile<<getDateTime()<<"---name is not exist!\n";
        return ;
    }
    else
    {
        cout<<"query success!"<<endl;
        cout <<" | "<<"name"
               <<" | "<<"gender"
                 <<" | "<<"competion"
                   <<" | "<<"phone number"
                     <<" | "<<"address"
                       <<" | "<<"finial result"
                         <<endl;
        cout <<" | "<<getNameN(indexQ)<<
               " | "<<getGenderN(indexQ)<<
               " | "<<getCompetitionN(indexQ)<<
               " | "<<getPhoneNumberN(indexQ)<<
               " | "<<getAddressN(indexQ)<<
               " | "<<getFinialResultN(indexQ)<<" | "<<endl;

        outFile<<getDateTime()<<"---query success!\n";
    }


}

int Athlete::adminOperation()
{
    int choose;
    if(Admin())
    {
        system("cls");

        cout<<"\n login successful \n"<<endl;
        do
        {
            displayAll();
            cout<<"\n Choose from 1, 2, 3 or 4 :\n"<<endl;
            cout<<"1.add Event\n"<<endl;
            cout<<"2.update Event();\n"<<endl;
            cout<<"3.delete Event\n"<<endl;
            cout<<"4.exit management state\n"<<endl;
            cin>>choose;

            switch (choose)
            {
                case 1:
                        {
                            add();
                            break;
                        }
                case 2:
                        {
                            update();
                            break;
                        }
                case 3:
                        {
                            del();
                            break;
                        }
            }
        }while(choose>0 && choose<4);
    }
    //system("clear");
    return 0;
}
int Athlete::userOperation()
{
    int step = 0;
    cout<<"\n Choose from 1, 2 or 3 :\n"<<endl;
    cout<<"1.query \n"<<endl;
    cout<<"2.back \n"<<endl;
    cin>>step;
    switch (step)
    {
        case 1:
                {
                    //system("clear");
                    cout<<"\n start to book \n"<<endl;
                    query();
                    break;
                }
        case 2:
                {
                    return -1;
                }
        default : cout<<"please input right number 1 or 2";
    }
    return 1;
}


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

int LogInfo()
{
    cout<<"************************************************************************"<<endl;
    cout<<"*                 Welcome to database management system                   *"<<endl;
    cout<<"************************************************************************"<<endl;
    return 1;
}

