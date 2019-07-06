#define _USE_MATH_DEFINES
#include <cmath>
#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>


double func(double x)
{
	double e = 2.71828182845904523536;
	double pi = 3.14159265358979323846;

	// DEFINIR AQUI A FUNÇÃO A SER INTEGRADA
	double y= pow(x, (1/3)) + log(x);
	return y;
}

float diferenca_central(float x, float delta_x)
{
	float derivada = (func(x + delta_x) - func(x - delta_x)) / (2 * delta_x);
	return derivada;
}

float passo_para_frente(float x, float delta_x)
{
	float derivada = (func(x + delta_x) - func(x)) / delta_x;
	return derivada;
}

float passo_atras(float x, float delta_x)
{
	float derivada = (func(x) - func(x - delta_x)) / delta_x;
	return derivada;
}

float interpol_Richard(float x, float delta_x1,float delta_x2, int p)
{
	float d1 = passo_para_frente(x, delta_x1);
	float d2 = passo_para_frente(x, delta_x2);
	int q = delta_x1/ delta_x2;
	float derivada = d1 + ((d1 - d2) / (pow(q, -p) - 1));
	return derivada;
}


// CHAMADAS DE FUNÇÃO

int main()
{
	float result;
	//result = diferenca_central(2,0.001);
	//result = passo_para_frente(1,0.25);
	//result = passo_atras(x,delta_x);
	result = interpol_Richard(2, 0.5, 0.25, 1);

    std::cout << result; 
}

