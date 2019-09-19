#include <iostream>
#include <cmath>

using namespace std;

double calcVolume(double l, double w, double h);
double calcVolume(double r);
double calcVolume(double r, double h);

const double PI = 3.14;

int main(){
    int choice;
    double l, w, h, r;

    cout << "What would you like to calculate the Volume of?" << endl;
    cout << "1:Box 2:Sphere 3:Cylinder" << endl;

    cin >> choice;

    switch(choice){
        case(1):
            cout << "Length: ";
            cin >> l;
            cout << "Width: ";
            cin >> w;
            cout << "Length: ";
            cin >> h;
            cout << calcVolume(l, w, h) << endl; 
            break;
        
        case(2):
            cout << "Radius: ";
            cin >> r;
            cout << calcVolume(r) << endl;
            break;
        
        case(3):
            cout << "Radius: ";
            cin >> r;
            cout << "Height:";
            cin >> h;
            cout << calcVolume(r, h) << endl;
            break;
    }
        
    
    return 0;
}

double calcVolume(double l, double w, double h){
    return (l*w*h);
}

double calcVolume(double r){ 
    return (4.0/3)*(PI)*(pow(r,3));
}

double calcVolume(double r, double h){
     return (PI)*(pow(r,2))*h;
}