#include "sources/GraphicalUserInterface/Window/Window.hpp"
#include "sources/Core/Core.hpp"

int main(int argc, char *argv[])
{
    QApplication *app = new QApplication(argc, argv);
    Core client(argc, argv);
    client.StartWindow();
    return app->exec();
}