#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include <iostream>

using namespace std;


void adicionarElementoParaVetorPar(int elemento , int * vetorEntradaInicial , int * posicaoPar,int posicaoVetor);

void adicionarElementoParaVetorImpar(int elemento , int * vetorEntradaInicial, int * posicaoImpar,int posicaoVetor);

void imprimeValoresPares(int * vetorPar, int posicaoPar);

void imprimeValoresImpares(int * vetorImpar, int posicaoImpar);

void ordenacaoPorQuickSort(int *vetorDesordenado, int posicaoInicio, int posicaoFim );

int particiona( int *vetorDesordenado, int posicaoInicio, int posicaoFim);

int main()
{

 int vetorEntradaInicial[30];
 int vetorPar[15];
 int vetorImpar[15];
 int posicaoPar =0; 
 int posicaoImpar=0;
 int numero = 0;
 int qtdNumeros =0;
 int posicao = 0;
 int i = 0;

     cout << "Exercicio 2!!!\n";
     cout << "Nesse Exercício é preciso que você entre com os 30 primeiros números iniciais.\n";
     cout << endl;

     while(qtdNumeros<10){
	 qtdNumeros++;
 	 printf ("Entrada de posição  %d \n",  qtdNumeros);
         scanf("%d", &vetorEntradaInicial[posicao]);
    	 posicao++;
     }

     cout << endl;

     for(i; i < qtdNumeros ; i++){
       if (vetorEntradaInicial[i] %2 == 0) {
       	 adicionarElementoParaVetorPar(vetorEntradaInicial[i] ,vetorPar,&posicaoPar,posicaoPar);
       }else{
         adicionarElementoParaVetorImpar(vetorEntradaInicial[i] , vetorImpar,&posicaoImpar,posicaoImpar);
       }
     }

     ordenacaoPorQuickSort(vetorImpar,0,posicaoImpar);
     ordenacaoPorQuickSort(vetorPar,0,posicaoPar);			
     imprimeValoresPares(vetorPar, posicaoPar);
     cout << endl;
     imprimeValoresImpares(vetorImpar, posicaoImpar);

return 0; 

}

void adicionarElementoParaVetorPar(int elemento, int * vetorPar, int * posicaoPar,int posicaoVetor){
	if(posicaoVetor==15){
		 cout << "O vetor de números pares está cheio!!\n";
	}else{
	         vetorPar[posicaoVetor] = elemento;
		 *posicaoPar=*posicaoPar +1;

	}
	
}
void adicionarElementoParaVetorImpar(int elemento , int * vetorImpar , int * posicaoImpar ,int posicaoVetor){
	if(posicaoVetor==15){
		 cout << "O vetor de números Impares está cheio!!\n";
	}else{
		 vetorImpar[posicaoVetor] = elemento;		
		 *posicaoImpar = *posicaoImpar+1;	
	}
}

void imprimeValoresImpares(int * vetorImpar, int posicaoImpar){
	if(posicaoImpar!=0){   
	    int x = 0;	
 	    int posicaoValorImpar = 1;	
	    for(x ; x  < posicaoImpar ; x++){
		 	cout << "VALOR IMPAR posição("<< posicaoValorImpar <<") : " << vetorImpar[x] << "\n";
			posicaoValorImpar++;
	    }
	}else{
	    cout << "VETOR IMPAR VAZIO!\n";
	}

}

void imprimeValoresPares(int * vetorPar, int posicaoPar){
	if(posicaoPar!=0){ 
	    int j = 0;
	    int posicaoValorPar = 1;	
	    for(j ; j  < posicaoPar ; j++){
		 	cout << "VALOR PAR posição("<< posicaoValorPar <<") : " << vetorPar[j] << "\n";
	     		posicaoValorPar++;	
	    }
	}else{
	    cout << "VETOR PAR VAZIO!\n";
	}

}

void ordenacaoPorQuickSort( int *vetorDesordenado, int posicaoInicio, int posicaoFim )
{
   int pivot;
   if (posicaoInicio < posicaoFim) 
   {
      pivot = particiona( vetorDesordenado, posicaoInicio, posicaoFim);
      ordenacaoPorQuickSort( vetorDesordenado, posicaoInicio, pivot);
      ordenacaoPorQuickSort(vetorDesordenado, pivot+1, posicaoFim);
   }
}

int particiona( int *vetorDesordenado, int posicaoInicio, int posicaoFim )
{
   int x,i,j,auxiliar;
   x = vetorDesordenado[posicaoInicio];
   i = posicaoInicio - 1;
   j = posicaoFim + 1;
   
   for(;;) 
   {
      do { j--; } while( vetorDesordenado[j] > x );
      do { i++; } while( vetorDesordenado[i] < x );
      
      if (i < j) 
      {
         auxiliar = vetorDesordenado[i];
         vetorDesordenado[i] = vetorDesordenado[j];
         vetorDesordenado[j] = auxiliar;
      }
      else
      {
         return j;
      }
   }
}


