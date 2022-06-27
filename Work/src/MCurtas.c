#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "hash.h"
#include "queue.h"

//criação da lista
struct list {
    char *string;
    struct list *next;
};

typedef struct list LIST;

void inserir_hash(){

    init();

    //tecla 2
    insert(97, 2);
    insert(98, 2);
    insert(99, 2);
    insert(-150, 2);
    insert(-156, 2);
    insert(-157, 2);
    insert(-154, 2);
    insert(-155, 2);
    insert(65, 2);
    insert(66, 2);
    insert(67, 2);
    insert(-188, 2);
    insert(-189, 2);
    insert(-187, 2);
    insert(-186, 2);
    
    //tecla 3
    insert(100, 3);
    insert(101, 3);
    insert(102, 3);
    insert(-148, 3);
    insert(-147, 3);
    insert(68, 3);
    insert(69, 3);
    insert(70, 3);
    insert(-180, 3);
    insert(-179, 3);

    //tecla 4
    insert(103, 4);
    insert(104, 4);
    insert(105, 4);
    insert(-144, 4);
    insert(71, 4);
    insert(72, 4);
    insert(73, 4);
    insert(-176, 4);

    //tecla 5
    insert(106, 5);
    insert(107, 5);
    insert(108, 5);
    insert(74, 5);
    insert(75, 5);
    insert(76, 5);

    //tecla 5
    insert(109, 6);
    insert(110, 6);
    insert(111, 6);
    insert(-138, 6);
    insert(-137, 6);
    insert(-136, 6);
    insert(77, 6);
    insert(78, 6);
    insert(79, 6);
    insert(-170, 6);
    insert(-169, 6);
    insert(-168, 6);

    //tecla 7
    insert(112, 7);
    insert(113, 7);
    insert(114, 7);
    insert(115, 7);
    insert(80, 7);
    insert(81, 7);
    insert(82, 7);
    insert(83, 7);

    //tecla 8
    insert(116, 8);
    insert(117, 8);
    insert(118, 8);
    insert(-131, 8);
    insert(84, 8);
    insert(85, 8);
    insert(86, 8);
    insert(-163, 8);

    //tecla 9
    insert(119, 9);
    insert(120, 9);
    insert(121, 9);
    insert(122, 9);
    insert(87, 9);
    insert(88, 9);
    insert(89, 9);
    insert(90, 9);
}

int main(int argc, char *argv[]){

    //definição do nome do update de cada dicionário
    char *file;
    file = argv[1];
    int file_size = strlen(file);
    if(file_size == 14)
    {
        file = "portuguese-update.txt";
    }
    else if(file_size == 20)
    {
        file = "portuguese-large-update.txt";
    }
    else if(file_size == 11)
    {
        file = "english-update.txt";
    }
    else if(file_size == 16)
    {
        file = "english-freq-update.txt";
    }
    FILE *fp = fopen( argv[1], "r" );
    FILE *fpUpdate = fopen( file, "w" );
    FILE *fpEnd = fopen( file, "a" );
    char line[128];
    LIST *current, *head, *current2;
    head = current = NULL;

    //inserção do dicionário numa lista
    double time_spent = 0.0;
    clock_t begin = clock();
    while(fgets(line, sizeof(line), fp)){
        LIST *node = malloc(sizeof(LIST));
        node->string = strdup(line);
        node->next =NULL;
        if(head == NULL){
            current = head = node;
        } else {
            current = current->next = node;
        }
    }
    fclose(fp);
   
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Demorou %f segundos a ler o dicionário! \n", time_spent);

    printf("TABELA DOS ALGARISMOS: \n");
    printf("2: a b c á à â ã ç\n");
    printf("3: d e f é ê\n");
    printf("4: g h i í\n");
    printf("5: j k l\n");
    printf("6: m n o ó ô õ\n");
    printf("7: p q r s\n");
    printf("8: t u v ú\n");
    printf("9: w x y z\n");

    //inserir as letras correspondentes a cada algarismo numa hash table
    inserir_hash();

    char palavra[25];
    int nr;
    init_queue();
    
    //loop para a inserção das mensagens
    while(1){
        puts("\n** Escreva a sua mensagem **");
        scanf("%s", palavra);
        int nr = atoi(palavra);
        int nr2 = nr;
        int psize = 0;
        int parr[27];
        char answer[1];
        bool sugest = false;
        char sug[25];

        if(nr == 0){
            break;
        }
        if(nr == 1){
            printf("Mensagem: ");
            print_queue();
            init_queue();
            continue;
        }
        
        while(nr2)
        {
            parr[psize] = nr2 % 10;
            nr2 /= 10;
            psize++;
        }
        int parr2[psize];
        int u = psize -1;
        
       for(int j = 0; j < psize; j++){
            parr2[j] = parr[u];
            u--;
        }

        for(current = head; current ; current=current->next){ //percorrer a lista que contém o dicionário
            int i = 0;
            int count = 0;
            char *teste = current->string;
            int numbers[25];
            while(teste[i] != '\0')
            {
                
                if(teste[i]<0)
                {
                    int sum = teste[i] + teste[i+1];
                    numbers[count] = sum;
                    i = i + 2;
                    count++;
                }
                else
                {   if(teste[i] == 10)
                        {
                            break;
                        }
                    else if(teste[i] == 39 ) //ignorar apóstrofos
                    {
                        //nada
                    }
                    else
                    {   
                        int num = teste[i];
                        numbers[count] = num;
                        count++;
                    }
                    i++;
                }
            }
            if(psize == count) //em caso de a palavra em questão ter o mesmo tamanho do input do utilizador
            {   
                int check = 0;
                int a;
                for(int z = 0; z < psize; z++){ //percorrer as letras correspondentes a cada número
                    a = parr2[z];
                    struct node *temp = chain[a];         
                    while(temp)
                    {
                        if(numbers[z] == temp->data){
                            check++;
                            break;
                        } 
                        temp = temp->next;
                    }
                }

                if(check == psize) //em caso de se encontrar uma palavra que corresponda ao código inserido
                {
                    printf("Sugestão: %s, aceita (s/n)?", teste);
                    scanf("%s", answer);
                    if(strcmp(answer, "s") == 0){
                        enqueue(teste);
                        sugest = true;
                        break;
                    } else{
                        continue;
                    }
                }
            }
            else
            {
                continue;
            }
        }
        if(sugest == false) //inserir nova palavra no dicionário
        {

            printf("Não existem mais sugestões; introduza a palavra do teclado.\n");
            scanf("%s", sug);
            fprintf(fpUpdate,"%s",sug);
            current = head;
            while (current->next!= NULL)
            {
                
                current = current->next;
            }
            
            LIST *node = malloc(sizeof(LIST));
            node->string = strdup(sug);
            node->next =NULL;
            
            current = current->next = node;
            current = head;
                
        }

    }
}


