#include "histogramme.h"
#include "stdio.h"

using namespace std;

Histogramme::Histogramme(QString type, Application* app, int NbValeurReelle, float centre, float epsilon)
{
    mNbValeurReelle=NbValeurReelle;
    for(int i=0;i<TailleHisto;i++)
    {
        mQuantites[i]=0;
    }
    if(type=="test")
    {
        mType = "test";
            for(int i=0;i<TailleHisto;i++)
            {
                mValeursIntervalles[i]=100.5+10.0*i;
                mQuantites[i]= -(i-floor(TailleHisto/2))*(i-floor(TailleHisto/2))+ floor(TailleHisto/2)*floor(TailleHisto/2)+1;
            }
    }
    else if(type=="valeurBruitee")
        {
            mType = "valeurBruitee";
            for(int i=0;i<NbValeurReelle;i++)
            {
                mValeursReelles.push_back(app->loiLaplace(centre,epsilon));
                Sleep(1);
                //cout << mValeursReelles[i] <<endl;
            }
            //cout << "valeur max :"<< getMaxValeurReelle()<<endl;
            for(int i=0;i<TailleHisto;i++)
            {
                //mValeursIntervalles[i]=getMinValeurReelle()+i*(getMaxValeurReelle()-getMinValeurReelle())/TailleHisto;
                if((centre-(this->getMinValeurReelle()))>((this->getMaxValeurReelle())-centre))
                {
                    mValeursIntervalles[i]=getMinValeurReelle()+i*2*(centre-(this->getMinValeurReelle()))/TailleHisto;
                    mValeursIntervalles[i]=(1./10.)*floor(10*mValeursIntervalles[i]);
                }
                else
                {
                     mValeursIntervalles[TailleHisto-i-1]=getMaxValeurReelle()-i*2*((this->getMaxValeurReelle())-centre)/TailleHisto;
                     mValeursIntervalles[TailleHisto-i-1]=(1./10.)*floor(10*mValeursIntervalles[TailleHisto-i-1]);
                }

            }
            for(int i=0;i<NbValeurReelle;i++)
            {
                int j=0;
                while(mValeursReelles[i]>=mValeursIntervalles[j] && j < TailleHisto)
                {
                    j++;
                }
                mQuantites[j-1]++;
            }
        }
    else
        {
            for(int i=0;i<TailleHisto;i++)
                mValeursIntervalles[i]=i;
        }


}

float Histogramme::getValeurIntervalle(int i)
{
    return mValeursIntervalles[i];
}

float Histogramme::getValeurReelle(int i)
{
    return mValeursReelles[i];
}

float Histogramme::getMaxValeurReelle()
{
    float max=mValeursReelles[0];
    for(int i=0;i< mNbValeurReelle;i++)
    {
        if(mValeursReelles[i]>max)
            max=mValeursReelles[i];
    }
    return max;
}

float Histogramme::getMinValeurReelle()
{
    float min=mValeursReelles[0];
    for(int i=0;i<mNbValeurReelle;i++)
    {
        if(mValeursReelles[i]<min)
            min=mValeursReelles[i];
    }
    return min;
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

QString Histogramme::getType()
{
    return mType;
}
