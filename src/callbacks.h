#include <gtk/gtk.h>


void
on_login_clicked                       (GtkWidget       *graphic,
                                        gpointer         user_data);

void
on_logout_clicked                      (GtkWidget       *graphic,
                                        gpointer         user_data);

void
on_logout2_clicked                     (GtkWidget       *graphic,
                                        gpointer         user_data);

void
on_add_clicked                         (GtkWidget       *graphic,
                                        gpointer         user_data);

void
on_add_new_clicked                     (GtkWidget       *graphic,
                                        gpointer         user_data);

void
on_quit1_clicked                       (GtkWidget	*graphic,
                                        gpointer         user_data);

void
on_quit_clicked                        (GtkWidget       *graphic,
                                        gpointer         user_data);

void
on_users_clicked                       (GtkWidget       *graphic,
                                        gpointer         user_data);

void
on_add_clicked                         (GtkWidget       *graphic,
                                        gpointer         user_data);

void
on_user_list_exit_clicked              (GtkWidget	*graphic,
                                        gpointer         user_data);

void
on_users_list_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_staff_clicked                       (GtkWidget	*graphic,
                                        gpointer         user_data);

void
on_quit_st_clicked                     (GtkWidget	*graphic,
                                        gpointer         user_data);

void
on_add_new_st_clicked                  (GtkWidget	*graphic,
                                        gpointer         user_data);

void
on_add_st_clicked                      (GtkWidget	*graphic,
                                        gpointer         user_data);

void
on_quit_st_list_clicked                (GtkWidget	*graphic,
                                        gpointer         user_data);
