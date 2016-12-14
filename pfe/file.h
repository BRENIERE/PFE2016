#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>

#include "application.h"
#include "windows.h"


class File : public QFile
{
    Q_OBJECT

public:
    File(const QString &name);
    QString retourneLigne();
    void ecrire(float a, float b, Application* app);
    QString getNomFichier();


private:
    File* mFichierEntree;
    File* mFichierSortie;
};

#endif // FILE_H
