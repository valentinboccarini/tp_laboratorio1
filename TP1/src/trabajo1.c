/*
 ============================================================================
 Name        : tp1.c
 Author      : Valentin Boccarini
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : 8 abr. 2022
 Profesores	 : Gaston Argibay, Camila Iglesias Guerrero.
 Division	 : 1E
 Materia	 : Laboratorio/Programacion I
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define Bitcoin 4606954.55

int main(void) {

	setbuf(stdout, NULL);
    int opcionMenu;
    float kilometros;
    float precioAerolineas;
    float precioLatam;
    float precioLatamDebito;
    float precioAerolineasDebito;
    float precioLatamCredito;
    float precioAerolineasCredito;
    float precioLatamBitcoin;
    float precioAerolineasBitcoin;
    float precioLatamUnitario;
    float precioAerolineasUnitario;
    float diferenciaPrecios;
    int primerFlag;
    int segundoFlag;
    int tercerFlag;

    kilometros = 0;
    primerFlag = 1;
    segundoFlag = 1;
    tercerFlag = 1;


    	do
    	{
    		printf("\n1. Ingrese los kilometros: (km = %.2f)", kilometros);
    		printf("\n2. Ingrese el precio de los vuelos\n- Precio vuelo Aerolineas: %.2f\n- Precio vuelo Latam: %.2f", precioAerolineas, precioLatam);
    		printf("\n3. Calcular todos los costos:");
    		printf("\n4. Informar resultados");
    		printf("\n5. Carga forzada de datos.");
    		printf("\n6. Salir.");

    		if(!utn_getInt(&opcionMenu,"\nIngrese una opción: ","\nOpcion incorrecta, reintente: ",1,6,3))
				{
				switch(opcionMenu)
				{
					case 1:
						if(utn_getFloat(&kilometros, "\nIngrese los kilometros: ","\nEl rango de Kilometros ingresados es incorrecto.\nReingrese los kilometros: ",0,99999999,5) != 0)
						{
							printf("\nHubo un error en la carga de kilometros. Reinicie le programa.");
							break;
						}
						primerFlag = 0;
						break;

					case 2:
						if(!utn_getFloat(&precioAerolineas,"\nIngrese el precio del vuelo en Aerolineas: ","\nEl precio ingresado es incorrecto, reingrese el precio: ",0,99999999,5))
						{
							if(utn_getFloat(&precioLatam,"\nIngrese el precio del vuelo en Latam: ","\nEl precio ingresado es incorrecto, reingrese el precio: ",0,99999999,5) != 0)
							{
								printf("\nHubo un error en la carga de los precios. Reinicie el programa.");
								break;
							}
						}
						segundoFlag = 0;
						break;

					case 3:

						if(!primerFlag && !segundoFlag)
						{
							if (!sacarPrecioConTarjetaDebito(precioLatam, &precioLatamDebito)
								&& !sacarPrecioConTarjetaDebito(precioAerolineas, &precioAerolineasDebito)
								&& !sacarPrecioTarjetaCredito(precioLatam, &precioLatamCredito)
								&& !sacarPrecioTarjetaCredito(precioAerolineas, &precioAerolineasCredito)
								&& !sacarPrecioBitcoin(precioLatam, Bitcoin, &precioLatamBitcoin)
								&& !sacarPrecioBitcoin(precioAerolineas, Bitcoin, &precioAerolineasBitcoin)
								&& !sacarPrecioUnitario(kilometros, precioLatam, &precioLatamUnitario)
								&& !sacarPrecioUnitario(kilometros, precioAerolineas, &precioAerolineasUnitario)
								&& !sacarDiferenciaEntrePrecios(precioAerolineas, precioLatam, &diferenciaPrecios))
							{
								printf("\nLos calculos ya se realizaron con exito.\n");
								tercerFlag = 0;
							}
						}
						else
						{
							printf("\nPara poder realizar el calculo de costos primero, ingrese el valor de los vuelos y los kilometros.\n");
						}
						break;
					case 4:
						if(!tercerFlag)
						{
							informe(kilometros, precioLatam,precioLatamDebito, precioLatamCredito,
									precioLatamBitcoin, precioLatamUnitario, precioAerolineas,
									precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin,
									precioAerolineasUnitario, diferenciaPrecios);
						}
						else
						{
							printf("\nPara poder informar los costos, primero hay que calcularlos en la opcion (3\n");
						}
						break;

					case 5:
						kilometros = 7090;
						precioAerolineas = 162965;
						precioLatam = 159339;
						if (!sacarPrecioConTarjetaDebito(precioLatam, &precioLatamDebito) &&
							!sacarPrecioConTarjetaDebito(precioAerolineas, &precioAerolineasDebito)
							&& !sacarPrecioTarjetaCredito(precioLatam, &precioLatamCredito)
							&& !sacarPrecioTarjetaCredito(precioAerolineas, &precioAerolineasCredito)
							&& !sacarPrecioBitcoin(precioLatam, Bitcoin, &precioLatamBitcoin)
							&& !sacarPrecioBitcoin(precioAerolineas, Bitcoin, &precioAerolineasBitcoin)
							&& !sacarPrecioUnitario(kilometros, precioLatam, &precioLatamUnitario)
							&& !sacarPrecioUnitario(kilometros, precioAerolineas, &precioAerolineasUnitario)
							&& !sacarDiferenciaEntrePrecios(precioAerolineas, precioLatam, &diferenciaPrecios))
						{
							informe(kilometros, precioLatam,precioLatamDebito, precioLatamCredito,
								    precioLatamBitcoin, precioLatamUnitario, precioAerolineas,
									precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin,
									precioAerolineasUnitario, diferenciaPrecios);
							primerFlag = 0;
							segundoFlag = 0;
							tercerFlag = 0;
						}
						break;
					case 6:
						break;
					}
				}

    } while (opcionMenu != 6);

	return 0;
}
