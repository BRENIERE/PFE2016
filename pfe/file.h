//////////////////////////////
///
///  @file file.h
///  @brief
///  @author VIOLET Julien
///  @author BRENIERE Loup
///  @version 1
///  @date 12/01/2017
///
///
///
//////////////////////////////


#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>
#include <vector>

#include "application.h"
#include "windows.h"

using namespace std;


////////////////////////
///
///  @class File
///
///  @brief classe gérant les modifications de fichier
///
////////////////////////
class File : public QFile
{
    Q_OBJECT

public:

    /////////////////////////////
    ///
    /// @brief Crée un nouveau fichier
    ///
    /// @param name : nom du fichier
    ///
    /////////////////////////////
    File(const QString &name);

    /////////////////////////////
    ///
    /// @brief Retourne une ligne d'un fichier
    ///
    /// @param pos : numéro de la ligne
    ///
    /////////////////////////////
    QString retourneLigne(int pos);

    /////////////////////////////
    ///
    /// @brief Retourne une colonne d'un fichier
    ///
    /// @param pos : numéro de la colonne
    ///
    /////////////////////////////
    vector<int> retourneColonne(int pos);

    /////////////////////////////
    ///
    /// @brief modifie les valeurs d'une ligne en utilisant la loi de laplace
    ///
    /// @param b : parametre epsilon
    /// @param app : une application
    ///
    /////////////////////////////
    void ecrire(QString ligne, float b, Application* app);

    /////////////////////////////
    ///
    /// @brief permet de garder un certain nombre de ligne aléatoirement dans un fichier
    ///
    /// @param pourcent : pourcentage de valeurs gardées
    /// @param ficSortie : fichier de sortie
    /// @param app : une application
    ///
    /////////////////////////////
    void garderNLignes(float pourcent, File* ficSortie, Application* app);

    /////////////////////////////
    ///
    /// @brief Complete un fichier qui a gardé un certain nombre de ligne
    ///
    /// @param ficOrigine : le fichier d'origine avant d'avoir gardé quelques lignes
    /// @param pourcent : pourcentage de ligne gardé
    /// @param app : application
    ///
    /////////////////////////////
    void completerFichier(File* ficOrigine, float pourcent, Application* app);

    /////////////////////////////
    ///
    /// @brief retourne le nom du fichier
    ///
    /////////////////////////////
    QString getNomFichier();

    /////////////////////////////
    ///
    /// @brief Retourne le nombre de ligne du fichier
    ///
    /////////////////////////////
    int getNombreDeLignes();


private:
    File* mFichierEntree;
    File* mFichierSortie;
};

#endif // FILE_H
