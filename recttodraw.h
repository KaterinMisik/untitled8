#ifndef RECTTODRAW_H
#define RECTTODRAW_H

#include <QObject>
#include <QRectF>

class RectToDraw : public QRectF
{
public:
    RectToDraw(const QRectF& rect, QObject *parent = nullptr);
    RectToDraw(const QString &rectInString, char pointsSplitter, char xySplitter);
    void readFromString(const QString &rectInString, char pointsSplitter, char xySplitter);


};

#endif // RECTTODRAW_H
