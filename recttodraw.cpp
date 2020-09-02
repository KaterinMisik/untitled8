#include "recttodraw.h"
#include <QPushButton>

RectToDraw::RectToDraw(const QRectF& rect, QObject *parent) : QRectF(rect)
{

}

RectToDraw::RectToDraw(const QString &rectInString, char pointsSplitter, char xySplitter)
{
    readFromString(rectInString,pointsSplitter,xySplitter);
}
//"144,81:626,232"      ':'                     ','
void RectToDraw::readFromString(const QString &rectInString, char pointsSplitter, char xySplitter)
{
    QStringList point = rectInString.split(pointsSplitter);
    //point ("144,81", "626,232")
    if(point.count()!=2) return;
    QStringList xy1 = point.at(0).split(xySplitter);//xy1("144","81")
    QStringList xy2 = point.at(1).split(xySplitter);

    setTopLeft(QPointF(xy1.at(0).toFloat(), xy1.at(1).toFloat()));
    setBottomRight(QPointF(xy2.at(0).toFloat(), xy2.at(1).toFloat()));

}
