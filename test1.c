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

static void on_open_image (GtkButton* button, gpointer user_data)
{
	GtkWidget *image = GTK_WIDGET (user_data);
	GtkWidget *toplevel = gtk_widget_get_toplevel (image);
	GtkFileFilter *filter = gtk_file_filter_new ();
	GtkWidget *dialog = gtk_file_chooser_dialog_new (_("Open image"),
	                                                 GTK_WINDOW (toplevel),
	                                                 GTK_FILE_CHOOSER_ACTION_OPEN,
	                                                 GTK_STOCK_OK, GTK_RESPONSE_ACCEPT,
	                                                 GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
	                                                 NULL);

	gtk_file_filter_add_pixbuf_formats (filter);
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (dialog),
	                             filter);

	switch (gtk_dialog_run (GTK_DIALOG (dialog)))
	{
		case GTK_RESPONSE_ACCEPT:
		{
			gchar *filename =
				gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
			gtk_image_set_from_file (GTK_IMAGE (image), filename);
			break;
		}
		default:
			break;
	}
	gtk_widget_destroy (dialog);
}

//버튼 함수
static void pack_button (GtkWidget* hbox,const char* label,GCallback func)
	{
			GtkWidget* button = gtk_button_new_with_label(label);
			gtk_widget_set_size_request (button,BTN_WIDTH,BTN_HEIGHT);
			gtk_container_add (GTK_CONTAINER(hbox),button);
			gtk_signal_connect (GTK_OBJECT (button), "clicked",G_CALLBACK(func),NULL);
	}
    int main(int argc, char *argv[])
    {
		GtkWidget* window, *hbox;
		GtkWidget* button1,*button2,*button3,*fileopen;
		GtkWidget* *box;
		GtkWidget* image;

		//초기화 처리
		gtk_init(&argc,&argv);


		box = gtk_box_new(GTK_ORIENTATION_VERTICAL,5);
		button = gtk_button_new_with_label(_("Open Image"));
		image = gtk_image_new();
		gtk_box_pack_start (GTK_BOX (box),image,TRUE,TRUE,0);
		gtk_box_pack_start (GTK_BOX (box),button,FALSE,FASLE,0);
		//대화상자 설정
		window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
		g_signal_connect (G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);
		g_signal_connect (fileopen,"clicked",G_CALLBACK(on_open_image),image);

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
