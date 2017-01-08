//////////////////////////////
///
///  @file application.h
///  @brief
///  @author VIOLET Julien
///  @author BRENIERE Loup
///  @version 1
///  @date 5/12/2016
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
///  @brief
///
////////////////////////


using namespace std;

class Application : public QObject
{
    Q_OBJECT

    public:

    Application();
    float loiLaplace(double centre, double epsilon);
    float uniformeAleatoire(float min, float max, QString type);
    vector< vector<int> > enumerationEtOccurence(vector<int> colonne);

    signals:

    private slots:

    private:
};

#endif // APPLICATION_H
