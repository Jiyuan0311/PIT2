
#include "Fahrzeug.h"
#include "Fahrrad.h"
#include "PKW.h"
#include <memory>
#include <vector>
using namespace std;

double dGlobalZeit = 0.0;

void vAufgabe_1() {
	//Fahrzeug::init();
	Fahrzeug f1;
	Fahrzeug f2("PKW2");

	Fahrzeug *f3= new Fahrzeug("PKW3");
	delete f3;
	auto f4 = make_unique<Fahrzeug>();
	auto f5 = make_shared<Fahrzeug>("PKW4");
	cout << f5.use_count() << endl;
	shared_ptr<Fahrzeug> f6 = f5;
	cout << f6.use_count() << endl;
    vector<unique_ptr<Fahrzeug>> v;
	v.push_back(move(f4));
	v.clear();
	cout << "cleared " << endl;
	vector<shared_ptr<Fahrzeug>> v2;
	v2.push_back(f5);
	v2.push_back(move(f6));
	cout << "Vector size: " << v2.size() << endl;
	cout << f6.use_count() << endl;
}

void vAufgabe_1a() {
	auto f1 = make_unique<Fahrzeug>("PKW1", 30.0);
	auto f2 = make_unique<Fahrzeug>("PKW2", 40.0);
	auto f3 = make_unique<Fahrzeug>("PKW3", 50.0);

	vector<unique_ptr<Fahrzeug>> v2;
	v2.push_back(move(f1));
	v2.push_back(move(f2));
	v2.push_back(move(f3));

	while (dGlobalZeit < 0.01)
	{
		Fahrzeug::vKopf();
		for (vector<unique_ptr<Fahrzeug>>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			it->get()->vSimulieren();
			cout << *(it->get()) << endl;
		}
		dGlobalZeit += 0.0001;
		cout << endl;
	}

	
	cout << "Vector size: " << v2.size() << endl;

}

void vAufgabe_2() {
	//Fahrzeug::d
	//Fahrzeug::init();
	auto p1 = make_unique<PKW>("PKW1", 180.0, 10.0, 80);
	auto p2 = make_unique<PKW>("PKW2", 120.0, 8.0, 80);
	auto f1 = make_unique<Fahrrad>("Fahrrad1", 25.0);
	auto f2 = make_unique<Fahrrad>("Fahrrad2", 20.0);

	vector<unique_ptr<Fahrzeug>> v2;
	
	v2.push_back(move(p1));
	v2.push_back(move(p2));
	v2.push_back(move(f1));
	v2.push_back(move(f2));


	while (dGlobalZeit < 7)
	{
		Fahrzeug::vKopf();
		if (dGlobalZeit - 3 < 0.01 && dGlobalZeit - 3 >= 0)
		{
			for (vector<unique_ptr<Fahrzeug>>::iterator it = v2.begin(); it != v2.end(); it++)
			{
				it->get()->dTanken(80);
			}
		}
		for (vector<unique_ptr<Fahrzeug>>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			it->get()->vSimulieren();
			cout << *(it->get()) << endl;
		}
		
		cout << endl;

		dGlobalZeit += 0.01;
	}


	cout << "Vector size: " << v2.size() << endl;

}

void vAufgabe_3()
{
	
	PKW p1("PKW1", 200, 15, 80);
	PKW p2("PKW2", 120, 80);
	p1.vKopf();
	cout << p1 << endl << p2 << endl;
	dGlobalZeit = 0.3;
	p1.vSimulieren();

	cout << p1 << endl << p2 << endl;
	if (p2 < p1) cout << "OK!";

	PKW p3("");
	p3 = p1;

	cout << p1 << endl << p3 << endl;
}


int main() {
	vAufgabe_3();
	return 0;
}