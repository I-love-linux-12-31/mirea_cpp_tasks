#include <gtk-4.0/gtk/gtk.h> // подключаем GTK+
#include <cairo/cairo.h> // подключаем библиотеку векторной графики Cairo
#include <math.h>  // подключаем библиотеку математических функций и констант

/* Функция, вызываемая на перерисовку содержимого окна */
void on_draw_event (GtkWidget *widget, cairo_t *cr, gpointer data)
{
    /* Отрисовка неба */
    cairo_set_source_rgb(cr, 0.0, 0.0, 1.0);
    cairo_rectangle(cr, 0, 0, 700, 300);
    cairo_fill(cr);
    /* Отрисовка земли */
    cairo_set_source_rgb(cr, 0.3, 0.3, 0.0);
    cairo_rectangle(cr, 0, 300, 700, 200);
    cairo_fill(cr);

    /* Отрисовка солнца */
    cairo_set_source_rgb(cr, 1, 1, 0.0);
    cairo_arc(cr, 500, 0, 50, 0, M_PI);
    cairo_fill(cr);
    /* Отрисовка лучей */
    cairo_move_to(cr, 500, 0);
    cairo_line_to(cr, 400, 50);
    cairo_move_to(cr, 500, 0);
    cairo_line_to(cr, 500, 100);
    cairo_move_to(cr, 500, 0);
    cairo_line_to(cr, 600, 50);
    cairo_stroke(cr);
}

/* Функция, вызываемая на событие нажатия кнопки */
void button_click (GtkButton *button, gpointer data)
{
    gtk_main_quit();
}

/* Основная функция с которой стартует выполнение программы */
int main( int argc, char *argv[])
{
    /* запустить GTK+ */
    gtk_init(&argc, &argv);

    /* создать новый виджет - окно и установить свойства*/
    GtkWidget *window;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 650, 500);
    gtk_window_set_title(GTK_WINDOW(window), "Sun");
    gtk_container_set_border_width (GTK_CONTAINER (window), 10);
    /* Событие, которое отрабатывает на закрытие окна */
    g_signal_connect(G_OBJECT(window), "destroy",
                     G_CALLBACK(gtk_main_quit), NULL);

    /* создать виджет - вертикального расположения элементов   */
    GtkWidget *vbox;
    vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 1);
    gtk_container_add(GTK_CONTAINER (window), vbox);

    /* создать виджет - область для рисования   */
    GtkWidget *drawing_area;
    drawing_area = gtk_drawing_area_new();
    /* разместить область в верхней части окна*/
    gtk_box_pack_start (GTK_BOX(vbox), drawing_area, TRUE, TRUE, 10);
    /* Событие отрисовки содержимого области */
    g_signal_connect(G_OBJECT(drawing_area), "draw", G_CALLBACK(on_draw_event), NULL);

    /* создать виджет - кнопка   */
    GtkWidget *button;
    button = gtk_button_new_with_label("Quit");
    gtk_container_set_border_width (GTK_CONTAINER (button), 10);
    /* разместить кнопку в нижней части окна*/
    gtk_box_pack_end (GTK_BOX(vbox), button, FALSE, FALSE, 10);
    /* Событие, которое отрабатывает на нажатие кнопки */
    g_signal_connect(GTK_BUTTON(button), "clicked",
                     G_CALLBACK(button_click), NULL);

    /* отобразить окно и все его виджеты */
    gtk_widget_show_all(window);

    /* передаём управление GTK+ */
    gtk_main();

    return 0;