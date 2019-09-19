#include <iostream>
#include <string>

using namespace std;

class Address{
    public:
        void set();
        void input();
        void output();
        string getPostalCode();

        
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
        friend istream & operator>>(istream & in, Address & address);
        friend ostream & operator<<(ostream & out, Address & address);
        
};

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

string Address::getPostalCode(){
    return postalCode;
}

ostream & operator<<(ostream & out, Address & address){
    out << address.streetNr << " " << address.streetName << endl;
    out << address.city << endl;
    out << address.postalCode << endl;
    out << endl;

    return out;
}

istream & operator>>(istream & in, Address & address){
    getline(in >> ws, address.streetName, '\n');
    in >> address.streetNr;
    getline(in >> ws, address.city);
    in >> address.postalCode;   

    return in;
}