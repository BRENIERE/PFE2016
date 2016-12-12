#include "mainwindow.h"

MainWindow::MainWindow()
{

    QWidget* fenetre = new QWidget();
    setCentralWidget(fenetre);
    fenetre->setFixedSize(300,150);
    bouton = new QPushButton("toto");
    vl = new QVBoxLayout();
    vl->addWidget(bouton);
    fenetre->setLayout(vl);
}
