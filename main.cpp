#include <iostream>
#include <fstream>
#include "RandNum.h"
#include <vector>
using namespace std;

int main(){
    ofstream fcout_U01("U01Data.txt");
    if(!fcout_U01.is_open())
        return -1;
    ofstream fcout_Gaussian("gaussianData.txt");
    if(!fcout_Gaussian.is_open())
        return -1;
    ofstream fcout_Rayleigh("rayleighData.txt");
    if(!fcout_Rayleigh.is_open())
        return -1;
    ofstream fcout_Poisson("poissonData.txt");
    if(!fcout_Poisson.is_open())
        return -1;
    GenerateRandNum grn;
    vector<double> v1(30000);
    for(int i = 0;i < 10000;i++)
    {
        v1[i] = grn.gaussrand(0,1);
        v1[i+10000] = grn.gaussrand(0,4.26);
        v1[i+20000] = grn.gaussrand(-2.5,1);
    }
    for(vector<double>::iterator it = v1.begin();it != v1.end();it++)
        fcout_Gaussian << (*it) << endl;

    vector<double> v2(40000);
    for(int i = 0;i < 10000;i++)
    {
        v2[i] = grn.poisson(0.2);
        v2[i+10000] = grn.poisson(1);
        v2[i+20000] = grn.poisson(6);
        v2[i+30000] = grn.poisson(10);
    }
    for(vector<double>::iterator it = v2.begin();it != v2.end();it++)
        fcout_Poisson << (*it) << endl;

    vector<double> v3(30000);
    for(int i = 0;i < 10000;i++)
    {
        v3[i] = grn.raleighRandNum(1);
        v3[i+10000] = grn.raleighRandNum(0.36);
        v3[i+20000] = grn.raleighRandNum(3.4);
    }
    for(vector<double>::iterator it = v3.begin();it != v3.end();it++)
        fcout_Rayleigh << (*it) << endl;
    
        for(int i =0;i < 1000000;i++)
            fcout_U01 << grn.U_Random()<<endl; 
    
    fcout_Rayleigh.close();
    fcout_Gaussian.close();
    fcout_Poisson.close();
    fcout_U01.close();

    return 0;

}