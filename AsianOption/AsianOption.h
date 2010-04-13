#include <vector>
#include "mtrand.h"

//GENERATE A MATRIX OF PSEUDO-RANDOM STANDARD NORMAL VARIABLES
std::vector<std::vector<double>> createNormMatrix(int numRows, int numCols){
double u, v, x, y, q;	
std::vector<std::vector<double>> normalMatrix;
MTRand drand;
	for (int i = 0; i < numRows; i++){
		std::vector<double> normalVector;
		for (int j = 0; j < numCols; j++){
			u = drand();
			v = 1.7156*drand() - 0.5);
			x = u - 0.449871;
			y = abs(v) + 0.386595;
			q = SQR(x) + y*(0.19600*y - 0.25472*x);

			while (q > 0.27597 && (q > 0.27846 || SQR(v) > -4.0*log(u)*SQR(u))){
				u = drand();
				v = 1.7156*drand() - 0.5);
				x = u - 0.449871;
				y = abs(v) + 0.386595;
				q = SQR(x) + y*(0.19600*y - 0.25472*x);
			}
			normalVector.push_back(drand());
		}
		normalMatrix.push_back(normalVector);
	}
	return normalMatrix;
}

//GENERATE A MATRIX OF STOCK PATHS

//CALCULATE THE MEAN OF THE ROWS
std::vector<double> meanPriceVector(std::vector<std::vector<double>> stockPriceMatrix){

	std::vector<double> meanVector;
	for (int i = 0; i < stockPriceMatrix.size(); i++){
		double sum  = 0;
		for (int j = 0; j < stockPriceMatrix[0].size(); j++){
			sum = stockPriceMatrix[i][j] + sum;
		}
		meanVector[i].pushBack(sum/stockPriceMatrix[0].size());
	}
	return meanVector;
}

//CALCULATE THE PAYOFFS OF THE ROWS

//PRICE THE OPTION 

//CALCULATE THE STANDARD ERROR