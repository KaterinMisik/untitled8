#include "triangletodraw.h"
#include "QDebug"


QVector<QPointF> TriangleToDraw::getPoints() const
{
    return points;
}

QPointF TriangleToDraw::getPoint(int index)
{
    if(index<0) return points[0];
    else if(index>2) return points[2];
    return points[index];
}

QLineF* TriangleToDraw::getLines()
{

    lines[0] = QLineF(points[0], points[1]);
    lines[1] = QLineF(points[1],points[2]);
    lines[2] = QLineF(points[2], points[0]);
    return lines;
}

TriangleToDraw::TriangleToDraw(): points(3)
{

}





TriangleToDraw::TriangleToDraw(const QString &rectInString, char xySplitter): points(3)
{
    readFromString(rectInString,xySplitter);
}

void TriangleToDraw::setPoint(int id, const QPointF &val)
{
    points[id] = val;
}


void TriangleToDraw::readFromString(const QString &rectInString, char xySplitter)
{

    QStringList point;
    if(point.count() > 0) return;
    QStringList xy1 = point.at(0).split(xySplitter);//xy1("144","81")
    QStringList xy2 = point.at(1).split(xySplitter);
    QStringList xy3 = point.at(2).split(xySplitter);

}

QString TriangleToDraw::ToSave()
{

    QString toreturn="";
    foreach (auto point, points)

    {
        toreturn += QString::number(point.x()) + ","+
                QString::number(point.y())  + ";" ;
    }

    toreturn += "\n";
    return toreturn;
}
