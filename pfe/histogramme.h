#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H

#define TailleHisto 11
//#define NbValeurReelle 2000

#include <math.h>
#include <Windows.h>
#include <QString>
#include <vector>

#include "application.h"

using namespace std;

class Histogramme
{
public:
    Histogramme(QString type, Application* app, int NbValeurReelle, float centre, float epsilon);
    float getValeurIntervalle(int i);
    float getValeurReelle(int i);
    float getMaxValeurReelle();
    float getMinValeurReelle();
    int getQuantite(int i);
    int getMaxQuantites();
    int getMinQuantites();
    QString getType();

private:
    float mValeursIntervalles[TailleHisto];
    vector<float> mValeursReelles;
    int mQuantites[TailleHisto];
    int mNbValeurReelle;
    QString mType;

};

#endif // HISTOGRAMME_H
