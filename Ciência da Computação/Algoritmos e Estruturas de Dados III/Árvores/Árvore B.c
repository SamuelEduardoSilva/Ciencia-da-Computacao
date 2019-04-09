#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<locale.h>
#define MAX 100

/*

Estava dando trabalho implementar, ai encontrei algumas video-aulas com implementações classicas da B-Tree,
e utilizei ela como base. O cara do vídeo inclusive, cria essa "interface" bem legal, achei dahora e coloquei também kk

*/


struct node
{
    int value[MAX];
    struct node *keys[MAX+1];
    struct node *parent;
    int keyCount;
} *tRoot = NULL;


int treeOrder;


void showMenu();
void doInsert();
void doDelete();
void doSearch();
void doInOrder();


struct node* newNode(int value,struct node *parent);
struct node* insertN(int value,struct node *root,struct node *parent);


void inOrder(struct node *root);
void levelOrder(struct node *root);

int main()
{

    setlocale(LC_ALL,"Portuguese");
    printf("Digite a ordem da Árvore B: ");
    scanf("%d",&treeOrder);


    showMenu();

    getch();
    return 0;
}


void showMenu(){
   system("cls");
   printf("      _____           _____              \n");
   printf("     | __  |   ___   |_   _|___ ___ ___  \n");
   printf("     | __ -|  |___|    | | |  _| -_| -_| \n");
   printf("     |_____|           |_| |_| |___|___| \n");

   printf("\n\n");
   printf("(1) Inserir um nó.\n");
   printf("(2) Procurar um nó\n");
   printf("(3) Mostrar In-Ordem\n");
   printf("(4) Sair\n");

  switch(getch()){
     case '1' : doInsert();   break;
     case '2' : doSearch();   break;
     case '3' : doInOrder();   break;
     default  : exit(0);
  }
}

void doInsert()
{
     int value;

     system("cls");
     printf("--- Inserção ---\n");
     printf("Valor: ");
     scanf("%d",&value);

     tRoot = insertN(value,tRoot,NULL);

     printf("\n\n\nDigite qualquer tecla para continuar...\n");
     getch();
     showMenu();
}


void doSearch()
{
     int toFind;

     system("cls");
     printf("--- Procurar ---\n");

     printf("\n\n\nDigite qualquer tecla para continuar...\n");
     getch();
     showMenu();
}

void doInOrder()
{
     int i;

     system("cls");
     printf("--- Mostrando ---\n");


     if (tRoot != NULL) inOrder(tRoot);
     else printf("\nA árvore está vazia!\n");

     printf("--- Level Order ---\n");
     if (tRoot != NULL) levelOrder(tRoot);
     else printf("\nA árvore está vazia!\n");

     printf("\n\n\nDigite qualquer tecla para continuar...\n");
     getch();
     showMenu();
}


struct node* newNode(int value,struct node *parent)
{
       struct node *root = (struct node*)malloc(sizeof(struct node));
       root->value[0] = value;
       root->keyCount = 2;
       root->parent = parent;

       int i;
       for (i = 1; i <= treeOrder + 2; i++)
       {
           root->value[i] = (int)NULL;
           root->keys[i] = NULL;
       }

       return root;
}

struct node* insertN(int value,struct node *root,struct node *parent)
{
       int i = 0, j;

       if (root == NULL){
          return newNode(value,parent);
       } else {
          while(1){
             if ( (void*)root->value[i] != NULL ){
                if (value == root->value[i]){
                   printf("O valor digitado já existe!\n");
                   break;
                } else if ( value > root->value[i] ){
                   if (root->keys[i+1] != NULL && root->keys[i+1]->keyCount < treeOrder + 1) {
                       root->keys[i+1] = insertN(value,root->keys[i+1],root);
                       break;
                   } else i++;

                   continue;
                } else {
                   if (root->keys[i] != NULL && root->keys[i]->keyCount < treeOrder + 1) {
                       root->keys[i] = insertN(value,root->keys[i],root);
                       break;
                   } else {
                     for (j = treeOrder - 2; j >= i; j--) root->value[j+1] = root->value[j];
                     root->value[i] = value;
                     root->keyCount++;


                     break;
                   }

                }
             } else {
               root->value[i] = value;
               root->keyCount++;

               printf("Chaves: %d\n",root->keyCount);
               break;
             }

             i++;
          }

          if (root->keyCount > treeOrder){
             int left = (treeOrder-1)/2 - 1;
             int right = (treeOrder-1)/2 + 1;
             int mid = (treeOrder-1)/2;

             printf("Overflow! Divisão e Promoção de nó...\n");
             struct node *leftHalf = NULL;
             struct node *rightHalf = NULL;

             for (i = 0; i <= left; i++){
                 leftHalf = insertN(root->value[i],leftHalf,NULL);
             }

             for (i = right; i < treeOrder; i++){
                 rightHalf = insertN(root->value[i],rightHalf,NULL);
             }

             struct node *tempRoot = root;
             root = insertN(root->value[mid],parent,parent);

             if (parent == NULL){
               leftHalf->parent = root;
               rightHalf->parent = root;
               root->keys[0] = leftHalf;
               root->keys[1] = rightHalf;
             } else {
               for (i = 0; i < tempRoot->parent->keyCount; i++){
                   if (tempRoot->parent->keys[i] == tempRoot){
                      tempRoot->parent->keys[i]   = leftHalf;
                      tempRoot->parent->keys[i+1] = rightHalf;
                   }
               }
             }



             free(tempRoot);
          }
       }

       return root;
}


void inOrder(struct node *root)
{
     int i;
     if (root == NULL)
           return;
     else
     {
          for (i = 0; i < root->keyCount - 1; i++)
          {
            inOrder(root->keys[i]);
            printf("~%d~\n",root->value[i]);
          }
     }
}

void levelOrder(struct node *root)
{
     int i;
     if (root == NULL) return;
     else {
          for (i = 0; i < root->keyCount - 1; i++){
             printf("%d ",root->value[i]);
          }
          printf("   ");
          if (root->parent == NULL) printf("\n");
          else {
               for (i = 0; i < root->parent->keyCount; i++){
                   if (root->parent->keys[i] == root){
                      if (root->parent->keys[i+1] == NULL) printf("\n");
                      break;
                   }
               }
          }

          for (i = 0; i < root->keyCount; i++){
            levelOrder(root->keys[i]);
          }
     }
}
