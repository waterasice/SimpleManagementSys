#ifndef ATHLETE_H
#define ATHLETE_H
#include <iostream>
#include <string>
using namespace std;
class Athlete
{
public:
    Athlete() {initSystem();}
    ~Athlete(){}
    void initSystem();
    int Admin();
    int loginAdministrator();
    int adminOperation();
    int userOperation();
    void displayAll();

    string getNameN(int userID){return name[userID];}
    string getGenderN(int userID){return gender[userID];}
    string getCompetitionN(int userID){return competition[userID];}
    string getPhoneNumberN(int userID){return phoneNumber[userID];}
    string getAddressN(int userID){return address[userID];}
    string getFinialResultN(int userID){return finialResult[userID];}
    int getDataIndex(){return dataIndex;}

    void setNameN(string userName,int userID){ name[userID]=userName;}
    void setGenderN(string userGender,int userID){ gender[userID]=userGender;}
    void setCompetitionN(string userCompe,int userID){ competition[userID]=userCompe;}
    void setPhoneNumberN(string userPhone,int userID){ phoneNumber[userID]=userPhone;}
    void setAddressN(string userAdd,int userID){ address[userID]=userAdd;}
    void setFinialResultN(string userFinres,int userID){ finialResult[userID]=userFinres;}
    void setDataIndex(int index){ dataIndex = index;}
    void add();
    void update();
    void  del();
    int  serach(string name);
    void query();



private:
    string name[100];
    string gender[100];
    string competition[100];
    string phoneNumber[100];
    string address[100];
    string finialResult[100];
    int dataIndex;
};
#endif
