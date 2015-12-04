#include <gtk/gtk.h>
#include <glib.h>

  gchar *filename=NULL;
  gchar *infilename;

static void original(GtkButton *button,
		GtkImage *image)
{
	filename = infilename;
	gtk_image_set_from_file( image, filename );
}

static void halfsize(GtkButton *button,
		GtkImage *image)
{
	gchar* save = "images/halfsize.jpg";
        resize(filename,save);
	filename = save;
	gtk_image_set_from_file(image,filename);
}

static void grayscale(GtkButton *button,
                GtkImage *image)
{
	gchar* save = "images/gray.jpg";
	gray(filename,save);
	filename = save;
	gtk_image_set_from_file(image,filename);
}

static void Blur(GtkButton *button,
                GtkImage *image)
{
	gchar* save = "images/blur.jpg";
        blur(filename,save);
        filename = save;
        gtk_image_set_from_file(image,filename);
}

static void Sepia(GtkButton *button,
                GtkImage *image)
{
	gchar* save = "images/sepia.jpg";
        sepia(filename,save);
        filename = save;
        gtk_image_set_from_file(image,filename);
}

static void Gamma(GtkButton *button,
                GtkImage *image)
{
        gchar* save = "images/gamma3.jpg";
        bright(filename,save);
        filename = save;
        gtk_image_set_from_file(image,filename);
}

static void Save(GtkButton *button,
                GtkImage *image)
{
        gchar* save = "save-Image/save.jpg";
        saveImage(filename,save);
        //filename = save;
        //gtk_image_set_from_file(image,filename);
}



int main(int argc, char *argv[]) {

  GtkWidget *image;
  GtkWidget *window;
  GtkWidget *table;
  GtkWidget *button1,*button2,*button3,*button4,*button5,*button6,*button7,*button8,*button9;

  //초기화 설정
  gtk_init(&argc, &argv);
  //파일이름 저장
  filename = argv[1];
  infilename = argv[1];
  //대화상자 설정
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Image Process");

  gtk_container_border_width (GTK_CONTAINER (window), 10);
  //테이블 생성
  table = gtk_table_new(7,7,TRUE);

  image = gtk_image_new_from_file(filename);

  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

  button1 = gtk_button_new_with_label("original");
  button2 = gtk_button_new_with_label("half-resize");
  button3 = gtk_button_new_with_label("grayscale");
  button4 = gtk_button_new_with_label("blur");
  button5 = gtk_button_new_with_label("sepia");
  button6 = gtk_button_new_with_label("bright");
  button7 = gtk_button_new_with_label("save Image");
  button8 = gtk_button_new_with_label("unknown");
  button9 = gtk_button_new_with_label("unknown");

  g_signal_connect(G_OBJECT(button1),"clicked",
		G_CALLBACK(original),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button2),"clicked",
                G_CALLBACK(halfsize),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button3),"clicked",
		G_CALLBACK(grayscale),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button4),"clicked",
		G_CALLBACK(Blur),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button5),"clicked",
                G_CALLBACK(Sepia),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button6),"clicked",
                G_CALLBACK(Gamma),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button6),"clicked",
                G_CALLBACK(Save),GTK_IMAGE(image));

  //버튼 작성과 패킹
  gtk_table_attach_defaults(GTK_TABLE(table),button1,0,1,0,1);
  gtk_table_attach_defaults(GTK_TABLE(table),button2,0,1,1,2);
  gtk_table_attach_defaults(GTK_TABLE(table),button3,0,1,2,3);
  gtk_table_attach_defaults(GTK_TABLE(table),button4,0,1,3,4);
  gtk_table_attach_defaults(GTK_TABLE(table),button5,0,1,4,5);
  gtk_table_attach_defaults(GTK_TABLE(table),button6,0,1,5,6);
  gtk_table_attach_defaults(GTK_TABLE(table),button7,0,1,6,7);
  gtk_table_attach_defaults(GTK_TABLE(table),button8,6,7,0,1);
  gtk_table_attach_defaults(GTK_TABLE(table),button9,6,7,1,2);
  gtk_table_attach_defaults(GTK_TABLE(table),image,1,6,0,6);

  //프레임 생성
  gtk_container_add(GTK_CONTAINER(window), table);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
