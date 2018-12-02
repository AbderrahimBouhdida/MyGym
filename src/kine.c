
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kine.h"
#include <gtk/gtk.h>

void ajouter_kine(char nom[],char prenom[],char rdv[])
{
	FILE *f;
	f = fopen("src/rdv.txt","a+");
	if(f!=NULL){
		fprintf(f,"%s %s %s\n", nom, prenom, rdv);
	}
	fclose(f);

}


void afficher_kine(GtkWidget *plistview)
{ 
enum { COL_NOM,
       COL_PRENOM,
       COL_RDV,
       NUM_COLS
      };
char nom[20],prenom[20],rdv[20];
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f;
f=fopen("src/rdv.txt","r");
if(f!=NULL){
       while(fscanf(f,"%s %s %s",nom,prenom,rdv)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_NOM, nom,
		          COL_PRENOM, prenom,
		          COL_RDV, rdv,
                       -1);}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("nom",celrender,"text",COL_NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("prenom",celrender,"text",COL_PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("seance",celrender,"text",COL_RDV,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);


	gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

}
fclose(f);
}
                          

