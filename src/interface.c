/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_MyWindow (void)
{
  GtkWidget *MyWindow;
  GtkWidget *fixed1;
  GtkWidget *username;
  GtkWidget *pass;
  GtkWidget *label1;
  GtkWidget *label2;
  GtkWidget *login;
  GtkWidget *quit;
  GtkWidget *status;

  MyWindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (MyWindow, 500, 300);
  gtk_window_set_title (GTK_WINDOW (MyWindow), _("window1"));

  fixed1 = gtk_fixed_new ();
  gtk_widget_show (fixed1);
  gtk_container_add (GTK_CONTAINER (MyWindow), fixed1);
  gtk_widget_set_size_request (fixed1, 340, 242);

  username = gtk_entry_new ();
  gtk_widget_show (username);
  gtk_fixed_put (GTK_FIXED (fixed1), username, 232, 72);
  gtk_widget_set_size_request (username, 172, 35);
  gtk_entry_set_invisible_char (GTK_ENTRY (username), 9679);

  pass = gtk_entry_new ();
  gtk_widget_show (pass);
  gtk_fixed_put (GTK_FIXED (fixed1), pass, 232, 128);
  gtk_widget_set_size_request (pass, 172, 35);
  gtk_entry_set_visibility (GTK_ENTRY (pass), FALSE);
  gtk_entry_set_invisible_char (GTK_ENTRY (pass), 9679);

  label1 = gtk_label_new (_("Username"));
  gtk_widget_show (label1);
  gtk_fixed_put (GTK_FIXED (fixed1), label1, 72, 80);
  gtk_widget_set_size_request (label1, 104, 16);

  label2 = gtk_label_new (_("Password"));
  gtk_widget_show (label2);
  gtk_fixed_put (GTK_FIXED (fixed1), label2, 80, 144);
  gtk_widget_set_size_request (label2, 96, 16);

  login = gtk_button_new_with_mnemonic (_("login"));
  gtk_widget_show (login);
  gtk_fixed_put (GTK_FIXED (fixed1), login, 152, 208);
  gtk_widget_set_size_request (login, 71, 34);

  quit = gtk_button_new_with_mnemonic (_("Quit"));
  gtk_widget_show (quit);
  gtk_fixed_put (GTK_FIXED (fixed1), quit, 256, 208);
  gtk_widget_set_size_request (quit, 70, 33);

  status = gtk_label_new (_("hello :::::"));
  gtk_widget_show (status);
  gtk_fixed_put (GTK_FIXED (fixed1), status, 104, 32);
  gtk_widget_set_size_request (status, 284, 16);

  g_signal_connect ((gpointer) login, "clicked",
                    G_CALLBACK (on_login_clicked),
                    NULL);
  g_signal_connect ((gpointer) quit, "clicked",
                    G_CALLBACK (on_quit_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (MyWindow, MyWindow, "MyWindow");
  GLADE_HOOKUP_OBJECT (MyWindow, fixed1, "fixed1");
  GLADE_HOOKUP_OBJECT (MyWindow, username, "username");
  GLADE_HOOKUP_OBJECT (MyWindow, pass, "pass");
  GLADE_HOOKUP_OBJECT (MyWindow, label1, "label1");
  GLADE_HOOKUP_OBJECT (MyWindow, label2, "label2");
  GLADE_HOOKUP_OBJECT (MyWindow, login, "login");
  GLADE_HOOKUP_OBJECT (MyWindow, quit, "quit");
  GLADE_HOOKUP_OBJECT (MyWindow, status, "status");

  return MyWindow;
}

GtkWidget*
create_admin (void)
{
  GtkWidget *admin;
  GtkWidget *fixed2;
  GtkWidget *text;
  GtkWidget *logout;
  GtkWidget *users;

  admin = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (admin, 500, 300);
  gtk_window_set_title (GTK_WINDOW (admin), _("window1"));

  fixed2 = gtk_fixed_new ();
  gtk_widget_show (fixed2);
  gtk_container_add (GTK_CONTAINER (admin), fixed2);

  text = gtk_label_new (_("Hello admin"));
  gtk_widget_show (text);
  gtk_fixed_put (GTK_FIXED (fixed2), text, 16, 8);
  gtk_widget_set_size_request (text, 128, 48);

  logout = gtk_button_new_with_mnemonic (_("logout"));
  gtk_widget_show (logout);
  gtk_fixed_put (GTK_FIXED (fixed2), logout, 24, 256);
  gtk_widget_set_size_request (logout, 65, 28);

  users = gtk_button_new_with_mnemonic (_("Les adh\303\251rent"));
  gtk_widget_show (users);
  gtk_fixed_put (GTK_FIXED (fixed2), users, 352, 24);
  gtk_widget_set_size_request (users, 128, 32);

  g_signal_connect ((gpointer) logout, "clicked",
                    G_CALLBACK (on_logout_clicked),
                    NULL);
  g_signal_connect ((gpointer) users, "clicked",
                    G_CALLBACK (on_users_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (admin, admin, "admin");
  GLADE_HOOKUP_OBJECT (admin, fixed2, "fixed2");
  GLADE_HOOKUP_OBJECT (admin, text, "text");
  GLADE_HOOKUP_OBJECT (admin, logout, "logout");
  GLADE_HOOKUP_OBJECT (admin, users, "users");

  return admin;
}

GtkWidget*
create_kine (void)
{
  GtkWidget *kine;
  GtkWidget *fixed3;
  GtkWidget *label3;
  GtkWidget *logout2;

  kine = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (kine), _("window1"));

  fixed3 = gtk_fixed_new ();
  gtk_widget_show (fixed3);
  gtk_container_add (GTK_CONTAINER (kine), fixed3);

  label3 = gtk_label_new (_("hello Kine"));
  gtk_widget_show (label3);
  gtk_fixed_put (GTK_FIXED (fixed3), label3, 104, 80);
  gtk_widget_set_size_request (label3, 104, 32);

  logout2 = gtk_button_new_with_mnemonic (_("logout"));
  gtk_widget_show (logout2);
  gtk_fixed_put (GTK_FIXED (fixed3), logout2, 128, 160);
  gtk_widget_set_size_request (logout2, 71, 34);

  g_signal_connect ((gpointer) logout2, "clicked",
                    G_CALLBACK (on_logout2_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (kine, kine, "kine");
  GLADE_HOOKUP_OBJECT (kine, fixed3, "fixed3");
  GLADE_HOOKUP_OBJECT (kine, label3, "label3");
  GLADE_HOOKUP_OBJECT (kine, logout2, "logout2");

  return kine;
}

GtkWidget*
create_add (void)
{
  GtkWidget *add;
  GtkWidget *fixed4;
  GtkWidget *label4;
  GtkWidget *label5;
  GtkWidget *n_user;
  GtkWidget *n_pass;
  GtkObject *n_role_adj;
  GtkWidget *n_role;
  GtkWidget *add_new;
  GtkWidget *quit1;
  GtkWidget *label6;

  add = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (add), _("window1"));

  fixed4 = gtk_fixed_new ();
  gtk_widget_show (fixed4);
  gtk_container_add (GTK_CONTAINER (add), fixed4);

  label4 = gtk_label_new (_("Nom utilisateur"));
  gtk_widget_show (label4);
  gtk_fixed_put (GTK_FIXED (fixed4), label4, 24, 56);
  gtk_widget_set_size_request (label4, 128, 18);

  label5 = gtk_label_new (_("Mot de passe"));
  gtk_widget_show (label5);
  gtk_fixed_put (GTK_FIXED (fixed4), label5, 32, 112);
  gtk_widget_set_size_request (label5, 112, 16);

  n_user = gtk_entry_new ();
  gtk_widget_show (n_user);
  gtk_fixed_put (GTK_FIXED (fixed4), n_user, 184, 56);
  gtk_widget_set_size_request (n_user, 158, 26);
  gtk_entry_set_invisible_char (GTK_ENTRY (n_user), 9679);

  n_pass = gtk_entry_new ();
  gtk_widget_show (n_pass);
  gtk_fixed_put (GTK_FIXED (fixed4), n_pass, 184, 112);
  gtk_widget_set_size_request (n_pass, 158, 26);
  gtk_entry_set_visibility (GTK_ENTRY (n_pass), FALSE);
  gtk_entry_set_invisible_char (GTK_ENTRY (n_pass), 9679);

  n_role_adj = gtk_adjustment_new (1, 1, 6, 1, 10, 10);
  n_role = gtk_spin_button_new (GTK_ADJUSTMENT (n_role_adj), 1, 0);
  gtk_widget_show (n_role);
  gtk_fixed_put (GTK_FIXED (fixed4), n_role, 184, 160);
  gtk_widget_set_size_request (n_role, 56, 32);
  gtk_spin_button_set_numeric (GTK_SPIN_BUTTON (n_role), TRUE);

  add_new = gtk_button_new_with_mnemonic (_("Ajouter"));
  gtk_widget_show (add_new);
  gtk_fixed_put (GTK_FIXED (fixed4), add_new, 152, 232);
  gtk_widget_set_size_request (add_new, 65, 28);

  quit1 = gtk_button_new_with_mnemonic (_("Sortir"));
  gtk_widget_show (quit1);
  gtk_fixed_put (GTK_FIXED (fixed4), quit1, 248, 232);
  gtk_widget_set_size_request (quit1, 65, 28);

  label6 = gtk_label_new (_("Role"));
  gtk_widget_show (label6);
  gtk_fixed_put (GTK_FIXED (fixed4), label6, 96, 168);
  gtk_widget_set_size_request (label6, 44, 18);

  g_signal_connect ((gpointer) add_new, "clicked",
                    G_CALLBACK (on_add_new_clicked),
                    NULL);
  g_signal_connect ((gpointer) quit1, "clicked",
                    G_CALLBACK (on_quit1_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (add, add, "add");
  GLADE_HOOKUP_OBJECT (add, fixed4, "fixed4");
  GLADE_HOOKUP_OBJECT (add, label4, "label4");
  GLADE_HOOKUP_OBJECT (add, label5, "label5");
  GLADE_HOOKUP_OBJECT (add, n_user, "n_user");
  GLADE_HOOKUP_OBJECT (add, n_pass, "n_pass");
  GLADE_HOOKUP_OBJECT (add, n_role, "n_role");
  GLADE_HOOKUP_OBJECT (add, add_new, "add_new");
  GLADE_HOOKUP_OBJECT (add, quit1, "quit1");
  GLADE_HOOKUP_OBJECT (add, label6, "label6");

  return add;
}

GtkWidget*
create_userlist (void)
{
  GtkWidget *userlist;
  GtkWidget *fixed5;
  GtkWidget *user_list_exit;
  GtkWidget *add;
  GtkWidget *users_list;

  userlist = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (userlist, 500, 300);
  gtk_window_set_title (GTK_WINDOW (userlist), _("window1"));

  fixed5 = gtk_fixed_new ();
  gtk_widget_show (fixed5);
  gtk_container_add (GTK_CONTAINER (userlist), fixed5);

  user_list_exit = gtk_button_new_with_mnemonic (_("sortir"));
  gtk_widget_show (user_list_exit);
  gtk_fixed_put (GTK_FIXED (fixed5), user_list_exit, 392, 64);
  gtk_widget_set_size_request (user_list_exit, 70, 33);

  add = gtk_button_new_with_mnemonic (_("ajouter"));
  gtk_widget_show (add);
  gtk_fixed_put (GTK_FIXED (fixed5), add, 392, 16);
  gtk_widget_set_size_request (add, 70, 33);

  users_list = gtk_tree_view_new ();
  gtk_widget_show (users_list);
  gtk_fixed_put (GTK_FIXED (fixed5), users_list, 24, 32);
  gtk_widget_set_size_request (users_list, 300, 200);

  g_signal_connect ((gpointer) user_list_exit, "clicked",
                    G_CALLBACK (on_user_list_exit_clicked),
                    NULL);
  g_signal_connect ((gpointer) add, "clicked",
                    G_CALLBACK (on_add_clicked),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (userlist, userlist, "userlist");
  GLADE_HOOKUP_OBJECT (userlist, fixed5, "fixed5");
  GLADE_HOOKUP_OBJECT (userlist, user_list_exit, "user_list_exit");
  GLADE_HOOKUP_OBJECT (userlist, add, "add");
  GLADE_HOOKUP_OBJECT (userlist, users_list, "users_list");

  return userlist;
}

GtkWidget*
create_window1 (void)
{
  GtkWidget *window1;
  GtkWidget *fixed6;

  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window1), _("window1"));

  fixed6 = gtk_fixed_new ();
  gtk_widget_show (fixed6);
  gtk_container_add (GTK_CONTAINER (window1), fixed6);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window1, window1, "window1");
  GLADE_HOOKUP_OBJECT (window1, fixed6, "fixed6");

  return window1;
}

