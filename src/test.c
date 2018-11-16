#include <stdio.h>
#include <string.h>

void main(){
	char user[20],pass[20];
	int role;
	FILE *f;
	f = fopen("users.txt","a+");
	fprintf(f,"hello world 5");
	fclose(f);
	f = fopen("users.txt","a+");
	while(fscanf(f,"%s %s %d",user,pass,&role)!=EOF){
		printf("%s %s %d\n",user,pass,role);
	}
}
