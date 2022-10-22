#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("angajati.txt");
ofstream fout("angajati.txt");

ifstream gin("animale.txt");
ofstream gout("animale.txt");

ifstream hin("produse.txt");
ofstream hout("produse.txt");

int alegere;
class animal {
private:
    char rasa;
    string cod_animal; // merge?
    bool e_in_stoc; // merge?
    float pret_animal;
public:
    animal(char rasa, string cod_animal, bool e_in_stoc, float pret_animal)
    {
        this->rasa = rasa;
        this->cod_animal = cod_animal;
        this->e_in_stoc = e_in_stoc;
        this->pret_animal = pret_animal;
    }

    void citeste_date_animal()
    {
        gin >> rasa >> cod_animal >> e_in_stoc >> pret_animal;
    }
};

class produs {
private:
    string nume_produs;
    string cod_produs;
    bool e_in_stoc_produs;
    float pret_produs;
public:
    produs(string nume_produs, string cod_produs, bool e_in_stoc_produs, float pret_produs){
        this->nume_produs = nume_produs;
        this->cod_produs = cod_produs;
        this->e_in_stoc_produs = e_in_stoc_produs;
        this->pret_produs = pret_produs;
    }

    void citeste_date_produs()
    {
        hin >> nume_produs >> cod_produs >> e_in_stoc_produs >> pret_produs;
    }
};

class angajat {
private:
    char nume;
    string prenume;
    int CNP;
    int ani_vechime;
    string departament;
    double salariu;
public:
    angajat(char nume, string prenume, int CNP, int ani_vechime, string departament, double salariu) {
        this->nume = nume;
        this->prenume = prenume;
        this->CNP = CNP;
        this->ani_vechime = ani_vechime;
        this->departament = departament;
        this->salariu = salariu;
    }

    void citeste_date_angajat() {
        fin >> nume >> prenume >> CNP >> ani_vechime >> departament >> salariu;
    };

    /*void scrie_date_angajat() {
        cout << nume << prenume << CNP << ani_vechime << departament << salariu;
    };*/

    void setSalariu(int s) {
        salariu = s;
    }

    double getSalariu() {
        return salariu;
    }

    int getCNP() {
        return CNP;
    }

    int getAniVechime() {
        return ani_vechime;
    }
    void cere_promovare() {
        if (ani_vechime >= 2) {
            setSalariu(ani_vechime * 0.1 * salariu + salariu);
            cout << "Felicitari, " << prenume << ", suntem de acord cu cererea dumneavoastra. Noul dumneavoastra salariu va fi " <<  salariu <<" RON. Multumim pentru toata munca depusa!\n";
        }
        else
            cout << "Ne cerem scuze, " << prenume << ", nu indeplinti criteriul necesar pentru aprobarea acestei cereri.\n";

    }
};

    vector <angajat> lista_angajati;
    vector <animal> lista_animale;
    vector <produs> lista_produse;

   void citire()
   {
        int i, j, k;
        for (i=1; i <= lista_angajati.size(); i++)
            lista_angajati.at(i).citeste_date_angajat();
       /*for (i=1; i <= lista_angajati.size(); i++)
           lista_angajati.at(i).scrie_date_angajat();*/
        for (j=1; j <= lista_animale.size(); j++)
           lista_animale.at(i).citeste_date_animal();
        for (k=1; i <= lista_produse.size(); k++)
           lista_produse.at(i).citeste_date_produs();
   }

    void aplica_promovare() {
        int CNP, cnp_fixat;
        cout << "\t\t\t\t\t\tAPLICARE PENTRU PROMOVARE/MARIRE SALARIALA\n\n";
        cout << "Vrem sa rasplatim angajatii care lucreaza la noi de cel putin 2 ani cu o promovare.\n";
        cout<< "Va rugam sa va treceti Codul Numeric Personal (CNP), iar noi va vom spune daca va calificati pentru o marire, si cat va fi noul dumneavoastra salariu\n";
        cout << "\n\tCNP:\t";
        cin >> cnp_fixat;
        for (int i=1; i <= lista_angajati.size(); i++)
        {
            if (lista_angajati.at(i).getCNP() == cnp_fixat)
                lista_angajati.at(i).cere_promovare();
        }

};
   void meniu(){
       citire();
    cout << "PETSHOP:\n" << "Selecteaza tasta cu numarul optiunii dorite: \n";
    cout << "1) Cauta animal pentru client\n";
    cout << "2) Cauta produs pentru client\n";
    cout << "3) Aplica pentru promovare/marire de salariu\n";
    cout << "4) Iesire din program\n";
    cout << "Optiunea numarul:   ";
    cin >> alegere;
       switch (alegere) {

           case 1:
           {
               // cautare_animal;
               break;
           }
           case 2:
               {
                   // cautare_produs;
                   break;
               }
           case 3:
           {
               aplica_promovare();
               break;
           }
           case 4:
               break;

       }
    cin.get();
}
   int main()
{
       citire();
    int alegere;
    meniu();
    // ce fac aici?? care e logica??
    while (alegere != 0){
        citire();
        meniu();
    }
    return 0;
}


