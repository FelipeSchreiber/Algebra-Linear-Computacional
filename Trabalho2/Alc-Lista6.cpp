#define _USE_MATH_DEFINES
#include <cmath>
//#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
float edo(float t,float x)
{
	double e = 2.71828182845904523536;
	double pi = 3.14159265358979323846;

	// DEFINIR AQUI A EDO
	float y = t + x;
	return y;
}

float edo2(float t, float x, float xl)
{
	double e = 2.71828182845904523536;
	double pi = 3.14159265358979323846;

	// DEFINIR AQUI A EDO
	float y = -9.80665 - 1.0 * xl * abs(xl) ;
	return y;
}

float euler(float t_min, float t_max, float h, float x_0, float (*f)(float))
{
	float t = t_min;
	float x_k1 = x_0;
	float x_k;
	float K_1;

	while (t <= t_max)
	{
		x_k = x_k1;
		std::cout << "T= " << t << ", Euler = " << x_k << "\n" ;
		K_1 = edo(t,x_k);
		x_k1 = x_k + K_1 * h;
		t += h;
	}
	std::cout << "T= " << t << ", Euler = " << x_k1 << "\n";
	return x_k1;
}

float Runge_Kutta2(float t_min, float t_max, float h, float x_0)
{
	float t = t_min;
	float x_k1 = x_0;
	float x_k;
	float K_1;
	float K_2;
	while (t <= t_max)
	{
		x_k = x_k1;
		std::cout << "T= " << t << ", Runge Kutta Ordem 2 = " << x_k << "\n";
		K_1 = edo(t, x_k);
		K_2 = edo(t+h,x_k+h*K_1);
		x_k1 = x_k + (K_1+K_2) * (h/2);
		t += h;
	}
	std::cout << "T= " << t << ", Runge Kutta Ordem 2 = " << x_k1 << "\n";

	return x_k1;
}

float Runge_Kutta4(float t_min, float t_max, float h, float x_0)
{
	float t = t_min;
	float x_k1 = x_0;
	float x_k;
	float K_1;
	float K_2;
	float K_3;
	float K_4;
	while (t <= t_max)
	{
		x_k = x_k1;
		std::cout << "T= " << t << ", Runge Kutta Ordem 4 = " << x_k << "\n";
		K_1 = edo(t, x_k);
		K_2 = edo(t + h/2, x_k + ((h/2) * K_1));
		K_3 = edo(t + h / 2, x_k + ((h / 2) * K_2));
		K_4 = edo(t+h, x_k + h*K_3);
		x_k1 = x_k + (K_1 + 2*K_2 + 2*K_3 + K_4) * (h / 6);
		t += h;
	}
	std::cout << "T= " << t << ", Runge Kutta Ordem 4 = " << x_k1 << "\n";

	return x_k1;
}



float euler2(float t_min, float t_max, float h, float x_0,float xl_0)
{
	float t = t_min;
	float x_k1 = x_0;
	float xl_k1 = xl_0;
	float x_k;
	float xl_k;

	while (t <= t_max)
	{
		x_k = x_k1;
		xl_k = xl_k1;
		std::cout << "T= " << t << ", Euler Ordem 2 = " << x_k << "\n";

		x_k1 = x_k + xl_k * h + (edo2(t, x_k, xl_k) / 2)* pow(h, 2);
		xl_k1 = xl_k + edo2(t, x_k, xl_k)*h;
		t += h;
	}
	std::cout << "T= " << t << ", Euler Oredem 2= " << x_k1 << "\n";
	return x_k1;
}


float Runge_Kutta_Nystrom2(float t_min, float t_max, float h, float x_0, float xl_0)
{
	float t = t_min;
	float x_k1 = x_0;
	float xl_k1 = xl_0;
	float x_k;
	float xl_k;
	float K_1;
	float K_2;
	float K_3;
	float K_4;
	float Q;
	float L;
	while (t <= t_max)
	{
		x_k = x_k1;
		xl_k = xl_k1;
		std::cout << "T= " << t << ", Runge Kutta Nystrom Ordem 2 = " << x_k << "\n";
		K_1 = (h/2)*edo2(t, x_k, xl_k);
		Q = (h / 2)*(xl_k + (K_1 / 2));
		K_2 = (h / 2)*edo2(t + h / 2, x_k + Q, xl_k + K_1);
		K_3 = (h / 2)*edo2(t + h / 2, x_k + Q, xl_k + K_2);
		L = h * (xl_k + K_3);
		K_4 = (h / 2)*edo2(t + h, x_k +L, xl_k + 2 * K_3);
		x_k1 = x_k + h * (xl_k + (1.0/3.0)*(K_1 +K_2 + K_3));

		xl_k1 = xl_k + (1.0 / 3.0)* (K_1 + 2 * K_2 + 2 * K_3 + K_4);
		t += h;
	}
	std::cout << "T= " << t << ", Runge Kutta Nystrom Ordem 2 = " << x_k1 << "\n";

	return x_k1;
}


int main()
{
	euler(0.0, 1.0, 0.1, 0.0);
	//Runge_Kutta2(0.0, 1.0, 0.1, 0.0);
	//Runge_Kutta4(0.0, 1.0, 0.1, 0.0);
	//euler2(0.0, 1.0, 0.1, 0.0, 0.0);
	//Runge_Kutta_Nystrom2(0.0, 1.0, 0.1, 0.0, 0.0);

}
