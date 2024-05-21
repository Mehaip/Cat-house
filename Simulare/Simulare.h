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

	QPushButton* addBtn = new QPushButton{};
	QPushButton* delBtn = new QPushButton{};
	QPushButton* modifyBtn = new QPushButton{};

	void initGUI();
	void addCats();
	void initConnect();

public:

	PisicaGUI(PisicaService& service) : service{ service } {
		initGUI();
		addCats();
		initConnect();
		
	}
};
