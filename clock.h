#ifndef CLOCK_H
#define CLOCK_H
void func();
int** binary (int** a, int x, int y, int z);
void  do_drawing(cairo_t *cr,GtkWidget *window);
static gboolean clicked(GtkWidget *button, GdkEventButton *event,
    GtkWidget* window);
static gboolean clicked2(GtkWidget *button, GdkEventButton *event,
    GtkWidget* window);
static gboolean clicked3(GtkWidget *button, GdkEventButton *event,
    GtkWidget* window);

void enter_button() ;
struct tm* now_hms;
int a;
int b,c;

struct {
  	gushort count;
	} glob;

#endif // CLOCK_H
