#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QTextStream>
#include <QString>
#include <iostream>


class File : public QFile
{
    Q_OBJECT

public:
    File(const QString &name);
    QString retourneLigne();
    QString getNomFichier();

private:
    File* mFichierEntree;
    File* mFichierSortie;
};

#endif // FILE_H
