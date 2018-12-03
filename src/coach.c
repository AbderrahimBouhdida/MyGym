
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coach.h"

void ajouter_fiches(char seance[],char date[],char type[])
{
	FILE *f;
	f = fopen("src/seance.txt","a+");
	if(f!=NULL){
		fprintf(f,"%s %s %s\n", seance, date, type);
	}
	fclose(f);

}




void afficher_fiches(GtkWidget *plistview)
{ 
enum { COL_SEANCE,
       COL_DATE,
       COL_TYPE,
       NUM_COLS
      };
char seance[20],date[20],type[20];
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f;
f=fopen("src/seance.txt","r");
if(f!=NULL){
       while(fscanf(f,"%s %s %s",seance,date,type)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_SEANCE, seance,
		          COL_DATE, date,
		          COL_TYPE, type,
                       -1);}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("seance",celrender,"text",COL_SEANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("date",celrender,"text",COL_DATE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("type",celrender,"text",COL_TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);


	gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

}
fclose(f);
}


void afficher_profil(GtkWidget *plistview)
{ 
enum { COL_NOM,
       COL_PRENOM,
       COL_AGE,
       NUM_COLS
      };
char nom[20],prenom[20],age[20];
GtkListStore *liststore;
GtkCellRenderer *celrender;
GtkTreeViewColumn *col;
liststore = gtk_list_store_new(NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
FILE *f;
f=fopen("src/profiles.txt","r");
if(f!=NULL){
       while(fscanf(f,"%s %s %s",nom,prenom,age)!=EOF){
           GtkTreeIter iter;
            gtk_list_store_append(liststore, &iter);
            gtk_list_store_set(liststore, &iter,
                          COL_NOM, nom,
		          COL_PRENOM, prenom,
		          COL_AGE, age,
                       -1);}
	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("nom",celrender,"text",COL_NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("prenom",celrender,"text",COL_PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

	celrender = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes("age",celrender,"text",COL_AGE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);


	gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

}
fclose(f);
}
void modifier_seance_coach(char seance[], char date[], char type[])
{
	char seancek[20],datek[20],typek[20];
	FILE *f , *tmp;
	f=fopen("src/seance.txt","r");
	tmp=fopen("src/seance.tmp","a+");
	while(fscanf(f,"%s %s %s", seancek,datek,typek)!=EOF){
		if(!strcmp(seance,seancek) && !strcmp(date,datek)){
			fprintf(tmp,"%s %s %s\n",seance,date,type);
		}else
		fprintf(tmp,"%s %s %s\n",seancek,datek,typek);
	}
	fclose(f);
	fclose(tmp);
	rename("src/seance.tmp","src/seance.txt");
}










