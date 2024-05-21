#include "Repository.h"
#include <fstream>
#include <iostream>

void PisicaRepo::extract_from_file(string fileName) {
	
	string line;
	std::ifstream file(fileName);
	if (file.is_open()) {
		while (getline(file, line)) {
			string nume = "", culoare = "";
			int meows = 0;
			int i;
			for (i = 0; line[i] != ' ' && line[i] != NULL; i++) {
				nume += line[i];
			}
			i++;
			for (; line[i] != ' ' && line[i] != NULL; i++) {
				culoare += line[i];
			}
			i++;
			for (; line[i] != ' ' && line[i] != NULL; i++) {
				int cifre = 1;
				meows = (line[i] - '0') + meows * 10;
				cifre *= 10;
			}
			Pisica cat{ nume, culoare, meows };
			add_pisica(cat);
		}
		file.close();
	}
	else printf("cplm");
	
}

const vector<Pisica> PisicaRepo::get_all_pisici() {
	return this->pisici;
}

void PisicaRepo::add_pisica(Pisica pisica) {
	this->pisici.push_back(pisica);
}

void PisicaRepo::delete_pisica(Pisica pisica) {
	int pozitie = 0;
	for (auto& it : pisici) {
		pozitie++;
		if (pisica.getCuloare() == it.getCuloare() &&
			pisica.getNume() == it.getNume()) {
			break;
			
		}
	}

	this->pisici.erase(pisici.begin() + pozitie);
}

void PisicaRepo::modify_pisica(Pisica pisica, string new_nume,
	string new_culoare, int new_meows) {

	for (auto& it : pisici) {
		if (pisica.getCuloare() == it.getCuloare() &&
			pisica.getNume() == it.getNume()) {
			it.setNume(new_nume);
			it.setCuloare(new_culoare);
			it.setMeows(new_meows);
		}
	}
}

