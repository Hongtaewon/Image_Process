#include        <gtk/gtk.h>
#include        <stdio.h>

/* 이것은 리스트 아이템에 데이터를 저장하기 위한 데이터 식별자다. */
const   gchar   *list_item_data_key="list_item_data";

/* 우리가 GtkList widget에 연결시킬 시그널 핸들러들의 함수원형. */
static  void    sigh_print_selection    (GtkWidget      *gtklist,
                                         gpointer       func_data);
static  void    sigh_button_event       (GtkWidget      *gtklist,
                                         GdkEventButton *event,
                                         GtkWidget      *frame);

/* 사용자 인터페이스를 세팅하는 main 함수 */

gint main (int argc, gchar *argv[])
{
                GtkWidget       *separator;
                GtkWidget       *window;
                GtkWidget       *vbox;
                GtkWidget       *scrolled_window;
                GtkWidget       *frame;
                GtkWidget       *gtklist;
                GtkWidget       *button;
                GtkWidget       *list_item;
                GList           *dlist;
                guint           i;
                gchar           buffer[64];

                /* gtk+(그리고 결과적으로 gdk도)를 초기화한다. */

                gtk_init(&argc, &argv);

                /* 모든 widget을 넣어둘 윈도를 만든다.
                 * 윈도 매니저의 close-window-event를 다루기 위해 gtk_main_quit()
                 * 함수를 윈도의 "destroy" 이벤트에 연결시킨다. */
                window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
                gtk_window_set_title(GTK_WINDOW(window), "GtkList Example");
                gtk_signal_connect(GTK_OBJECT(window),
                                                                                         "destroy",
                                                                                         GTK_SIGNAL_FUNC(gtk_main_quit),
                                                                                         NULL);

                /* 윈도 내부에 widget들을 수직으로 정렬할 박스가 있어야 한다. */
                vbox=gtk_vbox_new(FALSE, 5);
                gtk_container_border_width(GTK_CONTAINER(vbox), 5);
                gtk_container_add(GTK_CONTAINER(window), vbox);
                gtk_widget_show(vbox);
                /* GtkList widget을 넣어두고자 하는 스크롤된 윈도다. */
                scrolled_window=gtk_scrolled_window_new(NULL, NULL);
                gtk_widget_set_usize(scrolled_window, 250, 150);
                gtk_container_add(GTK_CONTAINER(vbox), scrolled_window);
                gtk_widget_show(scrolled_window);

                /* GtkList widget을 만든다.  selection이 변할 때마다 그 선택된
                 * 아이템을 프린트해 보여주기 위해 sigh_print_selection()
                 * 시그널 핸들러 함수를 GtkList의 "selection_changed" 시그널에
                 * 연결시켜 둔다. */
                gtklist=gtk_list_new();
                gtk_container_add(GTK_CONTAINER(scrolled_window), gtklist);
                gtk_widget_show(gtklist);
                gtk_signal_connect(GTK_OBJECT(gtklist),
                                                                                         "selection_changed",
                                                                                         GTK_SIGNAL_FUNC(sigh_print_selection),
                                                                                         NULL);

                /* 리스트 아이템을 가두어 둘 "Prison"을 만든다. ;) */
                frame=gtk_frame_new("Prison");
                gtk_widget_set_usize(frame, 200, 50);
                gtk_container_border_width(GTK_CONTAINER(frame), 5);
                gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_OUT);
                gtk_container_add(GTK_CONTAINER(vbox), frame);
                gtk_widget_show(frame);

                /* 리스트 아이템의 "arresting"을 다룰 GtkList에 sigh_button_event()
                 * 시그널 핸들러를 연결시킨다. */
                gtk_signal_connect(GTK_OBJECT(gtklist),
                                                                                         "button_release_event",
                                                                                         GTK_SIGNAL_FUNC(sigh_button_event),
                                                                                         frame);

                /* Separator를 만든다. */
                separator=gtk_hseparator_new();
                gtk_container_add(GTK_CONTAINER(vbox), separator);
                gtk_widget_show(separator);

                /* 끝으로 버튼을 만들고 그것의 "clicked" 시그널을 윈도의 파괴에
                 * 연결시킨다. */
                button=gtk_button_new_with_label("Close");
                gtk_container_add(GTK_CONTAINER(vbox), button);
                gtk_widget_show(button);
                gtk_signal_connect_object(GTK_OBJECT(button),
                                  "clicked",
                                  GTK_SIGNAL_FUNC(gtk_widget_destroy),
                                  GTK_OBJECT(window));

                /* 이제 각각 라벨을 가지고 있는 5개의 리스트 아이템을 만들고,
                 * gtk_container_add()로써 그들을 GtkList에 첨가한다.
                 * 또한 라벨의 텍스트 문자열을 조사하고 그것을 각 리스트 아이템의
                 * list_item_data_key에 결합시킨다. */
                for (i=0; i<5; i++) {
                                GtkWidget       *label;
                                gchar           *string;

                                sprintf(buffer, "ListItemContainer with Label #%d", i);
                                label=gtk_label_new(buffer);
                                list_item=gtk_list_item_new();
                                gtk_container_add(GTK_CONTAINER(list_item), label);
                                gtk_widget_show(label);
                                gtk_container_add(GTK_CONTAINER(gtklist), list_item);
                                gtk_widget_show(list_item);
                                gtk_label_get(GTK_LABEL(label), &string);
                                gtk_object_set_data(GTK_OBJECT(list_item),
                                    list_item_data_key,
                                    string);
                }
                /* 여기서는, gtk_list_item_new_with_label()을 이용해서
                 * 다른 5개의 라벨을 만든다.
                 * 이번에는 라벨들에 대한 포인터가 없으므로 라벨의 텍스트
                 * 문자열을 조사할 수 없고, 그러므로 각 리스트 아이템의
                 * list_item_data_key를 똑같은 텍스트 문자열에 결합한다.
                 * 리스트 아이템을 추가하기 위해서 우리는 그들을 이중 연결
                 * 리스트(GList)에 밀어넣고, gtk_list_append_items()를 
                 * 호출해준다.  우리가 아이템들을 이중 연결 리스트에 밀어넣기
                 * 위해 g_list_prepend()를 사용하기 때문에, 그들의 순서는
                 * 뒤로 이어지는(descending) 것이 된다.  반대로 g_list_append()
                 * 를 이용했다면 앞에서 붙여지는(ascending)이 될 것이다. */
                dlist=NULL;
                for (; i<10; i++) {
                                sprintf(buffer, "List Item with Label %d", i);
                                list_item=gtk_list_item_new_with_label(buffer);
                                dlist=g_list_prepend(dlist, list_item);
                                gtk_widget_show(list_item);
                                gtk_object_set_data(GTK_OBJECT(list_item),
                                    list_item_data_key,
                                    "ListItem with integrated Label");
                }
                gtk_list_append_items(GTK_LIST(gtklist), dlist);

                /* 끝으로 우리는 윈도를 보고 싶어 한다, 아닌가? ;) */
                gtk_widget_show(window);

                /* GTK의 main 이벤트 루프를 시동한다. */
                gtk_main();

                /* gtk_main_quit()이 호출되면 제어는 여기로 온다. */
                return 0;
}

/* GtkList의 버튼 press/release 이벤트들과 연결된 시그널
 * 핸들러 함수들이다. */
void
sigh_button_event       (GtkWidget      *gtklist,
                         GdkEventButton *event,
                         GtkWidget      *frame)
{
                /* 세번째, 즉 가장 오른쪽에 있는 마우스 버튼이 놓여졌을 때만
                 * 어떤 일을 하도록 한다. */
                if (event->type==GDK_BUTTON_RELEASE &&
                                event->button==3) {
                                GList           *dlist, *free_list;
                                GtkWidget       *new_prisoner;

                                /* 현재 선택된 아이템을 가져와서 우리의 다음 prisoner로
                                 * 한다. */
                                dlist=GTK_LIST(gtklist)->selection;
                                if (dlist)
                                                                new_prisoner=GTK_WIDGET(dlist->data);
                                else
                                                                new_prisoner=NULL;

                                /* 이미 사로잡은 리스트 아이템을 조사하고, 그들을
                                 * 다시 리스트로 돌려준다.
                                 * gtk_container_children()이 리턴하는 이중 연결 리스트를
                                 * 꼭 해제(free)해줘야 함을 기억하라. */
                                dlist=gtk_container_children(GTK_CONTAINER(frame));
                                free_list=dlist;
                                while (dlist) {
                                                GtkWidget       *list_item;

                                                list_item=dlist->data;

                                                gtk_widget_reparent(list_item, gtklist);

                                                dlist=dlist->next;
                                }
                                g_list_free(free_list);

                                /* 새로 prisoner를 가지게 되면, GtkList로부터 그것을
                                 * 제거하고 "Prison" 프레임으로 밀어넣는다.
                                 * 아이템은 먼저 unselect되어야 한다. */
                                if (new_prisoner) {
                                                GList   static_dlist;

                                                static_dlist.data=new_prisoner;
                                                static_dlist.next=NULL;
                                                static_dlist.prev=NULL;

                                                gtk_list_unselect_child(GTK_LIST(gtklist),
                                                new_prisoner);
                                                gtk_widget_reparent(new_prisoner, frame);
                                }
                }
}

/* 이것은 GtkList가 "selection_changed" 시그널을 발생시키면
 * 호출되는 시그널 핸들러다. */
void
sigh_print_selection    (GtkWidget      *gtklist,
                                         gpointer       func_data)
{
                GList   *dlist;

                /* GtkList의 선택된 아이템의 이중 연결 리스트를 가져온다.
                 * 이것을 read-only로 다뤄야 함을 잊지 말자! */
                dlist=GTK_LIST(gtklist)->selection;

                /* 선택된 아이템이 없을 때는 아무 작업도 할 게 없고 그걸
                 * 사용자에게 알려준다. */
                if (!dlist) {
                                g_print("Selection cleared\n");
                                return;
                }
                /* 뭔가를 선택했고 그것을 프린트한다. */
                g_print("The selection is a ");

                /* 이중 연결 리스트에서 리스트 아이템을 취하고
                 * list_item_data_key와 관련된 데이터를 조사한다.
                 * 그리고 나서 그걸 프린트한다. */
                while (dlist) {
                                GtkObject       *list_item;
                                gchar           *item_data_string;

                                list_item=GTK_OBJECT(dlist->data);
                                item_data_string=gtk_object_get_data(list_item,
                                                                                                         list_item_data_key);
                                g_print("%s ", item_data_string);

                                dlist=dlist->next;
                }
                g_print("\n");
}
