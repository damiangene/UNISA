#include <iostream>
#include <cmath>

using namespace std;

double windchill(double v, double t);

int main(){

    double t, v;

    cout << "Wind speed in m/sec:";
    cin >> v;

    do{
        cout << "Temperature in degrees:";
        cin >> t;
    }while(t>10);

    cout << windchill(v, t) << endl;    

    return 0;
}

double windchill(double v, double t){
    return (13.12 + (0.6215 * t)) - (11.37 * pow(v,0.16)) + (0.3965 * t * pow(v,0.016));
}