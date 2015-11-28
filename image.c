#include <gtk/gtk.h>
#include <glib.h>
#define BTN_WIDTH 200
#define BTN_HEIGHT 50

  gchar *filename = "image.jpg";
  GtkWidget *frame,*image;
  GtkWidget *window,*hbox,*vbox;
  GtkWidget *table;
  GtkWidget *button1,*button2,*button3;

static void morning(GtkButton *button,
		GtkImage *image)
{
	static gboolean state = TRUE;
        printf ("Good morning\n");

	if( state )
	{
		filename = "image1.jpg";
		gtk_image_set_from_file( image, filename );
	}
	else
	{
		filename = "image.jpg";
		gtk_image_set_from_file( image, filename );
	}
	state = !state;
}

static void afternoon()
{
        printf ("Good afternoon\n");
}

static void evening()
{
        printf ("Good evening\n");
}



int main(int argc, char *argv[]) {

  GtkWidget *frame,*image;
  GtkWidget *window,*hbox,*vbox;
  GtkWidget *table;
  GtkWidget *button1,*button2,*button3;


  //초기화 설정
  gtk_init(&argc, &argv);

  //대화상자 설정
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Image Process");
  //테이블 생성
  table = gtk_table_new(2,3,TRUE);

  image = gtk_image_new_from_file(filename);

  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);
  vbox = gtk_vbox_new(FALSE,6);
  gtk_box_pack_start(GTK_BOX(vbox),image,FALSE,FALSE,0);

  button1 = gtk_button_new_with_label("Swap");
  g_signal_connect(G_OBJECT(button1),"clicked",
		G_CALLBACK(morning),GTK_IMAGE(image) );

  //버튼 작성과 패킹
  gtk_table_attach_defaults(GTK_TABLE(table),vbox,0,2,0,3);
  gtk_table_attach_defaults(GTK_TABLE(table),button1,2,3,0,1);

  //프레임 생성
  gtk_container_add(GTK_CONTAINER(window), table);


  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
