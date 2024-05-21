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



	auto btnLayout = new QHBoxLayout{};

	btnLayout->addWidget(addBtn);
	btnLayout->addWidget(delBtn);
	btnLayout->addWidget(modifyBtn);
	btnLayout->addWidget(sortBtn);
	btnLayout->addWidget(resetBtn);
	
	auto dreapta_layout = new QVBoxLayout{};

	dreapta_layout->addLayout(side_layout);
	dreapta_layout->addLayout(btnLayout);
	

	main_layout->addLayout(dreapta_layout);


}


void PisicaGUI::addCats() {
	cat_list->clear();
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

	QObject::connect(addBtn, &QPushButton::clicked, [&]() {
		auto nume = nume_line->text();
		auto culoare = culoare_line->text();
		auto meows = meows_line->text();

		string numeStr = nume.toStdString();
		string culoareStr = culoare.toStdString();
		string meowsStr = meows.toStdString();

		int meowsInt = std::stoi(meowsStr);

		service.add_pisica(numeStr, culoareStr, meowsInt);
		QListWidgetItem* item = new QListWidgetItem(nume);
		item->setData(Qt::UserRole, culoare);
		cat_list->addItem(item);
		});

	QObject::connect(delBtn, &QPushButton::clicked, [&]() {
		auto nume = nume_line->text().toStdString();
		auto culoare = culoare_line->text().toStdString();

		vector<Pisica> pisici = service.get_all_pisici();
		int poz = service.find_pisica(nume, culoare);
		Pisica cat = pisici[poz];

		service.delete_pisica(nume, culoare, cat.getMeows());
		QListWidgetItem* item = cat_list->takeItem(poz);
		delete item;

	});

	QObject::connect(sortBtn, &QPushButton::clicked, [&]() {

		this->cat_list->clear();
		vector<Pisica> pisici = service.sort_by_meows();
		for (auto& it : pisici) {
			string nume = it.getNume();
			string pisica = it.getCuloare();
			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(nume));
			item->setData(Qt::UserRole, QString::fromStdString(pisica));
			cat_list->addItem(item);
		}


		});

	QObject::connect(resetBtn, &QPushButton::clicked, [&]() {
		addCats();
		});
	
}