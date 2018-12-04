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

void
on_mod_user_btn_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_mod_user_exit_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_mod_st_exit_clicked                 (GtkWidget       *graphic,
                                        gpointer         user_data);

void
on_mod_st_btn_clicked                  (GtkWidget       *graphic,
                                        gpointer         user_data);

void
on_ajouter_rdv_kine_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_retour_profil_kine_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_ajouter_seance_kine_clicked         (GtkWidget      *objet_graphique,
                                        gpointer         user_data);


void
on_retour_seance_kine_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_afficher_profile_espace_kine_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_ajouter_seance_espace_kine_clicked  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);


void
on_retour_espace_kine_clicked           (GtkWidget       *objet_graphique2,
                                        gpointer         user_data);
void
on_treeview1_row_activated_kine_seance (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_retour_modifier_clicked             (GtkWidget       *graphic,
                                        gpointer         user_data);

void
on_modifier_sceance_kine_clicked       (GtkWidget       *graphic,
                                        gpointer         user_data);


//coach 
void
on_bcoach_profil_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_bcoach_dispo_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_bcoach_retour_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_bcoach_seance_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_bAjout_clicked                      (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_c_ajout_clicked                     (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_c_retour_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_coach_bretour_clicked               (GtkWidget      *objet_graphique,
                                        gpointer         user_data);

void
on_coach_butmodifier_clicked           (GtkWidget      *graphic,
                                        gpointer         user_data);

void
on_buttretour_modi_coach_clicked       (GtkWidget       *graphic,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_coach_seanceretour_clicked          (GtkWidget      *graphic,
                                        gpointer         user_data);
void
on_supprimer_s_coach_clicked           (GtkWidget       *graphic,
                                        gpointer         user_data);

