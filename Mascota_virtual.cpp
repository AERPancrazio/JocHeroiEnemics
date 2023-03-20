// Mascota_virtual.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

//simple critter
//demonstrates creating a new type

#include <iostream>
#include <string>
#include "criter.h"
using namespace std;

int main() {
    
    int triar;
    Animal mascota;

    mascota.triar_animal();

    do {
        
        cout << "\n-------------------------------------------------------------\n";
        cout << "\nQue vols fer?\n";
        cout << "1- Posar nom a la mascota\n";
        cout << "2- Consultar Nivells\n";
        cout << "3- Donar Menjar\n";
        cout << "4- Jugar\n";
        cout << "5- Sortir\n";
        cout << "\nOpcio triada: ";

        cin >> triar;
        switch (triar) {
        case 1:
            mascota.posar_nom();
            mascota.passar_temps();
            mascota.perdre_vida();
            break;
        case 2:
            mascota.consultar_nivells();
            mascota.passar_temps();
            mascota.perdre_vida();
            break;
        case 3:
            mascota.donar_menjar();
            mascota.passar_temps();
            mascota.perdre_vida();
            break;
        case 4:
            mascota.jugar();
            
            mascota.passar_temps();
            mascota.perdre_vida();
            break;
        }
       

    } while (triar < 5 && mascota.acabar_vida());
	return 0;
}
