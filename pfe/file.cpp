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

 QString File::getNomFichier()
 {
     return fileName();
 }
