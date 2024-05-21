#pragma once
#include "Repository.h"

class PisicaService
{
private:

	PisicaRepo& repo;

public:

	PisicaService(PisicaRepo& repo) : repo{ repo } {};

	const vector<Pisica> get_all_pisici();

	void add_pisica(string nume, string culoare, int meows);

	void delete_pisica(string nume, string culoare, int meows);

	void modify_pisica(string nume, string culoare, int meows,
		string new_nume, string new_culoare, int new_meows);
};

