#include "Pisica.h"


string Pisica::getNume() {
	return nume;
}

string Pisica::getCuloare() {
	return culoare;
}

int Pisica::getMeows() {
	return meows;
}

void Pisica::setNume(string new_name) {
	nume = new_name;
}

void Pisica::setCuloare(string new_color) {
	culoare = new_color;
}

void Pisica::setMeows(int new_meows) {
	meows = new_meows;
}
