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

void PisicaGUI::initConnect() {
	QObject::connect(cat_list, &QListWidget::itemSelectionChanged, [&]() {
		auto sel = cat_list->selectedItems();
		auto selItem = sel.at(0);
		auto nume = selItem->text().toStdString();
		auto culoare = selItem->data(Qt::UserRole).toString();
		string culoareStr = culoare.toStdString();
		int pozitie = service.find_pisica(nume, culoareStr);
		vector<Pisica> pisici = service.get_all_pisici();
		int meows = pisici[pozitie].getMeows();
		nume_line->setText(QString::fromStdString(nume));
		culoare_line->setText(culoare);
		string meowsSt;
		meowsSt = std::to_string(meows);
		meows_line->setText(QString::fromStdString(meowsSt));


		});
}