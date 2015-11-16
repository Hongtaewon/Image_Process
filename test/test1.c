#include <stdlib.h>
#include <gtk/gtk.h>

/* 이미지와 그것에 패킹된 라벨을 가지고 있는 hbox를 하나 만든다.
 * 그리고 그 박스를 리턴한다. */

static GtkWidget *xpm_label_box( gchar     *xpm_filename,
                                 gchar     *label_text )
{
    GtkWidget *box;
    GtkWidget *label;
    GtkWidget *image;

    /* 이미지와 라벨을 위한 박스를 만든다. */
    box = gtk_hbox_new (FALSE, 0);
    gtk_container_set_border_width (GTK_CONTAINER (box), 2);

    /* 버튼의 스타일을 취한다.. background 색깔을 취하는 것 같은데,
     * 아니라면 누군가 나에게 정정해 주길 바란다. */
    image = gtk_image_new_from_file (xpm_filename);

    /* 버튼을 위한 라벨을 만든다. */
    label = gtk_label_new (label_text);

    /* 박스 안으로 픽스맵과 라벨을 패킹해 넣는다. */
    gtk_box_pack_start (GTK_BOX (box), image, FALSE, FALSE, 3);
    gtk_box_pack_start (GTK_BOX (box), label, FALSE, FALSE, 3);

    gtk_widget_show (image);
    gtk_widget_show (label);

    return box;
}

/* 우리의 전형적인 callback 함수다. */
static void callback( GtkWidget *widget,
                      gpointer   data )
{
    g_print ("Hello again - %s was pressed\n", (char *) data);
}

int main( int   argc,
          char *argv[] )
{
    /* GtkWidget은 위젯들을 위한 기억장소 종류다. */
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *box;

    gtk_init (&argc, &argv);

    /* 윈도를 하나 만든다. */
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

    gtk_window_set_title (GTK_WINDOW (window), "Pixmap'd Buttons!");

    /* 모든 윈도들에 대해 이렇게 해주는 것이 좋을 것이다. */
    g_signal_connect (window, "destroy",
                      G_CALLBACK (gtk_main_quit), NULL);

    g_signal_connect (window, "delete-event",
                      G_CALLBACK (gtk_main_quit), NULL);

    /* 윈도의 border width를 세팅한다. */
    gtk_container_border_width (GTK_CONTAINER (window), 10);

    /* 새로운 버튼을 하나 만든다. */
    button = gtk_button_new ();

    /* "clicked" 시그널을 우리의 콜백함수와 연결한다.*/
    g_signal_connect (button, "clicked",
                      G_CALLBACK (callback), (gpointer) "cool button");

    /* 박스를 만드는 함수다. */
    box = xpm_label_box ("info.xpm", "cool button");

    /* 우리 widget들을 패킹하고, 보여준다. */
    gtk_widget_show (box);

    gtk_container_add (GTK_CONTAINER (button), box);

    gtk_widget_show (button);

    gtk_container_add (GTK_CONTAINER (window), button);

    gtk_widget_show (window);

    /* 여기서부터는 뭔가 재미있는 일이 시작될 때까지 무작정 기다린다. */
    gtk_main ();

    return 0;
}
