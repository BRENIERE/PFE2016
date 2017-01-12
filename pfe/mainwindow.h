#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>

#include "zonedessin.h"
#include "histogramme.h"
#include "application.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
    MainWindow(Histogramme* histo, Application* app);


    private:
    QPushButton* bouton;
    QVBoxLayout* vl;
    QLineEdit *lineEditNbValeur;
    QLineEdit* lineEditCentre;
    QLineEdit* lineEditEpsilon;
    QLabel* labelNbValeur;
    QLabel* labelCentre;
    QLabel* labelEpsilon;
    Application* mApp;
    Histogramme* mHisto;
    QWidget* mFenetre;
    ZoneDessin* mZoneDessin;

    private slots:
    void coucou();

};

#endif // MAINWINDOW_H
