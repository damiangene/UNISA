#include <iostream>
#include <string>

using namespace std;

class Address
{
    public:
        void set();
        void input();
        void output();

        
    Address(){
        streetName = "";
        streetNr = 0;
        city = "";
        postalCode = "0000";
    }

    private:
        string streetName;
        int streetNr;
        string city;
        string postalCode;
};

int main(){
    Address address_1;

    address_1.set();
    address_1.output();

    return 0;
}


void Address::set(){
    cout << "What street do you live in?" << endl;
    getline(cin, streetName);
    
    cout << "What is the number of your house?" << endl;
    cin >> streetNr;

    cout << "What city do you live in?" << endl;
    cin.ignore();
    getline(cin,city);

    cout << "What is your postal code?" << endl;
    cin >> postalCode;
    cout << endl;
}

void Address::output(){

    cout << streetNr << " " << streetName << endl;
    cout << city << endl;
    cout << postalCode << endl;
}

// Street name: Preller St
// Street number: 543
// City: Muckleneuk
// Postal code: 0002
