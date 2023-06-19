#include <QApplication>
#include "Pong.h"

int main(int argc, char *argv[])
{
    // istanzio applicazione Qt
    QApplication app(argc, argv);
    
    // lancia il gioco
    (new Pong())->show();

    // eseguo applicazione
    return app.exec();
}
