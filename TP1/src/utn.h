/*
 * utn.h
  Name        : tp1.c
 Author      : Valentin Boccarini
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : 8 abr. 2022
 Profesores	 : Gaston Argibay, Camila Iglesias Guerrero.
 Division	 : 1E
 Materia	 : Laboratorio/Programacion I

 */

#ifndef UTN_H_
#define UTN_H_

#include <stdio.h>
#include <stdlib.h>


	int utn_getInt(int *, char *, char *, int, int, int);
	int utn_getFloat(float*, char*, char*, float, float, int);
	int sacarPrecioConTarjetaDebito(float, float*);
	int sacarPrecioTarjetaCredito(float, float*);
	int sacarPrecioBitcoin(float,float, float*);
	int sacarPrecioUnitario(float, float, float*);
	int sacarDiferenciaEntrePrecios(float, float, float*);
	void informe(float, float, float, float, float, float, float, float, float, float, float, float);

#endif /* UTN_H_ */
