#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

ifstream inStream;
ofstream outStream;

int main(){

    string inputFile, outputFile;
    char temp;
    size_t pos1;
    bool endOfSentence = true;

    cout << "What file would you like to correct: ";
    cin >> inputFile;

    inputFile += ".txt";

    cout << "What file would you like to use for the output: ";
    cin >> outputFile;

    outputFile += ".txt";

    inStream.open(inputFile);
    if (inStream.fail()){
        cout << "Input file opening failed. \n" << endl;
        exit(1);
    }

    outStream.open(outputFile);
    if (outStream.fail()) {
    cout << "Output file opening failed.\n";
    exit(1);
    }

    while (inStream.get(temp), !inStream.fail()){
        if (temp == '5'){
            temp = 's';
        }

        if (temp == '.'){
            endOfSentence = true;
        }
        else if (endOfSentence && temp != ' '){
            temp = toupper(temp);
            endOfSentence = false;
        }
        
        outStream << temp;
    }    

    return 0;
}