#ifndef QIMAGEWIDGET_H
#define QIMAGEWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QMargins>
#include <QPoint>

#include <QMouseEvent>
#include "recttodraw.h"
#include "toolbar.h"
#include <QLineF>

#include "triangletodraw.h"



class QImageWidget : public QWidget
{
    Q_OBJECT
    ToolBar *toolBar;
    QRectF creatorRect, creatorRectangle, new_creatorRectangle;
    QList<RectToDraw> rects, circles;
    TriangleToDraw creatorTriangles;
    QLineF creatorTriangle;
    QPoint endPos;
    QPoint creatorTrial, new_creatorTriangle;

public:
    explicit QImageWidget(ToolBar *toolB, QWidget *parent = nullptr);
    ~QImageWidget();
    explicit QImageWidget(const QPoint &startingPos) :
        new_creatorRectangle(startingPos, startingPos),
        currentTriangle()
    {
        setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
        setAttribute(Qt::WA_TranslucentBackground);
        showMaximized();
    }

    void setPoints(const QPoint& p1, const QPoint& p2);
private:

    QString _noFigureMessage;
    QPixmap _originalImage;
    QString _noImageMessage;
    QString new_data;
    int _margin;
    QList<TriangleToDraw> triangles;

    QList<QPoint> pointsList;
    QList<QPointF> pointsList1;
    QMargins _margins;
    int _point;
    QPoint _points;
    QColor _backgroundColor;
    QColor _Color;
    QString _Tomany;
    QPointF previousPoint;
    TriangleToDraw currentTriangle, currentTriangle1;

    QPoint Npoint;
    QPoint Npoint1;

    QRect actualImageRect();
    void updateMargins();
    void updatePoints();
public:
    void setPixmap(QPixmap pixmap);
    QPixmap pixmap(){
        return _originalImage;
    }

    int margin(){return _margin;}
    int point(){return _point;}


    //  void UploadPointsToConfig();
    // void UploadPointsToConfig1();
signals:
    void pointChanged();
    void marginChanged();

protected:

    virtual void mouseDoubleClickEvent(QMouseEvent *event) override;

public:
    QPointF startPoint() const;
    QPointF endPoint() const;
    QLineF angleline, newLine, newLine1, newLine2, newLine3;
    QLineF angleline2;
    QRect m_currentRegion;
    void setStartPoint(const QPointF point);
    void setEndPoint(const QPointF point);
    void SaveFile(QString filepath);
    void SaveFile2(QString filepath2);
    void SaveFile3(QString filepath3);
    void SaveFile4(QString filepath4);
    void emitSlot();
public slots:

    void QParseFileData(const QStringList &data);
signals:
    void regionSelected(const QRect &);
private:
    QRect currentRegion;


protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;


private:
    void drawRectTo(const QPoint &endPoint);

    int Triangling = 0;

    bool modified = false;
    bool Rectangling = false;
    bool RectanglingforCircle = false;
    bool Circling = false;
    bool saveboxcontrol = false;
    bool uploadcontrol = false;
    int myPenWidth = 1;
    QColor myPenColor = Qt::blue;
    QImage image;
    QPoint lastPoint, PPoint;
    void drawRect(const QPoint &endPoint);
    void drawRectangle(const QPoint &endPoint);
    void drawEllipse(const QPoint &creatorRect);
    void drawTriangle(const QPoint &endPoint);
    void drawLine(const QPoint &endPoint);

    void drawLines(const QVector<QLineF> &);
    void drawTriangl(QLineF, QLineF, QLineF);

    void setTopRight(const QPointF lastPoint);
    void setTopLeft(const QPointF endPoint);
    void setTopLeft0(const QPointF endPoint);
    void setTopLeft1(const QPointF endPoint);
    void setPoint (const QPointF );
    void setTopRight1(const QPointF lastPoint);
    void setPoints(const QPointF);
    void setPoints1(const QPointF);
    void setPoints2(const QPointF);
    void setLine(const QLineF);
private slots:



};


#endif // QIMAGEWIDGET_H
