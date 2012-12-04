#ifndef __TYPEGENERATION_H
#define __TYPEGENERATION_H

#include <time.h>
#include "main.h"
#include "input.h"

int TypeGeneration()
{
	srand((unsigned)time(NULL));
	switch(rand()%9)
	{
		case 0:
		{
			float a, b, c, d;
			inputData(a, b, c, d); 
			TCalc <float, float, float, float, float> Object(a, b, c, d); 
			return Object.Calc(); 
		}	 
		case 1: 
		{ 
			double a,b,c,d; 
			inputData(a, b, c, d); 
			TCalc <double, double, double, double, double> Object(a, b, c, d); 
			return Object.Calc(); 
		} 
		case 2: 
		{ 
			float a,b; 
			double c,d; 
			inputData(a, b, c, d); 
			TCalc <float, float, double, double, double> Object(a, b, c, d); 
			return Object.Calc(); 
		} 
		case 3: 
		{ 
			double a,b; 
			int c,d; 
			inputData(a, b, c, d); 
			TCalc <double, double, int, int, double> Object(a, b, c, d); 
			return Object.Calc(); 
		} 
		case 4: 
		{ 
			float c,d; 
			int a,b; 
			inputData(a, b, c, d); 
			TCalc <int, int, float, float, float> Object(a, b, c, d); 
			return Object.Calc(); 
		} 
		case 5: 
		{ 
			int a,b; 
			double c,d; 
			inputData(a, b, c, d); 
			TCalc <int, int, double, double, double> Object(a, b, c, d); 
			return Object.Calc(); 
		} 
		case 6: 
		{ 
			float a; 
			int b; 
			double c,d; 
			inputData(a, b, c, d); 
			TCalc <float, int, double, double, double> Object(a, b, c, d); 
			return Object.Calc(); 
		}
		case 7: 
        { 
			double a,b; 
            int c; 
            float d; 
            inputData(a, b, c, d); 
            TCalc <double, double, int, float, double> Object(a, b, c, d); 
            return Object.Calc(); 
        } 
		case 8: 
        { 
            int a,b,c,d; 
            inputData(a, b, c, d); 
            TCalc <int, int, int, int, int> Object(a, b, c, d); 
            return Object.Calc(); 
        } 
		
		default: 
			cout << "Неизвестная ошибка..." << endl; 
        return 0; 
   } 
}

#endif