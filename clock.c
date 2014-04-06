#include <cairo.h>
#include <gtk/gtk.h>
#include <math.h>
#include "clock.h"



static gboolean time_handler(GtkWidget *widget)

{	
	glob.count += 1;
 	gtk_widget_queue_draw(widget);  
   enter_button();
   func();
	return TRUE;

}

static gboolean on_draw_event(GtkWidget *widget, 
			   cairo_t *cr, gpointer user_data)
{	
  	do_drawing(cr,widget);        
  	return FALSE;
}

static gboolean clicked(GtkWidget *button, GdkEventButton *event,
    GtkWidget* window)
{
	a = 1;	
	b =0 ;
	c = 0; 
	gtk_widget_queue_draw(window);			
   return TRUE;

}

static gboolean clicked2(GtkWidget *button, GdkEventButton *event,
    GtkWidget* window)

{
	a = 0;	
	b =1 ;
	c = 0; 
	gtk_widget_queue_draw(window);	
   return TRUE;
}


static gboolean clicked3(GtkWidget *button, GdkEventButton *event,
    GtkWidget* window)

{
	a = 0;	
	b =0 ;
	c = 1; 
	gtk_widget_queue_draw(window);    
   return TRUE;
}


void do_drawing(cairo_t *cr,GtkWidget *window)

{
  	time_t now = time(NULL);
  	now_hms = localtime(&now);

  	GtkWidget *win = gtk_widget_get_toplevel(window);  
  	gint width, height;
  	gtk_window_get_size(GTK_WINDOW(win), &width, &height);
     

	if(a==1)
	{      
 		cairo_set_source_rgb(cr, 0, 0, 0);
  		cairo_set_line_width(cr, 5);  
  		cairo_set_source_rgb(cr, 0.0, 0.0, 0.0);  
  		cairo_arc(cr, width/2, height/2 -40 , 50, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  		cairo_set_source_rgb(cr, 1.0, 1.0, 1.0); 
  		cairo_fill(cr);    
	
  		int i;
		int inset;
		int x,y;
		x = width/2;
		y=height/2 -40;
	
		for(i=1;i<=12;i++){
		
			if(i%3==0)
				 inset = 40;
			else inset = 45;
	
			cairo_move_to(cr, width/2+ inset * cos(i*M_PI/6),
					height/2-40+ inset * sin(i*M_PI/6));
  		   cairo_set_line_width(cr, 2);
			cairo_set_source_rgb(cr, 0, 1.0, 0);  
            
    		cairo_line_to (cr,width/2+ 50*cos(i*M_PI/6),
                                y+50*sin(i*M_PI/6));
    		cairo_stroke(cr);
			}

    	cairo_set_line_width(cr, 1);
		cairo_set_source_rgb(cr, 0.8, 0.4, 0);  

		const int temp1=now_hms->tm_hour;
		const int temp2=now_hms->tm_min;
		const int temp3=now_hms->tm_sec;
      cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND);
		cairo_move_to(cr,x,y);
    	cairo_line_to(cr, x+45*sin((temp3*M_PI/30)),
					y-45*cos((temp3*M_PI/30)));
    	cairo_stroke(cr);
 		cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND);
    	cairo_set_line_width(cr, 4);
		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
            
		cairo_move_to(cr,x,y);
    	cairo_line_to(cr, x+40*sin((temp3*M_PI/1800)+(temp2*M_PI/30)),
						y-40*cos((temp3*M_PI/1800)+(temp2*M_PI/30)));
    	cairo_stroke(cr);

    	cairo_set_line_width(cr, 6);
		cairo_set_source_rgb(cr, 1.0, 1.0, 0.0);  
  		cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND);           

		cairo_move_to(cr,x,y);
   	cairo_line_to(cr, x+30*sin((temp3*M_PI/21600)+(temp2*M_PI/360)+(temp1*M_PI/6)),
				y-30*cos((temp3*M_PI/21600)+(temp2*M_PI/360)+(temp1*M_PI/6) ));
    	cairo_stroke(cr);
	
	}
 







 	if(b==1){ 
 	
		const int temp1=now_hms->tm_hour;
		const int temp2=now_hms->tm_min;
		const int temp3=now_hms->tm_sec;
		 	
		int **a,i;
		a = malloc(sizeof(int*)*6);
		for(i=0;i<6;i++)
		a[i] = malloc(sizeof(int)*4);
	
		a = binary(a,temp1,temp2,temp3);

		int x,y;
		x = (width/2)-60;
		y=(height/2)-80;
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x, y , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
		if(a[1][0] == 1)
  			cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
			cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);
  		cairo_fill(cr);    

	  	cairo_set_source_rgb(cr, 1, 0, 0);
	  	cairo_set_line_width(cr, 1);  
	  	cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
	  	cairo_arc(cr, x, y+20 , 10, 0, 2 * M_PI);
	  	cairo_stroke_preserve(cr);
	  	if(a[1][1] == 1)
		  	cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
			cairo_set_source_rgb(cr, 0.0, 1.0, 0.0); 
	  	cairo_fill(cr); 

	  	cairo_set_source_rgb(cr, 1, 0, 0);
	  	cairo_set_line_width(cr, 1);  
	  	cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
	  	cairo_arc(cr, x, y+40 , 10, 0, 2 * M_PI);
	  	cairo_stroke_preserve(cr);
	  	if(a[1][2] == 1)
		  	cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
			cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);
  		cairo_fill(cr); 
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x, y+60 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  		if(a[1][3] == 1)
  			cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
			cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);
  		cairo_fill(cr); 

  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+20, y , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  		if(a[0][0] == 1)
  			cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
			cairo_set_source_rgb(cr, 0.0, 1.0, 0.0); 
  		cairo_fill(cr); 
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+20, y+20 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  		if(a[0][1] == 1)
  			cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
			cairo_set_source_rgb(cr, 0.0, 1.0, 0.0); 
  			cairo_fill(cr); 
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+20, y+40 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  		if(a[0][2] == 1)
  			cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
			cairo_set_source_rgb(cr, 0.0, 1.0, 0.0); 
  		cairo_fill(cr); 
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+20, y+60 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
    	if(a[0][3] == 1)
  			cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
			cairo_set_source_rgb(cr, 0.0, 1.0, 0.0); 
  		cairo_fill(cr); 

  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+50, y , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
    	if(a[3][0] == 1)
  			cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
			cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);  
  		cairo_fill(cr); 
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+50, y+20 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
   	if(a[3][1] == 1)
  			cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
			cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);  
  		cairo_fill(cr); 

  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+50, y+40 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
   	 	if(a[3][2] == 1)
  				cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
			else
				cairo_set_source_rgb(cr, 0.0, 1.0, 0.0); 
  		cairo_fill(cr); 


  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+50, y+60 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
   	 	if(a[3][3] == 1)
  				cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
			else
				cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);  
  		cairo_fill(cr); 
	
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+70, y , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  	  	if(a[2][0] == 1)
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
		cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);  
  		cairo_fill(cr); 
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+70, y+20 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  	   	if(a[2][1] == 1)
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
			else
		cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);  
  		cairo_fill(cr); 

  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+70, y +40, 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  		  	if(a[2][2] == 1)
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
		cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);   
  		cairo_fill(cr); 
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+70, y+60 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  	  	if(a[2][3] == 1)
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
		cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);  
  		cairo_fill(cr); 
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+100, y , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  	  	if(a[5][0] == 1)
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
		cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);   
  		cairo_fill(cr); 
	
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+100, y+20 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
    	if(a[5][1] == 1)
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
		cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);  
  		cairo_fill(cr); 
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+100, y+40 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  	  	if(a[5][2] == 1)
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
		cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);  
  		cairo_fill(cr); 
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+100, y+60 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  	  	if(a[5][3] == 1)
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
		cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);  
  		cairo_fill(cr); 
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+120, y , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  	  	if(a[4][0] == 1)
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
		cairo_set_source_rgb(cr, 0.0, 1.0, 0.0);   
  		cairo_fill(cr); 
	
	
  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+120, y+20 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
  	  	if(a[4][1] == 1)
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
		cairo_set_source_rgb(cr, 0.0, 1.0, 0.0); 
  		cairo_fill(cr); 

  		cairo_set_source_rgb(cr, 1, 0, 0);
  		cairo_set_line_width(cr, 1);  
  		cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  		cairo_arc(cr, x+120, y+40 , 10, 0, 2 * M_PI);
  		cairo_stroke_preserve(cr);
    	if(a[4][2] == 1)
  			cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
		else
		cairo_set_source_rgb(cr, 0.0, 1.0, 0.0); 
  		cairo_fill(cr); 

  	cairo_set_source_rgb(cr, 1, 0, 0);
  	cairo_set_line_width(cr, 1);  
  	cairo_set_source_rgb(cr, 1.0, 0.0, 0.0);  
  	cairo_arc(cr, x+120, y+60 , 10, 0, 2 * M_PI);
  	cairo_stroke_preserve(cr);
    	if(a[4][3] == 1)
  	cairo_set_source_rgb(cr, 1.0, 0.0, 0.0); 
	else
	cairo_set_source_rgb(cr, 0.0, 1.0, 0.0); 
  	cairo_fill(cr); 

}

if (c==1)
	{ 
 	gint x,y;
 	x=30;y=30;
 
 	{if(now_hms->tm_hour /10 ==1)
 	{
 	cairo_set_source_rgb(cr,0.0,0.0,0.0);
 	cairo_set_line_width(cr, 1); 
 	cairo_move_to(cr,x,y);
 	cairo_line_to(cr,x,y+60);
 	cairo_stroke(cr);
}	
	
	if(now_hms->tm_hour /10 ==2)
{
	cairo_set_source_rgb(cr,0.0,0.0,0.0);
	 cairo_set_line_width(cr, 1); 
	 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
	 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x+20,y+60);
 cairo_stroke(cr);}

if(now_hms->tm_hour /10 ==3)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x,y+30);
 cairo_move_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_stroke(cr);}


if(now_hms->tm_hour /10 ==4)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x+20,y);

 cairo_stroke(cr);}

if(now_hms->tm_hour /10 ==5)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_stroke(cr);}

 if(now_hms->tm_hour /10 ==6)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x,y+30); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_stroke(cr);}

if(now_hms->tm_hour /10 ==7)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x+20,y+60);
 
 cairo_stroke(cr);}

if(now_hms->tm_hour /10 ==8)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x,y+30); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to (cr,x+20,y+30);
 cairo_stroke(cr);}

if(now_hms->tm_hour /10 ==9)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);

 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to (cr,x+20,y+30);
 cairo_stroke(cr);}

 if(now_hms->tm_hour /10 ==0)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x,y);
 cairo_stroke(cr);}

}


x=55;y=30;
{if(now_hms->tm_hour %10 ==1)
{
 cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+60);
 cairo_stroke(cr);
}

if(now_hms->tm_hour %10 ==2)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x+20,y+60);
 cairo_stroke(cr);}

if(now_hms->tm_hour %10 ==3)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x,y+30);
 cairo_move_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_stroke(cr);}


if(now_hms->tm_hour %10 ==4)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x+20,y );

 cairo_stroke(cr);}

if(now_hms->tm_hour %10 ==5)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_stroke(cr);}

 if(now_hms->tm_hour %10 ==6)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x,y+30); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_stroke(cr);}

if(now_hms->tm_hour %10 ==7)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x+20,y+60);
 
 cairo_stroke(cr);}

if(now_hms->tm_hour %10 ==8)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x,y+30); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to (cr,x+20,y+30);
 cairo_stroke(cr);}

if(now_hms->tm_hour %10 ==9)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);

 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to (cr,x+20,y+30);
 cairo_stroke(cr);}

 if(now_hms->tm_hour %10 ==0)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x,y);
 cairo_stroke(cr);}
}


//minutes printing

x=110;y=30;
 
 {if(now_hms->tm_min /10 ==1)
{
 cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+60);
 cairo_stroke(cr);
}

if(now_hms->tm_min /10 ==2)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x+20,y+60);
 cairo_stroke(cr);}

if(now_hms->tm_min /10 ==3)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x,y+30);
 cairo_move_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_stroke(cr);}


if(now_hms->tm_min /10 ==4)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x+20,y );

 cairo_stroke(cr);}

if(now_hms->tm_min /10 ==5)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_stroke(cr);}

 if(now_hms->tm_min /10 ==6)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x,y+30); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_stroke(cr);}

if(now_hms->tm_min /10 ==7)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x+20,y+60);
 
 cairo_stroke(cr);}

if(now_hms->tm_min /10 ==8)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x,y+30); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to (cr,x+20,y+30);
 cairo_stroke(cr);}

if(now_hms->tm_min /10 ==9)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);

 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to (cr,x+20,y+30);
 cairo_stroke(cr);}

 if(now_hms->tm_min /10 ==0)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x,y);
 cairo_stroke(cr);}

}


x=135;y=30;
{if(now_hms->tm_min %10 ==1)
{
 cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+60);
 cairo_stroke(cr);
}

if(now_hms->tm_min %10 ==2)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x+20,y+60);
 cairo_stroke(cr);}

if(now_hms->tm_min %10 ==3)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x,y+30);
 cairo_move_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_stroke(cr);}


if(now_hms->tm_min %10 ==4)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
cairo_line_to(cr,x+20,y );
 cairo_stroke(cr);}

if(now_hms->tm_min %10 ==5)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_stroke(cr);}

 if(now_hms->tm_min %10 ==6)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x,y+30); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_stroke(cr);}

if(now_hms->tm_min %10 ==7)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x+20,y+60);
 
 cairo_stroke(cr);}

if(now_hms->tm_min %10 ==8)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x,y+30); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to (cr,x+20,y+30);
 cairo_stroke(cr);}

if(now_hms->tm_min %10 ==9)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);

 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to (cr,x+20,y+30);
 cairo_stroke(cr);}

 if(now_hms->tm_min %10 ==0)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x,y);
 cairo_stroke(cr);}
}


//secnds printing

x=180;y=30;
 
 {if(now_hms->tm_sec /10 ==1)
{
 cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+60);
 cairo_stroke(cr);
}

if(now_hms->tm_sec /10 ==2)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x+20,y+60);
 cairo_stroke(cr);}

if(now_hms->tm_sec /10 ==3)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x,y+30);
 cairo_move_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_stroke(cr);}


if(now_hms->tm_sec /10 ==4)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x+20,y );
 cairo_stroke(cr);}

if(now_hms->tm_sec /10 ==5)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_stroke(cr);}

 if(now_hms->tm_sec /10 ==6)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x,y+30); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_stroke(cr);}

if(now_hms->tm_sec /10 ==7)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x+20,y+60);
 
 cairo_stroke(cr);}

if(now_hms->tm_sec /10 ==8)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x,y+30); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to (cr,x+20,y+30);
 cairo_stroke(cr);}

if(now_hms->tm_sec /10 ==9)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);

 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to (cr,x+20,y+30);
 cairo_stroke(cr);}

 if(now_hms->tm_sec /10 ==0)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x,y);
 cairo_stroke(cr);}

}


x=205;y=30;
{if(now_hms->tm_sec %10 ==1)
{
 cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+60);
 cairo_stroke(cr);
}

if(now_hms->tm_sec %10 ==2)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x+20,y+60);
 cairo_stroke(cr);}

if(now_hms->tm_sec %10 ==3)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x,y+30);
 cairo_move_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_stroke(cr);}


if(now_hms->tm_sec %10 ==4)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x+20,y);
 cairo_stroke(cr);}

if(now_hms->tm_sec %10 ==5)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_stroke(cr);}

 if(now_hms->tm_sec %10 ==6)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x,y+30); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_stroke(cr);}

if(now_hms->tm_sec %10 ==7)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x+20,y+30);
 cairo_line_to(cr,x+20,y+60);
 
 cairo_stroke(cr);}

if(now_hms->tm_sec %10 ==8)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x,y+30); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to (cr,x+20,y+30);
 cairo_stroke(cr);}

if(now_hms->tm_sec %10 ==9)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+30);
 cairo_line_to(cr,x+20,y+30); 
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x,y+60);

 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x+20,y);
 cairo_line_to (cr,x+20,y+30);
 cairo_stroke(cr);}

 if(now_hms->tm_sec %10 ==0)
{cairo_set_source_rgb(cr,0.0,0.0,0.0);
 cairo_set_line_width(cr, 1); 
 cairo_move_to(cr,x,y);
 cairo_line_to(cr,x,y+60);
 cairo_line_to(cr,x+20,y+60);
 cairo_line_to(cr,x+20,y);
 cairo_line_to(cr,x,y);
 cairo_stroke(cr);}
}

}}








int ** binary(int** a, int x, int y, int z){

	int i,buff;
	buff = x%10;
	for(i=3;i>=0;i--){
		
		a[0][i] = buff%2;
		buff = buff/2;

	}
		buff = x/10;

	for(i=3;i>=0;i--){
		a[1][i] = buff%2;
		buff = buff/2;
	}
		buff = y%10;

	for(i=3;i>=0;i--){
		a[2][i] = buff%2;
		buff = buff/2;
	}
		buff = y/10;

	for(i=3;i>=0;i--){
		a[3][i] = buff%2;
		buff = buff/2;
	}
		buff = z%10;

	for(i=3;i>=0;i--){
		a[4][i] = buff%2;
		buff = buff/2;
	}
		buff = z/10;

	for(i=3;i>=0;i--){
		a[5][i] = buff%2;
		buff = buff/2;
	}

return a;
}




  



	
