#include <iostream>
#include <string>
#include "criter.h"


using namespace std;

void Animal::triar_animal() {
    srand(time(NULL));
    int a;
    a = 1 + rand() % 3;
    if (a == 1) {
        cout << "Ha nascut la teva mascota... Es un GOS!!!";
        tipus = "Gos";
    }
    if (a == 2) {
        cout << "Ha nascut la teva mascota... Es un GAT!!!";
        tipus = "Gat";
    }
    if (a == 3) {
        cout << "Ha nascut la teva mascota... Es un Capibara!!!";
        tipus = "Capibara";
    }
}


void Animal::posar_nom() {
    cout << "\nIntrodueix el nom el qual vols posar al teu " << tipus << ": ";
    cin >> nom;
    temps = 1;
}



void Animal::passar_temps() {
    cout << "\n";
    if (temps == 0) {
        cout << "A pasat molt poc temps, els nivells actuals no han canviat\n";
    }
    if (temps == 1) {
        gana= gana +1;
        aburriment = aburriment + 1;
        cout << "Ha passat el temps, la gana i el aburriment han augmentat una mica. Consulta-ho per saber el seu nivell actual\n";
        temps = 0;
    }
    if (temps == 2) {
        gana = gana + 3;
        aburriment = aburriment + 3;
        cout << "Ha passat el temps, la gana i el aburriment han augmentat. Consulta-ho per saber el seu nivell actual.\n";
        temps = 0;
    }
    if (temps == 3) {
        gana = gana + 5;
        aburriment = aburriment + 5;
        cout << "Ha passat el temps, la gana i el aburriment han augmentat notablement. Es recomana consultar el nivell per evitar problemes.\n";
        temps = 0;
    }
    if (temps == 4) {
        gana = gana + 2;
        cout << "Ha passat un temps mentres jugabes.Ha augmentat el nivell de gana. Consulta-ho per saber el seu nivell actual\n";
        temps = 0;
    }
    if (temps == 5) {
        aburriment = aburriment + 2;
        cout << "Ha passat un temps mentres manjabes.Ha augmentat el nivell de aburriment. Consulta-ho per saber el seu nivell actual\n";
        temps = 0;
    }
}


void Animal::consultar_nivells() {
    cout << "El nivell de Gana actual es: " << gana << "\n";
    cout << "El nivell de Aburriment actual es: " << aburriment << "\n";

    //nivells gana
    if (gana <= 5) cout << "El " << nom << " te gana, es recomana donar de menjar.\n";
    else if (gana >= 6 && gana <=9 ) cout << "El " << nom << " te molta gana, es recomana que es dongui de menjar urgentment.\n";
    else if (gana == 10) cout << "El " << nom << " esta en estat de emergencia degut a la gana que te, podria ser la ultima oportunitat de baixar el seu nivell de gana.\n";

    //nivells aburriment
    if (aburriment <= 5) cout << "El " << nom << " esta aburrit, es recomana jugar amb ell.\n";
    else if (aburriment >= 6 && aburriment <= 9) cout << "El " << nom << " esta molt aburrit, es recomana jugar amb ell urgentment.\n";
    else if (aburriment == 10) cout << "El " << nom << " esta en estat de emergencia degut a la gana que te, podria ser la ultima oportunitat de baixar el seu nivell de gana.\n";
}


void Animal::perdre_vida() {
    if (gana >= 11) {
        cout << "----------HAS PERDUT----------\n";
        cout << "El teu " << tipus << " a arribat a uns nivells de gana tant extrems que ha marxat a un lloc millor.\n";
        cout << "Esperem que sigui feliç alla on sigui.\n";
        vida = false;
    }
    if (aburriment >= 11) {
        cout << "----------HAS PERDUT----------\n";
        cout << "El teu " << tipus << " a arribat a uns nivells de aburriment tant extrems que ha escapat.\n";
        cout << "Esperem que sigui feliç siguent lliure.\n";
        vida = false;
    }
}
bool Animal::acabar_vida() {
    return vida;
}
void Animal::jugar() {
    cout << "A que vols jugar amb el teu " << tipus;
    cout << "\n1- Jugar a la pilota\n";
    cout << "2- Jugar amb altres " << tipus << "\n";
    int jugaralgo = 0;
    cin >> jugaralgo;
    switch (jugaralgo)
    {
    case 1:
        cout << "Tu i el " << nom << " jugueu un rato a tirar i buscar una pilota.\n";
        aburriment = aburriment - 1;
        temps = 4;
        if (aburriment << 0) aburriment = 0;
        break;
    case 2:
        cout << "Aneu al parc de " << tipus << " i paseu un rato.";
        aburriment = aburriment - 3;
        temps = 4;
        if (aburriment << 0) aburriment = 0;
        break;
    }
}

void Animal::donar_menjar() {
    cout << "A que vols donar de menjar al teu " << tipus;
    cout << "\n1- Donar Galeta\n";
    cout << "2- Donar sushi \n";
    int jugaralg2o = 0;
    cin >> jugaralg2o;
    switch (jugaralg2o)
    {
    case 1:
        cout << "Dones una galeta al " << nom << ".\n";
        gana = gana - 1;
        temps = 5;
        if (gana << 0) gana = 0;
        break;
    case 2:
        cout << "Dons al "<< nom << "un bon plat de sushi";
        gana = gana - 3;
        temps = 5;
        if (gana << 0) gana = 0;
        break;
    }
}