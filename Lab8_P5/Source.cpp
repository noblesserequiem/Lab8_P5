#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;
class lista;

class Produs {
private:
	char *producator;
	int pret;
	Produs *urm;
public:
	Produs(char *prod, int pt)
	{
		producator = new char(strlen(prod) + 1);
		strcpy_s(producator, sizeof(prod) + 1, prod);
		pret = pt;
		urm = NULL;
	}
	virtual void afisare()
	{
		cout << "==================================" << endl;
		cout << "Producator: " << producator << endl;
		cout << "Pret: " << pret << endl;
	}
	friend class lista;
};

class Masina_Spalat:public Produs {
private:
	int Nr_programe;
public:
	Masina_Spalat(char *prod, int pt, int nr_p) :Produs(prod, pt)
	{
		Nr_programe = nr_p;
	}
	void afisare() 
	{
		Produs::afisare();
		cout << "Nr programe: " << Nr_programe<<endl;
	}
	friend class lista;

};

class Aragaz:public Produs{
	char *tip_arzatoare;
public:
	Aragaz(char *prod, int pt, char*tip_a) :Produs(prod, pt)
	{
		tip_arzatoare = new char(strlen(tip_a) + 1);
		strcpy_s(tip_arzatoare, sizeof(tip_a) + 1, tip_a);
	}
	void afisare()
	{
		Produs::afisare();
		cout << "Tip arzatoare: " << tip_arzatoare<<endl;
	}
	friend class lista;
};

class lista {
public:
	Produs *head;
	void adaugare(Produs *a);
	void afisare();
};

class MyException {
public:
	char code[80];
	int var;
	MyException() {
		*code = 0; 
		var = 0;
	}
	MyException(char *cd, int v)
	{
		strcpy_s(code, sizeof(cd) + 1, cd);
		var = v;
	}
};





int main()
{

	_getch();
	return 0;
}