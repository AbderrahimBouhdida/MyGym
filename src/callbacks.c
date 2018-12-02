#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "func.h"
#include "kine.h"

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
	GtkWidget *coach;
	GtkWidget *adherant;
	GtkWidget *medecin;
	GtkWidget *diet;
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
			/*adherant = create_adherant();
			gtk_widget_show(adherant);
			gtk_widget_hide(current);*/
			break;
		case 3 :
			/*coach = create_coach();
			gtk_widget_show(coach);
			gtk_widget_hide(current);*/
			break;
		case 4 :
			/*diet = create_diet();
			gtk_widget_show(diet);
			gtk_widget_hide(current);*/
			break;
		case 5 :
			kine = create_kine();
			gtk_widget_show(kine);
			gtk_widget_hide(current);
			break;
		case 6 :
			/*medecin = create_medecin();
			gtk_widget_show(medecin);
			gtk_widget_hide(current);*/
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
	add = create_add();
	gtk_widget_show(add);
}


void
on_add_new_clicked                     (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	char username[20], password[20],email[20],nom[20],prenom[20],tel[20],cin[20];
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
	GtkWidget *cin_in;
	GtkWidget *newi;
	GtkWidget *plistview;
	//newi = lookup_widget(graphic,"userlist");
        //plistview = lookup_widget(newi,"users_list");
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
	cin_in = lookup_widget(graphic,"cin_ad");
	strcpy(username,gtk_entry_get_text(GTK_ENTRY(user_in)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(pass_in)));
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(nom_in)));
	strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(prenom_in)));
	strcpy(email,gtk_entry_get_text(GTK_ENTRY(email_in)));
	strcpy(cin,gtk_entry_get_text(GTK_ENTRY(cin_in)));
	strcpy(tel,gtk_entry_get_text(GTK_ENTRY(tel_in)));
	day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_in));
	month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois_in));
	year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anne_in));
	ajouter (cin,username,password,nom,prenom,email,tel,day,month,year,2);
	/*afficher(plistview,"user");
	gtk_widget_hide(newi);
	gtk_widget_show(newi);*/
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
	GtkWidget *modcin,*moduser,*modname,*modprenom,*modlogin,*modpass,*modtel,*modemail;
	gchar *name,*prenom,*login,*pass,*tel,*email,*cin;
	moduser = create_mod_user();
	modcin = lookup_widget(moduser,"mod_cin");
	modname = lookup_widget(moduser,"mod_name");
	modprenom = lookup_widget(moduser,"mod_prenom");
	modlogin = lookup_widget(moduser,"mod_login");
	modpass = lookup_widget(moduser,"mod_pass");
	modtel = lookup_widget(moduser,"mod_tel");
	modemail = lookup_widget(moduser,"mod_email");
	GtkTreeIter iter;
	GtkTreeModel *model = gtk_tree_view_get_model (treeview);
	gtk_tree_model_get_iter(model, &iter, path);
	gtk_tree_model_get (model, &iter, 1, &cin ,2, &name,3, &pass, 4, &login, 5, &prenom, 6, &email, 7, &tel, -1);
	printf("%s %s %s %s %s %s %s",cin,name,prenom,login,pass,tel,email); 
	gtk_entry_set_text (GTK_ENTRY (modcin), _(cin));
	gtk_entry_set_text (GTK_ENTRY (modname), _(name));
	gtk_entry_set_text (GTK_ENTRY (modprenom), _(prenom));
	gtk_entry_set_text (GTK_ENTRY (modlogin), _(login));
	gtk_entry_set_text (GTK_ENTRY (modpass), _(pass));
	gtk_entry_set_text (GTK_ENTRY (modtel), _(tel));
	gtk_entry_set_text (GTK_ENTRY (modemail), _(email));
	gtk_widget_show(moduser);
	printf ("activated: %s\n", name);
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
	char cin[20],username[20], password[20],email[20],nom[20],prenom[20],tel[20],r[20];
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
	GtkWidget *cin_in;
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
	cin_in = lookup_widget(graphic,"cin_st");
	strcpy(username,gtk_entry_get_text(GTK_ENTRY(user_in)));
	strcpy(password,gtk_entry_get_text(GTK_ENTRY(pass_in)));
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(nom_in)));
	strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(prenom_in)));
	strcpy(email,gtk_entry_get_text(GTK_ENTRY(email_in)));
	strcpy(tel,gtk_entry_get_text(GTK_ENTRY(tel_in)));
	strcpy(cin,gtk_entry_get_text(GTK_ENTRY(cin_in)));
	day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour_in));
	month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois_in));
	year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(anne_in));
	strcpy(r,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role_in)));
	role = getrole(r);
	if (role!=0)
		ajouter (cin,username,password,nom,prenom,email,tel,day,month,year,role);

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


void
on_mod_user_btn_clicked                (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	GtkWidget *current,*modcin,*modname,*modprenom,*modlogin,*modpass,*modtel,*modemail;
	char name[20],prenom[20],login[20],pass[20],tel[20],email[20],cin[20];
	modcin = lookup_widget(graphic,"mod_cin");
	modname = lookup_widget(graphic,"mod_name");
	modprenom = lookup_widget(graphic,"mod_prenom");
	modlogin = lookup_widget(graphic,"mod_login");
	modpass = lookup_widget(graphic,"mod_pass");
	modtel = lookup_widget(graphic,"mod_tel");
	modemail = lookup_widget(graphic,"mod_email");
	strcpy(cin,gtk_entry_get_text(GTK_ENTRY(modcin)));
	strcpy(name,gtk_entry_get_text(GTK_ENTRY(modname)));
	strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(modprenom)));
	strcpy(login,gtk_entry_get_text(GTK_ENTRY(modlogin)));
	strcpy(pass,gtk_entry_get_text(GTK_ENTRY(modpass)));
	strcpy(tel,gtk_entry_get_text(GTK_ENTRY(modtel)));
	strcpy(email,gtk_entry_get_text(GTK_ENTRY(modemail)));
	moduser(cin,name,prenom,login,pass,tel,email);
	current = lookup_widget(graphic,"mod_user");
	gtk_widget_hide(current);
}


void
on_mod_user_exit_clicked               (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	GtkWidget *current;
	current = lookup_widget(graphic,"mod_user");
	gtk_widget_hide(current);
}


void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkWidget *modcin,*modst,*modname,*modprenom,*modlogin,*modpass,*modtel,*modemail;
	gchar *name,*prenom,*login,*pass,*tel,*email,*cin;
	modst = create_mod_st();
	modcin = lookup_widget(modst,"mod_cin_st");
	modname = lookup_widget(modst,"mod_name_st");
	modprenom = lookup_widget(modst,"mod_prenom_st");
	modlogin = lookup_widget(modst,"mod_login_st");
	modpass = lookup_widget(modst,"mod_pass_st");
	modtel = lookup_widget(modst,"mod_tel_st");
	modemail = lookup_widget(modst,"mod_email_st");
	GtkTreeIter iter;
	GtkTreeModel *model = gtk_tree_view_get_model (treeview);
	gtk_tree_model_get_iter(model, &iter, path);
	gtk_tree_model_get (model, &iter, 1, &cin ,2, &name,3, &pass, 4, &login, 5, &prenom, 6, &email, 7, &tel, -1);
	printf("%s %s %s %s %s %s %s",cin,name,prenom,login,pass,tel,email); 
	gtk_entry_set_text (GTK_ENTRY (modcin), _(cin));
	gtk_entry_set_text (GTK_ENTRY (modname), _(name));
	gtk_entry_set_text (GTK_ENTRY (modprenom), _(prenom));
	gtk_entry_set_text (GTK_ENTRY (modlogin), _(login));
	gtk_entry_set_text (GTK_ENTRY (modpass), _(pass));
	gtk_entry_set_text (GTK_ENTRY (modtel), _(tel));
	gtk_entry_set_text (GTK_ENTRY (modemail), _(email));
	gtk_widget_show(modst);
}


void
on_mod_st_exit_clicked                 (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	GtkWidget *current;
	current = lookup_widget(graphic,"mod_st");
	gtk_widget_hide(current);
}


void
on_mod_st_btn_clicked                  (GtkWidget       *graphic,
                                        gpointer         user_data)
{
	GtkWidget *current,*modcin,*modname,*modprenom,*modlogin,*modpass,*modtel,*modemail;
	char name[20],prenom[20],login[20],pass[20],tel[20],email[20],cin[20];
	modcin = lookup_widget(graphic,"mod_cin_st");
	modname = lookup_widget(graphic,"mod_name_st");
	modprenom = lookup_widget(graphic,"mod_prenom_st");
	modlogin = lookup_widget(graphic,"mod_login_st");
	modpass = lookup_widget(graphic,"mod_pass_st");
	modtel = lookup_widget(graphic,"mod_tel_st");
	modemail = lookup_widget(graphic,"mod_email_st");
	strcpy(cin,gtk_entry_get_text(GTK_ENTRY(modcin)));
	strcpy(name,gtk_entry_get_text(GTK_ENTRY(modname)));
	strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(modprenom)));
	strcpy(login,gtk_entry_get_text(GTK_ENTRY(modlogin)));
	strcpy(pass,gtk_entry_get_text(GTK_ENTRY(modpass)));
	strcpy(tel,gtk_entry_get_text(GTK_ENTRY(modtel)));
	strcpy(email,gtk_entry_get_text(GTK_ENTRY(modemail)));
	moduser(cin,name,prenom,login,pass,tel,email);
	current = lookup_widget(graphic,"mod_st");
	gtk_widget_hide(current);
}

void
on_ajouter_rdv_kine_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *a,*b,*c,*ajouter_seance_kine,*sceance_kine,*List_view;
	char nom[20],prenom[20],rdv[20];
	sceance_kine = create_sceance_kine();
	ajouter_seance_kine = lookup_widget(objet_graphique,"ajouter_seance_kine");
	a=lookup_widget(objet_graphique,"entry3");
	b=lookup_widget(objet_graphique,"entry4");
	c=lookup_widget(objet_graphique,"entry5");
	strcpy(nom,gtk_entry_get_text(GTK_ENTRY(a)));
	strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(b)));
	strcpy(rdv,gtk_entry_get_text(GTK_ENTRY(c)));
	ajouter_kine(nom,prenom,rdv);
	List_view=lookup_widget(sceance_kine,"treeview1");
	afficher_kine(List_view);
	gtk_widget_show(sceance_kine);
	gtk_widget_hide(ajouter_seance_kine);
	
}

void
on_retour_profil_kine_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *kine,*profile_kine;
kine=create_kine();
gtk_widget_show (kine);
profile_kine=lookup_widget(objet_graphique,"profile_kine");
gtk_widget_hide(profile_kine);
}

void
on_ajouter_seance_kine_clicked         (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *sceance_kine,*ajouter_sceance_kine;
sceance_kine=lookup_widget(objet_graphique,"sceance_kine");
ajouter_sceance_kine=create_ajouter_seance_kine();
gtk_widget_show(ajouter_sceance_kine);
gtk_widget_hide(sceance_kine);
}

void
on_retour_seance_kine_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *kine,*sceance_kine;
kine=create_kine();
gtk_widget_show (kine);
sceance_kine=lookup_widget(objet_graphique,"sceance_kine");
gtk_widget_hide(sceance_kine);
}


void
on_afficher_profile_espace_kine_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *kine,*profile_kine;
profile_kine=create_profile_kine();
gtk_widget_show (profile_kine);
kine=lookup_widget(objet_graphique,"kine");
gtk_widget_hide(kine);
}


void
on_ajouter_seance_espace_kine_clicked  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *sceance_kine,*kine,*List_view;
sceance_kine=create_sceance_kine();
kine=lookup_widget(objet_graphique, "kine");
gtk_widget_hide(kine);
List_view=lookup_widget(sceance_kine,"treeview1");
afficher_kine(List_view);
gtk_widget_show(sceance_kine);
}


void
on_retour_espace_kine_clicked           (GtkWidget       *objet_graphique2,
                                        gpointer         user_data)
{
	GtkWidget *MyWindow,*kine;
	kine=lookup_widget(objet_graphique2,"kine");
	MyWindow=create_MyWindow();
	gtk_widget_show(MyWindow);
	gtk_widget_hide(kine);
}

