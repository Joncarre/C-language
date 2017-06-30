//
//  Created by Jonathan Carrero.
//  Copyright (c) Jonathan Carrero. All rights reserved.
//

/*
  IMPORTANTE: 
  - Los nodos vac�os se representan con '.'
  - Los nodos en los que hay amigos se representan con 'X'
  - Los nodos en los que no hay amigos ni son hoja se representan con 'N'

  ENTRADA DE EJEMPLO:
  5
  N N X . . N . . X N . . X . .
  N N N . . N . . X N . . N . .
  N X N . . X . . X X . . X . .
  N X X . . X . . X X . . X . .
  N X . . N . .

  SALIDA DE EJEMPLO:
  4
  1
  5
  6
  1
*/
#include <iostream>
#include "Arbin.h"
using namespace std;

void resuelve();
// -----------------------------------------------------------------
// Complejidad: O(N), donde N es el n�mero de nodos en la entrada
void tiempoAyuda(const Arbin<char> &arbol, int &tiempo){
	if (arbol.esVacio()){ // Si es vac�o...
		tiempo = 0;
	}
	else {
		int tiempoIz, tiempoDr;
		// LLAMADA RECURSIVA
		tiempoAyuda(arbol.hijoIz(), tiempoIz);
		tiempoAyuda(arbol.hijoDr(), tiempoDr);
		// C�LCULO DEL TIEMPO
		tiempo = tiempoIz + tiempoDr;
		if (arbol.raiz() == 'X' && tiempo == 0)
			tiempo++;
		else if (tiempo > 0)
			tiempo++;
	}
}
// -----------------------------------------------------------------
// Complejidad: O(N), donde N es el n�mero de nodos en la entrada
Arbin<char> leerArbol(){
	char entrada;
	cin >> entrada;
	if (entrada == '.')
		return Arbin<char>();
	else{
		const Arbin<char> &iz = leerArbol();
		const Arbin<char> &dr = leerArbol();
		return Arbin<char>(iz, entrada, dr);
	}
}
// -----------------------------------------------------------------
// Complejidad: O(N), donde N es el n�mero de nodos en la entrada
void resuelve(){
	int tiempo = 0;
	Arbin<char> arbol = leerArbol();
	tiempoAyuda(arbol, tiempo);
	// El "tiempo - 1" se pone porque una vez que la recursi�n ha llegado a la cima, igualmente le suma 1,
	// pero en realidad no debe sumarle nada...
	cout << "Tiempo: " <<  tiempo - 1 << endl;
}
// -----------------------------------------------------------------
int main(){
	int numCasos;
	cin >> numCasos;
	for (int i = 0; i < numCasos; i++){
		resuelve();
	}
	system("PAUSE");
	return 0;
}
