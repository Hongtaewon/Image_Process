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
        gchar* save = "images/bright.jpg";
        bright(filename,save);
        filename = save;
        gtk_image_set_from_file(image,filename);
}

static void cw90(GtkButton *button,
                GtkImage *image)
{
        gchar* save = "images/cw90.jpg";
        rotatecw(filename,save);
        filename = save;
        gtk_image_set_from_file(image,filename);
}

static void ccw90(GtkButton *button,
                GtkImage *image)
{
        gchar* save = "images/ccw90.jpg";
        rotateccw(filename,save);
        filename = save;
        gtk_image_set_from_file(image,filename);
}

static void Flip(GtkButton *button,
                GtkImage *image)
{
        gchar* save = "images/x-mirror.jpg";
        flip(filename,save);
        filename = save;
        gtk_image_set_from_file(image,filename);
}

static void Flop(GtkButton *button,
                GtkImage *image)
{
        gchar* save = "images/y-mirror.jpg";
        flop(filename,save);
        filename = save;
        gtk_image_set_from_file(image,filename);
}


static void negative(GtkButton *button,
                GtkImage *image)
{
        gchar* save = "images/negative.jpg";
        negate(filename,save);
        filename = save;
        gtk_image_set_from_file(image,filename);
}

static void Sharp(GtkButton *button,
                GtkImage *image)
{
        gchar* save = "images/sharpe.jpg";
        sharp(filename,save);
        filename = save;
        gtk_image_set_from_file(image,filename);
}

static void Poster(GtkButton *button,
                GtkImage *image)
{
        gchar* save = "images/Poster.jpg";
        poster(filename,save);
        filename = save;
        gtk_image_set_from_file(image,filename);
}

static void Sketch(GtkButton *button,
                GtkImage *image)
{
        gchar* save = "images/sketch.jpg";
        sketch(filename,save);
        filename = save;
        gtk_image_set_from_file(image,filename);
}

static void Save(GtkButton *button,
                GtkImage *image)
{
        gchar* save = "save-Image/save.jpg";
        saveImage(filename,save);
}

int main(int argc, char *argv[]) {

  GtkWidget *image;
  GtkWidget *window;
  GtkWidget *table,hbox;
  GtkWidget *button1,*button2,*button3,*button4,*button5,*button6,*button7,*button8,*button9,*button10;
  GtkWidget *button11,*button12,*button13,*button14,*button15;

  //초기화 설정
  gtk_init(&argc, &argv);
  //파일이름 저장
  filename = argv[1];
  infilename = argv[1];
  //대화상자 설정
  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "Image Process");

  //테이블 생성
  table = gtk_table_new(7,7,TRUE);
  //이미지 생성
  image = gtk_image_new_from_file(filename);
  //종료 신호
  g_signal_connect(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);
  //버튼 작성
  button1 = gtk_button_new_with_label("original");
  button2 = gtk_button_new_with_label("half-resize");
  button3 = gtk_button_new_with_label("grayscale");
  button4 = gtk_button_new_with_label("blur");
  button5 = gtk_button_new_with_label("sepia");
  button6 = gtk_button_new_with_label("bright");
  button7 = gtk_button_new_with_label("save Image");
  button8 = gtk_button_new_with_label("rotate ccw90");
  button9 = gtk_button_new_with_label("rotate cw90");
  button10 = gtk_button_new_with_label("negative");
  button11 = gtk_button_new_with_label("sharp");
  button12 = gtk_button_new_with_label("poster");
  button13 = gtk_button_new_with_label("sketch");
  button14 = gtk_button_new_with_label("x-axis mirror");
  button15 = gtk_button_new_with_label("y-axis mirror");

  //버튼 이벤트 연결
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
  g_signal_connect(G_OBJECT(button7),"clicked",
                G_CALLBACK(Save),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button8),"clicked",
                G_CALLBACK(ccw90),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button9),"clicked",
                G_CALLBACK(cw90),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button10),"clicked",
                G_CALLBACK(negative),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button11),"clicked",
                G_CALLBACK(Sharp),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button12),"clicked",
                G_CALLBACK(Poster),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button13),"clicked",
                G_CALLBACK(Sketch),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button14),"clicked",
                G_CALLBACK(Flip),GTK_IMAGE(image));
  g_signal_connect(G_OBJECT(button15),"clicked",
                G_CALLBACK(Flop),GTK_IMAGE(image));
  gtk_widget_set_size_request(image,600,500);
  //테이블에 위젯 추가
  gtk_table_attach_defaults(GTK_TABLE(table),button1,0,1,0,1);
  gtk_table_attach_defaults(GTK_TABLE(table),button2,0,1,1,2);
  gtk_table_attach_defaults(GTK_TABLE(table),button3,0,1,2,3);
  gtk_table_attach_defaults(GTK_TABLE(table),button4,0,1,3,4);
  gtk_table_attach_defaults(GTK_TABLE(table),button5,0,1,4,5);
  gtk_table_attach_defaults(GTK_TABLE(table),button6,0,1,5,6);
  gtk_table_attach_defaults(GTK_TABLE(table),button7,0,1,6,7);
  gtk_table_attach_defaults(GTK_TABLE(table),button8,2,3,6,7);
  gtk_table_attach_defaults(GTK_TABLE(table),button9,3,4,6,7);
  gtk_table_attach_defaults(GTK_TABLE(table),button10,6,7,0,1);
  gtk_table_attach_defaults(GTK_TABLE(table),button11,6,7,1,2);
  gtk_table_attach_defaults(GTK_TABLE(table),button12,6,7,2,3);
  gtk_table_attach_defaults(GTK_TABLE(table),button13,6,7,3,4);
  gtk_table_attach_defaults(GTK_TABLE(table),button14,4,5,6,7);
  gtk_table_attach_defaults(GTK_TABLE(table),button15,5,6,6,7);
  gtk_table_attach_defaults(GTK_TABLE(table),image,1,6,0,6);

  //윈도우에 테이블 추가
  gtk_container_add(GTK_CONTAINER(window), table);

  gtk_widget_show_all(window);

  gtk_main();

  return 0;
}
