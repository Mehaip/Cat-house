#include "Service.h"

const vector<Pisica> PisicaService::get_all_pisici() {
	return repo.get_all_pisici();
}

void PisicaService::add_pisica(string nume, string culoare, int meows) {
	Pisica cat{ nume, culoare, meows };
	repo.add_pisica(cat);

}

void PisicaService::delete_pisica(string nume, string culoare, int meows) {
	Pisica cat{ nume, culoare, meows };
	repo.delete_pisica(cat);
}

void PisicaService::modify_pisica(string nume, string culoare, int meows,
	string new_nume, string new_culoare, int new_meows) {
	Pisica cat{ nume, culoare, meows };
	repo.modify_pisica(cat, new_nume, new_culoare, new_meows);
}

int PisicaService::find_pisica(string nume, string culoare) {
	vector<Pisica> pisici = repo.get_all_pisici();
	int position = 0;
	for (auto& it : pisici) {
		if (it.getNume() == nume && it.getCuloare() == culoare)
			return position;
		position++;
	}
	return -1;
}