#include "grapher.h"
#include <QPainter>

grapher::grapher(QWidget *parent)
    : QWidget(parent)
{
    resize(500, 500);
    xmin = -10;
    xmax = 10;
    ymin = -100;
    ymax = 100;
    inc = 0.1;

    a = 1;
    b = 0;
    c = 0;
}

grapher::~grapher()
{

}

void grapher::setA(double v)
{
    a = v;
}

void grapher::setB(double v)
{
    b = v;
}

void grapher::setC(double v)
{
    c = v;
}

void grapher::setxmax(double v)
{
    xmax=v;
}

void grapher::setxmin(double v)
{
    xmin=v;
}

void grapher::setymax(double v)
{
    ymax=v;
}

void grapher::setymin(double v)
{
    ymin=v;
}
double grapher::f(double x) const
{
    return a*x*x + b*x + c;
}

void grapher::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.scale(1, -1);

    painter.setWindow(xmin, ymin, xmax-xmin, ymax-ymin);
    painter.setPen(QPen(Qt::red, 0));

    // draw axes

    painter.drawLine(QLineF(0, ymin, 0, ymax));
    painter.drawLine(QLineF(xmin, 0, xmax, 0));

    painter.setPen(QPen(Qt::blue, 0));

    for (double x = xmin; x <= xmax; x += inc)
    {
        painter.drawLine(QLineF(x, f(x), x+inc, f(x+inc)));
    }

}
