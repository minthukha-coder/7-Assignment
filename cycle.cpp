//
// Created by User on 10/11/2022.
//

#include "cycle.h"
#include"iostream"
#include"fstream"
using namespace N;
using namespace std;

void cycle::welcome() {
    cout << "Welcome to our cycle ticket shop " << endl;
    allInfo();
    showdata();
}

void cycle::showdata() {
    string draw;
    string phNumber;
    string address;
    string name;
    string result;
    string status;
    cout << "\nPlease enter your name: ";
    cin >> name;
    username[usernameindex] = name;

    cout << "Please enter your phone number: ";
    cin >> phNumber;
    userphnumber[phnumberindex] = phNumber;

    cout << "Please enter your address : ";
    cin >> address;
    useraddress[addressindex] = address;
        insertFun();
        chooseOption();
}

void cycle::chooseOption(){
    cout << "\nIf you wanna play again / Press 1 or Press 2 for next people Press 3 to exit  "<< endl;
    cin >> press;
    if (press == "1") {
        insertFun();
    } else if (press == "2") {
        showdata();
    } else if (press == "3") {
        exit(1);
    } else {
        cout << "Invalid option " << endl;
        chooseOption();
    }
}

void cycle::insertFun() {
    cout << "You can insert above number " << endl;
    cin >> draw;
    for (i = 0; i < index; i++) {
        if (data[i] == draw) {
            while (true) {
                cout << "It is cost 10000Ks for one coupon" << endl;
                cout << "Please pay 10000Ks for one coupon " << endl;
                cin >> money;
                if (money == 10000) {
                    currentData = i;
                    cout << username[usernameindex] << " " << userphnumber[phnumberindex] << " "
                         << useraddress[addressindex] << " " << data[i] << " " << endl;
                    recordfile();
                    integerRecord();
                    chooseOption();
                } else {
                    wrong = 1;
                }
                if (wrong == 1) {
                    cout << "Wrong paid amount! Try Again " << endl;

                }
            }
        }else{
            count = 1;
        }
    }
        if (count == 1) {
            cout << "It's number is already done " << endl;
            insertFun();
        }


}

    void cycle::allInfo() {

    for (i = 0;i < index;i++){
        cout << data[i] << " ";
    }
}


//void cycle::integerChecking() {
//    for (int m = i; m < index; m++) {
//        data[m] = data[m+1];
//    }
//    for (int a = 0; a < index - 1; a++) {
//        cout << data[a] << " ";
//    }
//
//}

void cycle::integerRecord() {
    string filename = "output.txt";
    ofstream outfile;
    outfile.open(filename);
    if (!outfile.is_open()) {
        cout << "Unable to Record data in file!" << endl;
        // to do somethings
    }
        for (int m = i; m < index; m++) {
            data[m] = data[m + 1];
        }
        for (int a = 0; a < index - 1; a++) {
            cout << data[a] << " ";
            string toRecord = data[a] + " ";
            outfile << toRecord;
        }

        outfile.close();

    }


    void cycle::recordfile() {
        string filename = "record.txt";
        ofstream outfile;
        outfile.open(filename, ios::app);
        if (!outfile.is_open()) {
            cout << "Unable to Record data in file!" << endl;
            // to do somethings
        }
        string toRecord =username[usernameindex] + " " + userphnumber[phnumberindex] + " " +useraddress[addressindex] + " "  + data[currentData] + "\n";

        outfile << toRecord;
        outfile.close();

    }



void cycle::_integerloading(){
    cout << "Loading process is running..\n.\n.\n" << endl;
    string output = "output.txt";
    string dataline;
    string alldata;
    ifstream outputfile(output);

    if (outputfile.is_open()){
        while (getline(outputfile,dataline)){
            dataline = dataline+" ";
            for (auto &ch: dataline) {
                if (ch == ' ') {
                        data[index] = alldata;
                        index++;
                        alldata = "";
                } else {
                    string st(1, ch);
                    alldata = alldata + st;
                }

            }
        }
    }else{
        cout << "Can't open " << endl;
    }

   welcome();
}
