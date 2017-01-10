#include "mainwindow.h"

using namespace std;

MainWindow::MainWindow(Histogramme* histo, Application* app)
{
    mApp=app;
    mHisto=histo;
    QWidget* fenetre = new QWidget();
    mFenetre=fenetre;
    ZoneDessin* zoneDessin = new ZoneDessin(mHisto);
    mZoneDessin=zoneDessin;
    setCentralWidget(mFenetre);
    mFenetre->setFixedSize(800,400);
    bouton = new QPushButton("Actualiser");
    lineEdit = new QLineEdit("500");
    lineEdit->setInputMask("00009 ");
    vl = new QVBoxLayout();
    vl->addWidget(mZoneDessin);
    vl->addWidget(lineEdit);
    vl->addWidget(bouton);
    mFenetre->setLayout(vl);

    connect(bouton, SIGNAL(clicked()), this, SLOT(coucou()));

}


void MainWindow::coucou()
{
    int nbValeur;
    QString text = lineEdit->text();
    cout << "mon texte est : " << text.toStdString() << endl;
    if(text==" ")
    {
        cout << "veuillez saisir une valeur correcte !" <<endl;
    }
    else
    {
        nbValeur = text.toInt();
        cout << "nbValeur = "<< nbValeur <<endl;
        mHisto = new Histogramme("valeurBruitee",mApp,nbValeur);
        mZoneDessin->changerHisto(mHisto);
        mFenetre->update();

    }
}
