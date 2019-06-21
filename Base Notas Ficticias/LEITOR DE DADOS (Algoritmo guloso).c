#include <stdio.h>
#include <math.h>

int main(void){ 
	//Parte de pergar os valores do dados.txt
	
	char url[] = "dados.txt";
	float dado;
	int i=0, quantidade = 0;
	FILE *arq; 
	arq = fopen(url, "r");
 
	if(arq == NULL){
		printf("Erro ao abrir o arquivo\n");
		return 0;
	}
	
	while (!feof(arq)){	
		if(fscanf(arq,"%f", &dado)){
			quantidade = quantidade + 1;
		}
	}
	
	fclose(arq);
	arq = fopen(url, "r");
	
	int vetor[quantidade-1];
	
	while (!feof(arq)){	
		if(fscanf(arq,"%f", &dado)){
			vetor[i] = dado;
			i = i + 1;
		}
	}

	fclose(arq);
	
	//Inicio do algoritmo em si
	
	int troco, a = 1;
    i = 0;
    
    for(;;){
	
    
    printf("Digite o troco: ");
    scanf("%d", &troco);
    
    for(i=0; i<quantidade-1; i++){
		printf("%d nota(s) de R$ %d,00\n", troco/vetor[i], vetor[i]);
    	troco = troco % vetor[i];
    }
	
}
	return 0;
}
