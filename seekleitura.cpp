#include <stdio.h>
#include <stdlib.h>
typedef struct dados{
	int index;
	char data[26];
	char tweetid[23];
	char tweet[281];
}dados;

int main(){
	int x;
	FILE *arquivo = fopen("dadosTratado.csv","rb");
	if(arquivo==NULL){
		printf("Erro \n");
	}
	printf("Digite o indice que deseja (maximo 10990): \n");
	scanf("%d",&x);
	dados d;
	fseek(arquivo,x*sizeof(dados),SEEK_SET);
	fread(&d,sizeof(dados),1,arquivo);
	printf("Index: %d  \n Data: %s \n ID Tweet: %s \n Tweet: %s \n ",d.index,d.data,d.tweetid,d.tweet);
	
	fclose(arquivo);
}
