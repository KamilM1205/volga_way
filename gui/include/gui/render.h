#pragma once

#include <gtk-3.0/gtk/gtk.h>
#include "loader/loader.h"
#include "gui/utils.h"

gboolean draw1_cb(GtkWidget *widget, cairo_t *cr, gpointer data);
gboolean draw2_cb(GtkWidget *widget, cairo_t *cr, gpointer data);