#include <gtk/gtk.h>
#include <glib.h>
#include <resize.h>
#include <time.h>

gchar *filename;
GtkImage *save_image;

static void saveImg(GtkButton *button, GtkImage *image)
{
	time_t timer;

	printf("save this Image\n");

	image = save_image;
	timer = time(NULL);
	sprintf(filename, "%d\n", timer);

	gtk_image_set_from_file(image, filename);
}

static void swap(GtkButton *button, GtkImage *image)
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

static void halfsize(GtkButton *button, GtkImage *image)
{
        resize(filename,"resize.jpg");
	//filename = "resize.jpg";
	//gtk_image_set_from_file(image,filename);
}

static void grayscale(GtkButton *button, GtkImage *image)
{
	gray(filename,"gray.jpg");
	//filename = "gray.jpg";
	//gtk_image_set_from_file(image,filename);
}

int main(int argc, char *argv[]) {

  GtkWidget *frame,*image;
  GtkWidget *window,*hbox,*vbox;
  GtkWidget *table;
  GtkWidget *button1,*button2,*button3, *button4;
  gint i;

  //초기화 설정
  gtk_init(&argc, &argv);

  filename = argv[1];

  //대화상자 설정
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Image Process");

  gtk_container_border_width (GTK_CONTAINER (window), 10);
  //테이블 생성
  table = gtk_table_new(2,3,FALSE);

  frame = gtk_frame_new(NULL);
  image = gtk_image_new_from_file(filename);

  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  vbox = gtk_vbox_new(FALSE,4);
  gtk_box_pack_start(GTK_BOX(vbox),image,FALSE,FALSE,0);

  button1 = gtk_button_new_with_label("Swap");
  gtk_widget_set_size_request(button1, 200, 50);
  button2 = gtk_button_new_with_label("half-resize");
  gtk_widget_set_size_request(button2, 200, 50);
  button3 = gtk_button_new_with_label("grayscale");
  gtk_widget_set_size_request(button3, 200, 50);
  button4 = gtk_button_new_with_label("save");
  gtk_widget_set_size_request(button4, 200, 50);

  g_signal_connect(G_OBJECT(button1),"clicked", G_CALLBACK(swap), GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button2),"clicked", G_CALLBACK(halfsize), GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button3),"clicked", G_CALLBACK(grayscale), GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button4),"clicked", G_CALLBACK(saveImg), GTK_IMAGE(image));

  //버튼 작성과 패킹
  gtk_table_attach_defaults(GTK_TABLE(table),button1,0,1,0,1);
  gtk_table_attach_defaults(GTK_TABLE(table),button2,0,1,1,2);
  gtk_table_attach_defaults(GTK_TABLE(table),button3,0,1,2,3);
  gtk_table_attach_defaults(GTK_TABLE(table),button4,0,1,3,4);
  gtk_table_attach_defaults(GTK_TABLE(table),vbox,1,2,0,2);

  //프레임 생성
  gtk_container_add(GTK_CONTAINER(window), table);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
