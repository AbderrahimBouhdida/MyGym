int verifier(char user[], char pass[], char status[]);
void afficher (GtkWidget *listbox, char type[20]);
void ajouter (char cin[],char login[],char password[],char nom[],char prenom[],char email[],char tel[],int day,int month,int year, int role);
int getrole (char role[]);
void getrolename(int role, char rolen[]);
void moduser(char cin[],char name[],char prenom[],char login[],char pass[],char tel[],char email[]);
void deluser(char cin[]);
void del_users(char path[]);
