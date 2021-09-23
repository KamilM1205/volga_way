#include "gui/gui.h"
#include "gui/main_screen.h"

void main_window_destroy(GtkWidget* widget, gpointer data) {
    gtk_main_quit();
}

GUI::GUI(int argc, char **argv)
{
    gtk_init(&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 640, 480);
    gtk_window_set_title(GTK_WINDOW(window), "VolgaWay");

    g_signal_connect(window, "destroy", G_CALLBACK(main_window_destroy), NULL);
}

void GUI::file(Loader::VWF *f) 
{
    cur_file = f;
}

void GUI::run() {
    window = main_screen(window, cur_file);
    gtk_widget_show_all(window);
    gtk_main();
}

GUI::~GUI()
{
}