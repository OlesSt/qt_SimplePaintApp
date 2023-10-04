#include "painter.h"

Painter::Painter()
{

}

QImage Painter::getImage() const
{
    return image;
}

void Painter::setImage(const QImage &newImage)
{
    image = newImage;
    image.fill(Qt::white);
}

bool Painter::getDrawing() const
{
    return drawing;
}

void Painter::setDrawing(bool newDrawing)
{
    drawing = newDrawing;
}

QPoint Painter::getLastPoint() const
{
    return lastPoint;
}

void Painter::setLastPoint(QPoint newLastPoint)
{
    lastPoint = newLastPoint;
}

int Painter::getBrushSize() const
{
    return brushSize;
}

void Painter::setBrushSize(int newBrushSize)
{
    brushSize = newBrushSize;
}

QColor Painter::getBrushColor() const
{
    return brushColor;
}

void Painter::setBrushColor(const QColor &newBrushColor)
{
    brushColor = newBrushColor;
}
