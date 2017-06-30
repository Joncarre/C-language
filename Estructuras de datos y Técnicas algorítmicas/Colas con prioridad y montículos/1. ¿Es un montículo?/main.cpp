//
//  Created by Jonathan Carrero.
//  Copyright (c) Jonathan Carrero. All rights reserved.
//
#include <iostream>
#include <math.h>
#include <algorithm>
#include "BinTree.h"
using namespace std;

void resuelve();
BinTree<int> leerArbol();
bool esOrdenado(BinTree<int> arbol, int padre); // 'esOrdenado' quiere decir que se cumple que es de m�nimos
int altura(BinTree<int> arbol); // Funci�n que devuelve la altura de un �rbol
bool esCompleto(BinTree<int> arbol); // Funci�n que nos dice si un �rbol es completo
bool esSemiCompleto(BinTree<int> arbol); // Funci�n que nos dice si un �rbol es semicompleto
bool esMonticulo(BinTree<int> arbol); // Funci�n que nos dice si es un mont�culo
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(logN  + 1), donde N es la altura del �rbol semicompleto
int altura(BinTree<int> arbol){
	if (arbol.empty())
		return 0;
	else
		return 1 + max(altura(arbol.left()) , altura(arbol.right()));
}
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(N), donde N es el n�mero de elementos que se leen por la entrada
BinTree<int> leerArbol(){
	BinTree<int> arbol;
	int elemento;
	cin >> elemento;

	if (elemento == -1)
		return BinTree<int>();
	else{
		const BinTree<int> &dr = leerArbol();
		const BinTree<int> &iz = leerArbol();
		return BinTree<int>(dr, elemento, iz);
	}
	return arbol;
}
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(N), tiene la misma complejidad que 'esCompleto'
bool esSemiCompleto(BinTree<int> arbol){
	if (arbol.empty())
		return true;
	else if (esCompleto(arbol))
		return true;
	else return (
		((altura(arbol.left()) == altura(arbol.right())) && esCompleto(arbol.left()) && esSemiCompleto(arbol.right())) ||
		((altura(arbol.left()) == altura(arbol.right()) + 1) && esCompleto(arbol.right()) && esSemiCompleto(arbol.left()))
		);
}
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(N), donde N es el n�mero de nodos del �rbol
bool esCompleto(BinTree<int> arbol){
	if (arbol.empty())
		return true;
	else 
		return (
		esCompleto(arbol.left()) &&
		esCompleto(arbol.right()) &&
		altura(arbol.left()) == altura(arbol.right())
		);
}
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(N), donde N es el n�mero de nodos que tiene el �rbol
bool esOrdenado(BinTree<int> arbol, int padre){
	if (arbol.empty())
		return true;
	else{
		if (esOrdenado(arbol.left(), arbol.root()) &&
			esOrdenado(arbol.right(), arbol.root()) &&
			padre <= arbol.root())
			return true;
		else 
			return false;
	}
}
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(N), la mayor complejidad de las funciones a las que llama est� en O(N), donde N es el n�mero de nodos
bool esMonticulo(BinTree<int> arbol){
	if (arbol.empty())
		return true;
	else
	if (esSemiCompleto(arbol) &&
		esOrdenado(arbol.left(), arbol.root()) &&
		esOrdenado(arbol.right(), arbol.root()) &&
		esMonticulo(arbol.left()) &&
		esMonticulo(arbol.right()))
		return true;
	else return false;
}
// ------------------------------------------------------------------------------------------------------
// Complejidad: O(N)
void resuelve(){
	BinTree<int> arbol;
	arbol = leerArbol();

	if (esMonticulo(arbol))
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
	//system("PAUSE");
	return 0;
}
