#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "admin.h"


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
        current = lookup_widget(graphic,"authentification");
        user_d = lookup_widget(graphic,"login_auth");
        pass_d = lookup_widget(graphic,"pass_auth");
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
                        adherant = create_adherant();
                        gtk_widget_show(adherant);
                        gtk_widget_hide(current);
                        break;
                case 3 :
                        coach = create_bienvenue_coach();
                        gtk_widget_show(coach);
                        gtk_widget_hide(current);
                        break;
                case 4 :
                        diet = create_diet();
                        gtk_widget_show(diet);
                        gtk_widget_hide(current);
                        break;
                case 5 :
                        kine = create_bienvenue_kine();
                        gtk_widget_show(kine);
                        gtk_widget_hide(current);
                        break;
                case 6 :
                        medecin = create_bienvenue_medecin();
                        gtk_widget_show(medecin);
                        gtk_widget_hide(current);
                        break;
                default :
                        gtk_label_set_text(GTK_LABEL(status_d),status);
                        break;
        }
}



void
on_quitter_clicked                     (GtkWidget *graphic,
                                        gpointer         user_data)
{
        gtk_main_quit();
}


void
on_users_clicked                       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_staff_clicked                       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_events_clicked                      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_logout_admin_clicked                (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_users_list_row_activated            (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_retour_userlist_admin_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_supprimer_users_admin_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_modifier_users_admin_clicked        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_ajouter_users_admin_clicked         (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_annuler_users_admin_clicked         (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_annuler_users_del_clicked           (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_confirmer_users_del_clicked         (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_filtre_staff_admin_changed          (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_biebutt_profil_coach_clicked        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_bienbut_sean_coach_clicked          (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_bienbut_fich_coach_clicked          (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_bienbut_listedesadhe_coach_clicked  (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_bienbutt_retour_coach_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_modif_prof_coach_clicked            (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_retour_profil_coach_clicked         (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_treeview_sean_coach_row_activated   (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_annul_sean_coach_clicked            (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_ajout_sean_coach_clicked            (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_modif_sean_coach_clicked            (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_suppr_sean_coach_clicked            (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_retour_sean_coach_clicked           (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_espace_kine_profile_clicked  (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_dispo_espace_kine_clicked    (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_seance_espace_kine_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour__espace_kine_clicked  (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_fiche_med_kine_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_retour_profil_kine_clicked          (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_modifier_profil_kine_clicked        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_treeview_dispo_kine_row_activated   (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_annuler_rdv_kine_clicked     (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_ajouter_rdv_kine_clicked     (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_modifier_rdv_kine_clicked    (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_supprimer_rdv_kine_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_rdv_kine_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_retour_fiche_med_kine_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_retour_seance_kine_clicked          (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_bretour_listead_coach_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_fiche_medicale_medecin_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_dispo_medecin_clicked        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_profil_medecin_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_rendez_vous_medecin_clicked  (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_profil_medecin_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_modifier_profil_medecin_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_treeview_dispo_medecin_row_activated
                                        (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_supp_dispo_medecin_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_modi_dispo_medecin_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_ajouter_dispo_medecin_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_annuler_dispo_medecin_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_dispo_medecin_clicked (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_fiche_medecin_clicked (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_profil_espace_diet_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_dispo_espace_diet_clicked    (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_fm_espace_diet_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_rdv_espace_diet_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_espace_diet_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_supp_dispo_diet_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_ann_dispo_diet_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_mod_dispo_diet_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_ajou_dispo_diet_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_treeview_dispo_diet_row_activated   (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_retour_dispo_diet_clicked    (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_rdv_diet_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_fal_diet_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_retour_profil_diet_clicked   (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_buttonmod_profil_diet_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_adherant_modifier_clicked    (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_adherant_rendezvous_clicked  (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_combobox_choix_staff_changed        (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_combobox7_changed                   (GtkComboBox     *combobox,
                                        gpointer         user_data)
{

}


void
on_button_adherant_retour_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_adherant_valider_clicked     (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_treeview_adherant_evennement_row_activated
                                        (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_adherant_evennement_retour_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_adherant_les_evennement_retour_clicked
                                        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_retour_fich_coach_clicked           (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_fa_espace_diet_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_staff_list_row_activated            (GtkWidget *graphic,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_supprimer_staff_admin_clicked       (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_modifier_staff_admin_clicked        (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_ajouter_staff_admin_clicked         (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_annuler_staff_admin_clicked         (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_retour_stafflist_admin_clicked      (GtkWidget *graphic,
                                        gpointer         user_data)
{

}


void
on_button_adherant_supp_rdv_clicked    (GtkWidget *graphic,
                                        gpointer         user_data)
{

}

