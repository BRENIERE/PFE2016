#include "zonedessin.h"



ZoneDessin::ZoneDessin(Histogramme* histo)
{
    mHisto=histo;
}

void ZoneDessin::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    int marge = 30;
    int w=size().width();
    int h=size().height();
    int min = mHisto->getMinQuantites();
    int max = mHisto->getMaxQuantites();
    QFont serifFont("Times", 10, QFont::Bold);

// Définit de la couleur de fond
    painter.setBrush(QColor(255, 0, 0, 100));
    painter.setFont(serifFont);
    QLineF line1(marge,marge,marge,h-marge);
    QLineF line2(marge,marge,marge-5,marge+5);
    QLineF line3(marge,marge,marge+5,marge+5);
    painter.drawLine(line1);
    painter.drawLine(line2);
    painter.drawLine(line3);
    for(int i=0; i<TailleHisto;i++)
    {
        int quantite = mHisto->getQuantite(i);
        int hauteurRect =(quantite - min)*(h - 2*marge)/(max - min);
        int largeurRect = (w - 2*marge)/TailleHisto;
        int y = h - marge - hauteurRect;
        int x = marge + i*largeurRect;
        QRectF rectangle(x, y, largeurRect, hauteurRect);
        painter.drawRect(rectangle);

        //QPointF p(x,h-marge/4);
        QRectF r(x,h-marge,largeurRect,marge);
        QString text;
        text.setNum(mHisto->getValeur(i));
        painter.drawText(r,Qt::AlignCenter,text);

    }
    QString textMax,textMin;
    QRectF r2(0,0,marge,marge*2),r3(0,h-2*marge,marge,marge*2);
    textMax.setNum(max);
    textMin.setNum(min);
    painter.drawText(r2,Qt::AlignCenter,textMax);
    painter.drawText(r3,Qt::AlignCenter,textMin);
    painter.end();
}
