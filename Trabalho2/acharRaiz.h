#ifndef ACHAR_RAIZ_H
#define ACHAR_RAIZ_H

#include <vector>
#include <iostream>
using namespace std;

float derivativeF(float x);
float t(float x);
float w(float x);
float f(float x);
float f1(vector<float> X);
float f2(vector<float> X);
float derivativeF1x0(vector<float> X);
float derivativeF1x1(vector<float> X);
float derivativeF2x0(vector<float> X);
float derivativeF2x1(vector<float> X);
float q(float x,vector<float> params);
float derivativeQa(float x,vector<float> params);
float derivativeQb(float x,vector<float> params);
float p(float x);
float derivativeP(float x);
float s1(vector<float> X);
float s2(vector<float> X);
float s3(vector<float> X);
float derivativeS1x0(vector <float> X);
float derivativeS1x1(vector <float> X);
float derivativeS1x2(vector <float> X);
float derivativeS2x0(vector <float> X);
float derivativeS2x1(vector <float> X);
float derivativeS2x2(vector <float> X);
float derivativeS3x0(vector <float> X);
float derivativeS3x1(vector <float> X);
float derivativeS3x2(vector <float> X);
float d1(vector<float> C);
float d2(vector<float> C);
float d3(vector<float> C);
float derivativeD1c0(vector <float> C);
float derivativeD1c1(vector <float> C);
float derivativeD1c2(vector <float> C);
float derivativeD2c0(vector <float> C);
float derivativeD2c1(vector <float> C);
float derivativeD2c2(vector <float> C);
float derivativeD3c0(vector <float> C);
float derivativeD3c1(vector <float> C);
float derivativeD3c2(vector <float> C);
float h(float x,vector<float> params);
float derivativeHb0(float x,vector<float> params);
float derivativeHb1(float x,vector<float> params);
float derivativeHb2(float x,vector<float> params);
float z(float x);
float derivativeZ(float x);
float v1(vector <float> X);
float v2(vector <float> X);
float derivativeV1X0(vector <float> X);
float derivativeV1X1(vector <float> X);
float derivativeV2X0(vector <float> X);
float derivativeV2X1(vector <float> X);

float derivativeAproximated(float x0, float (*function)(float));

vector<vector <float> > computeJacobine(vector < vector<float (*)(vector<float>)> > matrixOfDerivatives, vector<float> X);

vector <vector<float> > computeJacobine(vector <float (*)(vector<float>)> equations, vector<vector <float> > B0, vector<float> X1, vector<float> X0, float* deltaX);

vector<vector <float> > computeJacobine(vector<float (*)(float, vector<float>)> matrixOfDerivatives, vector<float> X, vector<float> params);

vector <float> newtonMethodNL(vector<float (*)(vector<float>)> equations,vector< vector<float (*)(vector<float>)> > matrixOfPartialDerivatives ,float tol, vector <float> x0, int maxIter);

float bissectionMethod(float (*function)(float) , float tol, float a, float b, int maxIter);

vector <float> broydenMethodNL(vector<float (*)(vector<float>)> equations, vector<vector <float> > B,float tol, vector <float> x0, int maxIter);

float newtonMethod(float (*function)(float) , float (*derivativeOfFunction)(float, float (*f)(float)),float tol, float x0, int maxIter);

float newtonMethod(float (*function)(float) , float (*derivativeOfFunction)(float),float tol, float x0, int maxIter);

float inverseInterpolation(float (*function)(float),int numberOfPoints,float tol,int maxIter);

vector<float> leastSquaresNL(vector<float(*)(float,vector<float>)> matrixOfPartialDerivatives,
float(*equation)(float,vector<float>),vector<float> xValues, vector<float> yValues, vector<float> params, int maxIter);

float phi(vector< vector<float> > data,int index);
bool comparePoints(vector<float> p1, vector<float>p2); 
float **convertToPointer(vector <vector <float> > vec);
float *convertToPointer(vector<float>  vec);
vector<float>convertToVector(float*vec);
vector<vector<float> >convertToVector(float**vec);
vector<float> operator-(vector <float>vec);
vector<vector <float> > operator+(vector<vector <float> > matrix, vector<vector <float> > otherMatrix);
vector<vector <float> > operator*(vector <float> vec,vector <float> otherVec);
vector<vector <float> > operator/(vector<vector <float> > matrix,float num);
void operator+=(vector<vector <float> > &matrix, vector<vector <float> > otherMatrix);
vector<vector <float> > operator+(vector<vector <float> > otherMatrix,float**matrix);
vector<vector <float> > operator+(vector<vector <float> > matrix ,vector<vector <float> > otherMatrix);
void operator+=(vector <float> &otherVec,float*vec);
ostream & operator<<(ostream &o, vector<vector <float> > matrix);
#endif
