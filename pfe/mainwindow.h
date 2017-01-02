#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "zonedessin.h"
#include "histogramme.h"

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <iostream>



class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
    MainWindow(Histogramme* histo);


    private:
    QPushButton* bouton;
    QVBoxLayout* vl;

    private slots:
    void coucou();

};

#endif // MAINWINDOW_H
