#pragma once
#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	static int s_Total;
	
	void passar_temps();
	void posar_nom();
	void consultar_nivells();
	void jugar();
	void donar_menjar();
	void triar_animal();
	void perdre_vida();
	bool acabar_vida();

private:
	string nom;
	string tipus;
	int temps = 0;
	int gana = 0;
	int aburriment = 0;
	bool vida = true;
};