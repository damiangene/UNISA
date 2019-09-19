#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "Address.h"

ifstream in;
ofstream out;


int main(){
    Address temp, addresses [20];
    string pCode;
    int i = 0;

    in.open("Address.dat");
    if (in.fail()){
        cout << "Input file opening failed. \n" << endl;
        exit(1);
    }

    cout << "Postal code: ";
    cin >> pCode;
    cout << endl;

    while (in >> temp){
        if (temp.getPostalCode() == pCode){
            addresses[i] = temp;
            i++;
        }
    }
    
    for (Address &adds : addresses){
        if (adds.getPostalCode() == "0000"){
            exit(0);
        }
        cout << adds;
    }

    return 0;
}