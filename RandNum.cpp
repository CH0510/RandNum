#include "RandNum.h"

using namespace std;

GenerateRandNum::GenerateRandNum(){}

double GenerateRandNum::gaussrand_NORMAL() {
	static double V1, V2, S;
	static int phase = 0;
	double X;
         

	if (phase == 0) {
		do {
			double U1 = (double) e() / e.max();
			double U2 = (double) e() / e.max();

			V1 = 2 * U1 - 1;
			V2 = 2 * U2 - 1;
			S = V1 * V1 + V2 * V2;
		} while (S >= 1 || S == 0);
 
 
		X = V1 * sqrt(-2 * log(S) / S);
	} else
		X = V2 * sqrt(-2 * log(S) / S);
 
 
	phase = 1 - phase;
 
 
	return X;
}
 
 
double GenerateRandNum::gaussrand(double mean, double sigma) {
	return mean + gaussrand_NORMAL() * sigma;
} 

 
double GenerateRandNum::poisson(double lam)  /* 产生一个泊松分布的随机数，param:lam*/
{
        double Lambda = lam, k = 0;
        long double p = 1.0;
        long double l=exp(-Lambda);  /* 为了精度，才定义为long double的，exp(-Lambda)是接近0的小数*/
        //printf("%.15Lfn",l);
        while (p>=l)
        {
                double u = U_Random();
                p *= u;
                k++;
        }
        return k-1;
}
 
double GenerateRandNum::U_Random()   /* 产生一个0~1之间的随机数 */
{
        std::uniform_real_distribution<double> u(0,1);
        return u(e);
}


double GenerateRandNum::raleighRandNum(double sigma2){  //raleighRandNum ,para: sigma2
    double x1 = gaussrand(0,sigma2);
    double x2 = gaussrand(0,sigma2);
    return sqrt(pow(x1,2)+pow(x2,2));
}



double GenerateRandNum::randomExponential(double lambda)
{
    double pV = 0.0;
    while(1)
    {
        pV = (double)e()/(double)e.max();
        if (pV != 1)
        {
            break;
        }
    }
    pV = (-1.0/lambda)*log(1-pV);
    return pV;
}
