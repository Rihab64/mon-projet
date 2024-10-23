#include <iostream>
#include <string>

class Voiture {
private:
    std::string marque;
    std::string modele;
    int annee;
    float kilometrage;
    float vitesse;

public:
    Voiture() : marque("Inconnue"), modele("Inconnu"), annee(0), kilometrage(0.0), vitesse(0.0) {}

    Voiture(std::string marque, std::string modele, int annee, float kilometrage, float vitesse)
        : marque(marque), modele(modele), annee(annee), kilometrage(kilometrage), vitesse(vitesse) {}
    void accelerer(float valeur) {
        vitesse += valeur;
    }
    void freiner(float valeur) {
        vitesse -= valeur;
        if (vitesse < 0) vitesse = 0;
    }
    void afficherInfo() {
        std::cout << "Marque: " << marque << "\n"
                  << "Modèle: " << modele << "\n"
                  << "Année: " << annee << "\n"
                  << "Kilométrage: " << kilometrage << "\n"
                  << "Vitesse actuelle: " << vitesse << " km/h\n";
    }
    void avancer(float distance) {
        kilometrage += distance;
    }
    ~Voiture() {
        std::cout << "La voiture est détruite.\n";
    }
};

int main() {
    Voiture voiture1;
    voiture1.afficherInfo();
    Voiture voiture2("Toyota", "Corolla", 2022, 15000.0, 120.0);
    voiture2.afficherInfo();
    voiture2.accelerer(20);
    voiture2.afficherInfo();

    voiture2.freiner(50);
    voiture2.afficherInfo();

    voiture2.avancer(100);
    voiture2.afficherInfo();

    return 0;
}
