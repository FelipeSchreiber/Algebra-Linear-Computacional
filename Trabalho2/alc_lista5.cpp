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
	double y = pow(e,-pow(x,2));
	return y;
}

double integracao_polinomial(float a, float b, int n_points)
{
	float*pontos = (float *)malloc(n_points * sizeof(float));
	float*pesos = (float *)malloc(n_points * sizeof(float));
	double integral = 0.0;

	switch (n_points)
	{
	case 1:
		pontos[0] = (a + b) / 2;

		pesos[0] = b - a;

		break;

	case 2:
		pontos[0] = a;
		pontos[1] = b;

		pesos[0] = (b - a) / 2;
		pesos[1] = (b - a) / 2;

		break;

	case 3:
		pontos[0] = a;
		pontos[1] = (a + b) / 2;
		pontos[2] = b;

		pesos[0] = (b - a) / 6;
		pesos[1] = 2 * (b - a) / 3;
		pesos[2] = (b - a) / 6;

		break;

	case 4:
		pontos[0] = a;
		pontos[1] = a + ((b - a) / 3);
		pontos[2] = a + 2 * ((b - a) / 3);
		pontos[3] = b;

		pesos[0] = (b - a) / 8;
		pesos[1] = 3 * (b - a) / 8;
		pesos[2] = 3 * (b - a) / 8;
		pesos[3] = (b - a) / 8;

		break;

	case 5:
		pontos[0] = a;
		pontos[1] = a + ((b - a) / 4);
		pontos[2] = a + 2 * ((b - a) / 4);
		pontos[3] = a + 3 * ((b - a) / 4);
		pontos[4] = b;

		pesos[0] = 7 * (b - a) / 90;
		pesos[1] = 16 * (b - a) / 45;
		pesos[2] = 2 * (b - a) / 15;
		pesos[3] = 16 * (b - a) / 45;
		pesos[4] = 7 * (b - a) / 90;

		break;

	case 6:

		pontos[0] = a;
		pontos[1] = a + ((b - a) / 5);
		pontos[2] = a + 2 * ((b - a) / 5);
		pontos[3] = a + 3 * ((b - a) / 5);
		pontos[4] = a + 4 * ((b - a) / 5);
		pontos[5] = b;

		pesos[0] = 19 * (b - a) / 288;
		pesos[1] = 75 * (b - a) / 288;
		pesos[2] = 50 * (b - a) / 288;
		pesos[3] = 50 * (b - a) / 288;
		pesos[4] = 75 * (b - a) / 288;
		pesos[5] = 19 * (b - a) / 288;

		break;

	case 7:
		pontos[0] = a;
		pontos[1] = a + ((b - a) / 6);
		pontos[2] = a + 2 * ((b - a) / 6);
		pontos[3] = a + 3 * ((b - a) / 6);
		pontos[4] = a + 4 * ((b - a) / 6);
		pontos[5] = a + 5 * ((b - a) / 6);
		pontos[6] = b;

		pesos[0] = 41 * (b - a) / 840;
		pesos[1] = 216 * (b - a) / 840;
		pesos[2] = 27 * (b - a) / 840;
		pesos[3] = 272 * (b - a) / 840;
		pesos[4] = 27 * (b - a) / 840;
		pesos[5] = 216 * (b - a) / 840;
		pesos[6] = 41 * (b - a) / 840;

		break;

	case 8:
		pontos[0] = a;
		pontos[1] = a + ((b - a) / 7);
		pontos[2] = a + 2 * ((b - a) / 7);
		pontos[3] = a + 3 * ((b - a) / 7);
		pontos[4] = a + 4 * ((b - a) / 7);
		pontos[5] = a + 5 * ((b - a) / 7);
		pontos[6] = a + 6 * ((b - a) / 7);
		pontos[7] = b;

		pesos[0] = 751 * (b - a) / 17280;
		pesos[1] = 3577 * (b - a) / 17280;
		pesos[2] = 1323 * (b - a) / 17280;
		pesos[3] = 2989 * (b - a) / 17280;
		pesos[4] = 2989 * (b - a) / 17280;
		pesos[5] = 1323 * (b - a) / 17280;
		pesos[6] = 3577 * (b - a) / 17280;
		pesos[7] = 751 * (b - a) / 17280;

		break;

	case 9:
		pontos[0] = a;
		pontos[1] = a + ((b - a) / 8);
		pontos[2] = a + 2 * ((b - a) / 8);
		pontos[3] = a + 3 * ((b - a) / 8);
		pontos[4] = a + 4 * ((b - a) / 8);
		pontos[5] = a + 5 * ((b - a) / 8);
		pontos[6] = a + 6 * ((b - a) / 8);
		pontos[7] = a + 7 * ((b - a) / 8);
		pontos[8] = b;

		pesos[0] = 989 * (b - a) / 28350;
		pesos[1] = 5888 * (b - a) / 28350;
		pesos[2] = -928 * (b - a) / 28350;
		pesos[3] = 10496 * (b - a) / 28350;
		pesos[4] = -4540 * (b - a) / 28350;
		pesos[5] = 10496 * (b - a) / 28350;
		pesos[6] = -928 * (b - a) / 28350;
		pesos[7] = 5888 * (b - a) / 28350;
		pesos[8] = 989 * (b - a) / 28350;

		break;

	case 10:
		pontos[0] = a;
		pontos[1] = a + ((b - a) / 9);
		pontos[2] = a + 2 * ((b - a) / 9);
		pontos[3] = a + 3 * ((b - a) / 9);
		pontos[4] = a + 4 * ((b - a) / 9);
		pontos[5] = a + 5 * ((b - a) / 9);
		pontos[6] = a + 6 * ((b - a) / 9);
		pontos[7] = a + 7 * ((b - a) / 9);
		pontos[8] = a + 8 * ((b - a) / 9);
		pontos[9] = b;

		pesos[0] = 2857 * (b - a) / 89600;
		pesos[1] = 15741 * (b - a) / 89600;
		pesos[2] = 1080 * (b - a) / 89600;
		pesos[3] = 19344 * (b - a) / 89600;
		pesos[4] = 5778 * (b - a) / 89600;
		pesos[5] = 5778 * (b - a) / 89600;
		pesos[6] = 19344 * (b - a) / 89600;
		pesos[7] = 1080 * (b - a) / 89600;
		pesos[8] = 15741 * (b - a) / 89600;
		pesos[9] = 2857 * (b - a) / 89600;

		break;

	}

	for (int i = 0; i < n_points; i++)
	{
		integral += pesos[i] * func(pontos[i]);
	}

	return integral;
}

double quadratura_de_gauss(float a, float b, int n_points)
{

	float*pontos = (float *)malloc(n_points * sizeof(float));
	float*pesos = (float *)malloc(n_points * sizeof(float));
	double integral = 0.0;

	switch (n_points)
	{
	case 1:
		pontos[0] = 0.0000000000000000;

		pesos[0] = 2.0000000000000000;

		break;

	case 2:
		pontos[0] = -0.5773502691896257;
		pontos[1] = 0.5773502691896257;

		pesos[0] = 1.0000000000000000;
		pesos[1] = 1.0000000000000000;

		break;

	case 3:
		pontos[0] = 0.0000000000000000;
		pontos[1] = -0.7745966692414834;
		pontos[2] = 0.7745966692414834;

		pesos[0] = 0.8888888888888888;
		pesos[1] = 0.5555555555555556;
		pesos[2] = 0.5555555555555556;

		break;

	case 4:
		pontos[0] = -0.3399810435848563;
		pontos[1] = 0.3399810435848563;
		pontos[2] = -0.8611363115940526;
		pontos[3] = 0.8611363115940526;

		pesos[0] = 0.6521451548625461;
		pesos[1] = 0.6521451548625461;
		pesos[2] = 0.3478548451374538;
		pesos[3] = 0.3478548451374538;

		break;

	case 5:
		pontos[0] = 0.0000000000000000;
		pontos[1] = -0.5384693101056831;
		pontos[2] = 0.5384693101056831;
		pontos[3] = -0.9061798459386640;
		pontos[4] = 0.9061798459386640;

		pesos[0] = 0.5688888888888889;
		pesos[1] = 0.4786286704993665;
		pesos[2] = 0.4786286704993665;
		pesos[3] = 0.2369268850561891;
		pesos[4] = 0.2369268850561891;

		break;

	case 6:
		pontos[0] = 0.6612093864662645;
		pontos[1] = -0.6612093864662645;
		pontos[2] = -0.2386191860831969;
		pontos[3] = 0.2386191860831969;
		pontos[4] = -0.9324695142031521;
		pontos[5] = 0.9324695142031521;

		pesos[0] = 0.3607615730481386;
		pesos[1] = 0.3607615730481386;
		pesos[2] = 0.4679139345726910;
		pesos[3] = 0.4679139345726910;
		pesos[4] = 0.1713244923791704;
		pesos[5] = 0.1713244923791704;

		break;

	case 7:
		pontos[0] = 0.0000000000000000;
		pontos[1] = 0.4058451513773972;
		pontos[2] = -0.4058451513773972;
		pontos[3] = -0.7415311855993945;
		pontos[4] = 0.7415311855993945;
		pontos[5] = -0.9491079123427585;
		pontos[6] = 0.9491079123427585;

		pesos[0] = 0.4179591836734694;
		pesos[1] = 0.3818300505051189;
		pesos[2] = 0.3818300505051189;
		pesos[3] = 0.2797053914892766;
		pesos[4] = 0.2797053914892766;
		pesos[5] = 0.1294849661688697;
		pesos[6] = 0.1294849661688697;

		break;

	case 8:
		pontos[0] = -0.1834346424956498;
		pontos[1] = 0.1834346424956498;
		pontos[2] = -0.5255324099163290;
		pontos[3] = 0.5255324099163290;
		pontos[4] = -0.7966664774136267;
		pontos[5] = 0.7966664774136267;
		pontos[6] = -0.9602898564975363;
		pontos[7] = 0.9602898564975363;

		pesos[0] = 0.3626837833783620;
		pesos[1] = 0.3626837833783620;
		pesos[2] = 0.3137066458778873;
		pesos[3] = 0.3137066458778873;
		pesos[4] = 0.2223810344533745;
		pesos[5] = 0.2223810344533745;
		pesos[6] = 0.1012285362903763;
		pesos[7] = 0.1012285362903763;

		break;

	case 9:
		pontos[0] = 0.0000000000000000;
		pontos[1] = -0.8360311073266358;
		pontos[2] = 0.8360311073266358;
		pontos[3] = -0.9681602395076261;
		pontos[4] = 0.9681602395076261;
		pontos[5] = -0.3242534234038089;
		pontos[6] = 0.3242534234038089;
		pontos[7] = -0.6133714327005904;
		pontos[8] = 0.6133714327005904;

		pesos[0] = 0.3302393550012598;
		pesos[1] = 0.1806481606948574;
		pesos[2] = 0.1806481606948574;
		pesos[3] = 0.0812743883615744;
		pesos[4] = 0.0812743883615744;
		pesos[5] = 0.3123470770400029;
		pesos[6] = 0.3123470770400029;
		pesos[7] = 0.2606106964029354;
		pesos[8] = 0.2606106964029354;

		break;

	case 10:
		pontos[0] = -0.1488743389816312;
		pontos[1] = 0.1488743389816312;
		pontos[2] = -0.4333953941292472;
		pontos[3] = 0.4333953941292472;
		pontos[4] = -0.6794095682990244;
		pontos[5] = 0.6794095682990244;
		pontos[6] = -0.8650633666889845;
		pontos[7] = 0.8650633666889845;
		pontos[8] = -0.9739065285171717;
		pontos[9] = 0.9739065285171717;

		pesos[0] = 0.2955242247147529;
		pesos[1] = 0.2955242247147529;
		pesos[2] = 0.2692667193099963;
		pesos[3] = 0.2692667193099963;
		pesos[4] = 0.2190863625159820;
		pesos[5] = 0.2190863625159820;
		pesos[6] = 0.1494513491505806;
		pesos[7] = 0.1494513491505806;
		pesos[8] = 0.0666713443086881;
		pesos[9] = 0.0666713443086881;

		break;

	}

	for (int i = 0; i < n_points; i++)
	{
		integral += pesos[i] * func(0.5*(a + b + (pontos[i] * (b - a)))) * ((b - a) / 2);

	}

	return integral;
}


float main()
{
	double result;
	//result = integracao_polinomial(0, 1, 10);
	//result =quadratura_de_gauss(0, 1, 1);
	std::cout << result;
	return 0;
}

