#include <iostream>
#include <string>
#include <map>
#include <ctype.h>

using namespace std;

class Scrabble {
    public:
        Scrabble();
        Scrabble(string word, int rem);
        ~Scrabble();
        void Calculate();
        void Penalize();
        void SetLetters();
        void GetLetters(string &let1,string &let2, string &let3);
        void SetWord(string word, int rest);
        string GetWord();
        int GetPoints();

    private:
        friend ostream & operator<<(ostream & out, const Scrabble & word);

        string letters1, letters2, letters3;
        string wordBuilt;
        int points;
        int unused;
};

Scrabble:: Scrabble(){
    wordBuilt = "SCRABBLE";
    unused = 10;
}

Scrabble:: Scrabble(string word, int rem){
    wordBuilt = word;
    unused = rem;
}

Scrabble:: ~Scrabble(){
    cout << "Objects deleted" << endl;
}

void Scrabble:: GetLetters(string &let1, string &let2, string &let3){
    let1 = letters1;
    let2 = letters2;
    let3 = letters3;
}

//Retrieve word
string Scrabble:: GetWord(){
    return(wordBuilt);
}

//Retrieve points
int Scrabble:: GetPoints(){
    return(points);
}

//Initialises sets of letters
void Scrabble:: SetLetters(){
    letters1 = "A B D L U R S I E O ";
    letters2 = "B S R L O T E M P U ";
    letters3 = "V C M O P A R G Y R ";
}

void Scrabble::SetWord(string word, int rest){
    wordBuilt = "";
    for (int i = 0; i < word.size(); i++){
        wordBuilt += toupper(word[i]);
    }
   
    unused = rest;
}

void Scrabble::Penalize(){
    points = points - (3*unused);
}

void Scrabble::Calculate(){
    points = 0;
    const std::map<char, int> score_list {
        {'Q', 1},
        {'T', 2}, {'S', 2}, {'C', 2}, {'L', 2}, {'N', 2},
        {'B', 3}, {'D', 3}, {'P', 3}, {'R', 3}, {'M', 3},
        {'A', 4}, {'E', 4}, {'I', 4}, {'O', 4}, {'U', 4},
        {'K', 8}, {'X', 8}, {'Z', 8}, {'W', 8}, {'Y', 8},
        {'V', 9}, {'F', 9}, {'G', 9}, {'J', 9}, {'H', 9}
    };

    for (int i = 0; i < wordBuilt.size(); i++){
        auto itr = score_list.find(wordBuilt[i]);
        points += itr->second;
    }
}

ostream & operator<<(ostream & out, const Scrabble & word){ 
    out << word.wordBuilt << " " << word.points << endl;

    return out;            
}

int main(){
    int point;
    string word;
    string let1, let2, let3;
    int rest;
    Scrabble Scrabble1;
    
    Scrabble1.SetLetters();
    Scrabble1.GetLetters(let1, let2, let3);
    
    cout << "\nLet's play a bit of scrabble...You get 3 tries..." << endl;
    cout << "Please make the longest word possible using the " << "following letters:\n" << let1 << endl;
    cout << "\nYou will be penalised for letters not used.\n";
    
    cin >> word;
    
    rest = 10 - word.size();
    
    Scrabble1.SetWord(word,rest);
    Scrabble1.Calculate();
    Scrabble1.Penalize();
    
    cout << Scrabble1 << endl;
    cout << "\nPlease make the longest word possible using the " << "following letters:\n"<<let2<<endl;
    cout << "\nYou will be penalised for letters not used.\n";
    
    cin >> word;
    
    rest = 10 - word.size();
    
    Scrabble1.SetWord(word,rest);
    Scrabble1.Calculate();
    Scrabble1.Penalize();

    cout << Scrabble1 << endl;
    cout << "\nPlease make the longest word possible using the " << "following letters:\n"<<let3<<endl;
    cout << "\nYou will be penalised for letters not used.\n";
    
    cin >> word;
    
    rest = 10 - word.size();
    
    Scrabble1.SetWord(word,rest);
    Scrabble1.Calculate();
    Scrabble1.Penalize();
    
    cout << Scrabble1 << endl;
    
    return 0;
}