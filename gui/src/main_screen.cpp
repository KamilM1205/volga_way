#include "../include/gui/main_screen.h"

enum
{
    PID,
    X,
    Y,
    Z,
    SELECTED,
    NUM_COLS,
};

static GtkTreeModel* create_model() {
    GtkListStore* store = gtk_list_store_new(
        NUM_COLS,
        G_TYPE_UINT,
        G_TYPE_INT,
        G_TYPE_INT,
        G_TYPE_INT,
        G_TYPE_BOOLEAN
    );

    GtkTreeIter iter;
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter,
        PID, 1,
        X, 1,
        Y, 1,
        Z, 1,
        SELECTED, false,
        -1
    );
    return GTK_TREE_MODEL(store);
}

GtkWidget* main_screen(GtkWidget *window, Loader::VWF *vwf) 
{
    //Containers
    GtkWidget* vbox;
    GtkWidget* hbox;

    //Menu
    GtkWidget* menu_bar;
    GtkWidget* menu_file;
    GtkWidget* menu_file_file;
    GtkWidget* menu_file_open;
    GtkWidget* menu_file_quit;
    GtkWidget* menu_about;

    //Points tree
    GtkWidget* tree_view;
    GtkCellRenderer* renderer;

    //Rendering
    GtkWidget* drawing_area_top;
    GtkWidget* drawing_area_front;

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    // Menu
    menu_bar = gtk_menu_bar_new();
    menu_file = gtk_menu_new();
    menu_file_file = gtk_menu_item_new_with_label("Файл");
    menu_file_open = gtk_menu_item_new_with_label("Открыть");
    menu_file_quit = gtk_menu_item_new_with_label("Выйти");
    menu_about = gtk_menu_item_new_with_label("О программе");

    gtk_menu_item_set_submenu(GTK_MENU_ITEM(menu_file_file), menu_file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_file), menu_file_open);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_file), menu_file_quit);

    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_file_file);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), menu_about);

    g_signal_connect(G_OBJECT(menu_file_quit), "activate", G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_box_pack_start(GTK_BOX (vbox), menu_bar, false, false, 0);
    //End Menu

    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

    //Points tree
    tree_view = gtk_tree_view_new_with_model(create_model());
    renderer = gtk_cell_renderer_text_new ();
    /*gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (tree_view),
                                               -1,      
                                               "Name",  
                                               renderer,
                                               "text",
                                               "some",
                                               NULL);*/
    gtk_tree_view_insert_column_with_attributes (GTK_TREE_VIEW (tree_view),
                                               PID,      
                                               "Title",  
                                               renderer,
                                               "X", X,
                                               "Y", Y,
                                               "Z", Z,
                                               "Sel", SELECTED, 
                                               NULL);
    gtk_box_pack_start(GTK_BOX(hbox), tree_view, false, true, 0);
    //End points tree

    //Drawing area
    drawing_area_front = gtk_drawing_area_new();
    g_signal_connect(G_OBJECT(drawing_area_front), "draw", G_CALLBACK(draw1_cb), vwf);
    gtk_box_pack_start(GTK_BOX (hbox), drawing_area_front, true, true, 10);
    drawing_area_top = gtk_drawing_area_new();
    g_signal_connect(G_OBJECT(drawing_area_top), "draw", G_CALLBACK(draw2_cb), vwf);
    gtk_box_pack_start(GTK_BOX (hbox), drawing_area_top, true, true, 10);
    //End Drawing area

    gtk_box_pack_end(GTK_BOX (vbox), hbox, true, true, 0);
    gtk_container_add(GTK_CONTAINER (window), vbox);
    return window;
}