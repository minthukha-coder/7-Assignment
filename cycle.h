//
// Created by User on 10/11/2022.
//
#include"iostream"
#ifndef MY_PROJECT_CYCLE_H
#define MY_PROJECT_CYCLE_H

using namespace std;
 namespace N{
class cycle {
public:
    // attribute and behaviours
    int i = 0;
    int count = 0;
    int index = 0;
    int wrong = 0;
    int currentData = 0;
    int money = 0;
    int usernameindex = 0;
    int phnumberindex = 0;
    int addressindex = 0;
    string data[100];
    string draw;
    string answer;
    string press;
    string result;
    string username[100];
    string userphnumber[100];
    string useraddress[100];
    string _arrData[100];

    // method
    void welcome();
    void _integerloading();
    int IntegerRecord();
    void showdata();
    void recordfile();
    void integerChecking();
    void integerRecord();
    void allInfo();
    void forPress1();
    void chooseOption();
    void insertFun();
};

}


#endif //MY_PROJECT_CYCLE_H
