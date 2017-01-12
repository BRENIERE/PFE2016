//////////////////////////////
///
///  @file histogramme.h
///  @brief
///  @author VIOLET Julien
///  @author BRENIERE Loup
///  @version 1
///  @date 12/01/2017
///
///
///
//////////////////////////////

#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H

#define TailleHisto 11

#include <math.h>
#include <Windows.h>
#include <QString>
#include <vector>

#include "application.h"

using namespace std;


////////////////////////
///
///  @class Histogramme
///
///  @brief classe permettant de remplir les valeurs contenu dans un histogramme
///
////////////////////////
class Histogramme
{
public:

    /////////////////////////////
    ///
    /// @brief Creation d'un histogramme
    ///
    /// @param type : test ou valeurBruitee
    /// @param app : une application
    /// @param NbValeurReelle : nombre de valeur utilisé pour réaliser l'histogramme
    /// @param centre : moyenne de la loi de Laplace
    /// @param epsilon : parametre epsilon de la loi de Laplace
    ///
    /////////////////////////////
    Histogramme(QString type, Application* app, int NbValeurReelle, float centre, float epsilon);

    /////////////////////////////
    ///
    /// @brief retourne la valeur de l'intervalle à i
    ///
    /// @param i : position
    ///
    /////////////////////////////
    float getValeurIntervalle(int i);

    /////////////////////////////
    ///
    /// @brief retourne la valeur réelle à i
    ///
    /// @param i : position
    ///
    /////////////////////////////
    float getValeurReelle(int i);

    /////////////////////////////
    ///
    /// @brief retourne le max des valeurs reelles
    ///
    /////////////////////////////
    float getMaxValeurReelle();

    /////////////////////////////
    ///
    /// @brief retourne le min des valeurs reelles
    ///
    /////////////////////////////
    float getMinValeurReelle();

    /////////////////////////////
    ///
    /// @brief retourne la quantité à la postion i
    ///
    /// @param i : position
    ///
    /////////////////////////////
    int getQuantite(int i);

    /////////////////////////////
    ///
    /// @brief retourne la quantité maximale
    ///
    /////////////////////////////
    int getMaxQuantites();

    /////////////////////////////
    ///
    /// @brief retourne la quantité minimale
    ///
    /////////////////////////////
    int getMinQuantites();

    /////////////////////////////
    ///
    /// @brief retourne le type d'histogramme
    ///
    /////////////////////////////
    QString getType();

private:
    float mValeursIntervalles[TailleHisto];
    vector<float> mValeursReelles;
    int mQuantites[TailleHisto];
    int mNbValeurReelle;
    QString mType;

};

#endif // HISTOGRAMME_H
