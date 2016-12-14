#include "file.h"

using namespace std;

File::File(const QString &name) : QFile(name)
{

}

 QString File:: retourneLigne()
 {
    mFichierEntree= new File (fileName());
    if(!mFichierEntree->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        cerr << "on ne peut pas lire le fichier" <<endl;
    }

    QTextStream in(mFichierEntree);

    return in.readLine();

 }

 void File :: ecrire(float a, float b, Application* app)
 {
     mFichierSortie= new File (fileName());

     if (!mFichierSortie->open(QIODevice::WriteOnly | QIODevice::Text))
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
