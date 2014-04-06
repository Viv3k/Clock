#include <cairo.h>
#include <gtk/gtk.h>
#include <math.h>
#include <malloc.h>
#include "clock.h"

#include "clock.c"
GtkWidget *darea;  
GtkWidget *window;
GtkWidget *fixed;



GdkPixbuf *create_pixbuf(const gchar * filename)

{
   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   return pixbuf;
}



int main(int argc, char *argv[])
{

	GtkWidget *button1;
	GtkWidget *button2;
	GtkWidget *button3;
  	glob.count = 0;
  	gtk_init(&argc, &argv);

  	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  	darea = gtk_drawing_area_new();
  	 
  	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  	gtk_window_set_default_size(GTK_WINDOW(window),300, 300); 
  	gtk_window_set_title(GTK_WINDOW(window), "Clock");
   gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("web.png"));    
   fixed = gtk_fixed_new();
   gtk_container_add(GTK_CONTAINER(window), fixed);

   button1 = gtk_button_new_with_label("Analouge");
   gtk_fixed_put(GTK_FIXED(fixed), button1, 20,0);
   gtk_widget_set_size_request(button1, 80, 35);

   button2 = gtk_button_new_with_label("Binary");
   gtk_fixed_put(GTK_FIXED(fixed), button2, 100,0);
   gtk_widget_set_size_request(button2, 80, 35);

   button3 = gtk_button_new_with_label("Digital");
   gtk_fixed_put(GTK_FIXED(fixed), button3, 180,0);
   gtk_widget_set_size_request(button3, 80, 35);
  
   gtk_fixed_put(GTK_FIXED(fixed), darea, 0, 70);
 
   gtk_widget_set_redraw_on_allocate (darea,TRUE);
   gtk_widget_set_size_request(darea,300 ,210);

   func();
   g_signal_connect(G_OBJECT(darea), "draw", 
      		G_CALLBACK(on_draw_event), NULL);  
   g_signal_connect(G_OBJECT(window), "destroy",
  	    G_CALLBACK(gtk_main_quit), NULL);
   g_signal_connect(G_OBJECT(button1), "button-press-event", 
   			 G_CALLBACK(clicked), fixed);
	g_signal_connect(G_OBJECT(button2), "button-press-event", 
   			 G_CALLBACK(clicked2), fixed);
	g_signal_connect(G_OBJECT(button3), "button-press-event", 
   			 G_CALLBACK(clicked3), fixed);

  	g_timeout_add(100, (GSourceFunc) time_handler, (gpointer) window);

   gtk_widget_show_all(window);  
   gtk_main();
   return 0;

}



void enter_button() 
{
	 gint width;
	 gint height;   
    gtk_window_get_size(GTK_WINDOW(window),&width, &height);
    gtk_widget_queue_resize(darea); 
    gtk_widget_set_size_request(darea,width,height-70);

    }
 

void func()
{

    time_t current_time;
    const gchar* c_time_string;
    current_time = time(NULL);
    c_time_string = ctime(&current_time);
	 GtkWidget *button;
	 button  = gtk_button_new_with_label(c_time_string);
    gtk_fixed_put(GTK_FIXED(fixed),gtk_button_new_with_label(c_time_string), 50, 35);
    gtk_widget_set_size_request(gtk_button_new_with_label(c_time_string)	, 100, 0); 
   gtk_widget_show_all(window);  

}

