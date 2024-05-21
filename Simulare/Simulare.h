#pragma once
#include <QLineEdit>
#include <QWidget>
#include <QListWidget>
#include <QPushButton>
#include <QtWidgets/QMainWindow>
#include "ui_Simulare.h"
#include "Service.h"

class PisicaGUI : public QWidget {
private:

	PisicaService& service;
	QListWidget* cat_list = new QListWidget{};

	QLineEdit* nume_line = new QLineEdit{};
	QLineEdit* culoare_line = new QLineEdit{};
	QLineEdit* meows_line = new QLineEdit{};

	QPushButton* addBtn = new QPushButton{"&Add"};
	QPushButton* delBtn = new QPushButton{"&Del"};
	QPushButton* modifyBtn = new QPushButton{"&Modify"};
	QPushButton* sortBtn = new QPushButton{ "&Sort" };
	QPushButton* resetBtn = new QPushButton{ "&Reset" };

	void initGUI();
	void addCats();
	void initConnect();
	void resetCats();

public:

	PisicaGUI(PisicaService& service) : service{ service } {
		initGUI();
		addCats();
		initConnect();
		
	}
};
