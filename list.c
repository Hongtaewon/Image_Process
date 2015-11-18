#include <stdlib.h>

#define GLADE_FILE "greeting.glade"
#define ROOT_WIDGET "window1"

void morning ()
{
	printf("GOOD MORNING!!\n");
}

void afternoon()
{
	printf("GOOD AFTERNOON!!\n");
}

void evening()
{
	printf("GOOD EVENING!!\n");
}

int main (int argc, char* argv[])
{
	GladeXML* xml;

	gtk_init (&argc, &argv);
	if((xml = glade_xml_new (GLADE_FILE, ROOT_WIDGER, NULL)) == NULL)
	{
		g_error("Can not load the interface data.");
		exit(1);
	}

	glade_xml_signal_autoconnect (xml);
	gtk_widget_show_all (glade_xml_get_widget (xml, "window1"));
	gtk_main();

	return 0;
}
