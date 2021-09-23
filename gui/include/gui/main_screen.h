#pragma once

#include <gtk-3.0/gtk/gtk.h>
#include "loader/loader.h"
#include "gui/render.h"

GtkWidget* main_screen(GtkWidget *window, Loader::VWF *vwf);