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
    mZoneDessin->setMinimumSize(800,300);
    setCentralWidget(mFenetre);
    mFenetre->setFixedSize(800,600);
    bouton = new QPushButton("Actualiser");
    lineEditNbValeur = new QLineEdit("500");
    lineEditCentre = new QLineEdit("200.0");
    lineEditEpsilon = new QLineEdit("1.0");
    lineEditNbValeur->setInputMask("00009");
    lineEditCentre->setInputMask("00009.9");
    lineEditEpsilon->setInputMask("009.900");
    labelNbValeur = new QLabel();
    labelCentre = new QLabel();
    labelEpsilon = new QLabel();
    labelNbValeur->setText("Nombre de valeur :");
    labelCentre->setText("Moyenne :");
    labelEpsilon->setText("Epsilon :");
    vl = new QVBoxLayout();
    vl->addWidget(mZoneDessin);
    vl->addWidget(labelNbValeur);
    vl->addWidget(lineEditNbValeur);
    vl->addWidget(labelCentre);
    vl->addWidget(lineEditCentre);
    vl->addWidget(labelEpsilon);
    vl->addWidget(lineEditEpsilon);
    vl->addWidget(bouton);
    mFenetre->setLayout(vl);

    connect(bouton, SIGNAL(clicked()), this, SLOT(coucou()));

}


void MainWindow::coucou()
{
    int nbValeur;
    float centre;
    float epsilon;
    QString textValeur = lineEditNbValeur->text();
    QString textCentre = lineEditCentre->text();
    QString textEpsilon = lineEditEpsilon->text();
    cout << "mon texte est : " << textValeur.toStdString() << endl;
    if(textValeur==" " || textCentre==" " || textEpsilon==" ")
    {
        cout << "veuillez saisir une valeur correcte !" <<endl;
    }
    else
    {
        nbValeur = textValeur.toInt();
        centre = textCentre.toFloat();
        epsilon = textEpsilon.toFloat();
        cout << "nbValeur = "<< nbValeur <<endl;
        cout << "nbCentre = "<< centre <<endl;
        cout << "nbEpsilon = "<< epsilon <<endl;
        mHisto = new Histogramme("valeurBruitee",mApp,nbValeur,centre,epsilon);
        mZoneDessin->changerHisto(mHisto);
        mFenetre->update();

    }
}
