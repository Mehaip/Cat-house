#pragma once
#include <string>
using std::string;

class Pisica
{
private:
	string nume;
	string culoare;
	int meows;

public:

	/// constructor
	Pisica(string nume, string culoare, int meows) : nume{ nume }, culoare{ culoare }, meows{ meows } {};

	string getNume();
	string getCuloare();
	int getMeows();

	void setNume(string new_name);
	void setCuloare(string new_color);
	void setMeows(int new_meows);

};

