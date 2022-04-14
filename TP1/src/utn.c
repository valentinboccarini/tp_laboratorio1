/*
 * utn.c
 Name        : tp1.c
 Author      : Valentin Boccarini
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : 8 abr. 2022
 Profesores	 : Gaston Argibay, Camila Iglesias Guerrero.
 Division	 : 1E
 Materia	 : Laboratorio/Programacion I

 */


#include "utn.h"

int utn_getInt(int *pIngreso, char *mensaje, char *mensajeError, int minimo, int maximo, int reintento) {
	int retorno;
	int auxNumeroIngresado;
	int flagReintento;
	retorno = -1;
	if(pIngreso != NULL && mensaje != NULL && mensajeError != NULL && (minimo == -1 || minimo <= maximo || maximo == -1) && reintento >= -1) {
		do {
			printf("%s", mensaje);
			scanf("%d", &auxNumeroIngresado);
			scanf("%*[^\n]");
			if((minimo == -1 && auxNumeroIngresado <= maximo) || (auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo) || (auxNumeroIngresado >= minimo && maximo == -1)) {
				*pIngreso = auxNumeroIngresado;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);
				if(reintento == -1) {
					flagReintento = 1;
				} else {
					reintento--;
				}
			}
		} while(flagReintento == 1 || reintento >= 0);
	}
	return retorno;
}

int utn_getFloat(float *pIngreso, char *mensaje, char *mensajeError, float minimo, float maximo, int reintento) {
	int retorno;
	float auxNumeroIngresado;
	int flagReintento;
	retorno = -1;
	if(pIngreso != NULL && mensaje != NULL && mensajeError != NULL && (minimo == -1 || minimo <= maximo || maximo == -1) && reintento >= -1) {
		do {
			printf("%s", mensaje);
			scanf("%f", &auxNumeroIngresado);
			if((minimo == -1 && auxNumeroIngresado <= maximo) || (auxNumeroIngresado >= minimo && auxNumeroIngresado <= maximo) || (auxNumeroIngresado >= minimo && maximo == -1)) {
				*pIngreso = auxNumeroIngresado;
				retorno = 0;
				break;
			} else {
				printf("%s", mensajeError);

				if(reintento == -1) {
					flagReintento = 1;
				} else {
					reintento--;
				}
			}
		} while(flagReintento == 1 || reintento >= 0);
	}
	return retorno;
}
int sacarPrecioConTarjetaDebito(float precioIngresado, float* precioFinal)
{
	int retorno;
	float bufferResultado;

	retorno = -1;
	if(precioFinal != NULL)
	{
	bufferResultado = precioIngresado - precioIngresado * 0.10;
	*precioFinal = bufferResultado;
	retorno = 0;
	}

	return retorno;
}
int sacarPrecioTarjetaCredito(float precioIngresado, float* precioFinal)
{
	int retorno;
	float bufferResultado;

	retorno = -1;
	if(precioFinal != NULL)
	{
		bufferResultado = precioIngresado + precioIngresado * 0.25;
		*precioFinal = bufferResultado;
		retorno = 0;
	}

	return retorno;
}

int sacarPrecioBitcoin(float precioIngresado,float bitcoin,float* precioFinal)
{
	int retorno;
	float bufferResultado;

	retorno = -1;

	if(precioFinal != NULL)
	{
		bufferResultado = precioIngresado / bitcoin;
		*precioFinal = bufferResultado;
		retorno = 0;
	}
	return retorno;
}

int sacarPrecioUnitario(float kilometros, float precioIngresado, float* precioFinal)
{
	int retorno;
	float bufferResultado;

	retorno = -1;
	if(precioFinal != NULL)
	{
		bufferResultado = precioIngresado / kilometros;
		*precioFinal = bufferResultado;
		retorno = 0;
	}
	return retorno;
}

int sacarDiferenciaEntrePrecios(float precioAerolineas, float precioLatam, float* diferencia)
{
	int retorno;
	float bufferResultado;

	retorno = -1;
	if(diferencia != NULL)
	{
		if(precioAerolineas > precioLatam)
		{
			bufferResultado = precioAerolineas - precioLatam;
		}
		else
		{
			bufferResultado = precioLatam - precioAerolineas;
		}
		*diferencia = bufferResultado;
		retorno = 0;
	}
	return retorno;
}

void informe(float kilometros,float precioLatam, float precioLatamDebito, float precioLatamCredito, float precioLatamBitcoin,
		float precioLatamUnitario, float precioAerolineas, float precioAerolineasDebito, float precioAerolineasCredito, float precioAerolineasBitcoin,
		float precioAerolineasUnitario, float diferenciaPrecios)
{
	printf("\nKMs Ingresados: %.2f"
			"\n\nPrecio Latam: $%.2f"
			"\na) Precio con tarjeta de debito: $%.2f"
			"\nb) Precio con tarjeta de credito: $%.2f"
			"\nc) Precio pagando con Bitcoin: %f BTC"
			"\nd) Precio unitario: $%.2f"
			"\n\n Precio Aerolineas: $%.2f"
			"\na) Precio con tarjeta de debito: $%.2f"
			"\nb) Precio con tarjeta de credito: $%.2f"
			"\nc) Precio pagando con Bitcoin: %f BTC"
			"\nd) Precio unitario: $%.2f"
			"\n\nLa diferencia de precio es: $%.2f\n",kilometros, precioLatam,precioLatamDebito, precioLatamCredito, precioLatamBitcoin, precioLatamUnitario, precioAerolineas,
			precioAerolineasDebito, precioAerolineasCredito, precioAerolineasBitcoin, precioAerolineasUnitario, diferenciaPrecios);
}
