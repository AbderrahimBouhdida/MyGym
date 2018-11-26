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
void ajouter (char login[],char password[],char nom[],char prenom[],char email[],char tel[],int day,int month,int year, int role){
        FILE* f;
	f=fopen("/home/imou/Desktop/projects/mygym/login/src/users.txt","a");
	if(f!=NULL){
		 fprintf(f,"%s %s %d %s %s %s %s %d %d %d\n",login,password,role,nom,prenom,email,tel,day,month,year);
        }
	fclose(f);
}

void afficher (GtkWidget *plistview, char type[20]){
	enum
	 {
	   COL_TOGG,
	   COL_NAME,
	   COL_PASS,
	   COL_LOGI,
	   COL_PREN,
	   COL_MAIL,
	   COL_NTEL,
	   COL_DATE,
	   COL_ROLE,
	   NUM_COLS
	  };
	char login[20], password[20], nom[20], prenom[20], email[20], tel[20],rolen[20];
	int day, month, year, role;

	GtkListStore *liststore;
	GtkCellRenderer *celrender;
	GtkTreeViewColumn *col;
	liststore = gtk_list_store_new(NUM_COLS, G_TYPE_BOOLEAN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
        FILE* f;
        f=fopen("/home/imou/Desktop/projects/mygym/login/src/users.txt","r");
        if(f!=NULL){
		while(fscanf(f,"%s %s %d %s %s %s %s %d %d %d",login,password,&role,nom,prenom,email,tel,&day,&month,&year)!=EOF){
			GtkTreeIter iter;
			getrolename(role,rolen);
			if(!strcmp(type,"user")){
				if(role != 2 ) continue;
				gtk_list_store_append(liststore, &iter);
				gtk_list_store_set (liststore, &iter,
						      	   COL_TOGG, TRUE,
					              	   COL_NAME, nom,
					              	   COL_PASS, password,
					              	   COL_LOGI, login,
							   COL_PREN, prenom,
							   COL_MAIL, email,
							   COL_NTEL, tel,
							   COL_DATE, "test",
					              -1);
			        //printf("%s %s %d\n",login,pass,role);
			}else{
				if (role == 1 || role == 2) continue;
				gtk_list_store_append(liststore, &iter);
				gtk_list_store_set (liststore, &iter,
						      	   COL_TOGG, TRUE,
					              	   COL_NAME, nom,
					              	   COL_PASS, password,
					              	   COL_LOGI, login,
							   COL_PREN, prenom,
							   COL_MAIL, email,
							   COL_NTEL, tel,
							   COL_DATE, "test",
							   COL_ROLE, rolen,
					              -1);
			}
	        }

		celrender = gtk_cell_renderer_toggle_new();
		col = gtk_tree_view_column_new_with_attributes(" ",celrender,"activatable",COL_TOGG,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("Nom",celrender,"text",COL_NAME,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("Password",celrender,"text",COL_PASS,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("login",celrender,"text",COL_LOGI,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("prenom",celrender,"text",COL_PREN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("email",celrender,"text",COL_MAIL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("Tel",celrender,"text",COL_NTEL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("Date",celrender,"text",COL_DATE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);
		if(strcmp(type,"user")){
			celrender = gtk_cell_renderer_text_new();
	                col = gtk_tree_view_column_new_with_attributes("Role",celrender,"text",COL_ROLE,NULL);
	                gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);
		}

		gtk_tree_view_set_model (GTK_TREE_VIEW(plistview), GTK_TREE_MODEL (liststore));

	}
        fclose(f);
}

int getrole (char role[20]){
	if (!strcmp(role,"Coach")) return 3;
	else if (!strcmp(role,"Dieteticien")) return 4;
	else if (!strcmp(role,"Kine")) return 5;
	else if (!strcmp(role,"Medecin")) return 6;
	else
		return 0;
}

void getrolename(int role, char rolen[]){
	switch(role){
		case 2 : strcpy(rolen,"adherant");break;
		case 3 : strcpy(rolen,"coach");break;
		case 4 : strcpy(rolen,"diet");break;
		case 5 : strcpy(rolen,"kine");break;
		case 6 : strcpy(rolen,"medcin");break;
		default : printf("error");
	}
}
