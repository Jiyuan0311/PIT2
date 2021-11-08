#pragma once
#include "Fahrzeug.h"

using namespace std;

class Fahrrad :
    public Fahrzeug
{
public:
	Fahrrad();
	Fahrrad(std::string sName);
	Fahrrad(std::string sName, double dMaxGeschwindigkeit);
	virtual ~Fahrrad();

	double dGeschwindigkeit() const override;
	double dTanken();
};

