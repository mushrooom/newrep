#ifndef __MAIN_H
#define __MAIN_H

#define Error_Sqrt "Корень из отрицательного числа"
#define Error_ZeroDivide "Деление на ноль"
#define Error_Res "Переполнение результата"

#include <iostream>
#include <math.h>
#include <float.h>
#include <conio.h>

using namespace std;

template <class TypeA, class TypeB, class TypeC, class TypeD, class TypeResult>

class TCalc
{
	private: 
		TypeA *A;
		TypeB *B;
		TypeC *C;
		TypeD *D;

		TypeResult Res;

	public:
		TCalc(TypeA a, TypeB b, TypeC c, TypeD d)
		{
			A = new TypeA; *A = a;
			B = new TypeB; *B = b;
			C = new TypeC; *C = c;
			D = new TypeD; *D = d;
		}

		~TCalc()
		{
			delete A;
			delete B;
			delete C;
			delete D;
		}

		int Calc()
		{
			long double a, b, c, d;
			
			a = *A;
			b = *B;
			c = *C;
			d = *D;

			cout<<endl<<typeid(*A).name()<<" a = "<<a<<"; "
					  <<typeid(*B).name()<<" b = "<<b<<"; "
					  <<typeid(*C).name()<<" c = "<<c<<"; "
					  <<typeid(*D).name()<<" d = "<<d<<endl;

			long double x, y, res;
			try
			{
					x = (41*d)/a; 
					y = a - c/b + d;
					if (a == 0 || b == 0 || y == 0) throw Error_ZeroDivide;
					else 
					{
						if (x < 0)
						{
							#ifdef _DEBUG
								cout<<"\nЧислетель = "<<(sqrt(fabsl(x)))<<"i+"<<1;
								cout<<"\nЗнаменатель = "<<y<<endl;
							#endif
							cout<<"\nРезультат = "<<(sqrt(fabsl(x)))/y<<"i + "<<1/y<<endl;						
						}
						else
						{
						x = sqrt(x) + 1;
						res = x/y;
						if (typeid(TypeResult) == typeid(float))
							if (fabsl(res) > FLT_MAX) throw Error_Res;
							else 
							{
								Res = (TypeResult)res;
								#ifdef _DEBUG
									cout<<"\nЧислетель = "<<x;
									cout<<"\nЗнаменатель = "<<y<<endl;
								#endif
								cout<<"\nРезультат = "<<Res<<endl;
							}
						else
							if (typeid(TypeResult) == typeid(double))
								if (fabsl(res) > DBL_MAX) throw Error_Res;
								else 
								{
									Res = (TypeResult)res;
									#ifdef _DEBUG
										cout<<"\nЧислетель = "<<x;
										cout<<"\nЗнаменатель = "<<y<<endl;
									#endif
									cout<<"\nРезультат = "<<Res<<endl;
								}
						else
							if (typeid(TypeResult) == typeid(int))
								if (res > INT_MAX || res < INT_MIN || res!=int(res)) throw Error_Res;
								else 
								{
									Res = (TypeResult)res;  
									#ifdef _DEBUG
										cout<<"\nЧислетель = "<<x;
										cout<<"\nЗнаменатель = "<<y<<endl;
									#endif
									cout<<"\nРезультат = "<<Res<<endl;
								}
						}
						
							
					}
			}

			catch (char *error)
			{
				cout<<"\nОбработка исключительной ситуации...";
				cout<<"\nОшибка:"<<error<<endl;
			}
			catch (...)
			{
				cout<<"\nОбработка неизвестной исключительной ситуации."<<endl;
				throw;
			}
			cout << "\nДля продолжения нажмите любую клавишу, для выхода из программы нажмите ESC";
			return (_getch());
		}
};

#endif