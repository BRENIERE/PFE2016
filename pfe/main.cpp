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
    Histogramme histo;

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

    /*
    File fichier("../pfe/fichiers_texte/test.txt");
    fichier.ecrire(1,0.1,&app);
    fichier.ecrire(100,0.1,&app);

    for(int i=0; i<fichier.getNombreDeLignes();i++)
    {
    cout << fichier.retourneLigne(i).toStdString() << endl;
    }
    cout << fichier.getNombreDeLignes() << endl;
    */

    MainWindow fenetre(&histo);
    fenetre.show();


    return application.exec();

    return 0;
}

