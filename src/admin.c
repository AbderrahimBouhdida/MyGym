#include<string.h>
#include<stdio.h>
#include<gtk/gtk.h>
#include"admin.h"

int verifier(char user[], char pass[],char status[]){
	char user_f[20],pass_f[20],cin[20],nom[100],prenom[100],email[100],tel[100],sexe[100];
	int role,age,poid,taill;
	FILE *f;
	f = fopen("src/data/users.txt","r");
	if(f!=NULL){
		while(fscanf(f,"%s %s %s %d %s %s %d %s %s %s %d %d",cin,user_f,pass_f,&role,nom,prenom,&age,sexe,email,tel,&poid,&taill)!=EOF){
			printf("%d \n",role );
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
void ajouter (char cin[],char login[],char password[],char nom[],char prenom[],char email[],char tel[],int day,int month,int year, int role){
        FILE* f;
	f=fopen("src/data/users.txt","a");
	if(f!=NULL){
		 fprintf(f,"%s %s %s %d %s %s %s %s %d %d %d\n",cin,login,password,role,nom,prenom,email,tel,day,month,year);
        }
	fclose(f);
}

void afficher (GtkWidget *plistview, char type[20]){
	enum
	 {
	   COL_TOGG,
	   COL_CIN,
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
	char login[20], password[20], nom[20], prenom[20], email[20], tel[20],rolen[20],cin[20];
	int day, month, year, role;

	GtkListStore *liststore;
	GtkCellRenderer *celrender;
	GtkTreeViewColumn *col;
	GtkTreeSelection *selection;
	liststore = gtk_list_store_new(NUM_COLS, G_TYPE_BOOLEAN, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING);
        FILE* f;
        f=fopen("src/data/users.txt","r");
        if(f!=NULL){
		while(fscanf(f,"%s %s %s %d %s %s %s %s %d %d %d",cin, login,password,&role,nom,prenom,email,tel,&day,&month,&year)!=EOF){
			GtkTreeIter iter;
			getrolename(role,rolen);
			if(!strcmp(type,"user")){
				if(role != 2 ) continue;
				gtk_list_store_append(liststore, &iter);
				gtk_list_store_set (liststore, &iter,
						      	   COL_TOGG, FALSE,
							   COL_CIN, cin,
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
						      	   COL_TOGG, FALSE,
							   COL_CIN, cin,
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
		void toggled_func(GtkCellRendererToggle *cell_renderer, gchar *path, gpointer user_data){ 
		        GtkTreeIter iter;
		    	GtkTreePath *ppath;
		    	gboolean boolean;
			gchar *cin;
			// convertir la chaine path en GtkTreePath

		     	ppath = gtk_tree_path_new_from_string (path);

			// convertir la valeure recuperée en GtkTreeIter
		     	gtk_tree_model_get_iter (GTK_TREE_MODEL (user_data),
								   &iter,
								   ppath);
			//  utiliser la variable GtkTreeIter pour acceder la valeure booleaine
		     	gtk_tree_model_get (GTK_TREE_MODEL (user_data),
								   &iter,
								   COL_TOGG,&boolean,
								   -1);
			//get data
			gtk_tree_model_get (GTK_TREE_MODEL (user_data),
                                                                   &iter,
                                                                   COL_CIN,&cin,
                                                                   -1);

			// changer cette valeure booleaine (! boolean )
		     	gtk_list_store_set (user_data, &iter,
								   COL_TOGG, !boolean,
								   -1);
			//delete
			//deluser(cin);
			
		}

		celrender = gtk_cell_renderer_toggle_new();
		col = gtk_tree_view_column_new_with_attributes(" ",celrender,"active",COL_TOGG,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		g_signal_connect(G_OBJECT(celrender), "toggled", (GCallback)toggled_func, liststore);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("Cin",celrender,"text",COL_CIN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("Nom",celrender,"text",COL_NAME,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("prenom",celrender,"text",COL_PREN,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("login",celrender,"text",COL_LOGI,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(plistview),col);

		celrender = gtk_cell_renderer_text_new();
		col = gtk_tree_view_column_new_with_attributes("Password",celrender,"text",COL_PASS,NULL);
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
		//g_signal_connect(G_OBJECT(celrender), "toggled", (GCallback)toggled_func, liststore);
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

void moduser(char cin[],char name[],char prenom[],char login[],char pass[],char tel[],char email[]){
	char cin_o[20], login_o[20],password_o[20],nom_o[20],prenom_o[20],email_o[20],tel_o[20];
	int role_o,day,month,year;	
	FILE *f,*tmp;
        f=fopen("src/data/users.txt","r");
	tmp=fopen("src/data/users.tmp","a+");
	while(fscanf(f,"%s %s %s %d %s %s %s %s %d %d %d",cin_o, login_o,password_o,&role_o,nom_o,prenom_o,email_o,tel_o,&day,&month,&year)!=EOF){
		if(!strcmp(cin,cin_o)){
			fprintf(tmp,"%s %s %s %d %s %s %s %s %d %d %d\n",cin,login,pass,role_o,name,prenom,email,tel,day,month,year);	
		}else
		fprintf(tmp,"%s %s %s %d %s %s %s %s %d %d %d\n",cin_o, login_o,password_o,role_o,nom_o,prenom_o,email_o,tel_o,day,month,year);
	}
	fclose(f);
	fclose(tmp);
	rename("src/data/users.tmp","src/data/users.txt");
}

void deluser(char cin[]){
	char cin_o[20], login_o[20],password_o[20],nom_o[20],prenom_o[20],email_o[20],tel_o[20];
	int role_o,day,month,year;
	FILE *f,*tmp;
        f=fopen("src/data/users.txt","r");
	tmp=fopen("src/data/users.tmp","a+");
	while(fscanf(f,"%s %s %s %d %s %s %s %s %d %d %d",cin_o, login_o,password_o,&role_o,nom_o,prenom_o,email_o,tel_o,&day,&month,&year)!=EOF){
		if(!strcmp(cin,cin_o))
			continue;
		fprintf(tmp,"%s %s %s %d %s %s %s %s %d %d %d\n",cin_o, login_o,password_o,role_o,nom_o,prenom_o,email_o,tel_o,day,month,year);
	}
	fclose(f);
	fclose(tmp);
	rename("src/data/users.tmp","src/data/users.txt");
}
void del_users(char path[]){
	FILE *f;
	char cin[20];
	f=fopen("src/data/todel.txt","r");
	if(f!=NULL){
		while(fscanf(f,"%s",cin)!=EOF){
			deluser(cin);
		}
	}
	fclose(f);
	remove("src/data/todel.txt");
}

