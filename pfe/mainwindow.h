#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
    MainWindow();

    private:
    QPushButton* bouton;
    QVBoxLayout* vl;
};

#endif // MAINWINDOW_H
