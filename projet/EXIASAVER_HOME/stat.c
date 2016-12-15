#include <stdio.h>
#include <stdlib.h>
#include "triabulle.h"
int main (void)
{
	FILE* fichierst=fopen("stat.txt","r");
	char ligne[80];
	int n=0;
	int d=0;
	int s=0;
	int i=0;
	int dp=0;
	int sp=0;
	int ip=0;
	int tab[3];
	int choixmenu;
	while(fgets(ligne,255,fichierst)!=NULL){
		for(n=0;n<80;n++){
			if(ligne[n]==':'||ligne[n]==';'||ligne[n]=='0'||ligne[n]=='1'||ligne[n]=='2'||ligne[n]=='3'||ligne[n]=='4'||ligne[n]=='5'||ligne[n]=='6'||ligne[n]=='7'||ligne[n]=='8'||ligne[n]=='9'||ligne[n]==' '||ligne[n]=='x'||ligne[n]=='/')
			{
				printf("%c",ligne[n]);
			}
		}
		if(ligne[20]=='1'){s++;}
		if(ligne[20]=='2'){d++;}
		if(ligne[20]=='3'){i++;}
		printf("\n");
	}
	printf("\n vous voullez savoir quel ScreenSaver à été lancé le plus de fois?\n");
	printf("1:en chiffre\n");
	printf("2:en pourcentage\n");
	sp=(s*100)/(d+i+s);
	dp=(d*100)/(d+i+s);
	ip=(i*100)/(d+i+s);
	tab[0] = s;
	tab[1] = d;
	tab[2] = i;
	triabulle(tab,3);
	scanf("%d",&choixmenu);
	switch (choixmenu)
	{
		case 1:
			for(n=0;n<3;n++){
				if(tab[n]==s){printf("statique : %d \n",s);}
				if(tab[n]==d){printf("dynamique : %d \n",d);}
				if(tab[n]==i){printf("intéractif : %d \n",i);}
			}
			break;
		case 2:
			for(n=0;n<3;n++){
				if(tab[n]=s){printf("statique : %dpc \n",sp);}
				if(tab[n]=d){printf("dynamique : %dpc \n",dp);}
				if(tab[n]=i){printf("intéractif : %dpc \n",ip);}
			}
			break;
		default:break;
	}
	fclose(fichierst);
	return 0;
}
