#include <iostream>
#include <vector>
#include <fstream>

using namespace std;
 
struct osoba
{
        string imie;
        string nazwisko;
        int wiek;
};
 
class populacja
{
    vector <struct osoba> spis;
    public:
        void wczytaj(const char *);  
        void wypiszJSON();
        void zapiszJSON(const char *);
                             
};
 
void populacja::wczytaj(const char *id)
{
    struct osoba dane;
    ifstream plikk;
    plikk.open(id);  
 
    if(plikk.good())  
        while(!plikk.eof())  
        {
            plikk  >> dane.imie;
            plikk  >> dane.nazwisko;
            plikk  >> dane.wiek;
 
            spis.push_back(dane);
        }
    plikk.close();  
}
 
void populacja::wypiszJSON()
{
    string wyp;
    ifstream plik;
    plik.open("a.txt");
    if(plik.good())
        while(!plik.eof())
        {
            plik>>wyp;
        }
    plik.close();
}
 
void populacja::zapiszJSON(const char *id)
{
    ofstream plik;
    plik.open(id);
    for (vector<struct osoba>::iterator it = spis.begin(); it != spis.end(); ++it)
    {
        plik <<"["<<"{"<<it->imie<<":"<<it->nazwisko<<":"<<it->wiek<<"}"<<"]"<< "\n";
        cout <<"["<<"{"<<it->imie<<":"<<it->nazwisko<<":"<<it->wiek<<"}"<<"]"<< "\n";
    }
    plik.close();  
}
 

int main(int argc, char** argv) {
    
    cout << "Content-Type:application/json;charset=UTF-8" << (char)13 << (char)10
    << "\n"
    << "[ \n "
    << "  { \"title\":\"imie nazwisko\", \"subtitle\":\"wiek\" } \n"
    << "]";
    
    cout << "\n\n";
    
    populacja P;
    P.wczytaj("wpisz.txt");
    P.wypiszJSON();
    P.zapiszJSON("a.txt");
return 0;
}
