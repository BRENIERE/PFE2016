#include "histogramme.h"

Histogramme::Histogramme()
{
    for(int i=0;i<TailleHisto;i++)
    {
       mValeurs[i]=100.5+10.0*i;
       mQuantites[i]= -(i-floor(TailleHisto/2))*(i-floor(TailleHisto/2))+ floor(TailleHisto/2)*floor(TailleHisto/2)+1;
    }

}

float Histogramme::getValeur(int i)
{
    return mValeurs[i];
}

int Histogramme::getQuantite(int i)
{
    return mQuantites[i];
}

int Histogramme::getMaxQuantites()
{
    int max=mQuantites[0];
    for(int i=0;i<TailleHisto;i++)
    {
        if(mQuantites[i]>max)
            max=mQuantites[i];
    }
    return max;
}

int Histogramme::getMinQuantites()
{
    int min=mQuantites[0];
    for(int i=0;i<TailleHisto;i++)
    {
        if(mQuantites[i]<min)
            min=mQuantites[i];
    }
    return min;
}
