// exercice 1:
#include <iostream>
using namespace std;
class complex{
    private:
    float reel;
    float imaginaire;
    public:
    complex(float r=0,float i=0):reel(r),imaginaire(i){}
    void afficher(){
        cout<<reel<<"+"<<imaginaire<<"i"<<endl;
    }
    bool operator ==(const complex &other)const{
        return ((reel==other.reel)&&(imaginaire==other.imaginaire));
      
    }
    complex operator + (const complex &other )const{
        return complex(reel+ other.reel,imaginaire+other.imaginaire);
    }
    complex operator -(const complex &other)const{
        return complex(reel-other.reel,imaginaire-other.imaginaire);
    }
    complex operator *(const complex &other) const{
        return complex(reel*other.reel-imaginaire*other.imaginaire,imaginaire*other.imaginaire+reel*other.reel);
    }
    complex operator / (const complex &other )const{
        float  denominator =other.reel*other.reel+other.imaginaire*other.imaginaire;
        return complex((imaginaire*other.imaginaire+reel*other.reel)/denominator,(imaginaire*other.imaginaire-reel*other.reel)/denominator);
    }
};

int main() {
    float i1,r1,i2,r2;
    int choice;
    
    cout<<"donner la valeur reel de  prmier nombre complex ";
    cin>>r1;
      cout<<"donner la valeur imaginaire  de  prmier nombre complex ";
    cin>>i1;
      cout<<"donner la valeur reel  de  deuxieme nombre complexe";
    cin>>r2;
     cout<<"donner la valeur imaginaire  de  deuxieme nombre complexe";
    cin>>i2;
    complex c1(r1,i1);
     complex c2(r2,i2);
     c1.afficher();
     c2.afficher();
     cout<<"choose an operation:\n 1. egalite:\n 2. add:\n 3. soustract\n 4. multip:\n 5. division\n the operation is :";
     cin>>choice;
     
     switch(choice){
         case 1:
              cout<<"reslut de'egalite";
              if(c1==c2)
                cout<<"the complex are equal";
              else 
                  cout<<"the complex are not  equal";
                break;
          case 2:
              cout<<"reslut d'addition";
              (c1 + c2).afficher();
                break;
       case 3:
              cout<<"reslut de soustraction";
              (c1 - c2).afficher();
              break;
       case 4:
              
              cout<<"reslut de multiplication";
             (c1 * c2).afficher();
                break;
         case 5:
            
              cout<<"reslut de division ";
              (c1 / c2).afficher();
                break;
        
        default:
        cout<<"invalid choice";
     }
return 0;
}
//exercice 2
#include<iostream>
#include<string>
using namespace std;
class animal{
    protected:
    int age ;
    string nom;
    public:
    void set_value(const string& n,int a){
        nom=n;
        age=a;
    }
        virtual void afficher() const=0;
};
class zebra:public animal{
    private:
    string lieu="afrique";
     public:
    void afficher() const override{
        cout<<" je suis un zebra nomme "<<nom<<"\tj'ai\t"<<age<<"ans et je viens de "<<lieu<<endl;
    }
    };
    class dauphin:public animal{
    private:
    string lieu="ocean atlantique ";
     public:
    void afficher() const override{
        cout<<" je suis un Dauphin  nomme "<<nom<<"\tj'ai\t"<<age<<"ans et je viens de "<<lieu;
    }
    };
    int main(){
        zebra z1;
        dauphin d1;
        z1.set_value("stripes",4);
        d1.set_value("echo",6);
        z1.afficher();
        d1.afficher();
        return 0;
    }
     //exercice 3:
     #include<iostream>
#include<string>
using namespace std;
class personne{
    protected:
    string nom;
    string prenom ;
    string datedenaissance;
    public:
        personne(const string&n,const string&p,const string&dn):
            nom(n),
            prenom(p),
            datedenaissance(dn){}
            virtual void afficher ()const{
                cout<<"nom:"<<nom<<"prenom:"<<prenom<<"date de naissance :"<<datedenaissance<<endl;
            }
};
class employe : public personne {
    protected:
  double  salaire;
  
    public:
    employe(const string&n,const string&p,const string&dn,double s):personne(n,p,dn),salaire(s){}
    
    
    void afficher ()const override {
        personne:: afficher();
        cout<<"salaire:"<<salaire<<"eur";
        
    }
};
class chef: public employe{
    protected:
    string service ;
    public:
    chef(const string&n,const string&p,const string&dn,double s,const string&ser):employe(n,p,dn,s),service(ser){}
    void afficher()const override{
        employe::afficher();
        cout<<"service:"<<service<<endl;
    }
};
class directeur: public chef{
     private:
    string societe  ;
    public:
    directeur(const string&n,const string&p,const string&dn,double s,const string&ser,const string&socie):chef(n,p,dn,s,ser),societe(socie){}
    void afficher()const override{
        chef::afficher();
        cout<<"societe:"<<societe <<endl;
    }
};
int main(){
    personne personne ("russel","daniell","01/10/2000");
    employe employe ("wallace","josseph","06/28/1998",2000);
    chef chef("tomene","nicol","08/29/1967",3000,"informatique");
    directeur directeur("leblanc","marie","04/10/1993",3500,"informatique","TechCorp");
    cout<<"information de personne :";
    personne.afficher();
    cout<<endl;
    cout<<"information d'employe:";
    employe.afficher();
    cout<<endl;
    cout<<"information de chef:";
    chef.afficher();
    cout<<endl;
    cout<<"information de directeur:";
    directeur.afficher();
    cout<<endl;
    return 0;
}
//exercice 4 
#include<iostream>
#include<vector>
#include<iterator>
#include<cmath>
using namespace std;
class vector3d{
    private:
    float x,y,z;
    public:
    vector3d(float x=0,float y=0,float z=0):x(x),y(y),z(z){}
    void afficher()const{
        cout<<"("<<x<<","<<y<<","<<z<<")"<<endl;
    }
    vector3d add(const vector3d&other)const{
        return vector3d(x+other.x,y+other.y,z+other.z);
    }
    float produit_scalaire(const vector3d&other)const{
        return x*other.x+y*other.y+z*other.z;
       } bool coincide(const vector3d&other)const{
            return (x==other.x)&&(y==other.y)&&(z==other.z);
        }
        float norme()const{
            return (sqrt(x*x+y*y+z*z));
        }
       vector3d normax(const vector3d&other)const{
           return(this->norme()>other.norme())? *this :other;
       }
       static vector3d* normax(const vector3d* v1,const vector3d* v2){
           return(v1->norme()>v2->norme())? const_cast<vector3d*>(v1): const_cast<vector3d*>(v2);
       }
       static vector3d& normax( vector3d& v1, vector3d& v2){
           return(v1.norme()>v2.norme()) ? v1:v2;
       }
       
    };
  int main(){
     vector3d v1(23,45,7);
     vector3d v2(12,52,9);
     cout<<"le vecteur 1 est :";
     v1.afficher();
       cout<<endl;
     cout<<" le vecteur  2 est :";
     v2.afficher();
     cout<<endl;
     vector3d add=v1.add(v2);
     add.afficher();
       cout<<endl;
     float produit_scalaire=v1.produit_scalaire(v2);
     cout<<" produit scalaire:"<<produit_scalaire <<endl;
     cout<<" les vecteur sont-ils identiques ?"<<(v1.coincide(v2)?"oui":"non")<<endl;
     cout<<"norme de vecteur 1:"<<v1.norme()<<endl;
     cout<<"norme de vecteur 2:"<<v2.norme()<<endl;
     vector3d maxnorme=v1.normax(v2);
     cout<<" le vecteur a plus grand norme est:";
     maxnorme.afficher();
     vector3d* maxnormepotr=vector3d::normax(&v1,&v2);
     cout<<" le vecteur a plus grand norme par adresse est:";
     maxnormepotr->afficher();
      vector3d& maxnormeref=vector3d::normax(v1,v2);
     cout<<" le vecteur a plus grand norme par reference  est:";
     maxnormeref.afficher();
     return 0;
     
  }
  //exercice 5:
  #include <iostream>
using namespace std;
class test{
    private:
    static int count;
    public:
    void call(){
        count++;
        cout<<"la fonction call a ete appele "<<count<<"fois"<<endl;
        
    }
};
    int test::count= 0;

int main() {
    test t1;
    test t2;
    
    t1.call();
    t2.call();
    t1.call();
    t2.call();
    return 0;
}
//EXERCICE 6
//point_h
#ifndef POINT_H
#define POINT_H
class point{
    private:
    float x,y;
    public:
    point(float x=0,float y=0);
    void deplacer (float dx,float dy);
    void afficher()const;
};
#endif
//point.cpp
#include "Point.h“ 
#include <iostream>
#include <cmath>
using namespace std;
void point::deplacer(float dx,float dy){
    x+=dx;
    y+=dy;
} 
void point::afficher(){
    cout<<"("<<x<<","<<y<<")"<<endl;
}

int main (){
    point p(3,5.5);
    cout<<" point initial";
    p.afficher();
    p.deplacer(2.-3) ;
    cout<<" point apres le deplacement:"
    p.afficher();
    return 0;
}
//EXERCICE 7
#ifndef PILE_H
#define PILE_H
#include <vector>


using namespace std;

class Pile{
    private :
    vector int element;
    public:
    Pile()=default;
    void push (int  valeur);
    int pop();
    bool estvide()const;
    
};
#endif
// pile.cpp
#include "Pile.h"
#include <iostream>
using namespace std;


void Pile::push(int valeur) {
    elements.push_back(valeur);  
}


int Pile::pop() {
    if (estVide()) {
        throw runtime_error("Erreur: La pile est vide.");
    }
    int valeur = elements.back();  
    elements.pop_back();  
    return valeur;
}

bool Pile::estVide() const {
    return elements.empty();
}


int main() {
    Pile p1, p2;
    p1.push(10);
    p1.push(20);
    p1.push(30);
    p2.push(5);
    p2.push(15);
    cout << "Dépilage de p1 : ";
    while (!p1.estVide()) {
        cout << p1.pop() << " ";
    }
    cout << endl;
    cout << "Dépilage de p2 : ";
    while (!p2.estVide()) {
        cout << p2.pop() << " ";
    }
    cout << endl;

    return 0;
}
//EXERCICE 8
#ifndef FICHIER_H
#define FICHIER_H
#include <iostream>
#include<cstring>
class fichier{
    private :
    char* p;
    size_t longueur;
    public:
    fichier();
    ~fichier();
    
    void creation(size_t taille);
    void remplir();
    void afficher()const;
    
};
#endif
//fichier cpp
#include "fichier.h"
#include <iostream>
using namespace std;

fichier::fichier() : P(nullptr), longueur(0) {}

fichier::~fichier() {
    if (P != nullptr) {
        delete[] P;  
        cout << "Mémoire libérée." << endl;
    }
}


void fichier::Creation(size_t taille) {
    if (P != nullptr) {
        delete[] P; 
    }
    longueur = taille;
    P = new char[longueur];
    cout << "Mémoire allouée de " << longueur << " octets." << endl;
}

void fichier::Remplit() {
    if (P != nullptr) {
        memset(P, 'A', longueur); 
        cout << "Zone mémoire remplie." << endl;
    } else {
        cout << "Aucune mémoire allouée pour remplir." << endl;
    }
}
void fichier::Affiche() const {
    if (P != nullptr) {
        for (size_t i = 0; i < longueur; ++i) {
            cout << P[i];
        }
        cout << endl;
    } else {
    cout << "Aucune mémoire allouée pour afficher." << endl;
    }
}

int main() {
    
    fichier* Fichier = new fichier;

    Fichier->Creation(10);   
    Fichier->Remplit();     
    cout << "Contenu de la zone mémoire : ";
    Fichier->Affiche();      
    delete Fichier; 

    return 0;
}
//exercice 9
#ifndef FICHIER_H
#define FICHIER_H
#include <iostream>
struct elemet {
    int valeur;
    element* suivant;
    element(int v): valeur(v),suivant(nullptr){}
};
class list {
    private:
    element*premier;
    public:
    list();
    ~list();
    void ajoutd(int valeur);
    void suprimer();
    void afficher() const ;
    
};
#endif
    //list cpp
    #include "list.h"
    #include <iostream>
    using namespace  std;
    list::list() :premier (nullptr){}
    list::~list(){
        while(premier!= nullptr){
            supprimerdebut();
        }
        
    }
    void list::ajoutd(int valeur){
        element* nouvelelement=new elememt (valeur);
        nouvelelment->suivant=premier;
        premier =nouvelelement;
    }
    void list::suprimer(){
        if(premier!=nullptr){
            element*suprimerelement=premier;
            premier=premier->suivant;
            delete supprimer;
        }    
        }
    void list::afficher(){
        element*courant=premier;
      while (courant!=nullptr){
          cout<<courant->valeur<<"";
          courant=courant->suivant;
          
      }
      cout <<endl;
      
}

int main() {
    Liste maListe;


    maListe.ajouterDebut(34);
    maListe.ajouterDebut(46);
    maListe.ajouterDebut(50);

   
    cout << "Contenu de la liste : ";
    maListe.afficher();

    maListe.supprimerDebut();
    cout << "Après suppression du premier élément : ";
    maListe.afficher();
    maListe.supprimerDebut();
    maListe.supprimerDebut();

    cout << "Après suppression de tous les éléments : ";
    maListe.afficher();  

    return 0;
}
//exercice 10
#include<iostream>
#include <string>
using namespace std;
int main(){
    string datetime ="031120242030";
    string day= datetime.substr(0,2);
    string month= datetime.substr(2,2);
    string year= datetime.substr(4,4);
    string hour= datetime.substr(8,2);
    string minute= datetime.substr(10,2);
   cout<<"day:"<<day<<endl;
   cout<<"month:"<<month<<endl;
   cout<<"year:"<<year<<endl;
   cout<<"hour:"<<hour<<endl;
   cout<<"minute:"<<minute<<endl;
   return 0;
    
}
//exercice 11 
#ifndef TRAITEMENT_H
#define TRAITEMENT_H

#include <iostream>
#include <vector>
#include <algorithm>

class Traitement {
private:
    std::vector<int> vecteur;
public:
    void Initialise();
    void show(int index = 0) const;
    friend double moyenne(const Traitement& t);
    friend double mediane(Traitement& t);
};

#endif
//traitement en cpp
#include "Traitement.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

void Traitement::Initialise() {
    int nombre;
    while (vecteur.size() < 15) {
        cout << "Entrez un entier pair non nul : ";
        cin >> nombre;
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrée invalide, veuillez entrer un entier." << endl;
            continue;
        }
        if (nombre != 0 && nombre % 2 == 0) {
            vecteur.push_back(nombre);
        } else {
            cout << "Veuillez entrer un entier pair et non nul." << endl;
        }
    }
}
void Traitement::show(int index) const {
    if (index < vecteur.size()) {
        cout << vecteur[index] << " ";
        show(index + 1); 
    } else if (index == 0) {
        cout << "Le vecteur est vide.";
    } else {
        cout << endl;
    }
}
double moyenne(const Traitement& t) {
    int somme = 0;
    for (int nombre : t.vecteur) {
        somme += nombre;
    }
    return t.vecteur.empty() ? 0 : static_cast<double>(somme) / t.vecteur.size();
}

double mediane(Traitement& t) {
    if (t.vecteur.empty()) return 0;
    std::sort(t.vecteur.begin(), t.vecteur.end());

    int n = t.vecteur.size();
    if (n % 2 == 0) {
        return (t.vecteur[n / 2 - 1] + t.vecteur[n / 2]) / 2.0;
    } else {
        return t.vecteur[n / 2];
    }
}

int main() {
    Traitement t;

    t.Initialise();
    cout << "Elements du vecteur : ";
    t.show();
    double moyenneVal = moyenne(t);
    cout << "Moyenne des éléments : " << moyenneVal << endl;

    double medianeVal = mediane(t);
    cout << "Médiane des éléments : " << medianeVal << endl;

    return 0;
}
