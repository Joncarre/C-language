//
//  Created by Jonathan Carrero.
//  Copyright (c) Jonathan Carrero. All rights reserved.
//

/*
 ENTRADA DE EJEMPLO:
 5
 100 60 30 -1 -1 -1 58 -1 -1
 100 60 30 -1 -1 -1 59 -1 -1
 100 -1 -1
 100 83 -1 -1 -1
 100 82 -1 -1 -1

 SALIDA DE EJEMPLO:
 SI 3
 NO
 SI 1
 NO
 SI 2
*/
#include <iostream>
#include <algorithm>
#include "Arbin.h"
using namespace std;

void resuelve();
Arbin<int> leerArbol();
bool genealogico(Arbin<int> &arbol, int &padre, int &generaciones);
bool condicion(int hijo, int padre);
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
// Complejidad: O(N), donde N es el n�mero de nodos
int altura(Arbin<int> &arbol){
	if (arbol.esVacio())
		return 0;
	else
		return 1 + max(altura(arbol.hijoIz()), altura(arbol.hijoDr()));
}
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(1)
bool condicion(int hijo, int padre){
	if (padre - 18 >= hijo)
		return true;
	else
		return false;
}
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(N), donde N es el n�mero de nodos
bool genealogico(Arbin<int> &arbol){
	if (arbol.esVacio()) // Si es vac�o...
		return true;
	else if (arbol.hijoIz().esVacio() && arbol.hijoDr().esVacio()) // Si es hoja...
		return true;
	else if (arbol.hijoDr().esVacio()) // Si no tiene hijo derecho...
		return condicion(arbol.hijoIz().raiz(), arbol.raiz());
	else{ // Si tiene los dos hijos...
		return (genealogico(arbol.hijoIz()) &&
			genealogico(arbol.hijoDr()) &&
			condicion(arbol.hijoIz().raiz(), arbol.raiz()) &&
			condicion(arbol.hijoDr().raiz(), arbol.raiz()) &&
			(arbol.hijoIz().raiz() - 2 >= arbol.hijoDr().raiz()));
	}
}
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(N), donde N es el n�mero de nodos
void resuelve(){
	Arbin<int> arbol;
	arbol = leerArbol();
	bool correcto = genealogico(arbol);
	if (correcto)
		cout << "SI " << altura(arbol) << endl;
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
