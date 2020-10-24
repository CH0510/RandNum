#ifndef _RANDNUM__H
#define _RANDNUM__H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <random>
#include "unistd.h"

class GenerateRandNum
{
private :
        std::random_device e;
        double gaussrand_NORMAL();
public :
    GenerateRandNum();
    double gaussrand(double mean, double sigma);
    double U_Random();
    double poisson(double lam);
    double raleighRandNum(double sigma2);
    double randomExponential(double lambda); 
};

#endif // _RANDNUM