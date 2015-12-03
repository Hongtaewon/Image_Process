#include <gtk/gtk.h>
#include <glib.h>
#include <resize.h>

  gchar *filename=NULL;

static void swap(GtkButton *button,
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

static void halfsize(GtkButton *button,
		GtkImage *image)
{
        resize(filename,"resize.jpg");
	filename = "resize.jpg";
	gtk_image_set_from_file(image,filename);
}

static void grayscale(GtkButton *button,
                GtkImage *image)
{
	//blur(filename,"blur.jpg");
	gray(filename,"gray.jpg");
	filename = "gray.jpg";
	gtk_image_set_from_file(image,filename);
}

static void Blur(GtkButton *button,
                GtkImage *image)
{
        blur(filename,"blur.jpg");
        //gray(filename,"gray.jpg");
        filename = "blur.jpg";
        gtk_image_set_from_file(image,filename);
}

static void Sepia(GtkButton *button,
                GtkImage *image)
{
        sepia(filename,"sepia.jpg");
        filename = "sepia.jpg";
        gtk_image_set_from_file(image,filename);
}


int main(int argc, char *argv[]) {

  GtkWidget *image;
  GtkWidget *window,*hbox,*vbox;
  GtkWidget *table;
  GtkWidget *button1,*button2,*button3,*button4,*button5;
  gint i;

  //초기화 설정
  gtk_init(&argc, &argv);
  //파일이름 저장
  filename = argv[1];
  //대화상자 설정
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Image Process");

  gtk_container_border_width (GTK_CONTAINER (window), 10);
  //테이블 생성
  table = gtk_table_new(6,4,FALSE);

  image = gtk_image_new_from_file(filename);

  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

  button1 = gtk_button_new_with_label("Swap");
  button2 = gtk_button_new_with_label("half-resize");
  button3 = gtk_button_new_with_label("grayscale");
  button4 = gtk_button_new_with_label("blur");
  button5 = gtk_button_new_with_label("sepia");

  g_signal_connect(G_OBJECT(button1),"clicked",
		G_CALLBACK(swap),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button2),"clicked",
                G_CALLBACK(halfsize),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button3),"clicked",
		G_CALLBACK(grayscale),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button4),"clicked",
		G_CALLBACK(Blur),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button5),"clicked",
                G_CALLBACK(Sepia),GTK_IMAGE(image));

  //버튼 작성과 패킹
  gtk_table_attach_defaults(GTK_TABLE(table),button1,0,1,0,1);
  gtk_table_attach_defaults(GTK_TABLE(table),button2,0,1,1,2);
  gtk_table_attach_defaults(GTK_TABLE(table),button3,0,1,2,3);
  gtk_table_attach_defaults(GTK_TABLE(table),button4,0,1,3,4);
  gtk_table_attach_defaults(GTK_TABLE(table),button5,0,1,4,5);
  gtk_table_attach_defaults(GTK_TABLE(table),image,1,3,0,5);

  //프레임 생성
  gtk_container_add(GTK_CONTAINER(window), table);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
