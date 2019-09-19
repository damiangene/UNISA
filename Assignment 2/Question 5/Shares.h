#include <iostream>
#include <string>

using namespace std;

class Shares{
    public:
        // default constructor
        Shares();

        // overloaded constructor to set values 
        Shares(string CName, int NShares, float UValue);
        
        // destructor that does nothing
        ~Shares(){}   
        
        // accessors
        int getNrShares();
        float getUnitValue();    
        void updateShares(const Shares & s1);
                       
    private:
        string company;                 // company name
        int nrShares;                   // the number of shares this shareholder owns
        float unitValue;                // the current value of one share
        double pastUnitValues [5];      // five past values.  

        friend bool operator==(const Shares & s1, const Shares & s2);         
        friend istream & operator>>(istream & input, Shares & share);
        friend ostream & operator<<(ostream & output, const Shares & share);
          
};

// A default constructor
Shares::Shares(){
    company = "";
    nrShares = 0;
    unitValue = 0;
    fill(pastUnitValues, end(pastUnitValues), 0);        
}

// An overloaded constructor
Shares::Shares(string CName, int NShares, float UValue){
    company = CName;
    nrShares = NShares;
    unitValue = UValue;
    fill(pastUnitValues, end(pastUnitValues), 0);  
}

// Accessor function for member variable nrShares.
int Shares::getNrShares(){
    return nrShares;
}
// Accessor function for member variable unitValues.
float Shares::getUnitValue(){
    return unitValue;
}

// An overloaded equality operator== to compare two Shares objects.
bool operator==(const Shares & s1, const Shares & s2){
    if (s1.company == s2.company){
        return true;
    }
    
    return false;
}

// An overloaded extraction operator >> to input values of type Shares.
istream & operator>>(istream & in, Shares & share){ 
    in >> share.company >> share.nrShares >> share.unitValue;
    for (int i = 0; i < 5; i++){
        in >> share.pastUnitValues[i];
    }
    return in;            
}

// An overloaded insertion operator << outputting all member variables.
ostream & operator<<(ostream & out, const Shares & share){ 
    out << share.company << " " << share.nrShares << " " << share.unitValue;
    for (int i = 0; i < 5; i++){
        out << " " << share.pastUnitValues[i];
    }
    out << endl;
    return out;            
}

// A member function that adds the number of shares bought to nrShares.
// Updates the value of unitValue and also updates pastUnitValues.
void Shares::updateShares(const Shares & s1){
    if (company != s1.company){
        nrShares += s1.nrShares;
    }
    
    unitValue = s1.unitValue;

    for (int i = 0; i < 4; i++){
        pastUnitValues[i] = pastUnitValues[i+1];
    }

    pastUnitValues[4] = s1.unitValue;
}