#include<gtk/gtk.h>

static void button_clicked(GtkWidget *widget ,gpointer data){
	gtk_label_set_text(GTK_LABEL(data),"you click the button");
}

int main(int argc,char * argv[])
{
	gtk_init(&argc,&argv);
	GtkWidget * window,*label, *button,*hbox;
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,"delete-event",G_CALLBACK(gtk_main_quit),NULL);
	
	label = gtk_label_new("Hello wd");
	button = gtk_button_new_with_label("click me");



	g_signal_connect(button,"clicked",G_CALLBACK(button_clicked),(gpointer)label);
	hbox = gtk_vbox_new(0,0);
	
	gtk_box_pack_start(GTK_BOX(hbox),label,1,1,0);
	gtk_box_pack_start(GTK_BOX(hbox),button,1,1,0);
	gtk_container_add(GTK_CONTAINER(window),hbox);


	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}