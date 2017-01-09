/////////////////////////////
///
/// @file application.cpp
///
/////////////////////////////

#include "application.h"

using namespace std;

Application::Application()
{

}

float Application::loiLaplace(double centre, double epsilon)
{
    float u= uniformeAleatoire(-0.5,0.5,"real");
    return (centre - u/qAbs(u)*qLn(1-2*qAbs(u))/epsilon);

}

float Application::uniformeAleatoire(float min, float max, QString type)
{

    QTime t;
    int t2;
    t = t.currentTime();
    t2 = t.hour()*3600*1000+t.minute()*60*1000+t.second()*1000+t.msec();
    mt19937 gen(t2);

/*
    random_device rd;
    mt19937 gen(rd());
  */

    if (type=="int")
    {
        uniform_int_distribution<> dis(min, max);
        return dis(gen);
    }
    else if (type=="real")
    {
        uniform_real_distribution<> dis(min, max);
        return dis(gen);
    }
    else cout << "erreur de type" <<endl;
    return 0;

}

vector< vector<int> > Application::enumerationEtOccurence(vector<int> colonne)
{
   int tailleColonne = colonne.size();
   cout << "taille colonne :" << tailleColonne <<endl;
   vector< vector<int> > tab;
   vector<int> enumeration;
   vector<int> occurence;
   int j=0;
   int i=1;

   enumeration.push_back(colonne[0]);
   occurence.push_back(1);


  while(i<tailleColonne)
   {
       while(j<enumeration.size())
       {
           if(i<tailleColonne && colonne[i]==enumeration[j])
           {
                occurence[j]++;
                j=0;
                i++;
           }
           else j++;
        }
        if(i<tailleColonne && j==enumeration.size())
        {
            enumeration.push_back(colonne[i]);
            occurence.push_back(1);
            j=0;
            i++;
        }
    }

   tab.push_back(enumeration);
   tab.push_back(occurence);

   for (int i=0; i<enumeration.size();i++)
   {
       cout << "enum : " << tab[0][i] << " occurence : " << tab[1][i] <<endl;
   }

   return tab;
}
