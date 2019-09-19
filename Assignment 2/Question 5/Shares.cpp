#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Shares.h"

using namespace std;

ifstream in;
ofstream out;

int main(){

    string company;
    int nrShares;
    float unitValue, total = 0;
    Shares temp;
    bool exist = false;


    in.open("Portfolio.dat");
    if (in.fail()){
        cout << "Input file opening failed. \n" << endl;
        exit(1);
    }

    out.open("NewPortfolio.dat");
    if (out.fail()) {
    cout << "Output file opening failed.\n";
    exit(1);
    }

    cout << "Enter name of company in which shares are bought: ";
    cin >> company;

    cout << "Enter number of shares bought: ";
    cin >> nrShares;

    cout << "Enter unit value of one share: ";
    cin >> unitValue;

    Shares newShares(company, nrShares,unitValue);

    while(in >> temp){
        if(newShares == temp){
            temp.updateShares(newShares);
            exist = true;
        }
  
        out << temp; 
        total += temp.getNrShares() * temp.getUnitValue();       
    }

    if (!exist){
        newShares.updateShares(newShares);
        total += newShares.getNrShares() * newShares.getUnitValue();
        out << newShares;
    }

    cout << "Total value of all shares: R" << total << endl;
    
    return 0;
}