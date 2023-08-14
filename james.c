#include <stdio.h>

void acha_sequencia(char*lista, int);

int main(){
    // entradas
    int n;
    scanf("%d", &n);
    int size; //biggest size possible = 2*n + (n - 1) -- all 10s
    size = 2*n + (n-1);
    char lista_pix[size + 1];
    scanf(" %[^\n]", lista_pix);
    int i, s5=0, s7=0, s10=0;
    for(i = 0; i < size; i++){
        if(lista_pix[i] == '\0'){
            break;
        } else if(lista_pix[i] == '5'){
            s5++;
            continue;
        } else if(lista_pix[i] == '7'){
            s7++;
            continue;
        } else if(lista_pix[i] == '1'){
            s10++;
            continue;
        }
    }
    printf("James vendeu %d saladas de 5 reais, %d de 7 reais e %d de 10 reais.\n", s5, s7, s10);
    acha_sequencia(lista_pix, size);

    return 0;
}

void acha_sequencia(char lista[], int size){
    int i, contagem_recorde=1, contagem=1;
    char preco_recorde=lista[0], preco=lista[0];
    for(i = 1; i < size; i++){
        if(lista[i] == ' ' || lista[i] == '0' && lista[i+1]!='\0'){
            continue;
        } else if(lista[i] == preco){
            contagem++;
        } else{
            if(contagem > contagem_recorde){
                contagem_recorde = contagem;
                preco_recorde = preco;
            }
            preco = lista[i];
            contagem = 1;
        }

    }
    int recorde;
    switch (preco_recorde){
        case '1':
        recorde = 10;
        break;
        case '5':
        recorde = 5;
        break;
        case '7':
        recorde = 7;
        break;
    }

    printf("James vendeu %d saladas de %d reais consecutivamente.\n", contagem_recorde, recorde);

}