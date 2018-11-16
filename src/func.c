#include<string.h>
#include<stdio.h>
#include<gtk/gtk.h>
#include"func.h"

int verifier(char user[], char pass[],char status[]){
	char user_f[20],pass_f[20];
	int role;
	FILE *f;
	f = fopen("/home/youssef/Desktop/MyGym/src/users.txt","r");
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

void afficher (GtkWidget *listbox){
	enum
	 {
	   COL_NAME,
	   COL_PASS,
	   COL_ROLE,
	   NUM_COLS
	  };

	GtkTreeIter   iter;

	listbox = gtk_list_store_new(NUM_COLS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_UINT);
        char login[20],pass[20];
        int role;
        FILE* f;
        f=fopen("/home/imou/Desktop/projects/mygym/login/src/users.txt","r");
        if(f!=NULL){
		while(fscanf(f,"%s %s %d",login,pass,&role)!=EOF){
			gtk_list_store_append(listbox, &iter);
			gtk_list_store_set (listbox, &iter,
                      COL_NAME, login,
                      COL_PASS, pass,
                      COL_ROLE, role,
                      -1);
	                printf("%s %s %d\n",login,pass,role);
	        }
	}
        fclose(f);
}

