//////////////////////////////
///
///  @file application.h
///  @brief
///  @author VIOLET Julien
///  @author BRENIERE Loup
///  @version 1
///  @date 12/01/2017
///
///
///
//////////////////////////////

#ifndef APPLICATION_H
#define APPLICATION_H


#include <QString>
#include <QObject>
#include <QTime>
#include <iostream>
#include <random>
#include <QtGlobal>
#include <QtCore/qmath.h>
#include <vector>

////////////////////////
///
///  @class Application
///
///  @brief classe qui définit les fonctions princiaples
///
////////////////////////


using namespace std;

class Application : public QObject
{
    Q_OBJECT

    public:

    /////////////////////////////
    ///
    /// @brief Constructor.
    ///
    /// initialise l'application.
    ///
    /////////////////////////////
    Application();

    /////////////////////////////
    ///
    /// @brief Retourne une variable aléatoire associé à la loi de laplace de moyenne centre et de parametre epsilon
    ///
    /// @param centre : moyenne de loi la loi de laplace
    /// @param epsilon : parametre epsilon
    ///
    /////////////////////////////
    float loiLaplace(double centre, double epsilon);

    /////////////////////////////
    ///
    /// @brief Retourne une variable aléatoire associé à une loi uniforme entre min et max
    ///
    /// @param min : valeur minimale
    /// @param max : valeur maximale
    /// @param type : int ou reel
    ///
    /////////////////////////////
    float uniformeAleatoire(float min, float max, QString type);

    /////////////////////////////
    ///
    /// @brief Retourne un vecteur ayant un vecteur de valeur et un vecteur de d'occurence
    ///
    /// @param colonne : vecteur d'entier
    ///
    /////////////////////////////
    vector< vector<int> > enumerationEtOccurence(vector<int> colonne);

    signals:

    private slots:

    private:
};

#endif // APPLICATION_H
