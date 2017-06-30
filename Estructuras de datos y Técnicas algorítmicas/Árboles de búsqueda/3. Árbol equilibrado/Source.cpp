//
//  Created by Jonathan Carrero.
//  Copyright (c) Jonathan Carrero. All rights reserved.
//

/*
ENTRADA DE EJEMPLO:

3
2 1 -1 -1 3 -1 4 -1 -1
1 -1 3 2 -1 -1 4 -1 -1
4 1 -1 -1 3 -1 2 -1 -1

SALIDA DE EJEMPLO:

SI
NO
NO
*/
#include <iostream>
#include "Arbin.h"
using namespace std;
void resuelve();
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(N), donde N es la cantidad de n�meros en la entrada
Arbin<int>* leerArbol(){
	int entrada;
	cin >> entrada;
	if (entrada == -1)
		return new Arbin<int>();
	else{
		Arbin<int> *iz = leerArbol();
		Arbin<int> *dr = leerArbol();
		return new Arbin<int> (*iz, entrada, *dr);
	}
}
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(N), donde N es la cantidad de n�meros en la entrada
void resuelve(){
	Arbin<int> *arbol = leerArbol();
	if (arbol->equilibradoPublico() && arbol->ordenadoPublico())	// Si es ordenado (de b�squeda) y est� equilibrado...
		cout << "SI" << endl;
	else
		cout << "NO" << endl;
}
// ------------------------------------------------------------------------------------------------------
int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++){
		resuelve();
	}
	system("PAUSE");
	return 0;
}
