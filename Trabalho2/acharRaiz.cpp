#include <iostream>
#include "acharRaiz.h"
#include <math.h>
#include <vector>
#include <limits>
#include <algorithm>
#include <tgmath.h>
#include "multiplicarMatriz.h"
const float g = 9.806;
const float k = 0.00341;

using namespace std;

float t(float x)
{
 return (pow(x,2) - 4*cos(x));
}

float w(float x)
{
 return x*sqrt(g*k);
}

float f(float x)// entre 0 e 800 tem raiz!
{
 //cout<<"cosh("<<w(x)<<") = "<<coshl((long double) w(x) )<<endl;
 return (log10 ( coshl((long double) w(x) ) ) - 50);
}

float derivativeF(float x)
{
 return ( sinhl( w(x) )*sqrt(g*k)/( coshl(w(x))) * log(10) ); 
}

float derivativeAproximated(float x0, float (*function)(float))
{
 float deltaX = 0.001;
 float x1 = x0 + deltaX;
 float fa = (*function)(x0);
 float fi = (*function)(x1);
 return ((fi - fa)/deltaX);
}

float f1(vector<float> X)
{
 return (X[0] + 2*X[1] - 2);
}

float f2(vector<float> X)
{
 return (pow(X[0],2) + 4*pow(X[1],2) - 4);
}

float derivativeF1x0(vector<float> X)
{
 return 1;
}

float derivativeF1x1(vector<float> X)
{
 return 2;
}

float derivativeF2x0(vector<float> X)
{
 return 2*X[0];
}

float derivativeF2x1(vector<float> X)
{
 return 8*X[1];
}

float q(float x,vector<float> params)
{
 return exp(pow(x,params[0])/params[1]);
}

float derivativeQa(float x,vector<float> params)
{
 return (pow(x,params[0])*log(x)*q(x,params)/params[1]);
}

float derivativeQb(float x,vector<float> params)
{
 return (pow(x,2*params[0])*(-1)*q(x,params)/pow(params[1],2));
}

float p(float x)//entre 0 e 2 tem raiz
{
 cout<<"exp("<<2*x<<") = "<<exp(2*x)<<endl;
 return (4*cos(x)-exp(2*x) );
}

float derivativeP(float x)
{
 return (-4*sin(x) - 2*exp(2*x));
}

float s1(vector<float> X)
{
 return (16*pow(X[0],4) + 16*pow(X[1],4) + pow(X[2],4) - 16);
}

float s2(vector<float> X)
{
 return (pow(X[0],2) + pow(X[1],2) + pow(X[2],2) - 3);
}

float s3(vector<float> X)
{
 return (pow(X[0],3) - X[1] + X[2] - 1);
}

float derivativeS1x0(vector <float> X)
{
 return 64*pow(X[0],3);
}

float derivativeS1x1(vector <float> X)
{
 return 64*pow(X[1],3);
}

float derivativeS1x2(vector <float> X)
{
 return 4*pow(X[2],3);
}

float derivativeS2x0(vector <float> X)
{
 return 2*X[0];
}

float derivativeS2x1(vector <float> X)
{
 return 2*X[1];
}

float derivativeS2x2(vector <float> X)
{
 return 2*X[2];
}

float derivativeS3x0(vector<float> X)
{
 return 3*pow(X[0],2);
}

float derivativeS3x1(vector<float> X)
{
 return -1;
}

float derivativeS3x2(vector<float> X)
{
 return 1;
}

float d1(vector<float> C)
{
 return (2*pow(C[1],2) + pow(C[0],2) + 6*pow(C[2],2) - 1);
}

float d2(vector<float> C)
{
 return (8*pow(C[1],3) + 6*C[1]*pow(C[0],2)+ 36*C[1]*C[0]*C[2] + 108*C[1]*pow(C[2],2) );
}

float d3(vector<float> C)
{
 return (60*pow(C[1],4) + 60*pow(C[1],2)*pow(C[0],2)+ 576*pow(C[1],2)*C[0]*C[2] + 2232*pow(C[1],2)*pow(C[2],2) + 252*pow(C[2],2)*pow(C[0],2) + 1296*pow(C[2],3)*C[0] + 3348*pow(C[2],4) + 24*pow(C[0],3)*C[2] + 3*C[0] - 11.667);
}

float derivativeD1c0(vector <float> C)
{
 return 2*C[0];
}

float derivativeD1c1(vector <float> C)
{
 return 4*C[1];
}

float derivativeD1c2(vector <float> C)
{
 return 12*C[2];
}

float derivativeD2c0(vector <float> C)
{
 return 12*C[0]*C[1] + 36*C[1]*C[2];
}

float derivativeD2c1(vector <float> C)
{
 return (24*pow(C[1],2) + 6*pow(C[0],2) + 36*C[0]*C[2] + 108*pow(C[2],2));
}

float derivativeD2c2(vector <float> C)
{
 return 36*C[0]*C[1] + 216*C[1]*C[2];
}

float derivativeD3c0(vector<float> C)
{
 return (120*C[0]*pow(C[1],2) + 576*pow(C[1],2)*C[2] + 504*pow(C[2],2)*C[0] + 1296*pow(C[2],3) + 72*pow(C[0],2)*C[2] + 3);
}

float derivativeD3c1(vector<float> C)
{
 return (240*pow(C[1],3) + 120*C[1]*pow(C[0],2) + 1152*C[1]*C[2]*C[0] + 4464*C[1]*pow(C[2],2) );
}

float derivativeD3c2(vector<float> C)
{
 return (576*pow(C[1],2)*C[0] + 4464*C[2]*pow(C[1],2) + 504*pow(C[0],2)*C[2] + 3*1296*pow(C[2],2)*C[0] + 4*3348*pow(C[2],3) + 24*pow(C[0],3) );
}

float h(float x,vector<float> params)
{
 return params[0] + params[1]*pow(x,params[2]);
}

float derivativeHb0(float x,vector<float> params)
{
 return 1;
}

float derivativeHb1(float x,vector<float> params)
{
 return pow(x,params[2]);
}

float derivativeHb2(float x,vector<float> params)
{
 return log(x)*pow(x,params[2]);
}

float z(float x)
{
 return exp((double)x) - pow((double)x,2) - 4;
}

float derivativeZ(float x)
{
 return  exp((double)x) - 2*x;
}

float v1(vector <float> X)
{
 return X[0] -X[1] + 2;
}

float v2(vector <float> X)
{
 return exp((double)X[0]) + X[1] - 6;
}

float derivativeV1X0(vector <float> X)
{
 return 1;
}

float derivativeV1X1(vector <float> X)
{
 return -1;
}

float derivativeV2X0(vector<float> X)
{
 return exp((double)X[0]);
}

float derivativeV2X1(vector<float> X)
{
 return 1;
}

vector<vector <float> > computeJacobine(vector < vector<float (*)(vector<float>)> > matrixOfDerivatives, vector<float> X)
{
 vector<vector <float> > J;
 for(int i = 0; i<(int)matrixOfDerivatives.size(); i++)
 {
  vector <float> newRow = *(new vector <float>) ;
  for(int j = 0; j<(int)matrixOfDerivatives[0].size(); j++)
   newRow.push_back( matrixOfDerivatives[i][j](X) );
  J.push_back(newRow);
 }
  return J;
}

vector <vector<float> > computeJacobine(vector <float (*)(vector<float>)> equations, vector<vector <float> > B0, vector<float> X1, vector<float> X0, float* deltaX)
{
 vector <float> Y;
 float *R =(float*) malloc(sizeof(deltaX)); 
 int i;
 float moduloDeDeltaXSquared = 0;
 for(i = 0; i<(int)X0.size(); i++)
 {
	Y.push_back(equations[i](X1) - equations[i](X0));
  moduloDeDeltaXSquared += pow(deltaX[i],2);
 }
 float **B = convertToPointer(B0);
 MultiplicarMatrizVetor(B,deltaX,R,(int)B0.size(), (int)B0[0].size());
 Y += R; 
 B0 += (Y*(-convertToVector(deltaX)) )/moduloDeDeltaXSquared;
 return B0;
}

vector<vector <float> > computeJacobine(vector<float (*)(float, vector<float>)> matrixOfDerivatives, vector<float> X, vector<float> params)
{
 vector<vector <float> > J;
 for(int i = 0; i<(int)X.size(); i++)
 {
  vector <float> newRow = *(new vector <float>) ;
  for(int j = 0; j<(int)matrixOfDerivatives.size(); j++)
   newRow.push_back( matrixOfDerivatives[j](X[i],params) );
  //cout<<"NEWROW[0]: "<<newRow[0]<<" NEWROW[1]: "<<newRow[1]<<endl;
  J.push_back(newRow);
 }
 return J;
}

float **convertToPointer(vector <vector <float> > vec)
{
 float **matrix = (float**) malloc(vec.size()*sizeof(float*));
 for(int i = 0; i <(int) vec.size(); i++)
 {
  matrix[i] = (float*) malloc(vec[0].size()*sizeof(float));
  for(int j = 0; j < (int) vec[0].size(); j++)
  {
   matrix[i][j] = vec[i][j];
  }
 }
 return matrix;
}

float *convertToPointer(vector <float> vec)
{
 float *matrix = (float*) malloc(vec.size()*sizeof(float));
 for(int i = 0; i <(int) vec.size(); i++)
 {
  matrix[i] = vec[i];
 }
 return matrix;
}

vector<float> convertToVector(float*vec)
{
 vector<float> matrix;
 for(int i = 0; i <(int)(sizeof(vec)/sizeof(float)); i++)
 {
  matrix.push_back(vec[i]);
 }
 return matrix;
}

vector<vector<float> >convertToVector(float**matriz)
{
 vector<vector<float> >matrix;
 for(int i = 0; i< (int)(sizeof(matriz)/(sizeof(matriz[0]))); i++) 
 {
  matrix.push_back(convertToVector(matriz[i]));
 }
 return matrix;
}

vector <float> newtonMethodNL(vector<float (*)(vector<float>)> equations,vector <vector<float (*)(vector<float>)> > matrixOfPartialDerivatives ,float tol, vector <float> x0, int maxIter)
{
 int j;
 vector<vector <float> > jacobine;
 vector<float> x1(x0.size(),0);
 float* F;
 float* R;
 float **J;
 float **Jinverse;
 float * termosIndependentes = (float*) malloc(equations.size()*sizeof(float));
 for(j = 0; j<(int)equations.size(); j++)
 {
  termosIndependentes[j] = 0;
 }
 for(j = 0; j< maxIter; j++)
 {
   //cout<<"J: "<<endl;
   jacobine = computeJacobine(matrixOfPartialDerivatives, x0);
   int i;
	 F =(float*) malloc(x0.size()*sizeof(float));
	 R = (float*) malloc(x0.size()*sizeof(float));
	 for(i = 0; i<(int)x0.size(); i++)
	 {
		F[i] = equations[i](x0);
	 }
	 J = convertToPointer(jacobine);
	 Jinverse = eliminacaoGaussJordan(J, termosIndependentes, (int)equations.size());
	 MultiplicarMatrizVetor(Jinverse, F, R, (int)jacobine.size(), (int)jacobine[0].size());
	 for(i = 0; i<(int)x0.size(); i++)
	 {
		x1[i] = x0[i] - R[i];
	 }
   //cout<<J;
   free(F);
   free(R);
   deallocateArray(J, jacobine.size());
   deallocateArray(Jinverse, jacobine[0].size());
   F = convertToPointer(x1);
   R = convertToPointer(x0);
   if(calcularResiduo(F, R, x1.size(), 2) < tol)
   {
    free(termosIndependentes);
    cout<<"Metodo de Newton no de iter: "<<j<<endl;
    return x1;
   }
   else
    x0 = x1;
 }
 cout<<"NEWTON-NL NAO CONVERGIU"<<endl;
 free(termosIndependentes);
 return x0;
}

vector <float> broydenMethodNL(vector<float (*)(vector<float>)> equations, vector<vector <float> > B,float tol, vector <float> x0, int maxIter)
{
 int j;
 vector<vector <float> > jacobine;
 vector<float> x1(x0.size(),0);
 float* F;
 float* R;
 float **J;
 float **Jinverse;
 float * termosIndependentes = (float*) malloc(equations.size()*sizeof(float));
 for(j = 0; j<(int)equations.size(); j++)
 {
  termosIndependentes[j] = 0;
 }
 cout<<"\n\nB0:\n"<<B<<"\n\n"<<endl;
 for(j = 0; j< maxIter; j++)
 {
   //cout<<"J: "<<endl;
   jacobine = B;
   int i;
	 F =(float*) malloc(x0.size()*sizeof(float));
	 R = (float*) malloc(x0.size()*sizeof(float));
	 for(i = 0; i<(int)x0.size(); i++)
	 {
		F[i] = equations[i](x0);
	 }
	 J = convertToPointer(jacobine);
   Jinverse = eliminacaoGaussJordan(J, termosIndependentes, (int)equations.size());
	 MultiplicarMatrizVetor(Jinverse, F, R, (int)jacobine.size(), (int)jacobine[0].size());
	 for(i = 0; i<(int)x0.size(); i++)
	 {
		x1[i] = x0[i] - R[i];
	 }
   //cout<<J;
   free(F);
   B = computeJacobine(equations, jacobine, x1, x0, R);
   //cout<<"\n\nB:\n"<<B<<"\n\n"<<endl;
   free(R);
   deallocateArray(J, jacobine.size());
   deallocateArray(Jinverse, jacobine[0].size());
   F = convertToPointer(x1);
   R = convertToPointer(x0);
   if(calcularResiduo(F, R, x1.size(), 2) < tol)
   {
    free(termosIndependentes);
    free(F);
    free(R);
    cout<<"Metodo de Broyden no de iter: "<<j<<endl;
    cout<<"\nBROYDEN: "<<endl;
    return x1;
   }
   else
   {
    free(F);
    free(R);
    x0 = x1;
   }
 }
 cout<<"BROYDEN-NL NAO CONVERGIU"<<endl;
 free(termosIndependentes);
 return x0;
}

vector<float> leastSquaresNL(vector<float (*)(float,vector<float>)> matrixOfPartialDerivatives, float (*equation)(float, vector<float>), vector<float> xValues, vector<float> yValues, vector <float> params, int maxIter)
{
 int j;
 vector<vector <float> > J;
 J = computeJacobine(matrixOfPartialDerivatives, xValues, params);
 float**Jtranspose;
 float**inversa;
 vector <float> F;
 float* deltaB = (float*) malloc(J[0].size()*sizeof(float));
 //cout<<"\nJ0:\n"<<J;
 float **R = criarMatrizIdentidade(J[0].size());
 float *V =(float*) malloc(J[0].size()*sizeof(float));
 float * termosIndependentes = (float*) malloc(J[0].size()*sizeof(float));
 for(j = 0; j<(int)J[0].size(); j++)
 {
  termosIndependentes[j] = 0;
 }
 for(j = 0; j< maxIter; j++)
 {
   J = computeJacobine(matrixOfPartialDerivatives, xValues, params);
   //cout<<"\nJ0:\n"<<J;
   //cout<<"PARAMS:\n"<<endl;
   //for(int i = 0; i<(int)J[0].size(); i++)
   // cout<<params[i]<<endl;
   //cout<<"Fim Params"<<endl;
   F = *(new vector <float>);
	 for(int i = 0; i<(int)xValues.size(); i++)
	 {
		F.push_back(equation(xValues[i],params) - yValues[i]);
	 }
   //cout<<"F(B):\n"<<endl;
   //for(int i = 0; i<(int)xValues.size(); i++)
    //cout<<F[i]<<endl;
   //cout<<"Fim F(B)"<<endl;
	 Jtranspose = getTranspose(convertToPointer(J),J.size(),J[0].size());
   //cout<<"\nJtranspose:\n"<<endl;
   //imprimeMatriz(Jtranspose,J[0].size(),J.size());
   //Jtranspose = convertToVector(o);
   //cout<<"Jtranspose:\n"<<Jtranspose<<endl;
	 MultiplicarMatrizes(Jtranspose,convertToPointer(J), R,J[0].size(),J.size(), J[0].size());
   //cout<<"\nJtransposexJ:\n"<<endl;
   //imprimeMatriz(R,J[0].size(),J[0].size());
   MultiplicarMatrizVetor(Jtranspose,convertToPointer(-F),V,J[0].size(),J.size());
   //printf("-------------->>>>>\n");
   // imprimeMatriz(R,J[0].size(),J[0].size());
    // printf("-------------->>>>>\n");
   if( det(R, J[0].size()) != 0)
   {
    //printf("-------------->>>>>\n");
    //imprimeMatriz(R,J[0].size(),J[0].size());
     //printf("-------------->>>>>\n");
    inversa = eliminacaoGaussJordan(R, termosIndependentes, (int)J[0].size());
   }
   else
    return params;
   //cout<<"\nInversa:\n"<<endl;
   //imprimeMatriz(inversa,J[0].size(),J[0].size());
	 MultiplicarMatrizVetor(inversa,V,deltaB,J[0].size(),J[0].size());
   //cout<<"DELTA B:\n"<<endl;
   //for(int i = 0; i<(int)J[0].size(); i++)
   // cout<<deltaB[i]<<endl;
   //cout<<"Fim DELTA B"<<endl;
   params+=deltaB;
 }
 return params;
}

ostream & operator<<(ostream &o, vector<vector <float> > matrix)
{
 for(int i = 0; i<(int)matrix.size(); i++)
 {
  for(int j = 0; j<(int)matrix[0].size(); j++)
   o<<matrix[i][j]<<" ";
  o<<"\n";
 }
 return o;
}

vector<vector <float> > operator*(vector <float> vec,vector <float> otherVec)
{
 vector<vector <float> > matrixResult;
 for(int i = 0; i<(int)vec.size(); i++)
 {
  vector<float> row = *(new vector<float>);
  for(int j = 0; j<(int)otherVec.size(); j++)
   row.push_back(vec[i]*otherVec[j]);
  matrixResult.push_back(row);
 }
 return matrixResult;
}

vector<vector <float> > operator/(vector<vector <float> > matrix,float num)
{
 vector<vector <float> > matrixResult;
 for(int i = 0; i<(int)matrix.size(); i++)
 {
  vector<float> row = *(new vector<float>);
  for(int j = 0; j<(int)matrix[0].size(); j++)
   row.push_back(matrix[i][j]/num);
  matrixResult.push_back(row);
 }
 return matrixResult;
}

void operator+=(vector<vector <float> > &matrix,vector<vector <float> > otherMatrix)
{
 for(int i = 0; i<(int)matrix.size(); i++)
 {
  for(int j = 0; j<(int)matrix[0].size(); j++)
   matrix[i][j] += otherMatrix[i][j];
 }
}

vector<vector <float> > operator+(vector<vector <float> > otherMatrix,float**matrix)
{
 vector<vector <float> > matrixResult;
 for(int i = 0; i<(int)otherMatrix.size(); i++)
 {
  vector<float> row = *(new vector<float>);
  for(int j = 0; j<(int)(sizeof(matrix[0])/sizeof(float)); j++)
   row.push_back(matrix[i][j] + otherMatrix[i][j]);
  matrixResult.push_back(row);
 }
 return matrixResult;
}

void operator+=(vector <float> &otherVec,float*vec)
{
 for(int i = 0; i<(int)otherVec.size(); i++)
  otherVec[i] += vec[i];
}

vector<vector <float> > operator+(vector<vector <float> > matrix ,vector<vector <float> > otherMatrix)
{
 vector<vector <float> > matrixResult;
 for(int i = 0; i<(int)matrix.size(); i++)
 {
  vector<float> row = *(new vector<float>);
  for(int j = 0; j<(int)matrix[0].size(); j++)
   row.push_back(matrix[i][j] + otherMatrix[i][j]);
  matrixResult.push_back(row);
 }
 return matrixResult;
}

vector <float> operator-(vector <float>vec)
{
 vector <float> result;
 for(int i = 0; i<(int)vec.size(); i++)
 {
  result.push_back((-1)*vec[i]);
 }
 return result;
}

float bissectionMethod(float (*function)(float) , float tol, float a, float b, int maxIter)
{
 //supoe-se que f(a) < 0  e f(b) > 0
 if((*function)(a) > (*function)(b) )
 {
  float aux = a;
  a = b;
  b = aux; 
 } 
 int count = 0;
 float solution;
 while(fabs(a-b) > tol)
 {
  solution = (a+b)/2;
  if( (*function)(solution) > 0 )
   b = solution;
  else
   a = solution;
  if(count > maxIter)
   break;
  else
   count++;
 }
 cout<<"Bissection: "<<endl;
 cout<<"NUMERO ITER Bissecao: "<<count<<endl;
 return solution;
}

float newtonMethod(float (*function)(float) , float (*derivativeOfFunction)(float, float (*f)(float)),float tol, float x0, int maxIter)
{
 float x1 = 0;
 int i;
 for(i = 0; i<maxIter; i++)
 {/*
  cout<<"Root->>>>> "<<x0<<endl;
  cout<<"F(x0) = "<<(*function)(x0);
  cout<<"F'(x0) = "<<(*derivativeOfFunction)(x0, function);*/
  x1 = x0 - (*function)(x0)/(*derivativeOfFunction)(x0, function);
  if(fabs(x1 - x0) < tol)  
  {
   cout<<"Newton: "<<endl;
   cout<<"NUMERO ITER: "<<i<<endl;
   return x1;
  }
  else
   x0 = x1;
 }
 cout<<"\nNEWTON NAO CONVERGIU"<<endl;
 return x0;
}

float newtonMethod(float (*function)(float) , float (*derivativeOfFunction)(float),float tol, float x0, int maxIter)
{
 float x1 = 0;
 int i;
 for(i = 0; i<maxIter; i++)
 {
  /*cout<<"Root->>>>> "<<x0<<endl;
  cout<<"F(x0) = "<<(*function)(x0);
  cout<<"F'(x0) = "<<(*derivativeOfFunction)(x0);*/
  x1 = x0 - (*function)(x0)/(*derivativeOfFunction)(x0);
  if(fabs(x1 - x0) < tol)  
  {
   cout<<"\nNewton: "<<endl;
   cout<<"NUMERO ITER: "<<i<<endl;
   return x1;
  }
  else
   x0 = x1;
 }
 cout<<"\nNEWTON NAO CONVERGIU"<<endl;
 return x0;
}

float phi(vector< vector<float> > data,int index)
{
 float result = 1;
 for(int i = 0; i<(int)data.size(); i++) 
 {
  if(i == index)
   continue;
  else
  {
   result *= (-1)*data[i][1]/(data[index][1] - data[i][1]);
  }
 }
 //cout<<"\nResult: "<<result<<endl;
 return result;
}

bool comparePoints(vector<float> p1, vector<float>p2) 
{ 
    return ( fabs(p1[1]) < fabs(p2[1]) ); //ordem decrescente do valor de y em modulo
} 

float inverseInterpolation(float (*function)(float), int numberOfPoints, float tol,int maxIter)
{
 float x0 = numeric_limits<float>::max();
 int i;
 float root = 0;
 vector< vector<float> > data;
 vector <float> point;
 data.reserve(numberOfPoints);
 for(i = 0; i<numberOfPoints; i++) 
 {
  point = *(new vector<float>);
  point.reserve(2);
  //point.push_back((i+1)*10);
  //point.push_back( (*function)((i+1)*10) );
  if(i == 0)
  {
   point.push_back(0);
   point.push_back( (*function)(0) );
  }
  if(i == 1)
  {
   point.push_back(0.5);
   point.push_back( (*function)(0.5) );
  }
  if(i == 2)
  {
   point.push_back(1);
   point.push_back( (*function)(1) );
  }
  //cout<<"X: "<<point[0]<<" Y: "<<point[1]<<endl;
  data.push_back( point ); 
 }
 
 for(int j = 0;  j<maxIter; j++){
   root = 0;
	 for(i = 0; i<(int)data.size(); i++)
	 {
		root += (phi(data,i)*data[i][0]);
	 }
	 if(fabs(root-x0) < tol)
		return root;
	 else
	 {
		sort(data.begin(),data.end(),comparePoints);
		for(i = 0; i<(int)data.size(); i++)
		{
		 cout<<"-> "<<data[i][0]<<" , "<< data[i][1] <<endl;
		}
    cout<<"\n\n"<<endl;
		data[numberOfPoints - 1][0] = root;
		data[numberOfPoints - 1][1] = (*function)(root);
    sort(data.begin(),data.end());
    x0 = root;
	 }
 }
 cout<<"\nInverse Interpolation: "<<endl;
 return root;
}

