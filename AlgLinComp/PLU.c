/*
 * =====================================================================================
 *
 *       Filename:  PLU.c
 *
 *    Description:  Program to decompose a matrix in a 
 *
 *        Version:  1.0
 *        Created:  20/03/2019 22:24:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Felipe Schreiber Fernandes (), schreiber.felipe@poli.ufrj.br
 *   Organization:  UFRJ
 *
 * =====================================================================================
 */

#include <stdio.h>
#include "multiplicarMatriz.h"

int main()
{
        int i,j;
        /*Compilar com:
         gcc -o PLU PLU.c multiplicarMatriz.c -lm      


         Executar:
         ./PLU

        */
	float myMatrix[NUMERO_MAXIMO_LINHAS1][NUMERO_MAXIMO_COLUNAS1] = {
                                {19,5,3,1,2,1},
                                {5,20,5,3,1,2},
                                {3,5,19,5,1,2},
                                {1,3,5,16,1,2},
                                {2,1,1,1,15,3},
                                {1,2,2,2,3,14},
                                };

              /*COLOCAR AS CONSTANTES NO ARQUIVO .h*/
       
        float**matrix = matrizInit(NUMERO_MAXIMO_LINHAS1, myMatrix);
        float vector[NUMERO_MAXIMO_LINHAS1] = {30,10,10,-10,0,5};
        float* termosIndependentes = vectorInit(NUMERO_MAXIMO_LINHAS1, vector);
        float alpha = 0.52;
        float determinante = 0;
        
        multiplicarMatrizPorEscalar(matrix,alpha,NUMERO_MAXIMO_LINHAS1);
        
        //leastSquaresTest();
       
        //eigenvectorsJacobiMethodTest(matrix,NUMERO_MAXIMO_LINHAS1);
       
         //powerMethodTest(matrix,NUMERO_MAXIMO_LINHAS1);

        //gaussJordanEliminationTests(matrix,termosIndependentes,NUMERO_MAXIMO_LINHAS1);      

        //gaussEliminationTests(matrix,termosIndependentes,NUMERO_MAXIMO_LINHAS1);
            
        //gaussSeidelMethodTest(matrix,termosIndependentes,NUMERO_MAXIMO_LINHAS1);
        
        //jacobiMethodTest(matrix,termosIndependentes,NUMERO_MAXIMO_LINHAS1);
 
        //choleskyTest(matrix,termosIndependentes,NUMERO_MAXIMO_LINHAS1);                

         determinante = det(matrix, NUMERO_MAXIMO_LINHAS1);        
         printf("\nDet: %.5f\n",determinante);
}
