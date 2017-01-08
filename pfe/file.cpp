#include "file.h"

using namespace std;

File::File(const QString &name) : QFile(name)
{

}

 QString File:: retourneLigne(int pos)
 {
    mFichierEntree= new File (fileName());
    if(!mFichierEntree->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cerr << "on ne peut pas lire le fichier" <<endl;
    }

    QTextStream in(mFichierEntree);

    for(int i=0;i<pos;i++)
        in.readLine();

    return in.readLine();

 }

vector<int> File::retourneColonne(int pos)
 {
     vector<int>colonne;
     int nbLignes = this->getNombreDeLignes();
     QTextStream in(this);
     QStringList str;
     QString ligne;

     if(!this->open(QIODevice::ReadOnly | QIODevice::Text))
     {
         cerr << "on ne peut pas lire le fichier" <<endl;
     }

      for(int i=0;i<nbLignes;i++)
      {
          ligne=in.readLine();
          str=ligne.split(";");
          colonne.push_back(str[pos-1].toInt());
          cout << colonne[i] <<endl;
      }
      return colonne;

 }


 void File :: ecrire(QString ligne, float b, Application* app)
 {
     mFichierSortie= new File (fileName());

     if (!mFichierSortie->open(QIODevice::Append | QIODevice::Text))
         cout << "error";


     QStringList str=ligne.split(";");
     int nbelem=str.count();


     QTextStream out(mFichierSortie);
     for(int i=0;i<nbelem-1;i++)
     {
     out << app->loiLaplace(str[i].toFloat(),b) << ";";
     Sleep(1);
     }
     out << app->loiLaplace(str[nbelem-1].toFloat(),b) << endl;
     mFichierSortie->close();

 }

 void File :: garderNLignes(float pourcent, File* ficSortie, Application* app)
 {
     int nbLigne = this->getNombreDeLignes();
     int nombreLigneGarde = nbLigne*pourcent;
     cout << nbLigne << " / " <<nombreLigneGarde << endl;
     vector <int> tab;
     int j=0;

     tab.push_back(app->uniformeAleatoire(0,nbLigne-1,"int"));
     Sleep(1);
     for (int i=1;i<nombreLigneGarde;i++)
     {
        tab.push_back(app->uniformeAleatoire(0,nbLigne-1,"int"));
        Sleep(1);
        j=0;
        while(j<i)
        {

            if(tab[i]==tab[j])
            {
                tab[i]=app->uniformeAleatoire(0,nbLigne-1,"int");
                Sleep(1);
                j=0;
            }
            else j++;
        }
     }

     if (!ficSortie->open(QIODevice::WriteOnly | QIODevice::Text))
         cout << "error";

     QTextStream out(ficSortie);

     for(int i=0; i<nombreLigneGarde;i++)
     {
        cout << tab[i]<<endl;
        out <<this->retourneLigne(tab[i])<<endl;
     }

     ficSortie->close();

 }

 QString File::getNomFichier()
 {
     return fileName();
 }

 int File::getNombreDeLignes()
 {
     File* file= new File (fileName());
     if(!file->open(QIODevice::ReadOnly | QIODevice::Text))
     {
         cerr << "on ne peut pas lire le fichier" <<endl;
     }

     QTextStream in(file);
     int nombreDeLignes = 0;
     while(in.readLine()!=NULL)
     {
         nombreDeLignes++;
     }
     return nombreDeLignes;
 }
