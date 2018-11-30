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
	GtkWidget *current;
	current = lookup_widget(graphic,"userlist");
	add = create_add();
	gtk_widget_show(add);
	gtk_widget_hide(current);
}


void
on_add_new_clicked                     (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	char username[20], password[20],email[20],nom[20],prenom[20],tel[20];
	int r,day,month,year;
	GtkWidget *status;
	GtkWidget *user_in;
	GtkWidget *pass_in;
	GtkWidget *nom_in;
	GtkWidget *prenom_in;
	GtkWidget *tel_in;
	GtkWidget *email_in;
	GtkWidget *jour_in;
	GtkWidget *mois_in;
	GtkWidget *anne_in;
	status = lookup_widget(graphic,"status_add_ad");
	user_in = lookup_widget(graphic,"n_user");
	pass_in = lookup_widget(graphic,"n_pass");
	nom_in = lookup_widget(graphic,"nom_ad");
	prenom_in = lookup_widget(graphic,"prenom_ad");
	tel_in = lookup_widget(graphic,"tel_ad");
	email_in = lookup_widget(graphic,"email_ad");
	jour_in = lookup_widget(graphic,"day_ad");
	mois_in = lookup_widget(graphic,"month_ad");
	anne_in = lookup_widget(graphic,"year_ad");
	strcpy(username,gtk_entry_get_text(GTK_ENTRY(user_in)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(pass_in)));
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(nom_in)));
	strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(prenom_in)));
	strcpy(email,gtk_entry_get_text(GTK_ENTRY(email_in)));
	strcpy(tel,gtk_entry_get_text(GTK_ENTRY(tel_in)));
	day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_in));
	month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois_in));
	year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anne_in));
	ajouter (username,password,nom,prenom,email,tel,day,month,year,2);
}


void
on_quit1_clicked                       (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	GtkWidget *current;
	GtkWidget *plistview;
        GtkWidget *newi;
	newi = create_userlist();
        plistview = lookup_widget(newi,"users_list");
	afficher(plistview,"user");
	current = lookup_widget(graphic,"add");
	gtk_widget_hide(current);
	gtk_widget_show(newi);
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
{
        GtkWidget *plistview;
        GtkWidget *newi;
	newi = create_userlist();
        plistview = lookup_widget(newi,"users_list");
	afficher(plistview,"user");
        gtk_widget_show(newi);
}


void
on_user_list_exit_clicked              (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	GtkWidget *current;
	current = lookup_widget(graphic,"userlist");
	gtk_widget_hide(current);

}

void
on_users_list_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	   gchar *string;
	   GtkTreeIter iter;
	   GtkTreeModel *model = gtk_tree_view_get_model (treeview);
	   gtk_tree_model_get_iter(model, &iter, path);
	   gtk_tree_model_get (model, &iter, 2, &string, -1);
	   printf ("activated: %s\n", string);
}


void
on_staff_clicked                       (GtkWidget	*graphic,
                                        gpointer         user_data)
{
	GtkWidget *plistview;
        GtkWidget *newi;
	newi = create_stafflist();
        plistview = lookup_widget(newi,"treeview2");
	afficher(plistview,"staff");
        gtk_widget_show(newi);
}


void
on_quit_st_clicked                     (GtkWidget	*graphic,
                                        gpointer         user_data)
{
	GtkWidget *current;
	current = lookup_widget(graphic,"staff_add");
	gtk_widget_hide(current);
}


void
on_add_new_st_clicked                  (GtkWidget	*graphic,
                                        gpointer         user_data)
{
	char username[20], password[20],email[20],nom[20],prenom[20],tel[20],r[20];
	int role,day,month,year;
	GtkWidget *user_in;
	GtkWidget *pass_in;
	GtkWidget *nom_in;
	GtkWidget *prenom_in;
	GtkWidget *tel_in;
	GtkWidget *email_in;
	GtkWidget *jour_in;
	GtkWidget *mois_in;
	GtkWidget *anne_in;
	GtkWidget *role_in;
	user_in = lookup_widget(graphic,"username_st");
	pass_in = lookup_widget(graphic,"pass_st");
	nom_in = lookup_widget(graphic,"nom_st");
	prenom_in = lookup_widget(graphic,"prenom_st");
	tel_in = lookup_widget(graphic,"tel_st");
	email_in = lookup_widget(graphic,"email_st");
	jour_in = lookup_widget(graphic,"day_st");
	mois_in = lookup_widget(graphic,"month_st");
	anne_in = lookup_widget(graphic,"year_st");
	role_in = lookup_widget(graphic,"role");
	strcpy(username,gtk_entry_get_text(GTK_ENTRY(user_in)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(pass_in)));
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(nom_in)));
	strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(prenom_in)));
	strcpy(email,gtk_entry_get_text(GTK_ENTRY(email_in)));
	strcpy(tel,gtk_entry_get_text(GTK_ENTRY(tel_in)));
	day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_in));
	month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois_in));
	year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anne_in));
	strcpy(r,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role_in)));
	role = getrole(r);
	if (role!=0)
		ajouter (username,password,nom,prenom,email,tel,day,month,year,role);

}


void
on_add_st_clicked                      (GtkWidget	*graphic,
                                        gpointer         user_data)
{
	GtkWidget *add_st;
	add_st = create_staff_add();
	gtk_widget_show(add_st);
}


void
on_quit_st_list_clicked                (GtkWidget	*graphic,
                                        gpointer         user_data)
{
	GtkWidget *current;
	current = lookup_widget(graphic,"stafflist");
	gtk_widget_hide(current);
}

