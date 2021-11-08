#pragma once
#include "Fahrzeug.h"

class PKW :
    public Fahrzeug
{
public:
	PKW();
	PKW(std::string sName);
	PKW(std::string sName, double dMaxGeschwindigkeit);
	PKW(std::string sName, double dMaxGeschwindigkeit, double dVerbrauch);
	PKW(std::string sName, double dMaxGeschwindigkeit, double dVerbrauch, double dVolumen);
	virtual ~PKW();

	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity()) override;
	virtual double getTankinhalt() const override;
	virtual void vSimulieren() override;
	virtual void vAusgeben(std::ostream&) const override;
	PKW& operator =(const PKW&);

private:
	double p_dVerbrauch;		//Liter/100km
	double p_dTankvolumen;		//Liter
	double p_dTankinhalt;		//Liter
};

