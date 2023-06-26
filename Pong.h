#pragma once

#include <QWidget>
#include <QTimer>
#include <list>

class Pong : public QWidget
{
    Q_OBJECT

    private:

        QTimer _engine;
        int _cols, _rows;
        QPoint _ball;
        QPoint _pad1;
        QPoint _pad2;
        int _pad1Dir = 0;
        int _pad2Dir = 0;
        void reset();

    public:

        Pong(int cols=60, int rows=40, int scale=20);

        // @override
        virtual void paintEvent(QPaintEvent *e);
        virtual void keyPressEvent(QKeyEvent *e);

    public slots:

        void advance();

};
