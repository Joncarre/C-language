//
//  Created by Jonathan Carrero.
//  Copyright (c) Jonathan Carrero. All rights reserved.
//

/*
 ENTRADA DE EJEMPLO:
 6
 0 0 0 -1 -1 -1 -1 
 0 0 -1 -1 0 -1 -1 
 0 0 0 -1 -1 -1 0 -1 -1 
 0 0 -1 -1 0 0 -1 -1 -1
 0 0 -1 0 -1 -1 0 -1 -1
 0 -1 0 -1 0 -1 -1

 SALIDA DE EJEMPLO:
 SI
 SI
 SI
 SI
 NO
 NO
*/
#include <iostream>
#include <algorithm>
#include "Arbin.h"
using namespace std;

void resuelve();
Arbin<int> leerArbol();
int alturaMinima(Arbin<int> arbol);
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(N), donde N es el n�mero de elementos le�dos por la entrada
Arbin<int> leerArbol(){
	int numero;
	cin >> numero;

	if (numero == -1)
		return Arbin<int>();
	else{
		const Arbin<int> &iz = leerArbol();
		const Arbin<int> &dr = leerArbol();
		return Arbin<int>(iz, numero, dr);
	}
}
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(N), donde N es el n�mero de nodos que tiene el �rbol
int alturaMinima(Arbin<int> arbol){
	if (arbol.esVacio())
		return 0;
	else
		return 1 + min(alturaMinima(arbol.hijoIz()), alturaMinima(arbol.hijoDr()));
}
// ------------------------------------------------------------------------------------------------------
// Complejidad: O()
bool esZurdo(Arbin<int> &arbol){
	if (arbol.esVacio())
		return true;
	else{
		return (esZurdo(arbol.hijoIz()) &&
				esZurdo(arbol.hijoDr()) &&
				alturaMinima(arbol.hijoIz()) >= alturaMinima(arbol.hijoDr()));
	}
}
// ------------------------------------------------------------------------------------------------------
// Complejidad: O()
void resuelve(){
	Arbin<int> arbol;
	arbol = leerArbol();
	bool zurdo = esZurdo(arbol);
	if (zurdo)
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
