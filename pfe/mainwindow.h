//////////////////////////////
///
///  @file mainwindow.h
///  @brief
///  @author VIOLET Julien
///  @author BRENIERE Loup
///  @version 1
///  @date 12/01/2017
///
///
///
//////////////////////////////

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

////////////////////////
///
///  @class MainWindow
///
///  @brief classe gérant la fenetre et son contenu
///
////////////////////////
class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:

    /////////////////////////////
    ///
    /// @brief crée une fenetre incluant un histogramme
    ///
    /// @param histo : un histogramme
    /// @param app : une application
    ///
    /////////////////////////////
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
    /////////////////////////////
    ///
    /// @brief callback appelé lors de l'appuie sur le bouton et met à jour l'histogramme en fonction des valeurs saisies
    ///
    /////////////////////////////
    void coucou();

};

#endif // MAINWINDOW_H
