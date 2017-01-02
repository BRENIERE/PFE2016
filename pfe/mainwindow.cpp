#include "mainwindow.h"

MainWindow::MainWindow(Histogramme* histo)
{

    QWidget* fenetre = new QWidget();
    ZoneDessin* zoneDessin = new ZoneDessin(histo);
    setCentralWidget(fenetre);
    fenetre->setFixedSize(800,400);
    bouton = new QPushButton("toto");
    vl = new QVBoxLayout();
    vl->addWidget(zoneDessin);
    vl->addWidget(bouton);
    fenetre->setLayout(vl);

}
