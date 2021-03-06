#include<gtk/gtk.h>
static void button_clicked(GtkWidget *widget ,gpointer data){
	g_print("Button is pressed\n");
}

int main(int argc,char * argv[])
{
	gtk_init(&argc,&argv);
	GtkWidget * window, *button;
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	button=gtk_button_new_with_label("Click me");

	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);
	g_signal_connect(button,"clicked",G_CALLBACK(button_clicked),NULL);
	//gtk_widget_set_size_request(window,30,300);
	gtk_widget_set_size_request(button,10,50);
//	gtk_container_add(GTK_CONTAINER(window),button);
	
	gtk_window_set_title(GTK_WINDOW(window),"hello hello");
	
	gtk_widget_show_all(window);
//gtk_label_set_text(GTK_LABEL(label), "World Hello ");
	gtk_main();

	return 0;
}