#pragma once

#include <iostream>
#include<string>
#include <iomanip>
#include <limits>

extern double dGlobalZeit;
using namespace std;

class Fahrzeug
{
public:
	Fahrzeug(std::string p_sName);
	Fahrzeug(std::string sName, double p_dMaxGeschwindigkeit);

	virtual void vAusgeben(std::ostream&) const;

	////Klassenfunktion für die Ausgabe von Kopfzeile der Zusammenfassung
	static void vKopf();
	virtual void vSimulieren();
	virtual double getTankinhalt() const;
	virtual double dTanken(double dMenge = std::numeric_limits<double>::infinity());
	virtual double dGeschwindigkeit() const;
	bool operator <(const Fahrzeug&);
	virtual Fahrzeug& operator =(const Fahrzeug&);

	Fahrzeug();
	virtual~Fahrzeug();
private:
	static inline int p_iMaxID = 0;
	Fahrzeug(const Fahrzeug&) = delete;

protected:
	std::string p_sName; 
	
	const int p_iID;
	

	double p_dMaxGeschwindigkeit;				//Maximalgeschwindigkeit des Fahrzeugs
	double p_dGesamtstrecke = 0.0;				//bisher zurueckgelegte Gesamtstrecke
	double p_dGesamtZeit = 0.0;					//die gesamte Fahrzeit des Objektes
	double p_dZeit = 0.0;						//Zeit, zu der das Fahrzeug zuletzt simuliert wurde

};

ostream& operator <<(ostream&, const Fahrzeug&);

