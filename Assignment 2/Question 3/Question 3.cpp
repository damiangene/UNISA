#include <iostream>
#include <string>

using namespace std;

class Restaurant{
    public:
        Restaurant(){
            Shifts[0] = "h1";
            Shifts[1] = "h2";
            Shifts[2] = "h3";
        };

        int getTables();
        int getTempStaff();
        int getPermStaff();
        string getShifts(int shift){
            return Shifts[shift];
        };

    private:
        string Menu;
        int Tables;
        int TempStaff;
        int PermStaff;
        string Shifts[3];
    };

int main(){

    Restaurant mimmos;

    //  .........(additional code)
    string menu = mimmos.Menu;
    //  .........(additional code)

    //get information about shift 3
    cout << "Shift info:" << mimmos[2].getShifts() << endl;
    return 0;
}
