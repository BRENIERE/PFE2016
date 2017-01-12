#ifndef ZONEDESSIN_H
#define ZONEDESSIN_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>

#include "histogramme.h"

class ZoneDessin : public QWidget
{
public:
    ZoneDessin(Histogramme* histo);
    void changerHisto(Histogramme* histo);

private:
    Histogramme* mHisto;

protected:
     void paintEvent(QPaintEvent *event);
};

#endif // ZONEDESSIN_H
