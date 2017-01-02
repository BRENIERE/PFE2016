#include "mainwindow.h"

using namespace std;

MainWindow::MainWindow(Histogramme* histo)
{

    QWidget* fenetre = new QWidget();
    ZoneDessin* zoneDessin = new ZoneDessin(histo);
    setCentralWidget(fenetre);
    fenetre->setFixedSize(800,400);
    bouton = new QPushButton("toto");
    QLineEdit *lineEdit = new QLineEdit("Entrez un nom de fichier");
    vl = new QVBoxLayout();
    vl->addWidget(zoneDessin);
    vl->addWidget(lineEdit);
    vl->addWidget(bouton);
    fenetre->setLayout(vl);

    connect(bouton, SIGNAL(clicked()), this, SLOT(coucou()));

}


void MainWindow::coucou()
{
    cout << "coucou" << endl;
}
