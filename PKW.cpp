#include "PKW.h"

PKW::PKW()
{
}
PKW::PKW(string sName)
	:Fahrzeug(sName)
{
}
PKW::PKW(string sName, double dMaxGeschwindigkeit)
	: Fahrzeug(sName, dMaxGeschwindigkeit)
{
}

PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch)
	: Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(55.0), p_dTankinhalt(55.0 / 2)
{
}

PKW::PKW(string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dVolumen)
	: Fahrzeug(sName, dMaxGeschwindigkeit), p_dVerbrauch(dVerbrauch), p_dTankvolumen(dVolumen), p_dTankinhalt(dVolumen / 2)
{
}

PKW::~PKW()
{
}

double PKW::dTanken(double dMenge)
{
	if (p_dTankinhalt + dMenge < p_dTankvolumen)
	{
		p_dTankinhalt += dMenge;
	}
	else
	{
		dMenge = p_dTankvolumen - p_dTankinhalt;
		p_dTankinhalt = p_dTankvolumen;
	}

	return dMenge;
}

void PKW::vSimulieren()
{
	
	double zeitDifferenz = dGlobalZeit - p_dZeit;
	if (fabs(p_dZeit - dGlobalZeit) > 0.01)
	{
		
		double dStrecke = dGeschwindigkeit() * zeitDifferenz;
		if (dStrecke < (p_dTankinhalt * 100 / p_dVerbrauch))//genug Kraftstoff für die Strecke
		{
			p_dGesamtstrecke += dStrecke;
			p_dGesamtZeit = dGlobalZeit;
			p_dTankinhalt -= (p_dVerbrauch * dStrecke) / 100.0;
		}
		else
		{
			p_dGesamtstrecke += p_dTankinhalt * 100 / p_dVerbrauch;
			p_dGesamtZeit = dGlobalZeit;
			p_dTankinhalt = 0.0;
		}
		
		p_dZeit = dGlobalZeit;
	}
	
}


void PKW::vAusgeben(ostream& out) const
{
	Fahrzeug::vAusgeben(out);
	out << resetiosflags(ios::left) << setiosflags(ios::left) << setprecision(2) << fixed;
	out << setw(20) << p_dGesamtstrecke * p_dVerbrauch / 100 << setw(20) << p_dTankinhalt;		//Gesamtverbrauch und aktuelle Tankinhalt
}

PKW& PKW::operator =(const PKW& pkw)
{
	Fahrzeug::operator=(pkw);
	p_dVerbrauch = pkw.p_dVerbrauch;
	p_dTankvolumen = pkw.p_dTankvolumen;
	p_dTankinhalt = pkw.p_dTankinhalt;

	return *this;
}


double PKW::getTankinhalt() const
{
	return p_dTankinhalt;
}

