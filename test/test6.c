#include <gtk/gtk.h>

/* Change this to point to your images */
#define FILE1 "/home/hong/EmbeddedSW/Image_Process/image.jpg"
#define FILE2 "/home/hong/EmbeddedSW/Image_Process/image1.jpg"

static void
cb_swap( GtkButton *button,
       GtkImage  *image )
{
   static gboolean state = TRUE;

   if( state )
      gtk_image_set_from_file( image, FILE2 );
   else
      gtk_image_set_from_file( image, FILE1 );

   state = ! state;
}

int
main( int    argc,
     char **argv )
{
   GtkWidget *window,
           *vbox,
           *image,
           *button;

   gtk_init( &argc, &argv );

   window = gtk_window_new( GTK_WINDOW_TOPLEVEL );
   g_signal_connect( G_OBJECT( window ), "destroy",
                 G_CALLBACK( gtk_main_quit ), NULL );

   vbox = gtk_vbox_new( FALSE, 6 );
   gtk_container_add( GTK_CONTAINER( window ), vbox );

   image = gtk_image_new_from_file( FILE1 );
   gtk_box_pack_start( GTK_BOX( vbox ), image, FALSE, FALSE, 0 );

   button = gtk_button_new_with_label( "Swap" );
   g_signal_connect( G_OBJECT( button ), "clicked",
                 G_CALLBACK( cb_swap ), GTK_IMAGE( image ) );
   gtk_box_pack_start( GTK_BOX( vbox ), button, FALSE, FALSE, 0 );

   gtk_widget_show_all( window );

   gtk_main();

   return( 0 );
}
