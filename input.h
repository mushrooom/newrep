#ifndef __INPUT_H
#define __INPUT_H

#include <fstream>
#include <iostream>
#include <typeinfo.h> 

using namespace std;
template <class T>
int input (T& t, const char var)
{
	ifstream inp("CON");
	cout<<"Введите значение переменной '"<<var<<"' типа "<<typeid(t).name()<<"===> ";
	inp>>t;

	switch (inp.rdstate())
	{
		case ios::goodbit: 
		case ios::eofbit: 
			return 0;
		case ios::failbit:
		case ios:: badbit:
			cout<<"\nОшибка ввода\n";
			return 1;
	};
	
	cout<<"\nНеизвестная ошибка на вводе...";
	return 1;
}

template <class TypeA, class TypeB, class TypeC, class TypeD>
void inputData(TypeA& a, TypeB& b, TypeC& c, TypeD& d)
{
     while (input(a, 'a'));
     while (input(b, 'b'));
	 while (input(c, 'c'));
     while (input(d, 'd'));
}

#endif  