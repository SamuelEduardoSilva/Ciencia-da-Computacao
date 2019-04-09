#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct no
{
    int dado;
    struct no *prox;
    struct no *ant;
};

typedef struct
{
    struct no *inicio;
    struct no *fim;
}lista;

void create(lista *q)
{
    q->inicio=NULL;
}

int isEmpty(lista q)
{
    if (q.inicio==NULL)
        return (1);
    else
        return (0);
}

int size(lista q)
{
    struct no *aux;
    int cont = 0;
    aux = q.inicio;
    if(!isEmpty(q))
    {
        if(aux!=q.fim)
        {
            do
            {
                cont++;
                aux = aux->prox;
            }while(aux != q.inicio);
        }
        else
            cont = 1;
    }

    return cont;

}

void insert(lista *q, int d,int op,int pos)
{
    struct no *aux;
    aux= (struct no *) malloc(sizeof(struct no));
    aux->dado = d;
    if (q->inicio == NULL)
    {
        q->inicio = aux;
        q->fim = aux;
        aux->ant = aux;
        aux->prox = aux;
        return;
    }
    if (op == 1)
    {
        aux->prox = q->inicio;
        q->fim->prox = aux;
        q->inicio = aux;
        aux->ant = q->fim;

    }
    else if(op == 2)
    {
        int cont = 1;
        struct no *atual  = q->inicio;
        struct no *anterior = NULL;

        while(cont<pos)
        {
            anterior = atual;
            atual = atual->prox;
            cont++;
        }
        anterior->prox = aux;
        aux->ant = anterior;
        aux->prox = atual;
        atual->ant = aux;
    }
    else
    {
        q->fim->prox = aux;
        aux->ant = q->fim;
        q->fim  = aux;
        aux->prox = q->inicio;
        q->inicio->ant = aux;

    }
}

void imprime(lista q)
{
        struct no *aux;
        if (!isEmpty(q))
        {
            aux = q.inicio;
            if (aux != q.fim)
            {
                do
                {
                    printf("%d ", aux->dado);
                    aux = aux->prox;
                } while (aux != q.inicio);
            }
            else
                printf("%d", aux->dado);
        }
        else
            printf("Lista Vazia!\n");
}

void remover(lista *q, int d,int pos)
{
        struct no *aux, *atual, *anterior;
        if(d == 1)
        {
            aux = q->inicio;
            if (q->inicio == q->fim)
            {
                q->inicio = NULL;
                q->fim = NULL;
            }
            else
            {
                q->inicio = q->inicio->prox;
                q->fim->prox = q->inicio;
                q->inicio->ant = aux->ant;
            }
            free(aux);
        }
        else if(d == 2)
        {
            aux = q->fim;
            aux->ant->prox = q->inicio;
            q->fim = aux->ant;
            q->inicio->ant = aux->ant;
            free(aux);
        }
        else
        {
            if(pos == 1)
                remover(q,1,0);
            else if(pos == size(*q))
                remover(q,2,0);
            else
            {
                int cont = 1;
                anterior = q->inicio;
                atual = anterior->prox;

                while(cont < pos-1)
                {
                    anterior = atual;
                    atual = atual->prox;
                    cont++;
                }
                aux = atual;
                anterior->prox = aux->prox;
                free(aux);
            }

        }
}

void imprimeprimeiro(lista q)
{
    if(isEmpty(q))
            printf("Lista Vazia!\n");
    else
            printf("\nPrimeiro elemento da lista : %d\n",q.inicio->dado);
}
void imprimeultimo(lista q)
{
    if(isEmpty(q))
            printf("Lista Vazia!\n");
    else
            printf("\nUltimo elemento da lista : %d\n",q.fim->dado);
}
void imprimeN(lista q,int n)
{
        struct no *aux;
        aux = q.inicio;
        int cont = 1;
        if(isEmpty(q))
            printf("Lista Vazia!\n");
        else
        {
            printf("N-ésimo número da lista: ");
            if(n == 1)
                printf("%d\n",q.inicio->dado);
            else if(n == size(q))
                printf("%d\n",q.fim->dado);
            else
            {
                while(cont < n)
                {
                    aux = aux->prox;
                    cont++;
                }
                printf("%d\n",aux->dado);
            }
        }

}
int soma(lista q)
{
    struct no *aux;
    aux = q.inicio;
    int soma = 0;

    aux = q.inicio;
    if (aux != q.fim)
    {
            do
            {
                aux = aux->prox;
                soma += aux->dado;
            } while (aux != q.inicio);
    }
    else
         soma = aux->dado;

    return soma;

}

void copiar(lista *nova,lista q)
{

   struct no *aux;

   create(nova);

   aux = q.inicio;

   if(aux != q.fim)
   {
       do
       {
         insert(nova,aux->dado,3,0);
         aux = aux->prox;
       }while(aux!=q.inicio);
   }
   else
       insert(nova,q.inicio->dado,1,0);



}

void inverte(lista *q)
{
    lista temp;
    create(&temp);

    struct no *aux;

    aux = q->inicio;

    if(aux == q->fim)
        return;
    else
    {
        do
        {
            insert(&temp,aux->dado,1,0);
            aux = aux -> prox;

        }while(aux!=q->inicio);
    }

    *q = temp;

}

void concatena(lista *x,lista y)
{

    struct no *aux;
    aux = y.inicio;

    if(aux == y.fim)
       insert(x,aux->dado,3,0);
    else
    {
        do
        {

            insert(x,aux->dado,3,0);
            aux = aux->prox;

        }while(aux!=y.inicio);
    }

}

int compara(lista a,lista b)
{
    struct no *aux1 = a.inicio;
    struct no *aux2 = b.inicio;

    if(size(a) != size(b))
        return 0;
    else
    {
        if(aux1 == a.fim)
        {
            if(aux1->dado == aux2->dado)
                return 1;
            else
                return 0;
        }
        else
        {
            do
            {

                if(aux1->dado != aux2->dado)
                    return 0;

                aux1 = aux1->prox;
                aux2 = aux2->prox;

            }while(aux1 != a.inicio);
        }
    }
    return 1;

}
int main()
{
    setlocale(LC_ALL,"Portuguese");

    int op;
    char opc;
    lista a,b;
    create(&a);
    create(&b);

    while(1)
    {
        printf("\n\n---Menu---\n\n");
        printf("\n-> Funções para listas circulares duplamente encadeadas.\n\n");
        printf("1 - Inserir um elemento n no início da lista.\n");
        printf("2 - Inserir um elemento n no na k-ésima posição da lista.\n");
        printf("3 - Inserir um elemento n no final da lista.\n");
        printf("4 - Imprimir apenas o primeiro elemento da lista.\n");
        printf("5 - Imprimir apenas o último elemento da lista.\n");
        printf("6 - Imprimir apenas o n-ésimo elemento da lista.\n");
        printf("7 - Retornar a quantidade de nós existentes na lista.\n");
        printf("8 - Retornar a soma dos valores dos nós.\n");
        printf("9 - Faça uma função que faça a cópia de uma lista.\n");
        printf("10 - Faça uma função que inverta a ordem dos elementos de uma lista.\n");
        printf("11 - Faça uma função que concatene (junte) duas listas, uma após a outra.\n");
        printf("12 - Escreva uma função que compare duas listas.\n");
        printf("13 - Excluir o primeiro elemento da lista.\n");
        printf("14 - Excluir o último elemento da lista.\n");
        printf("15 - Excluir o k-ésimo elemento da lista.\n");
        printf("16 - Imprima uma das listas.\n");

        printf("\nDigite a opção desejada: ");
        scanf("%d",&op);
        if(op == 1)
        {
            int n;
            printf("Digite o valor de n: ");
            scanf("%d",&n);
            printf("Em qual lista deseja inserir: ");
            scanf(" %c",&opc);
            if(opc == 'a')
              insert(&a,n,1,0);
            else
              insert(&b,n,1,0);
        }
        else if(op == 2)
        {
            int n;
            int pos;
            printf("Em qual lista deseja inserir: ");
            scanf(" %c",&opc);
            if(opc == 'a')
            {
                printf("Tamanho atual da lista: %d\n",size(a));
                printf("Digite o valor de n: ");
                scanf("%d",&n);
                printf("Digite a posição desejada: ");
                scanf("%d",&pos);
                insert(&a,n,2,pos);
            }
            else
            {
                printf("Tamanho atual da lista: %d\n",size(b));
                printf("Digite o valor de n: ");
                scanf("%d",&n);
                printf("Digite a posição desejada: ");
                scanf("%d",&pos);
                insert(&b,n,2,pos);
            }

        }
        else if(op == 3)
        {
            int n;
            printf("Digite o valor de n: ");
            scanf("%d",&n);
            printf("Em qual lista deseja inserir: ");
            scanf(" %c",&opc);
            if(opc == 'a')
               insert(&a,n,3,0);
            else
               insert(&b,n,3,0);
        }
        else if(op == 4)
        {
            printf("De qual lista deseja imprimir: ");
            scanf(" %c",&opc);
            if(opc == 'a')
              imprimeprimeiro(a);
            else
              imprimeprimeiro(b);
        }
        else if(op == 5)
        {
            printf("De qual lista deseja imprimir: ");
            scanf(" %c",&opc);
            if(opc == 'a')
              imprimeultimo(a);
            else
              imprimeultimo(b);
        }
        else if(op == 6)
        {
            int n;
            printf("\nDigite o valor de n: ");
            scanf("%d",&n);

            printf("De qual lista deseja imprimir: ");
            scanf(" %c",&opc);
            if(opc == 'a')
            {
                 printf("\nTamanho atual da lista a: %d\n",size(a));
                 imprimeN(a,n);
            }
            else
            {
                printf("\nTamanho atual da lista b: %d\n",size(b));
                 imprimeN(b,n);
            }


        }
        else if(op == 7)
        {
            printf("De qual lista deseja saber o tamanho: ");
            scanf(" %c",&opc);
            if(opc == 'a')
                printf("\nTamanho atual da lista a: %d\n",size(a));
            else
                printf("\nTamanho atual da lista b: %d\n",size(b));

        }
        else if(op == 8)
        {
            printf("De qual lista deseja saber a soma de seus elementos: ");
            scanf(" %c",&opc);
            if(opc == 'a')
            {
                int s = soma(a);
                printf("\nSoma dos elementos da lista: %d\n",s);
            }
            else
            {
                int s = soma(b);
                printf("\nSoma dos elementos da lista: %d\n",s);
            }
        }
        else if(op == 9)
        {
            lista nova;
            printf("\nDigite qual lista deseja copiar: ");
            scanf(" %c",&opc);
            if(opc == 'a')
               copiar(&nova,a);
            else
               copiar(&nova,b);

            printf("Lista copiada:\n");
            imprime(nova);
        }
        else if(op == 10)
        {
            printf("\nDigite qual lista deseja-se inverter: ");
            scanf(" %c",&opc);
            printf("\nLista invertida: ");

            if(opc == 'a')
            {
                inverte(&a);
                imprime(a);
            }
            else
            {
                inverte(&b);
                imprime(b);
            }
        }
        else if(op == 11)
        {
            int x;
            printf("\nConcatenar:\n");
            printf("1 - a em b.\n");
            printf("2 - b em a.\n");
            printf("Opção: ");
            scanf("%d",&x);

            printf("Lista concatenada:\n");
            if(x == 1)
            {
                concatena(&a,b);
                imprime(a);
            }
            else
            {
                concatena(&b,a);
                imprime(b);
            }
        }
        else if(op == 12)
        {
            int l = compara(a,b);
            if(l)
                printf("\nListas iguais!\n");
            else
                printf("\nListas diferentes!\n");
        }
        else if(op == 13)
        {
            printf("De qual lista deseja remover do inicio: ");
            scanf(" %c",&opc);

            if(opc == 'a')
                remover(&a,1,0);
            else
                remover(&b,1,0);

        }
        else if(op == 14)
        {
            printf("De qual lista deseja remover do fim: ");
            scanf(" %c",&opc);

            if(opc == 'a')
                remover(&a,2,0);
            else
                remover(&b,2,0);
        }
        else if(op == 15)
        {
            printf("De qual lista deseja remover: ");
            scanf(" %c",&opc);
            if(opc == 'a')
                printf("Tamanho atual da lista a: %d\n",size(a));
            else
                printf("Tamanho atual da lista b: %d\n",size(b));

            printf("De qual posição deseja remover: ");
            int k;
            scanf("%d",&k);

            if(opc == 'a')
                remover(&a,3,k);
            else
                remover(&b,3,k);
        }
        else if(op == 16)
        {
            printf("Qual lista deseja imprimir: ");
            scanf(" %c",&opc);
            if(opc == 'a')
                imprime(a);
            else
                imprime(b);
        }
        else
            printf("Opção incorreta!\n");
        int z;
        printf("\n\nSair ?\n");
        printf("1 - Não.\n");
        printf("2 - Sim.\n");
        printf("Opção: ");
        scanf("%d",&z);

        if(z == 2)
            break;
        system("cls");
    }
}

