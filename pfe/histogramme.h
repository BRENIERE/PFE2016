#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H

#define TailleHisto 11

#include <math.h>

class Histogramme
{
public:
    Histogramme();
    float getValeur(int i);
    int getQuantite(int i);
    int getMaxQuantites();
    int getMinQuantites();

private:
    float mValeurs[TailleHisto];
    int mQuantites[TailleHisto];
};

#endif // HISTOGRAMME_H
