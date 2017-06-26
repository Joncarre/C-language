//
//  Created by Jonathan Carrero.
//  Copyright (c) Jonathan Carrero. All rights reserved.
//

#ifndef PARTIDA_H
#define PARTIDA_H

#include <string>
#include <iostream>
#include "fecha.h"
#include "Conecta4.h"
using namespace std;

typedef enum { EnCurso, Terminada } tEstadoPartida;

typedef struct {
	string id_Partida;
	string jugador1;
	string jugador2;
	tFecha inicio;
	tFecha actualizacion;
	tEstadoPartida estadoPartida;
	tConecta4 juego;
}tPartida;

// Recibe los identificadores de los adversarios (sus nombres) y devuelve una partida con todos sus datos rellenos.
void nueva(tPartida & partida, string const& jugador1, string const& jugador2);
// Aplica la jugada col al juego, y si se pudo realizar, devuelve true y actualiza los dem�s campos de la partida.
bool aplicarJugada(tPartida & partida, int col);
// Modifica el estado de la partida a 'Terminada', y la fecha de la �ltima actualizaci�n.
void abandonar(tPartida & partida);
// Dado un flujo de archivo, escribe los datos de la partida.
void guardar(tPartida const& partida, ofstream & archivo);
// Dado un flujo de archivo, lee los datos de la partida.
bool cargar(tPartida & partida, ifstream & archivo);

#endif  // PARTIDA_H
