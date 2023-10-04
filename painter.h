#ifndef PAINTER_H
#define PAINTER_H

#include <QImage>
#include <QPainter>


class Painter : public QPainter
{
    Q_OBJECT
public:
    Painter();

    QImage getImage() const;
    void setImage(const QImage &newImage);

    bool getDrawing() const;
    void setDrawing(bool newDrawing);

    QPoint getLastPoint() const;
    void setLastPoint(QPoint newLastPoint);

    int getBrushSize() const;
    void setBrushSize(int newBrushSize);

    QColor getBrushColor() const;
    void setBrushColor(const QColor &newBrushColor);

private:
    QImage image;
    bool drawing;
    QPoint lastPoint;
    int brushSize;
    QColor brushColor;
};

#endif // PAINTER_H
