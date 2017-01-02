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
