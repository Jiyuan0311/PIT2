#include "Fahrzeug.h"

extern double dGlobalZeit;

using namespace std;

Fahrzeug::Fahrzeug(): p_iID(++p_iMaxID), p_sName("")
{
	cout << "Fahrzeug: " << p_sName << "(ID: " << p_iID << ") ist erzeugt." << endl;
}

Fahrzeug::Fahrzeug(string sName) : p_iID(++p_iMaxID), p_sName(sName)
{
	cout << "Fahrzeug: " << p_sName << "(ID: " << p_iID << ") ist erzeugt." << endl;
}

Fahrzeug::Fahrzeug(string sName, double maxGeschwindigkeit) : p_dMaxGeschwindigkeit(maxGeschwindigkeit > 0 ? maxGeschwindigkeit : 0), p_iID(++p_iMaxID), p_sName(sName)
{
	cout << "Fahrzeug: " << p_sName << "(ID: " << p_iID << ") ist erzeugt." << endl;
}

Fahrzeug::~Fahrzeug()
{
	cout << "Fahrzeug: " << p_sName << "(ID: " << p_iID << ") ist geloescht." << endl;
}

void Fahrzeug::vAusgeben(ostream& out) const
{
	out << resetiosflags(ios::left) << setiosflags(ios::left) << setprecision(2) << fixed;
	out << setw(5) << p_iID << setw(20) << p_sName << setw(20) << dGeschwindigkeit() << setw(20) << p_dGesamtstrecke;
	
}


void Fahrzeug::vKopf()
{
	cout << resetiosflags(ios::left) << setiosflags(ios::left);
	extern double dGlobalZeit;
	cout << "Aktuelle Zeit: " << dGlobalZeit << endl;
	cout << setw(5) << "ID" << setw(20) << "Name" << setw(20) << "Geschwindigkeit" << setw(20) << "Gesamtstrecke"
		<< setw(20) << "GesamtVerbrauch" << setw(20) << "Tankinhalt"<< endl;
	cout << "--------------------------------------------------------------------------------------------------" << endl;
}

void Fahrzeug::vSimulieren()
{
	double zeitDifferenz = dGlobalZeit - p_dZeit;
	if (fabs(p_dZeit - dGlobalZeit) > 0.01)
	{
		p_dZeit = dGlobalZeit;
		double dStrecke = dGeschwindigkeit() * zeitDifferenz;
		p_dGesamtstrecke += dStrecke;
		p_dGesamtZeit = dGlobalZeit;
	}
}

double Fahrzeug::dGeschwindigkeit() const
{
	return p_dMaxGeschwindigkeit;
}

ostream& operator <<(ostream& out, const Fahrzeug& obj)
{
	obj.vAusgeben(out);
	return out;
}

bool Fahrzeug::operator <(const Fahrzeug& fahrzeug)
{
	return (p_dGesamtstrecke < fahrzeug.p_dGesamtstrecke);
}

Fahrzeug& Fahrzeug::operator =(const Fahrzeug& fahrzeug)
{
	p_sName = fahrzeug.p_sName;
	p_dMaxGeschwindigkeit = fahrzeug.p_dMaxGeschwindigkeit;

	return *this;
}

double Fahrzeug::dTanken(double dMenge)
{
	return 0.0;
}

double Fahrzeug::getTankinhalt() const
{
	return 1;
}