#include <iostream>
#include "loader/loader.h"
#include "gui/gui.h"

int main(int argc, char **argv)
{
    Loader::VWF file;

    if (argc > 1)
    {
        file = Loader::load_file(argv[1]);
    }
    GUI gui = GUI(argc, argv);
    gui.file(&file);
    gui.run();
    return 0;
}