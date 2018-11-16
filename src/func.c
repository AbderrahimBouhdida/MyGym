#include<string.h>
#include<stdio.h>
#include<gtk/gtk.h>
#include"func.h"

int verifier(char user[], char pass[],char status[]){
	char user_f[20],pass_f[20];
	int role;
	FILE *f;
	f = fopen("/home/imou/Desktop/projects/mygym/login/src/users.txt","r");
	if(f!=NULL){
		while(fscanf(f,"%s %s %d",user_f,pass_f,&role)!=EOF){
			if(!strcmp(user,user_f) && !strcmp(pass,pass_f)){
				strcpy(status,user);
				fclose(f);
				return role;
			}
		}
		strcpy(status,"Invalid");
		return -1;
	}else{
	strcpy(status,"Fichier introuvable !");
	return -1;
	}

}
void ajouter (char login[],char password[], int role){
        FILE* f;
	f=fopen("/home/imou/Desktop/projects/mygym/login/src/users.txt","a");
	if(f!=NULL){
		 fprintf(f,"%s %s %d\n",login,password,role);
        }
	fclose(f);
}

void afficher (GtkWidget *plistview){
	enum
	 {
	   COL_TOGG,
	   COL_NAME,
	   COL_PASS,
	   COL_ROLE,
	   NUM_COLS
	  };

	GtkListStore *liststore;
	GtkCellRenderer *celrender;
	GtkTreeViewColumn *col;

	liststore = gtk_list_store_new(NUM_COLS, G_TYPE_BOOLEAN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_UINT);
        char login[20],pass[20];
        int role;
        FILE* f;
        f=fopen("/home/imou/Desktop/projects/mygym/login/src/users.txt","r");
        if(f!=NULL){
		while(fscanf(f,"%s %s %d",login,pass,&role)!=EOF){
			GtkTreeIter iter;
			gtk_list_store_append(liststore, &iter);
			gtk_list_store_set (liststore, &iter,
					      COL_TOGG, FALSE,
			                      COL_NAME, login,
			                      COL_PASS, pass,
			                      COL_ROLE, role,
			                      -1);
	                printf("%s %s %d\n",login,pass,role);
	        }
		plistview = gtk_tree_view_new_with_model(GTK_TREE_MODEL(liststore));

		celrender = gtk_cell_renderer_toggle_new();
		col = gtk_tree_view_column_new_with_attributes(" ",celrender,"active",COL_TOGG,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("login",celrender,"text",COL_NAME,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("Password",celrender,"text",COL_NAME,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("role",celrender,"text",COL_NAME,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);


	}
        fclose(f);
}

