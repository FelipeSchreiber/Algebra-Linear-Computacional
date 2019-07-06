#include "acharRaiz.h"
#include <iostream>
#include <math.h>

using namespace std;

int main(){
 //cout<<w(1)/log(10)<<endl;
 cout<<fixed;
 cout<<bissectionMethod(z , 0.00001, 0, 3, 30)<<endl;
 cout<<"-----------------------------------------------------\n"<<endl;
 cout<<newtonMethod(z , derivativeZ, 0.00001, 2, 30)<<"\n"<<endl;
 cout<<"-----------------------------------------------------\n"<<endl;
 cout<<newtonMethod(p , derivativeAproximated, 0.00001, 2, 30)<<"\n"<<endl;
 cout<<"-----------------------------------------------------\n"<<endl;
 cout<<inverseInterpolation(p ,3,0.00001, 30)<<endl;
 cout<<"-----------------------------------------------------\n"<<endl;
 vector<float(*)(vector<float>)> equations;
 equations.push_back(v1);
 equations.push_back(v2);
 //equations.push_back(d3);
 vector< vector<float(*)(vector<float>)> > jacobine;
 vector<float(*)(vector<float>)> firstRow;
 firstRow.push_back(derivativeV1X0);
 firstRow.push_back(derivativeV1X1);
 //firstRow.push_back(derivativeD1c2);
 vector<float(*)(vector<float>)> secondRow;
 secondRow.push_back(derivativeV2X0);
 secondRow.push_back(derivativeV2X1);
 //secondRow.push_back(derivativeD2c2);
/*
 vector<float(*)(vector<float>)> thirdRow;
 thirdRow.push_back(derivativeD3c0);
 thirdRow.push_back(derivativeD3c1);
 thirdRow.push_back(derivativeD3c2);*/
 jacobine.push_back(firstRow);
 jacobine.push_back(secondRow);
//jacobine.push_back(thirdRow);
 vector <float> chute;
 chute.push_back(1.5);
 chute.push_back(1.0);
 cout<<"CHUTE.size(): "<<chute.size()<<endl;
 //chute[0] = 2.0;
 //chute[1] = 3.0;
 chute = newtonMethodNL(equations, jacobine, 0.00001, chute, 30);
 cout<<"-----------------------------------------------------\n"<<endl;
 //chute = broydenMethodNL(equations, computeJacobine(jacobine,chute),0.00001, chute, 30);
 cout<<"-----------------------------------------------------\n"<<endl;
 cout<<"RAIZES:\n\n"<<endl;
 cout<<"CHUTE.size(): "<<chute.size()<<endl;
 for(int i = 0; i<(int)chute.size();i++)
 { 
  cout<<chute[i]<<endl;
 }
 cout<<"-----------------------------------------------------\n"<<endl;
 vector<float>params(3,1.0); 
 //params.push_back(0);
 //params.push_back(1);
 vector<float(*)(float,vector<float>)> jacobiano;
 jacobiano.push_back(derivativeHb0); 
 jacobiano.push_back(derivativeHb1); 
 jacobiano.push_back(derivativeHb2);
 vector<float> xValues{1.0,2.0,3.0};
 vector<float> yValues {1.0,2.0,9.0};
 params = leastSquaresNL(jacobiano,q,xValues,yValues,params,8);
 for(int i = 0; i<(int)params.size();i++)
 { 
  cout<<params[i]<<endl;
 } 
 //cout<<inverseInterpolation(t,3,0.0001,17)<<endl;
 //cout<<bissectionMethod(t , 0.0001, 0, 10, 100)<<endl;
}

