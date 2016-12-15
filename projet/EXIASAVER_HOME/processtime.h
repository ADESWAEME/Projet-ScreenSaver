#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int process_time(void)
{
	time_t now=time(NULL);
	FILE* fichierst=fopen("stat.txt","r+");
	struct tm tm_now=*localtime(&now);
	char s_now[sizeof "JJ/MM/AAAA HH:MM:SS"];
	strftime (s_now, sizeof s_now, "%d/%m/%Y %H:%M:%S", &tm_now);
	fseek(fichierst, 0,SEEK_END);
	fprintf(fichierst,"%s;", s_now);
	fclose(fichierst);
	return 0;
}
