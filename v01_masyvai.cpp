
//
//  main.cpp
//  V01_masyvas
//
//  Created by Kamilė Zobėlaitė on 2024-02-13.
//

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>

#define x 50        // nd masyvo dydis x

using namespace std;

struct Vartotojas
{
    string vardas;
    string pavarde;
    int nd[x];              // namu darbu masyvas
    int egz;                // studento egzamino rezultatas
    double vid = 0.0;       // namu darbu pazymiu vidurkis
    double gal = 0.0;       // galutinis ivertinimas
    double med = 0.0;       // namu darbu mediana
    
};
double Vidurkis(double suma, int nariai);
double Mediana(int paz[], int nariai);
void Ivesti(Vartotojas vart[], int &n);
void spausdinti(int rnkts, Vartotojas vart[], int n);
double generavimasPaz();

int main() {

    int n;
    cout << "Iveskite vartotoju skaiciu:" << endl;
    cin >> n;
    Vartotojas vart[n];
    int pasirinkimas;
    cout << "Pasirinkite: " << endl;
    do{
        // meniu skiltis pasirinkimai
        cout << "Jeigu norite ivesti duomenis ranka, spauskite 1" << endl;
        cout << "Jeigu norite, kad pazymiai butu generuojami automatiskai, spauskite 2" << endl;
        cout << "Jeigu norite, kad pazymiai, studentu vardai ir pavardes butu generuojami automatiskai, spauskite 3" << endl;
        cout << "Jeigu norite, kad programa baigtu darba, spauskite 4" << endl;
        cin >> pasirinkimas;
        switch(pasirinkimas) {
            case 1: {
                for (int i = 0; i < n; i++)
                {
                    double sum = 0.0;
                    cout << "Iveskite " << i+1 << "-ojo studento varda:" << endl;
                    cin >> vart[i].vardas;
                    cout << "Iveskite " << i+1 << "-ojo pavarde:" << endl;
                    cin >> vart[i].pavarde;
                    cout << "Iveskite pazymius uz namu darbus kai noresite baigti ivedima, irasykite 0: " << endl;
                    int pazymys;
                    int kiek = 0;
                    while(true){
                        cin >> pazymys;
                        
                        while (!cin>>pazymys || pazymys < 0 || pazymys > 10)
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Klaida! Pazymys turi buti nuo 1 iki 10: \n";
                            cin >> pazymys;
                          
                        }
                        if(pazymys==0)
                            break;
                        vart[i].nd[kiek] = pazymys;
                        sum+=pazymys;
                        kiek++;
                       
                    }
                    cout << "Iveskite egzamino rezultata:" << endl;
                    cin >> vart[i].egz;
                    while(!cin >> vart[i].egz ||vart[i].egz<1 || vart[i].egz>10)
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "Klaida! Egzamino rezultatas turi buti nuo 1 iki 10: \n";
                        cin >> vart[i].egz;
                    }
                    vart[i].vid = Vidurkis(sum, kiek);
                    vart[i].med = Mediana(vart[i].nd, kiek);
                }
                
            }
        }
    } while(pasirinkimas != 4);
//
//    for (int i = 0; i < n; i++)
//    {
//        double sum = 0.0;        // tarpiniu pazymiu suma
//        cout << "Iveskite " << i+1 << "-ojo studento varda:" << endl;
//        cin >> vart[i].vardas;
//        cout << "Iveskite " << i+1 << "-ojo pavarde:" << endl;
//        cin >> vart[i].pavarde;
//        cout << "Kiek yra tarpiniu pazymiu?" << endl;
//        cin >> kiek;
//        while(kiek<1 || kiek>x)
//        {
//            cout << "Iveskite tarpiniu pazymiu kieki:" << endl;
//            cin >> kiek;
//        }
//        for (int j = 0; j < kiek; j++){
//            cout << "Iveskite " << j+1 << " pazymi" << endl;
//            cin >> vart[i].nd[j];
//            while(vart[i].nd[j]<1 || vart[i].nd[j]>10)
//            {
//                cout << "Klaida! Pazymys turi buti nuo 1 iki 10: \n";
//                cin >> vart[i].nd[j];
//            }
//            sum += vart[i].nd[j];
//        }
//        cout << "Iveskite egzamino rezultata:" << endl;
//        cin >> vart[i].egz;
//        while(vart[i].egz<1 || vart[i].egz>10)
//        {
//            cout << "Klaida! Egzamino rezultatas turi buti nuo 1 iki 10: \n";
//            cin >> vart[i].egz;
//        }
//        vart[i].vid = Vidurkis(sum, kiek);
//        vart[i].med = Mediana(vart[i].nd, kiek);
//        
//        
//    }
    
    int rnkts;      // pasirinkimas, kaip norima skaiciuoti galutini ivertinima - pagal vidurki ar mediana
    cout << "Pasirinkite kaip norite, kad skaiciuotu jusu galutini ivertinima: 0 - pagal vidurki, 1 - pagal mediana: " << endl;
    cin >> rnkts;
    spausdinti (rnkts, vart, n);
    
    
    return 0;
}
double Vidurkis(double suma, int nariai)
{
    return suma/nariai;
    
}

double Mediana(int paz[], int nariai)
{
    sort(paz, paz+nariai);
    if(nariai % 2 != 0)
        return double(paz[nariai/2]);
    return double(paz[(nariai-1) / 2] + paz[nariai/2] / 2.0);
    
}
//void Ivesti(Vartotojas vart[], int &n)
//{
//    
//    for(int i = 0; i < n; i++)
//    {
//        int kiek = 0;       // pazymiu uz nd kiekis
//        cout << "Iveskite " << i+1 << "-ojo studento varda:" << endl;
//        cin >> vart[i].vardas;
//        cout << "Iveskite " << i+1 << "-ojo pavarde:" << endl;
//        cin >> vart[i].pavarde;
//        while
//    }
//}

void spausdinti (int rnkts, Vartotojas vart[], int n)
{
    while (!cin>>rnkts || (rnkts != 0 && rnkts !=1))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Klaida! Turite pasirinkti 0 (galutinis ivert. skaiciuojamas pagal vidurki) arba 1 (pagal mediana): \n";
        cin >> rnkts;
    }
    if (rnkts == 0)
    {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)<< "Galutinis (vid.)" << endl;
        cout << "---------------------------------------------------" << endl;
        for ( int i = 0; i < n; i++)
        {
            vart[i].gal = 0.4*vart[i].vid+0.6*vart[i].egz;
            cout << left << setw(15) << vart[i].pavarde << setw(15) << vart[i].vardas << setw(15) << fixed << setprecision(2) << vart[i].gal << endl;
        }
        
        
    }
    else if (rnkts == 1)
    {
        cout << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(15)<< "Galutinis (med.)" << endl;
        cout << "---------------------------------------------------" << endl;
        for ( int i = 0; i < n; i++)
        {
            vart[i].gal = 0.4*vart[i].med+0.6*vart[i].egz;
            cout << left << setw(15) << vart[i].pavarde << setw(15) << vart[i].vardas << setw(15) << fixed << setprecision(2) << vart[i].gal << endl;
        }
        
    }
}
double generavimasPaz()
{
    srand(0);
    return rand()%10+1;
}
