#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct dados{
	int index;
	char data[26];
	char tweetid[23];
	char tweet[280];
}dados;
int main(){
	dados d[1];
	FILE *arquivo = fopen("dadosTweets5.csv","rb");
	if(arquivo == NULL){
		printf("Deu bagual");
	}
	int rowcount=0;
	int fieldcount=0;
	char line[1024];
	int contadores[9];
	float percentuais[9];
	for(int j=0;j<9;j++){
		 contadores[j]=0;;
	}
	while(fgets(line,sizeof(line),arquivo)){
		rowcount++;
		fieldcount=0;
		if(rowcount == 1){
			continue;
		}
		else{
			char *field = strtok(line,";");
			while(field){
				if(fieldcount==0){
					d[0].index=atoi(field);
				}
				if(fieldcount==1){
					strcpy(d[0].data,field);
				}
				if(fieldcount==2){
					strcpy(d[0].tweetid,field);
				}
				if(fieldcount==3){
					strcpy(d[0].tweet,field);
					int length;
					length=strlen(d[0].tweet);
					for(int i=0;i<length;i++){
						field[i]=tolower(field[i]);
					}
					if(strstr(field,"boulos")!=NULL){
						contadores[0]++;
					}
					if(strstr(field,"covas")!=NULL){
						contadores[1]++;
					}
					if(strstr(field,"russomanno")!=NULL){
						contadores[2]++;
					}
					if(strstr(field,"marcio franca")!=NULL){
						contadores[3]++;
					}
					if(strstr(field,"jilmar tatto")!=NULL){
						contadores[4]++;
					}
					if(strstr(field,"arthur do val")!=NULL){
						contadores[5]++;
					}
					if(strstr(field,"joice hasselmann")!=NULL){
						contadores[6]++;
					}
					if(strstr(field,"levy fidelix")!=NULL){
						contadores[7]++;
					}
					if(strstr(field,"andrea matarazzo")!=NULL){
						contadores[8]++;
					}
				}
			field = strtok(NULL, ";");
			fieldcount++;
			}
			printf("Index: %d  \n Data: %s \n ID Tweet: %s \n Tweet: %s \n ",d[0].index,d[0].data,d[0].tweetid,d[0].tweet);
		}
	
	}	
	rowcount-=2;
	printf("Linhas: %d \n",rowcount);
	for(int j=0;j<9;j++){
		percentuais[j]=(contadores[j]*100)/rowcount;
	}
	printf("BOULOS \n Mencoes: %d \n Porcentagem %.2f%% \n",contadores[0],percentuais[0]);
	fclose(arquivo);
	printf("BRUNO COVAS \n Mencoes: %d \n Porcentagem %.2f%% \n",contadores[1],percentuais[1]);
	fclose(arquivo);
	printf("CELSO RUSSOMANNO \n Mencoes: %d \n Porcentagem %.2f%% \n",contadores[2],percentuais[2]);
	fclose(arquivo);
	printf("MARCIO FRANCA \n Mencoes: %d \n Porcentagem %.2f%% \n",contadores[3],percentuais[3]);
	fclose(arquivo);
	printf("JILMAR TATTO \n Mencoes: %d \n Porcentagem %.2f%% \n",contadores[4],percentuais[4]);
	fclose(arquivo);
	printf("ARTHUR DO VAL \n Mencoes: %d \n Porcentagem %.2f%% \n",contadores[5],percentuais[5]);
	fclose(arquivo);
	printf("JOICE HASSELMANN \n Mencoes: %d \n Porcentagem %.2f%% \n",contadores[6],percentuais[6]);
	fclose(arquivo);
	printf("LEVY FIDELIX \n Mencoes: %d \n Porcentagem %.2f%% \n",contadores[7],percentuais[7]);
	fclose(arquivo);
	printf("ANDREA MATARAZZO \n Mencoes: %d \n Porcentagem %.2f%% \n",contadores[8],percentuais[8]);
	fclose(arquivo);
}
