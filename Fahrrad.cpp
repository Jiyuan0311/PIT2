#include "Fahrrad.h"

Fahrrad::Fahrrad()
{
}

Fahrrad::Fahrrad(string sName)
	:Fahrzeug(sName)
{
}

Fahrrad::Fahrrad(string sName, double dMaxGeschwindigkeit)
	: Fahrzeug(sName, dMaxGeschwindigkeit)
{
}

Fahrrad::~Fahrrad()
{
}

double Fahrrad::dGeschwindigkeit() const
{
	double dSpeed = p_dMaxGeschwindigkeit * pow(0.9, floor(p_dGesamtstrecke / 20));
	if (dSpeed < 12) dSpeed = 12;
	return dSpeed;
}

double Fahrrad::dTanken()
{
	return 0.0;
}
