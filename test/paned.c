#include <gtk/gtk.h>
   
/* "messages"의 리스트를 만든다 */
GtkWidget *
create_list (void)
{

    GtkWidget *scrolled_window;
    GtkWidget *list;
    GtkWidget *list_item;
   
    int i;
    char buffer[16];
   
    /* 스크롤바(필요할 때만)가 딸린 스크롤된 윈도를 만든다. */
    scrolled_window = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolled_window),
                                    GTK_POLICY_AUTOMATIC, 
                                    GTK_POLICY_AUTOMATIC);
   
    /* 새로운 리스트를 만들어 이를 스크롤된 윈도에 집어넣는다. */
    list = gtk_list_new ();
    gtk_container_add (GTK_CONTAINER(scrolled_window), list);
    gtk_widget_show (list);
   
    /* 윈도에 메시지 몇개를 더한다 */
    for (i=0; i<10; i++) {

        sprintf(buffer,"Message #%d",i);
        list_item = gtk_list_item_new_with_label (buffer);
        gtk_container_add (GTK_CONTAINER(list), list_item);
        gtk_widget_show (list_item);

    }
   
    return scrolled_window;
}
   
/* 텍스트 몇개를 텍스트 widget에 더한다. - 아래 함수는 우리의 윈도가 realize 될
때 불리는 callback이다. gtk_widget_realize로 realize되도록 강제할 수도 있지만
그건 먼저 계층구조의 한 부분이 되어야 할 것이다.
*/
void
realize_text (GtkWidget *text, gpointer data)
{
    gtk_text_freeze (GTK_TEXT (text));
    gtk_text_insert (GTK_TEXT (text), NULL, &text->style->black, NULL,
    "From: pathfinder@nasa.gov\n"
    "To: mom@nasa.gov\n"
    "Subject: Made it!\n"
    "\n"
    "We just got in this morning. The weather has been\n"
    "great - clear but cold, and there are lots of fun sights.\n"
    "Sojourner says hi. See you soon.\n"
    " -Path\n", -1);
   
    gtk_text_thaw (GTK_TEXT (text));
}
   
/* "message"를 보여주는 스크롤된 텍스트 영역을 만든다. */
GtkWidget *
create_text (void)
{
    GtkWidget *table;
    GtkWidget *text;
    GtkWidget *hscrollbar;
    GtkWidget *vscrollbar;
   
    /* 텍스트 위젯과 스크롤바를 갖는 테이블을 만든다 */
    table = gtk_table_new (2, 2, FALSE);
   
    /* 텍스트 위젯을 왼쪽 위에 놓는다. Y 축 방향으로 GTK_SHRINK가 쓰인 것을
     * 주목할 것. */
    text = gtk_text_new (NULL, NULL);
    gtk_table_attach (GTK_TABLE (table), text, 0, 1, 0, 1,
                      GTK_FILL | GTK_EXPAND,
                      GTK_FILL | GTK_EXPAND | GTK_SHRINK, 0, 0);
    gtk_widget_show (text);
   
    /* HScrollbar를 왼쪽 아래에 놓는다. */
    hscrollbar = gtk_hscrollbar_new (GTK_TEXT (text)->hadj);
    gtk_table_attach (GTK_TABLE (table), hscrollbar, 0, 1, 1, 2,
                      GTK_EXPAND | GTK_FILL, GTK_FILL, 0, 0);
    gtk_widget_show (hscrollbar);
   
    /* VScrollbar를 오른쪽 위에 놓는다. */
    vscrollbar = gtk_vscrollbar_new (GTK_TEXT (text)->vadj);
    gtk_table_attach (GTK_TABLE (table), vscrollbar, 1, 2, 0, 1,
                      GTK_FILL, GTK_EXPAND | GTK_FILL | GTK_SHRINK, 0, 0);
    gtk_widget_show (vscrollbar);
   
    /* 텍스트 widget이 realize되었을 때 그 widget이 갖고 있는 메시지를
     * 출력하여주는 시그널 핸들러를 더한다. */
    gtk_signal_connect (GTK_OBJECT (text), "realize",
                        GTK_SIGNAL_FUNC (realize_text), NULL);
   
    return table;
}
   
int
main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *vpaned;
    GtkWidget *list;
    GtkWidget *text;

    gtk_init (&argc, &argv);
   
    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW (window), "Paned Windows");
    gtk_signal_connect (GTK_OBJECT (window), "destroy",
                        GTK_SIGNAL_FUNC (gtk_main_quit), NULL);
    gtk_container_border_width (GTK_CONTAINER (window), 10);
   
    /* vpaned widget을 만들어서 toplevel 윈도에 더한다. */
   
    vpaned = gtk_vpaned_new ();
    gtk_container_add (GTK_CONTAINER(window), vpaned);
    gtk_widget_show (vpaned);
   
    /* 이제 윈도 두 부분의 내용을 만든다. */
   
    list = create_list ();
    gtk_paned_add1 (GTK_PANED(vpaned), list);
    gtk_widget_show (list);
   
    text = create_text ();
    gtk_paned_add2 (GTK_PANED(vpaned), text);
    gtk_widget_show (text);
    gtk_widget_show (window);
    gtk_main ();
    return 0;
}
