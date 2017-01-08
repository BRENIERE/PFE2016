/////////////////////////////
///
/// @file main.cpp
///
/////////////////////////////


#include "application.h"
#include "mainwindow.h"
#include "file.h"
#include "histogramme.h"

#include <QApplication>


#include <iostream>
#include <windows.h>



using namespace std;
int main(int argc, char* argv[])
{
    QApplication application(argc,argv);
    Application app;
    Histogramme* histo = new Histogramme("valeurBruitee",&app);

    /*
    for(int i=1;i<=10;i++)
    {
    cout <<app.uniformeAleatoire(-0.5,0.5,"real") << " ";
    Sleep(1);
    }
    */

    /* for(int i=1;i<=10;i++)
    {
    cout <<app.loiLaplace(100,0.1) << " ";
    Sleep(1);
    }
    cout << endl;

    */


    File fichierEntree("../pfe/fichiers_texte/test.txt");
    File fichierSortie("../pfe/fichiers_texte/out.txt");
    File fichierGarderLigne("../pfe/fichiers_texte/garderLignes.txt");
    File fichierLignesRestantes("../pfe/fichiers_texte/lignesRestantes.txt");
    File fichierLireColonne("../pfe/fichiers_texte/lireColonne.txt");

    for (int i=0;i<fichierEntree.getNombreDeLignes();i++)
    {
        fichierSortie.ecrire(fichierEntree.retourneLigne(i),10,&app);
    }

    //fichierGarderLigne.garderNLignes(1,&fichierLignesRestantes,&app);
    app.enumerationEtOccurence(fichierLireColonne.retourneColonne(1));

    /*
    for(int i=0; i<fichier.getNombreDeLignes();i++)
    {
    cout << fichier.retourneLigne(i).toStdString() << endl;
    }
    cout << fichier.getNombreDeLignes() << endl;
    */

    MainWindow fenetre(histo);
    fenetre.show();


    return application.exec();

    return 0;
}

