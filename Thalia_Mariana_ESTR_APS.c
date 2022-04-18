// APS1 - Estrutura de Dados
// Aluna: Thalía Mariana Martins da Silva

#include <stdio.h>
#include <locale.h>

int vetor_lista[10], vetor_fila[10], vetor_pilha[10], cont_l=0, cont_f=0, cont_p=0;

int insere_elemento_fila(){
    
    int valor, cont;

    if (cont_f > 9){
        printf("\n A fila está cheia. \n");
    }
    else {
        if (cont_f != 0){
            printf("\n Fila atual: ");
            for (cont=0; cont<cont_f; cont++){
                printf("%d, ", vetor_fila[cont]);
            }
        }
        else {
            printf("\n A fila está vazia. \n");
        }
    }

    printf("\n Informe o valor a ser inserido na fila: ");
    scanf("%d", &valor);
    vetor_fila[cont_f] = valor;
    cont_f++;

    printf("\n Fila modificada: ");
    for (cont=0; cont<cont_f; cont++){
        printf("%d, ", vetor_fila[cont]);
    }
}

int exclui_elemento_fila(){

    int cont;

    if (cont_f == 0){
        printf("\n A fila está vazia. \n");
    }
    else {
        printf("\n Fila atual: ");
        for (cont=0; cont<cont_f; cont++){
            printf("%d, ", vetor_fila[cont]);
        }
        
        for (cont=1; cont<=cont_f; cont++){
            vetor_fila[cont-1] = vetor_fila[cont];
        }

        vetor_fila[cont_f] = NULL;
        cont_f--;

        printf("\n Fila modificada: ");
        for (cont=0; cont<cont_f; cont++){
            printf("%d, ", vetor_fila[cont]);
        }

    }

}

int insere_elemento_pilha(){

    int valor, cont;    

    if (cont_p > 9){
        printf("\n A pilha está cheia. \n");
    }
    else {
        if (cont_p != 0){
            printf("\n Pilha atual: ");
            for (cont=0; cont<cont_p; cont++){
                printf("%d, ", vetor_pilha[cont]);
            }
        }
        else {
            printf("\n A pilha está vazia. \n");
        }

        printf("\n Informe o valor a ser inserido na pilha: ");
        scanf("%d", &valor);

        cont = cont_p + 1;

        for (cont; cont>=1; cont--){
            vetor_pilha[cont] = vetor_pilha[cont-1];
        }

        vetor_pilha[0] = valor;
        cont_p++;

        printf("\n Pilha modificada: ");
        for (cont=0; cont<cont_p; cont++){
            printf("%d, ", vetor_pilha[cont]);
        }
    }
}

int exclui_elemento_pilha(){

    int cont;    

    if (cont_p==0){
        printf("\n A pilha está vazia. \n");
    }
    else {
        printf("\n Pilha atual: ");
        for (cont=0; cont<cont_p; cont++){
            printf("%d, ", vetor_pilha[cont]);
        }

        cont_p--;

        for (cont=1; cont<=cont_p; cont++){
            vetor_pilha[cont-1] = vetor_pilha[cont];
        }

        printf("\n Pilha modificada: ");
        for (cont=0; cont<cont_p; cont++){
            printf("%d, ", vetor_pilha[cont]);
        }
    }
}

int insere_elemento_lista(){

    int valor, cont;

    if (cont_l > 9){
        printf("\n A lista está cheia. \n");
    }
    else {
        if (cont_l != 0){
            printf("\n Lista atual: ");
            for (cont=0; cont<cont_l; cont++){
                printf("%d, ", vetor_lista[cont]);
            }
        }
        else {
            printf("\n A lista está vazia. \n");
        }

        printf("\n Informe o valor a ser inserido na lista: ");
        scanf("%d", &valor);
        vetor_lista[cont_l] = valor;
        cont_l++;

        ordena_lista();

        printf("\n Lista modificada: ");
        for (cont=0; cont<cont_l; cont++){
            printf("%d, ", vetor_lista[cont]);
        }       
    }
}

int exclui_elemento_lista(){

    int valor, cont, posicao = 15;

    if (cont_l==0){
        printf("\n A lista está vazia. \n");
    }
    else {
        printf("\n Fila atual: ");
        for (cont=0; cont<cont_l; cont++){
            printf("%d, ", vetor_lista[cont]);
        }

        printf("\n Informe o elemento a ser excluído da lista: ");
        scanf("%d", &valor);

        for (cont=0; cont<cont_l; cont++){
            if (valor == vetor_lista[cont]){
                posicao = cont;
            }
        }
        
        if (posicao != 15){
            for (cont=posicao; cont<cont_l; cont++){
                vetor_lista[cont] = vetor_lista[cont+1];
            }

            cont_l--;
            vetor_lista[cont_l] = NULL;

            printf("\n Fila modificada: ");
            for (cont=0; cont<cont_l; cont++){
                printf("%d, ", vetor_lista[cont]);
            }
        }
        else{
            printf("\n Elemento não encontrado na lista. \n");
        }

    }
}

int ordena_lista(){

    int cont = cont_l, i, aux=0;

    for (cont; cont-1>=0; cont--){
        for (i=0; i<=cont-2; i++){
            if (vetor_lista[i] > vetor_lista[i+1]){
                aux = vetor_lista[i];
                vetor_lista[i] = vetor_lista[i+1];
                vetor_lista[i+1] = aux;
            }
        }
    }
}

int main(){

    int escolha, escolha_estrutura;
    setlocale (LC_ALL, "");

    do {
        printf("\n\n Selecione a estrutura desejada: ");
        printf("\n [1] Lista");
        printf("\n [2] Fila");
        printf("\n [3] Pilha \n");
        scanf("%d", &escolha_estrutura);

        printf("\n\n Selecione a opção desejada: ");
        printf("\n [1] Inclusão");
        printf("\n [2] Exclusão");
        printf("\n [0] Sair \n");
        scanf("%d", &escolha);

        if (escolha_estrutura == 1 && escolha == 1){
            printf("Inclusão em Lista.\n");
            insere_elemento_lista();
        }

        if (escolha_estrutura == 1 && escolha == 2){
            printf("Exclusão em Lista.\n");
            exclui_elemento_lista();
        }

        if (escolha_estrutura == 2 && escolha == 1){
            printf("Inclusão em Fila.\n");
            insere_elemento_fila();
        }

        if (escolha_estrutura == 2 && escolha == 2){
            printf("Exclusão em Fila.\n");
            exclui_elemento_fila();
        }

        if (escolha_estrutura == 3 && escolha == 1){
            printf("Inclusão em Pilha.\n");
            insere_elemento_pilha();
        }

        if (escolha_estrutura == 3 && escolha == 2){
            printf("Exclusão em Pilha.\n");
            exclui_elemento_pilha();
        }
    }

    while(escolha != 0);
}