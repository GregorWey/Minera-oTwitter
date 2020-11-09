#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct dados{
	int index;
	char data[26];
	char tweetid[23];
	char tweet[281];
}dados;

int main(){
	FILE *aV= fopen("dadosTweets5.csv","rb");
	FILE *aN= fopen("dadosTratado.csv","wb");
	if((aV == NULL)||(aN==NULL)){
		printf("Erro \n");
	}
	int rowcount=0;
	int fieldcount=0;
	char line[1024];
	dados d;
	while(fgets(line,sizeof(line),aV)){
		rowcount++;
		fieldcount=0;
		if(rowcount == 1){
			continue;
		}
		else{
			char *field = strtok(line,";");
			while(field){
				if(fieldcount==0){
					d.index=atoi(field);
				}
				if(fieldcount==1){
					strcpy(d.data,field);
				}
				if(fieldcount==2){
					strcpy(d.tweetid,field);
				}
				if(fieldcount==3){
					strcpy(d.tweet,field);
				}
			field = strtok(NULL, ";");
			fieldcount++;
			}
		}
		printf("Index: %d  \n Data: %s \n ID Tweet: %s \n Tweet: %s \n ",d.index,d.data,d.tweetid,d.tweet);
		fwrite(&d,sizeof(dados),1,aN);
	}
	fclose(aV);
	fclose(aN);
}
