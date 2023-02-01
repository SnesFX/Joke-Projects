#include <gtk/gtk.h>
#include <stdlib.h>
#include <time.h>

static void show_joke(GtkWidget *label)
{
    srand(time(NULL));
    int num = rand() % 5;
    char *joke = NULL;

    switch (num)
    {
        case 0:
            joke = "Why did the tomato turn red?\n"
                   "Because it saw the salad dressing!";
            break;
        case 1:
            joke = "Why did the scarecrow win an award?\n"
                   "Because he was outstanding in his field!";
            break;
        case 2:
            joke = "Why did the cookie go to the doctor?\n"
                   "Because it was feeling crumbly!";
            break;
        case 3:
            joke = "Why was the math book sad?\n"
                   "Because it had too many problems.";
            break;
        case 4:
            joke = "Why did the bicycle fall over?\n"
                   "Because it was two-tired!";
            break;
    }

    gtk_label_set_text(GTK_LABEL(label), joke);
}

static void activate(GtkApplication *app, gpointer user_data)
{
    GtkWidget *window, *label;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Joke Generator");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    label = gtk_label_new(NULL);
    gtk_label_set_line_wrap(GTK_LABEL(label), TRUE);
    gtk_label_set_justify(GTK_LABEL(label), GTK_JUSTIFY_CENTER);
    gtk_container_add(GTK_CONTAINER(window), label);

    show_joke(label);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv)
{
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
