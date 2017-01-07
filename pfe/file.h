#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>
#include <vector>

#include "application.h"
#include "windows.h"


class File : public QFile
{
    Q_OBJECT

public:
    File(const QString &name);
    QString retourneLigne(int pos);
    void ecrire(QString ligne, float b, Application* app);
    void garderNLignes(float pourcent, File* ficSortie, Application* app);
    QString getNomFichier();
    int getNombreDeLignes();


private:
    File* mFichierEntree;
    File* mFichierSortie;
};

#endif // FILE_H
