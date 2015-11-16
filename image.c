#include <gtk/gtk.h>
#define BTN_WIDTH 200
#define BTN_HEIGHT 50

static void morning()
{
        printf ("Good morning\n");
}

static void afternoon()
{
        printf ("Good afternoon\n");
}

static void evening()
{
        printf ("Good evening\n");
}

static void pack_button (GtkWidget* hbox,const char* label,GCallback func)
        {
                        GtkWidget* button = gtk_button_new_with_label(label);
                        gtk_widget_set_size_request (button,BTN_WIDTH,BTN_HEIGH$
                        gtk_container_add (GTK_CONTAINER(hbox),button);
                        gtk_signal_connect (GTK_OBJECT (button), "clicked",G_CA$
        }

int main(int argc, char *argv[]) {

  GtkWidget *window,*hbox,*box;
  GtkWidget *image;
  GtkWidget *buttion1,*button2,*button3;
  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  box = gtk_box_new(GTK_ORIENTATION_VERTICAL,5);

  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title(GTK_WINDOW(window), "Red Rock");

  image = gtk_image_new_from_file("/home/hong/EmbeddedSW/Image_Process/image.jpg");


  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

	//버튼 작성과 패킹
        hbox = gtk_hbox_new (TRUE,0);
        pack_button (hbox,"1",morning);
        pack_button (hbox,"2",afternoon);
        pack_button (hbox,"3",evening);

  gtk_container_add(GTK_CONTAINER(window), image);
  gtk_container_add(GTK_CONTAINER(window), hbox);
  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
