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

//버튼 함수
static void pack_button (GtkWidget* hbox,const char* label,GCallback func)
	{
			GtkWidget* button = gtk_button_new_with_label(label);
			gtk_widget_set_size_request (button,BTN_WIDTH,BTN_HEIGHT);
			gtk_container_add (GTK_CONTAINER(hbox),button);
			gtk_signal_connect (GTK_OBJECT (func), "clicked",G_CALLBACK(func),NULL);
	}
    int main(int argc, char *argv[])
    {
		GtkWidget* window, *hbox;
		GtkWidget* button1,*button2,*button3;
		GtkWidget* *box;
		GtkWidget* image;

		//초기화 처리
		gtk_init(&argc,&argv);


		//대화상자 설정
		window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
		g_signal_connect (G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);

		//버튼 작성과 패킹
		hbox = gtk_hbox_new (TRUE,0);
		pack_button (hbox,"1",morning);
		pack_button (hbox,"2",afternoon);
		pack_button (hbox,"3",evening);

		gtk_container_add(GTK_CONTAINER(window),hbox);
		gtk_widget_show_all(window);

		//이벤트 루프
		gtk_main();

		return 0;
    }
