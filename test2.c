/* packbox.c */

#include <stdio.h>
#include <stdlib.h>
#include "gtk/gtk.h"

static gboolean delete_event( GtkWidget *widget,
                              GdkEvent  *event,
                              gpointer   data )
{
    gtk_main_quit ();
    return FALSE;
}

/* Button_label들로 이루어진 hbox를 만든다.  우리가 관심을 가진 변수들을
 * 위한 인자들이 이 함수로 넘겨진다.
 * 우리는 박스를 보이지 않고, 그 안에 있는 모든 것을 보일 것이다. */
static GtkWidget *make_box( gboolean homogeneous,
                            gint     spacing,
                            gboolean expand,
                            gboolean fill,
                            guint    padding )
{
  GtkWidget *box;
  GtkWidget *button;
  char padstr[80];

  /* 적당한 homogenous와 spacing을 가진 hbox를 만든다. */
  box = gtk_hbox_new (homogeneous, spacing);

  /* 적절히 세팅된 버튼들을 만든다. */
  button = gtk_button_new_with_label ("gtk_box_pack");
  gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
  gtk_widget_show (button);

  button = gtk_button_new_with_label ("(box,");
  gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
  gtk_widget_show (button);

  button = gtk_button_new_with_label ("button,");
  gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
  gtk_widget_show (button);

  /* expand의 값에 따르는 라벨을 가진 한 버튼을 만든다. */
  if (expand == TRUE)
    button = gtk_button_new_with_label ("TRUE,");
  else
    button = gtk_button_new_with_label ("FALSE,");

  gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
  gtk_widget_show (button);

  /* 위의 경우와 같은 버튼을 만들지만, 더 단축된 표현이다. */
  button = gtk_button_new_with_label (fill ? "TRUE," : "FALSE,");
  gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
  gtk_widget_show (button);

  sprintf (padstr, "%d);", padding);

  button = gtk_button_new_with_label (padstr);
  gtk_box_pack_start (GTK_BOX (box), button, expand, fill, padding);
  gtk_widget_show (button);

  return box;
}

int main( int   argc,
          char *argv[])
{
  GtkWidget *window;
  GtkWidget *button;
  GtkWidget *box1;
  GtkWidget *box2;
  GtkWidget *separator;
  GtkWidget *label;
  GtkWidget *quitbox;
  int which;

  /* 언제나 이렇게 시작하는 것을 잊지 말 것! */
  gtk_init (&argc, &argv);

  if (argc != 2) {
    fprintf (stderr, "usage: packbox num, where num is 1, 2, 3.\n");
    /* GTK를 끝내는 부분이며, exit status는 1이다. */
    gtk_exit (1);
  }

  which = atoi (argv[1]);

  /* 우리의 윈도를 만든다. */
  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);

  /* Main 윈도에 destroy 시그널을 연결시켜 줘야 한다.  이것은 제대로 된
   * 동작을 위해 매우 중요한 것이다. */
  g_signal_connect (window, "delete-event",
                      G_CALLBACK (delete_event), NULL);
  gtk_container_border_width (GTK_CONTAINER (window), 10);

  /* 우리는 수평박스들을 패킹해 넣을 수직박스(vbox)를 만든다.
   * 버튼이 들어있는 수평박스는 이 수직박스 안으로 순서대로 쌓인다.
   * (스택 구조를 생각하면 될 것이다.) */
  box1 = gtk_vbox_new (FALSE, 0);

  switch (which) {
  case 1:
        /* 새로운 라벨을 만든다. */
        label = gtk_label_new ("gtk_hbox_new (FALSE, 0);");

        /* 라벨들을 왼쪽으로 정렬시킨다.  이것에 대해서 widget의 속성
         * 세팅하기에서 다시 다룰 것이다. */
        gtk_misc_set_alignment (GTK_MISC (label), 0, 0);

        /* 라벨을 수직박스(vbox box1)에 패킹한다.  한 vbox에 패킹되는
         * widget들은 순서대로 다른 것들의 위쪽으로 패킹된다. */
        gtk_box_pack_start (GTK_BOX (box1), label, FALSE, FALSE, 0);

        /* 라벨을 보여준다. */
        gtk_widget_show (label);

        /* make_box 함수를 적절한 인자로써 호출한다. */
        box2 = make_box (FALSE, 0, FALSE, FALSE, 0);
        gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
        gtk_widget_show (box2);

        box2 = make_box (FALSE, 0, TRUE, FALSE, 0);
        gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
        gtk_widget_show (box2);

        box2 = make_box (FALSE, 0, TRUE, TRUE, 0);
        gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
        gtk_widget_show (box2);
        /* 하나의 separator를 만든다.  이들에 대해서 뒤에서 자세히
         * 다룰 것이며, 꽤나 간단한 것이다. */
        separator = gtk_hseparator_new ();

        /* separator를 vbox 안으로 패킹한다.  이들 각각의 widget은
         * vbox 안으로 패킹되므로, 수직 방향으로 쌓일 것이다. */
        gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 5);
        gtk_widget_show (separator);

        /* 또다른 라벨을 만들어 그것을 보여준다. */
        label = gtk_label_new ("gtk_hbox_new (TRUE, 0);");
        gtk_misc_set_alignment (GTK_MISC (label), 0, 0);
        gtk_box_pack_start (GTK_BOX (box1), label, FALSE, FALSE, 0);
        gtk_widget_show (label);

        /* 각 인자는 homogeneous, spacing, expand, fill, padding이다. */
        box2 = make_box (TRUE, 0, TRUE, FALSE, 0);
        gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
        gtk_widget_show (box2);

        box2 = make_box (TRUE, 0, TRUE, TRUE, 0);
        gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
        gtk_widget_show (box2);

        /* 또다른 separator */
        separator = gtk_hseparator_new ();
        /* gtk_box_pack_start 의 마지막 3가지 인자들은
         * expand, fill, padding 이다. */
        gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 5);
        gtk_widget_show (separator);

        break;

    case 2:

        /* 라벨을 새로 만든다. box1은 main()의 시작부분에서 만들어진
         * 대로 vbox이다. */
        label = gtk_label_new ("gtk_hbox_new (FALSE, 10);");
        gtk_misc_set_alignment (GTK_MISC (label), 0, 0);
        gtk_box_pack_start (GTK_BOX (box1), label, FALSE, FALSE, 0);
        gtk_widget_show (label);

        box2 = make_box (FALSE, 10, TRUE, FALSE, 0);
        gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
        gtk_widget_show (box2);

        box2 = make_box (FALSE, 10, TRUE, TRUE, 0);
        gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
        gtk_widget_show (box2);

        separator = gtk_hseparator_new ();
        gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 5);
        gtk_widget_show (separator);

        label = gtk_label_new ("gtk_hbox_new (FALSE, 0);");
        gtk_misc_set_alignment (GTK_MISC (label), 0, 0);
        gtk_box_pack_start (GTK_BOX (box1), label, FALSE, FALSE, 0);
        gtk_widget_show (label);

        box2 = make_box (FALSE, 0, TRUE, FALSE, 10);
        gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
        gtk_widget_show (box2);

        box2 = make_box (FALSE, 0, TRUE, TRUE, 10);
        gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
        gtk_widget_show (box2);

        separator = gtk_hseparator_new ();
        gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 5);
        gtk_widget_show (separator);
        break;

    case 3:
        /* 이것은 gtk_box_pack_end()를 이용하여 widget을 오른쪽 정렬하는
         * 걸 보여준다.  먼저, 앞에서처럼 새로운 박스를 하나 만든다. */
        box2 = make_box (FALSE, 0, FALSE, FALSE, 0);
        /* 라벨을 하나 만든다. */
        label = gtk_label_new ("end");
        /* 그것을 gtk_box_pack_end()로써 패킹하므로, make_box()로 만들어진
         * hbox의 오른쪽으로 놓여지게 된다.
        gtk_box_pack_end (GTK_BOX (box2), label, FALSE, FALSE, 0);
        /* 라벨을 보인다. */
        gtk_widget_show (label);

        /* box2를 box1 안으로 패킹한다. */
        gtk_box_pack_start (GTK_BOX (box1), box2, FALSE, FALSE, 0);
        gtk_widget_show (box2);

        /* bottom 쪽을 위한 separator. */
        separator = gtk_hseparator_new ();
        /* 이것은 400픽셀의 너비에 5픽셀의 높이(두께)로 separator를
         * 세팅한다. 이것은 우리가 만든 hbox가 또한 400픽셀의 너비이기
         * 때문이고, "end" 라벨은 hbox의 다른 라벨들과 구분될(separated)
         * 것이다.  그렇지 않으면, hbox 내부의 모든 widget들은 가능한만큼
         * 서로 빽빽히 붙어서 패킹될 것이다. */
        gtk_widget_set_usize (separator, 400, 5);
        /* main()함수의 시작부분에서 만들어진 vbox(box1)으로 separator를 
         * 패킹한다. */
        gtk_box_pack_start (GTK_BOX (box1), separator, FALSE, TRUE, 5);
        gtk_widget_show (separator);
    }

    /* 또다른 hbox를 만든다.. 우리가 원하는 만큼 얼마든지 만들수 있다! */
    quitbox = gtk_hbox_new (FALSE, 0);

    /* 우리의 quit 버튼이다. */
    button = gtk_button_new_with_label ("Quit");

    /* 윈도를 파괴하기 시그널을 세팅한다.  이것은 위에서 정의된 우리의 
     * 시그널 핸들러에 의해 포착될, "destroy"시그널을 윈도로 보내준다. */
    g_signal_connect_swapped (button, "clicked",
                              G_CALLBACK (gtk_main_quit),
                              window);
    /* quitbox로 버튼을 패킹한다.  gtk_box_pack_start의 마지막 세 인자는
     * expand, fill, padding이다. */
    gtk_box_pack_start (GTK_BOX (quitbox), button, TRUE, FALSE, 0);
    /* vbox(box1) 안으로 quitbox를 패킹한다. */
    gtk_box_pack_start (GTK_BOX (box1), quitbox, FALSE, FALSE, 0);

    /* 우리의 모든 widget을 포함하게 된 이 vbox를, main윈도로 패킹. */
    gtk_container_add (GTK_CONTAINER (window), box1);

    /* 그리고 남아있는 모든 것을 보여준다. */
    gtk_widget_show (button);
    gtk_widget_show (quitbox);

    gtk_widget_show (box1);
    /* 마지막에 윈도를 보여줘서 모든 것이 한번에 튀어나오며 보인다. */
    gtk_widget_show (window);

    /* 당연히 우리의 gtk_main이다. */
    gtk_main ();

    /* gtk_main_quit()을 호출했다면 제어는 이곳으로 온다.  gtk_exit()를
     * 호출하면 그렇지 않다. */

    return 0;
}
