/* menu.c */

#include <gtk/gtk.h>

static gint button_press (GtkWidget *, GdkEvent *);
static void menuitem_response (GtkWidget *, gchar *);

int main (int argc, char *argv[])
{

    GtkWidget *window;
    GtkWidget *menu;
    GtkWidget *menu_bar;
    GtkWidget *root_menu;
    GtkWidget *menu_items;
    GtkWidget *vbox;
    GtkWidget *button;
    char buf[128];
    int i;

    gtk_init (&argc, &argv);

    /* 윈도를 만든다. */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_widget_set_usize( GTK_WIDGET (window), 200, 100);
    gtk_window_set_title(GTK_WINDOW (window), "GTK Menu Test");
    gtk_signal_connect(GTK_OBJECT (window), "delete_event",
                       (GtkSignalFunc) gtk_main_quit, NULL);

    /* menu-widget을 시작한다.  여기서 메뉴 widget들에 대해
     * gtk_show_widget()을 쓰면 안된다!
     * 이것은 메뉴 아이템을 가지고 있는 메뉴고, 우리가 어플에서
     * "Root Menu"를 클릭했을 때 팝업될 것이다. */
    menu = gtk_menu_new();

    /* 다음으로 우리는 세 메뉴엔트리를 만들기 위해 작은 루프를
     * 구현한다.  보통이라면, 우리는 각 메뉴 아이템들에 대해
     * "clicked" 시그널을 잡아낼 것이고, 그것을 위해 callback을
     * 세팅할 것이다.  그러나 공간을 절약하기 위해 그 과정은
     * 생략한다. */

    for(i = 0; i < 3; i++)
        {
            /* buf로 메뉴 이름을 복사한다. */
            sprintf(buf, "Test-undermenu - %d", i);

            /* 이름을 가진 새 메뉴 아이템을 만든다. */
            menu_items = gtk_menu_item_new_with_label(buf);

            /* 이것을 메뉴에 첨가한다. */
            gtk_menu_append(GTK_MENU (menu), menu_items);

            /* 메뉴 아이템이 선택되면 뭔가 쓸만한 동작을 시킨다. */
            gtk_signal_connect (GTK_OBJECT(menu_items), "activate",
                GTK_SIGNAL_FUNC(menuitem_response), (gpointer)
                g_strdup(buf));

            /* widget을 보인다. */
            gtk_widget_show(menu_items);
        }

    /* 이것은 root 메뉴며, 메뉴바에 나타날 메뉴의 이름 즉 라벨이
     * 될 것이다.  이것은 단지 눌러졌을 때 메뉴의 나머지 부분이
     * 팝업되기만 할 것이므로 특별히 시그널 핸들러가 결합되어
     * 있을 필요는 없다. */
    root_menu = gtk_menu_item_new_with_label("Root Menu");

    gtk_widget_show(root_menu);

      /* 이제 우리의 새롭게 만들어진 "menu"를, "root menu"가 되도록
       * 설정해 보자. */
      gtk_menu_item_set_submenu(GTK_MENU_ITEM (root_menu), menu);

      /* 메뉴와 버튼을 들여놓을 vbox */
      vbox = gtk_vbox_new(FALSE, 0);
      gtk_container_add(GTK_CONTAINER(window), vbox);
      gtk_widget_show(vbox);

      /* 메뉴를 담고 있을 menu-bar를 만들고 그것을 우리의 main 윈도에
       * 추가한다. */
      menu_bar = gtk_menu_bar_new();
      gtk_box_pack_start(GTK_BOX(vbox), menu_bar, FALSE, FALSE, 2);
      gtk_widget_show(menu_bar);

      /* 메뉴를 팝업시키도록 연결될 한 버튼을 만든다. */
      button = gtk_button_new_with_label("press me");
      gtk_signal_connect_object(GTK_OBJECT(button), "event",
          GTK_SIGNAL_FUNC (button_press), GTK_OBJECT(menu));
      gtk_box_pack_end(GTK_BOX(vbox), button, TRUE, TRUE, 2);
      gtk_widget_show(button);

      /* 끝으로 menu-item을 menu-bar에 이어준다.  이것이 바로
       * 내가 지금껏 지껄여 온 "root" 메뉴 아이템이다. =) */
      gtk_menu_bar_append(GTK_MENU_BAR (menu_bar), root_menu);

      /* 언제나 전체 윈도를 마지막에 보여준다. */
      gtk_widget_show(window);

      gtk_main ();

    return 0;
}

/* "widget"으로 넘겨받은 메뉴를 보임으로써 button-press에 응답한다.
 *
 * 인자 "widget"은 눌려진 버튼이 아니라 보여질 메뉴라는 걸 기억하자. */

static gint button_press (GtkWidget *widget, GdkEvent *event)
{

      if (event->type == GDK_BUTTON_PRESS) {
          GdkEventButton *bevent = (GdkEventButton *) event;
          gtk_menu_popup (GTK_MENU(widget), NULL, NULL, NULL, NULL,
                          bevent->button, bevent->time);
          /* 우리가 이 이벤트를 다루었음을 말한다.  여기서 멈춘다. */
          return TRUE;
      }

      /* 우리가 이 이벤트를 다루지 않았음을 말한다.  계속 지나친다. */
      return FALSE;
}

/* 메뉴 아이템이 선택되었을 때 문자열을 프린트한다. */

static void menuitem_response (GtkWidget *widget, gchar *string)
{
    printf("%s\n", string);
}
