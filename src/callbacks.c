#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "func.h"


void
on_login_clicked                       (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	GtkWidget *user_d;
	GtkWidget *pass_d;
	GtkWidget *status_d;
	GtkWidget *text_lbl;
	GtkWidget *admin;
	GtkWidget *kine;
	GtkWidget *current;

	char user[20],pass[20],status[20];
	int role;
	current = lookup_widget(graphic,"MyWindow");
	user_d = lookup_widget(graphic,"username");
	pass_d = lookup_widget(graphic,"pass");
	status_d = lookup_widget(graphic,"status");
	strcpy(user,gtk_entry_get_text(GTK_ENTRY(user_d)));
	strcpy(pass,gtk_entry_get_text(GTK_ENTRY(pass_d)));
	role = verifier(user,pass,status);
	switch (role){
		case 0 :
			gtk_label_set_text(GTK_LABEL(status_d),status);
			break;
		case 1 :
			admin = create_admin();
			gtk_widget_show(admin);
			gtk_widget_hide(current);
			break;
		case 2 :
			kine = create_kine();
			gtk_widget_show(kine);
			gtk_widget_hide(current);
			break;
		default :
			gtk_label_set_text(GTK_LABEL(status_d),status);
			break;
	}
}

void
on_logout_clicked                      (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	GtkWidget *current;
	GtkWidget *login;
	current = lookup_widget(graphic,"admin");
	login = create_MyWindow();
	gtk_widget_show(login);
	gtk_widget_hide(current);
}

void
on_logout2_clicked                      (GtkWidget       *graphic,
                                        gpointer         user_data)
{
        GtkWidget *current;
        GtkWidget *login;
        current = lookup_widget(graphic,"kine");
        login = create_MyWindow();
        gtk_widget_show(login);
        gtk_widget_hide(current);
}

void
on_add_clicked                         (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	GtkWidget *add;
	add = create_add();
	gtk_widget_show(add);
}


void
on_add_new_clicked                     (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	char username[20], password[20];
	int role;
	GtkWidget *user_in;
	GtkWidget *pass_in;
	GtkWidget *role_in;
	user_in = lookup_widget(graphic,"n_user");
	pass_in = lookup_widget(graphic,"n_pass");
	role_in = lookup_widget(graphic,"n_role");
	strcpy(username,gtk_entry_get_text(GTK_ENTRY(user_in)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(pass_in)));
	role = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(role_in));
	ajouter (username,password,role);
}


void
on_quit1_clicked                       (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	GtkWidget *current;
	current = lookup_widget(graphic,"add");
	gtk_widget_hide(current);
}


void
on_quit_clicked                        (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	gtk_main_quit();
}


void
on_users_clicked                       (GtkWidget       *graphic,
                                        gpointer         user_data)
{	GtkWidget *userlist;
	GtkWidget *listview;
	userlist = create_userlist();
	gtk_widget_show(userlist);
	listview = lookup_widget(graphic,"users_list");
	afficher(listview);

}


void
on_user_list_exit_clicked              (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	GtkWidget *current;
	current = lookup_widget(graphic,"userlist");
	gtk_widget_hide(current);

}

