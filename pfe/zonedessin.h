//////////////////////////////
///
///  @file zonedessin.h
///  @brief
///  @author VIOLET Julien
///  @author BRENIERE Loup
///  @version 1
///  @date 12/01/2017
///
///
///
//////////////////////////////

#ifndef ZONEDESSIN_H
#define ZONEDESSIN_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>

#include "histogramme.h"


////////////////////////
///
///  @class ZoneDessin
///
///  @brief classe créant une zone pour stocker l'histogramme et le dessine dedans
///
////////////////////////
class ZoneDessin : public QWidget
{
public:
    /////////////////////////////
    ///
    /// @brief crée une zone de dessin
    ///
    /// @param histo : un histogramme
    ///
    /////////////////////////////
    ZoneDessin(Histogramme* histo);

    /////////////////////////////
    ///
    /// @brief permet de modifier des valeurs de l'histogramme
    ///
    /// @param histo : un histogramme
    ///
    /////////////////////////////
    void changerHisto(Histogramme* histo);

private:
    Histogramme* mHisto;

protected:
     void paintEvent(QPaintEvent *event);
};

#endif // ZONEDESSIN_H
