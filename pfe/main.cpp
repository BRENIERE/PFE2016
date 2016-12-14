/////////////////////////////
///
/// @file main.cpp
///
/////////////////////////////


#include "application.h"
#include "mainwindow.h"
#include "file.h"

#include <QApplication>

#include <iostream>
#include <windows.h>


using namespace std;
int main(int argc, char* argv[])
{
    //QApplication application(argc,argv);
    Application app;

    /*
    for(int i=1;i<=10;i++)
    {
    cout <<app.uniformeAleatoire(-0.5,0.5,"real") << " ";
    Sleep(1);
    }
*/
    for(int i=1;i<=10;i++)
    {
    cout <<app.loiLaplace(100,0.1) << " ";
    Sleep(1);
    }
    cout << endl;

    File fichier("../pfe/fichiers_texte/test.txt");
    fichier.ecrire(1,0.001,&app);
    cout << fichier.retourneLigne().toStdString() << endl;

    /*MainWindow fenetre;
    fenetre.show();


    return application.exec();
*/
    return 0;
}

