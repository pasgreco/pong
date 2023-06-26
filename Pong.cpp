#include "Pong.h"
#include <QPainter>
#include <QKeyEvent>
#include <iostream>

Pong::Pong(int cols, int rows, int scale) : QWidget(0)
{
    _cols= cols;
    _rows = rows;

    connect(&_engine, SIGNAL(timeout()), this, SLOT(advance()));
    reset();
    setFixedSize(_cols*scale, _rows*scale);
}

void Pong::reset()
{
    _engine.setInterval(100);
    _pad1 = QPoint(0, _rows/2-2);
    _pad2 = QPoint(_cols-1, _rows/2-2);
    _ball = QPoint(_cols/2, _rows/2);
   
    update();
}
void Pong::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    painter.setWindow(0, 0, _cols, _rows);

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(QColor(0, 0, 0)));
    painter.drawRect(painter.window());

    painter.setBrush(QBrush(QColor(255, 255, 255)));
    painter.drawRect(_pad1.x(), _pad1.y(), 1, 4);
    painter.drawRect(_pad2.x(), _pad2.y(), 1, 4);
    
    painter.setPen(QPen(QBrush(QColor(255, 255, 255)), 0.1));
    //painter.setBrush(Qt::NoBrush);
    painter.drawRoundedRect(_ball.x(), _ball.y(), 1, 1, 0.5, 0.5);

}

void Pong::advance()
{
    _pad1 = QPoint(0, _pad1.y()+_pad1Dir);
    _pad1Dir = 0;  
    _pad2 = QPoint(_cols-1, _pad2.y()+_pad2Dir);
    _pad2Dir = 0;


     update();       // force paintEvent() call
}
void Pong::keyPressEvent(QKeyEvent *e)
{

   std::cout << e->keyCombination() << std::endl;

        if(e->key() == Qt::Key_Up)
        _pad2Dir = -1;
    else if(e->key() == Qt::Key_Down)
        _pad2Dir = 1;
    
    else if(e->key() == Qt::Key_I)
        _pad1Dir = -1;
    else if(e->key() == Qt::Key_K)
        _pad1Dir = 1;

    else if(e->key() == Qt::Key_S)
        _engine.start();
    
}

