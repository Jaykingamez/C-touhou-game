// gcc display_picture.c -o display_picture.exe  %GTK4-PKG-CONFIG%
// Check https://stdin.top/posts/gtk4-on-windows/ for more info
#include <stdio.h>
#include <gtk/gtk.h>

static void display_picture_activate (GtkApplication *app, gpointer user_data) {
  char* filename = (char*)user_data;

  // Create a new window
  GtkWidget *win = gtk_application_window_new(app);
  gtk_window_set_decorated (GTK_WINDOW (win), FALSE);
  // gtk_window_set_title (GTK_WINDOW (win), "Hello, World!");
  gtk_window_set_default_size (GTK_WINDOW (win), 1280, 720);

  GtkWidget *picture = gtk_picture_new_for_filename (filename);
  gtk_picture_set_content_fit (GTK_PICTURE (picture), GTK_CONTENT_FIT_FILL);

  GtkGesture *gesture = gtk_gesture_click_new ();
  // gtk_gesture_single_set_button (GTK_GESTURE_SINGLE (gesture), 1);
  g_signal_connect_swapped (gesture, "pressed", G_CALLBACK (gtk_window_close), win);
  gtk_widget_add_controller (picture, GTK_EVENT_CONTROLLER (gesture));

  gtk_window_set_child (GTK_WINDOW (win), picture);

  gtk_window_present (GTK_WINDOW (win));
  g_timeout_add_seconds(2, (GSourceFunc)gtk_window_close, win);
}

void display_picture_window(char* filename) {
  // Create a new application
  GtkApplication *app = gtk_application_new ("com.example.GtkApplication", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect (app, "activate", G_CALLBACK (display_picture_activate ), filename);
  g_application_run (G_APPLICATION (app), 0, NULL);
}
