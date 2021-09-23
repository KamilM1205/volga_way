#include "gui/render.h"

gboolean draw1_cb(GtkWidget *widget, cairo_t *cr, gpointer data)
{
    guint width,height;
    GdkRGBA color;
    GtkStyleContext *context;
    cairo_matrix_t matrix;
    Loader::VWF *vwf = (Loader::VWF*) data;

    context=gtk_widget_get_style_context(widget);
    width=gtk_widget_get_allocated_width(widget);
    height=gtk_widget_get_allocated_height(widget);
    cairo_scale(cr, width, height);
    

    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_rectangle(cr, 0, 0, 1, 1);
    cairo_fill (cr);

    //cairo_scale(cr, width/2, height/2);
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_set_line_width(cr, 0.002);
    for(int i = 0; i < (*vwf).point_count-1; i++) {
        cairo_move_to(cr, translate((*vwf).traectory.at(i).x, -10, 10, 0, 1), 
            translate((*vwf).traectory.at(i).z, -10, 10, 0, 1));
        cairo_line_to(cr, translate((*vwf).traectory.at(i+1).x, -10, 10, 0, 1),
            translate((*vwf).traectory.at(i+1).z, -10, 10, 0, 1));
    }
    cairo_stroke(cr);
    
    for(int i = 0; i < (*vwf).point_count; i++) {
        double x = translate((*vwf).traectory.at(i).x, -10, 10, 0, 1);
        double z = translate((*vwf).traectory.at(i).z, -10, 10, 0, 1);
        cairo_arc(cr, x, z, 0.006, 0, 2 * 3.14);
        cairo_fill(cr);
    }
    
    return TRUE;
}

gboolean draw2_cb(GtkWidget *widget, cairo_t *cr, gpointer data)
{
    guint width,height;
    GdkRGBA color;
    GtkStyleContext *context;
    cairo_matrix_t matrix;
    Loader::VWF *vwf = (Loader::VWF*) data;

    context=gtk_widget_get_style_context(widget);
    width=gtk_widget_get_allocated_width(widget);
    height=gtk_widget_get_allocated_height(widget);
    cairo_scale(cr, width, height);
    

    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_rectangle(cr, 0, 0, 1, 1);
    cairo_fill (cr);

    //cairo_scale(cr, width/2, height/2);
    cairo_set_source_rgb(cr, 0, 0, 0);
    cairo_set_line_width(cr, 0.0009);
    for(int i = 0; i < (*vwf).point_count-1; i++) {
        cairo_move_to(cr, translate((*vwf).traectory.at(i).x, -10, 10, 0, 1), 
            translate((*vwf).traectory.at(i).y, -10, 10, 0, 1));
        cairo_line_to(cr, translate((*vwf).traectory.at(i+1).x, -10, 10, 0, 1),
            translate((*vwf).traectory.at(i+1).y, -10, 10, 0, 1));
    }
    cairo_stroke(cr);

    for(int i = 0; i < (*vwf).point_count; i++) {
        double x = translate((*vwf).traectory.at(i).x, -10, 10, 0, 1);
        double y = translate((*vwf).traectory.at(i).y, -10, 10, 0, 1);
        cairo_arc(cr, x, y, 0.006, 0, 2 * 3.14);
        cairo_fill(cr);
    }

    return TRUE;
}