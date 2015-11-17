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
                        gtk_widget_set_size_request (button,BTN_WIDTH,BTN_HEIGHT);
                        gtk_container_add (GTK_CONTAINER(hbox),button);
                        gtk_signal_connect (GTK_OBJECT (button), "clicked",G_CALLBACK(func),NULL);
        }


int main(int argc, char *argv[]) {

  GtkWidget *window,*window1,*hbox;
  GtkWidget *image,*frame;
  GtkWidget *button1,*button2,*button3;
  GtkWidget *table;

  //초기화 설정
  gtk_init(&argc, &argv);

  //대화상자 설정
  window1 = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window1), "Red Rock");
  //테이블 생성
  table = gtk_table_new(2,3,TRUE);


  image = gtk_image_new_from_file("image.jpg");


  g_signal_connect(G_OBJECT(window1), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

  //버튼 작성과 패킹
                hbox = gtk_hbox_new (TRUE,0);
                pack_button (hbox,"1",morning);
                pack_button (hbox,"2",afternoon);
                pack_button (hbox,"3",evening);

  gtk_table_attach_defaults(GTK_TABLE(table),image,0,2,0,3);
  gtk_table_attach_defaults(GTK_TABLE(table),hbox,2,3,0,1);

  //프레임 생성
  //gtk_container_add(GTK_CONTAINER(hbox),image);
  gtk_container_add(GTK_CONTAINER(window1), table);


  gtk_widget_show_all(window1);

  gtk_main();

  return 0;
}
