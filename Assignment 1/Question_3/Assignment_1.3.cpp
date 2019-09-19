#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <math.h>

using namespace std;
ifstream inStream;
ofstream outStream;

int main(){
    
    inStream.open("marks.dat");
    if (inStream.fail()){
        cout << "Input file opening failed. \n" << endl;
        exit(1);
    }

    string student_marks[10][2];
    string subject;
    int weight1, mark1, weight2, mark2;
    int total;
    int i = 0;

    while (inStream >> subject >> weight1 >> mark1 >> weight2 >> mark2){
        
        total = (weight1*mark1 + weight2*mark2);

        student_marks[i][0] = subject;
        student_marks[i][1] = to_string(total).substr(0,2) + "." + to_string(total).substr(2,4) + "%";

        i++; 
    }   

    outStream.open("yearmark.dat");
    if (outStream.fail( ))
    {
    cout << "Output file opening failed.\n";
    exit(1);
    }

    for (int i = 0; i < 6; i++){
        outStream << student_marks[i][0] + " " + student_marks[i][1] + "\n"; 
    }
    return 0;
}