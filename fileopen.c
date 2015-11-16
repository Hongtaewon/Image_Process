#include <gtk/gtk.h>

/* Get the selected filename and print it to the console */
static void file_ok_sel( GtkWidget        *w,
                         GtkFileSelection *fs )
{
    g_print ("%s\n", gtk_file_selection_get_filename (GTK_FILE_SELECTION (fs)));
}

static void image(GtkWidget        *w,GtkFileSelection *fs )
{
	gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "Red Rock");

  image = gtk_image_new_from_file("/home/hong/EmbeddedSW/Image_Process/image.jpg");

  gtk_container_add(GTK_CONTAINER(window), image);

  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

  gtk_widget_show_all(window);
}


int main( int   argc,
          char *argv[] )
{
    GtkWidget *filew;
    
    gtk_init (&argc, &argv);
    
    /* Create a new file selection widget */
    filew = gtk_file_selection_new ("File selection");
    
    g_signal_connect (filew, "destroy",
	              G_CALLBACK (gtk_main_quit), NULL);
    /* Connect the ok_button to file_ok_sel function */
    g_signal_connect (GTK_FILE_SELECTION (filew)->ok_button,
		      "clicked", G_CALLBACK (image), (gpointer) filew);

    /* Connect the cancel_button to destroy the widget */
    g_signal_connect_swapped (GTK_FILE_SELECTION (filew)->cancel_button,
	                      "clicked", G_CALLBACK (gtk_widget_destroy),
			      filew);

    /* Lets set the filename, as if this were a save dialog, and we are giving
     a default filename */
    gtk_file_selection_set_filename (GTK_FILE_SELECTION(filew), 
				     "");

    gtk_widget_show (filew);
    gtk_main ();
    return 0;
}
