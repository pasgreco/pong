#pragma once

#include <QWidget>

class Pong : public QWidget
{
    Q_OBJECT

    private:

    public:

        Pong();

        // @override
        virtual void paintEvent(QPaintEvent *e);
        virtual void keyPressEvent(QKeyEvent *e);

    public slots:

        void advance();

};
