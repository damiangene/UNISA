#include <iostream>

using namespace std;

int main(){

    typedef float* flt_ptr;

    flt_ptr examMarks;
    float highest = 0;

    int nrElements;
    cout << "How many exam marks would you like to add: ";
    cin >> nrElements;

    examMarks =  new float[nrElements];

    for (int i = 0; i < nrElements; i++){
        cout << "Enter mark " << i + 1 << endl;
        cin >> examMarks[i];

        if (examMarks[i] > highest){
            highest = examMarks[i];
        }
    }

    cout << "The highest mark achieved was: " << highest << endl;

    delete examMarks;

    return 0;
}