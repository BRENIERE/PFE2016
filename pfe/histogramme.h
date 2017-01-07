#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H

#define TailleHisto 11
#define NbValeurReelle 500


#include "application.h"
#include <math.h>
#include <Windows.h>
#include <QString>

class Histogramme
{
public:
    Histogramme(QString type, Application* app);
    float getValeurIntervalle(int i);
    float getValeurReelle(int i);
    float getMaxValeurReelle();
    float getMinValeurReelle();
    int getQuantite(int i);
    int getMaxQuantites();
    int getMinQuantites();

private:
    //int mNbValeursRelles;
    float mValeursIntervalles[TailleHisto];
    float mValeursReelles[NbValeurReelle];
    int mQuantites[TailleHisto];

};

#endif // HISTOGRAMME_H
