#pragma once
#include "Pisica.h"
#include <vector>
using std::vector;
class PisicaRepo
{
private:
	vector<Pisica> pisici;
	string fileName;
	

public:
	PisicaRepo(string fileName) : fileName{ fileName } {
		extract_from_file(fileName);
	};

	void extract_from_file(string fileName);

	const vector<Pisica> get_all_pisici();

	void add_pisica(Pisica pisica);

	void delete_pisica(Pisica pisica);

	void modify_pisica(Pisica pisica, string new_nume, string new_culoare, int new_meows);


};

