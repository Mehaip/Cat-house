#include "Simulare.h"
#include <QLayout>
#include <QLabel>
#include <qformlayout.h>
void PisicaGUI::initGUI() {
	
	auto main_layout = new QHBoxLayout{};
	this->setLayout(main_layout);

	auto col1 = new QVBoxLayout{};
	main_layout->addLayout(col1);

	col1->addWidget(new QLabel{ "Pisicute" });
	col1->addWidget(cat_list);

	auto side_layout = new QFormLayout{};

	side_layout->addRow("Nume",nume_line);
	side_layout->addRow("Culoare",culoare_line);
	side_layout->addRow("meows",meows_line);

	main_layout->addLayout(side_layout);


}

void PisicaGUI::addCats() {
	vector<Pisica> pisici = service.get_all_pisici();

	for (auto& it : pisici) {
		string nume = it.getNume();
		string pisica = it.getCuloare();
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(nume));
		item->setData(Qt::UserRole, QString::fromStdString(pisica));
		cat_list->addItem(item);
	}

}