#ifndef GRAPHER_H
#define GRAPHER_H

#include <QWidget>

class grapher : public QWidget
{
    Q_OBJECT

public:
    grapher(QWidget *parent = 0);
    ~grapher();

    double f(double) const; // evaluate this quadratic
                             // poly at given x value

    void paintEvent(QPaintEvent *);

    void setA(double);
    void setB(double);
    void setC(double);

    void setxmax(double v);
    void setxmin(double v);
    void setymax(double v);
    void setymin(double v);



private:
    double a, b, c; // coefficients of a quadratic poly
    double xmin, xmax, ymin, ymax; // ranges of x, y
    double inc;  // sampling interval
};

#endif // GRAPHER_H
