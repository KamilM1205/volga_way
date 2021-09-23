#pragma once

#include <gtk-3.0/gtk/gtk.h>
#include "loader/loader.h"

class GUI
{
private:
    GtkWidget *window;
    Loader::VWF *cur_file;
public:
    GUI(int argc, char **argv);
    void file(Loader::VWF *f);
    void run();
    ~GUI();
};
