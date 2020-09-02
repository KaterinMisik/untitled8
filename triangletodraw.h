#ifndef TRIANGLETODRAW_H
#define TRIANGLETODRAW_H
#include <QObject>
#include <QRectF>
#include <QLineF>
class TriangleToDraw
{
private:
    QVector<QPointF> points;
    QLineF lines[3];
public:
    TriangleToDraw();
    TriangleToDraw(const QString &rectInString, char xySplitter);
    void setPoint(int id, const QPointF& val);
    void readFromString(const QString &rectInString, char xySplitter);
    QString ToSave();
    void reset();

    QVector<QPointF> getPoints() const;
    QPointF getPoint(int);
    QLineF* getLines();
    void setPoints(const QPointF);
    void setPoints1(const QPointF);
    void setPoint1(const QPointF);
    void setPoint2(const QPointF);


    QLineF newLine1;
};

#endif // TRIANGLETODRAW_H



