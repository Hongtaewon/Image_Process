#include <gtk/gtk.h>
/* filesel.c */

/* 선택된 파일 이름을 취해서 그것을 콘솔로 프린트한다. */
void file_ok_sel (GtkWidget *w, GtkFileSelection *fs)
{
    g_print ("%s\n", gtk_file_selection_get_filename (GTK_FILE_SELECTION (fs)));
}

void destroy (GtkWidget *widget, gpointer data)
{
    gtk_main_quit ();
}

int main (int argc, char *argv[])
{
    GtkWidget *filew;

    gtk_init (&argc, &argv);

    /* 파일선택 widget을 하나 만든다. */
    filew = gtk_file_selection_new ("File selection");

    gtk_signal_connect (GTK_OBJECT (filew), "destroy",
                        (GtkSignalFunc) destroy, &filew);
    /* file_ok_sel 함수로 ok_button을 연결시킨다. */
    gtk_signal_connect (GTK_OBJECT (GTK_FILE_SELECTION (filew)->ok_button),
                        "clicked", (GtkSignalFunc) file_ok_sel, filew );

    /* gtk_widget_destroy 함수로 cancel_button을 연결시킨다. */
    gtk_signal_connect_object (GTK_OBJECT (GTK_FILE_SELECTION (filew)->cancel_button),
                               "clicked", (GtkSignalFunc) gtk_widget_destroy,
                               GTK_OBJECT (filew));

    /* 파일이름을 세팅한다. */
    gtk_file_selection_set_filename (GTK_FILE_SELECTION(filew),
                                     "penguin.png");

    gtk_widget_show(filew);
    gtk_main ();
    return 0;
}
