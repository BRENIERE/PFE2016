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

 void File :: ecrire(float a, float b, Application* app)
 {
     mFichierSortie= new File (fileName());

     if (!mFichierSortie->open(QIODevice::Append | QIODevice::Text))
         cout << "error";

     QTextStream out(mFichierSortie);
     for(int i=1;i<=9;i++)
     {
     out << app->loiLaplace(a,b) << " | ";
     Sleep(1);
     }
     out << app->loiLaplace(a,b) << endl;
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
