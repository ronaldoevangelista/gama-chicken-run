/*----------------------------------------------------------------------------------*/
/* Name: Trabalho de EDII - Hashing I bimestre 2007.1
*  Copyright: Ronaldo Evangelista, não a minima pra GPL nao usar sem permissao
*  professor: Marco Figueiredo Disciplina Estrutura de Dados II
*  Desenvolvido por :
*           Ronaldo Evangelista  - Email ronaldinho.evangelista@gmail.com
*           Rodolfo Rodrigo      - Email rodrigo.rodolfo@gmail.com
*           Luciano Morais       - Email johnivo@yahoo.com.br
*  Date: 31/03/07 20:07
*Description: Para a encenação do espetáculo "Paixão de Cristo" em Nova Jerusalém,os
*organizadores do evento resolverem reservar camarotes para os convidados  especiais.
*Para melhor localizar cada convidado durante o evento, foi implementada a ténica de 
*hashing para distribuir os camarotes, utilizando a função mod (    resto da divisão 
*interira) entre o número de RG do convidado e o número 10, que  era a quantidade de 
*camarotes em cada ponto da apresentação. Caso ocorresse colisão ( dois RGs na mesma
* posição), o primeiro convidado a se apresentar deveria permanecer no camarote, e o 
*que veio a seguir entraria numa lista de espera (única para todos os camarotes) por 
*ordem de chegada. Antes de começar a apresentação,       o organizador então deverá 
*verificar se existem camarotes livres e preenchê-los com os convidados na lista  de
*espera, não mais se importando com que camarote cada um deve ocupar             
/*----------------------------------------------------------------------------------*/
#include <stdio.h>
#include <conio.c>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10 
/*----------------------------------------------------------------------------------*/
/*|                          Estruruturas                                          |*/
struct lista_espera{
       int rg; 
       char nome[30]; 
       struct lista_espera *prox; 
       } convidado[10], * inicio;

struct convidados{
       int rg; 
       char nome[30]; 
       struct convidados *proximo; 
       }* lista;  
/*|                      variaveis globais                                         |*/
int i, j;
/*|                      Declaracao das Funcoes                                    |*/
/*----------------------------------------------------------------------------------*/
void inicializa();        //inicializacao do vetor com -1 no campo rg e livre no nome
void insere_convidado();       //inseri convidado no vetor ou na lista caso ja exista   
int remocaodaLista (int n);   //Remocao da lista encadeada 
void consultaLista(int n, struct convidados *lista); //pesquisa a lsta por um convida
void consulta(int n);//faz a busca por um convidado se nao achar no vetor vai a lista
void remocao(int n); //Remove um convidado do vetor se nao tiver no vetor vai a lista 
void removelistaParaVetor();       //reomove da lista e poe nas vagas livres do vetor

/*|                               Realatorios                                      |*/
/*----------------------------------------------------------------------------------*/
void listagem(struct convidados *lista);                          //percorre a lista
void relatorio_lista();                       //imprime a lista de espera  formatada
void relatorio();                                         //imprime o vetor estatico
void leituraparaConsulta();
void preencherCamaroteLivre(); 
/*|                              Floricultura                                      |*/
/*----------------------------------------------------------------------------------*/
void tela_verde(); 
void erro();
void imprime_relatorio();
void campos();                      //interface para mostra campos a serem prenchidos
void interface_remove();//TELA DE INSERCAO DE DADOS NA REMOCAO CHAMA A FUNCAO REMOVER
void menu();                                            //menu principal da aplicacao
void Sub_menu_Inseri();                                             //submenu inserir
void tela_menu();                                           //faz a tela azul do menu
void sair();                                   //sai do programa e mostra os creditos
void linhas();            
/*----------------------------------------------------------------------------------*/
int main(){
            clrscr();
            inicializa();
            textbackground(BLACK);         
            menu();  
            system("pause");
            return 0;
           }
/*----------------------------------------------------------------------------------*/
void inicializa(){        //inicializacao do vetor com -1 no campo rg e livre no nome
     for (i=0; i<TAM; i++){
         convidado[i].rg = -1; 
         strcpy(convidado[i].nome,"livre");       
         }
     }
/*----------------------------------------------------------------------------------*/
/*|                              Item I - Inclusao                                 |*/
/*| Funcao para inseri um convidado no camarote - inclusão de um convidado         |*/
/*|checando se ele será colocado no camarote ou na lista de espera;                |*/
/*|obs. verifica validacao rgs iguais aviso de que ja fo cadastrado                |*/
/*----------------------------------------------------------------------------------*/                  
void insere_convidado(){ 
     int h, dado;
     char conv[30];
       campos();
       textbackground(GREEN);      
       gotoxy(35,14);cprintf("[  OK  ]");                       //mostra ok na tela
       textbackground(BLACK); 
       gotoxy(45,8); gets(conv);                             //entrada do nome String
       fflush(stdin);
       gotoxy(45,10);scanf("%d",&dado);     //leitura dos dados de entrada RG Inteiro
       fflush(stdin);                                     //limpa o buffer do teclado
                              //validacao de numeros inteiros nao foi feita
       gotoxy(38,14);getchar();              //poe o cursor no o de ok e espera enter
       h = dado%TAM;          //funcao de hashing para calcular o enderaceço no vetor
             if (convidado[h].rg < 0){      //se o valor na posicao for menor ke zero 
                 convidado[h].rg = dado;   //ele atribui o rg do convidado na pisicao
                 strcpy(convidado[h].nome,conv); 
                 //printf ("\n convidado Acomodado no camarote N %d !", dado);
                 }
                 else{
                      if( convidado[h].rg == dado){
                      system("cls");
                      erro();linhas(); 
                      gotoxy(26,10); cprintf("CONVIDADO JA CADASTRADO !");
                      gotoxy(26,11); cprintf("SO E PERMITIDO UM CAMAROTE POR RG");
                       getchar(); 
                       system("cls");
                       textbackground(BLACK);   
//verifica possibilidade de incluir na fila dois rgs iguais  por enquanto naum incluir            
                       }
                       else{    
/*******************|Faz a insercao na lista de espera |*****************************/
                         struct convidados *p, *aux, *q; 
                         p = (struct convidados *) malloc (sizeof(struct convidados));
                         if (p == NULL){
                         erro(); linhas();                  //mensagem de erro funcao                                    
                         gotoxy(20,10); printf ("ERRO 101 - MEMORIA INSUFICIENTE !");
                         }
                         else{                      //preenchimento da estrura na fila 
                              p->rg = dado;
                              strcpy(p->nome,conv);
                              if (lista == NULL){
                                 p->proximo= lista;
                                 lista = p;
	                            }
                       else{
                            aux = lista; 
	                       while (aux != NULL){
                                   q = aux;
		                         aux = aux->proximo;
	                      }               
                           p->proximo = aux;
	                      q->proximo= p;
	                   }
                   }
/*****************| mensagem pra incluir na fila de espera |*************************/
             system("cls");
             tela_menu();linhas();            
             gotoxy(20,10); cprintf("CONVIDADO INCLUIDO NA FILA DE ESPERA");
             gotoxy(35,15);printf("[  OK  ]");
             getchar(); 
             system("cls");              
             }
    }
    textbackground(BLACK);  
}    
    
/*----------------------------------------------------------------------------------*/
/*|                              Item II Consulta                                  |*/
/*|Consulta  de um convidado pelo RG antes de começar o espetáculo, informando     |*/
/*|se ele está no camarote ou na lista de espera                                   |*/
/*----------------------------------------------------------------------------------*/
void consulta(int n){  //RECEBE COMO PARAMENTRO UM INTEIRO (VER VALIDACAO DE INTEIRO)
int dado = n % TAM;                     //hashing calcula a posivel pisicao no vetor
tela_menu();                                                    //tela azul frescura
if (convidado[dado].rg == n){//compara se o dado e igual ao dado na posicao do vetor
     linhas();
     gotoxy(29,7); cprintf("CONVIDADO ENCONTRADO.");
     gotoxy(17,9); cprintf("RG   : 00%d ",convidado[dado].rg);
     gotoxy(17,10); cprintf("NOME   : %s ",convidado[dado].nome);
     gotoxy(17,11);cprintf("CAMAROTE :000%d",dado); 
     gotoxy(38,15);getchar();
     textbackground(BLACK); 
     }
     else{                                     //se nao achar no vetor vai pra lista
         consultaLista(n,lista);              //chamada da rotina consualta na lista 
         gotoxy(35,15);printf("[  OK  ]");
         gotoxy(38,15);getchar();   
         textbackground(BLACK); 
   }
   }
/***********************************************************************************/   
void consultaLista(int n, struct convidados *lista){//sub rotina de consulta se o rg
     struct convidados * aux;                 // nao esta no camarote busca na lista
     clrscr();               
     if(lista){                                          //testa se a lista ta vazia 
              aux = lista;                               //copia o endereco da lista
     while(aux != NULL){                  //enqunato existir um proximo elemento ele  
             if(aux->rg == n){       //compara o dado da entrada com o dado da lista
               tela_verde();linhas(); 
               gotoxy(22,7); cprintf("CONVIDADO ENCONTRADO NA FILA DE ESPERA");
               gotoxy(17,9); cprintf("RG   : 00%d ",aux->rg); //se encontrou imprime
               gotoxy(17,10);cprintf("NOME : %-11s ",aux->nome);
               gotoxy(17,11);cprintf("AGUARDANDO UM CAMAROTE LIVRE"); 
              return ;
              }
              aux = aux->proximo;                              //ajuste de ponteiros
     }                                                //ajuste padrao para mensagens
     gotoxy(38,15);getchar();       
              }
              else{
              erro();  linhas();                             
                       for(i=0; i<TAM; i++){
                                if (convidado[i].rg == n){
                                gotoxy(17,9);  cprintf("RG   : %d ",convidado[i].rg);  
                              gotoxy(17,10); cprintf("Nome : %s ",convidado[i].nome);  
                                gotoxy(38,15);getchar();
                                }
                      }
              return ; 
              }
}
/***********************************************************************************/
void leituraparaConsulta(){
       system("cls"); tela_verde();fflush(stdin);
       linhas();               //prevencao de erros
       gotoxy(36,14);printf("[  OK  ]");
       gotoxy(35,6); printf ("LOCALIZAR CONVIDADO");                                                                                     
       gotoxy(17,9); printf ("RG :");
       textbackground(YELLOW);
       gotoxy(24,9);cprintf("         ");  
       textbackground(BLACK);       
       int dado;  
       gotoxy(24,9);scanf("%d",&dado);           //leitura do valor a ser pesquisado
       fflush(stdin); gotoxy(40,14);getchar(); system("cls"); 
        //atencao validacao de dados e preciso fazer para proibir entradas invalidas
       consulta(dado);                                           //ver consulta dado
}
/*----------------------------------------------------------------------------------*/
/*|                         Exclusao Item III                                      |*/    
/*|exclusão de um convidado (esteja ele no camarote ou da lista de espera), antes  |*/
/*|do começo do espetáculo                                                         |*/
/*----------------------------------------------------------------------------------*/     
void remocao(int n){                     //recebe um inteiro a ser removido do vetor
   //  clrscr();                                                  //frescuras graficas
     int dado = n% TAM;                      //calcula o endereco ou indice do vetor
     if(convidado[dado].rg == n){              //se o numero existir naquela posicao 
         convidado[dado].rg = -2;
         tela_verde();linhas();                               //substitui ele por -2
         strcpy(convidado[dado].nome,"LIVRE");            //e o campo nome por livre
         gotoxy(33,9);printf("CONVIDADO EXCLUIDO !");
         gotoxy(38,12);printf("[  OK  ]");
         gotoxy(42,12);getchar();//clrscr(); 
        }                                  //se nao estiver no vetor ele vai a lista
        else{
         int p = remocaodaLista(n); 
         printf("valor de P %d",p);
             if(p==1){
             for(i=0; i<TAM; i++){
                      if(convidado[i].rg == n){ 
                         convidado[i].rg = -2; 
                         strcpy(convidado[i].nome,"LIVRE");//e o campo nome por livre
                         gotoxy(33,9);printf("CONVIDADO EXCLUIDO !");
                         gotoxy(38,12);printf("[  OK  ]");    
                         return;             
                      } 
             }                                         
                                             //percorrer a lista em busca do inteiro 
            }
           else{
                gotoxy(35,12);printf("NAO EXISTE");
                gotoxy(38,15);printf("[  OK  ]");  
                getchar();  
                }
            }
}
/************************************************************************************/
int remocaodaLista (int n){    //sub rotina remover busca 

      struct convidados * aux, *aux2;       
     //relatorio_lista();
     aux2=NULL;
     aux=lista;


           while((aux!=NULL) && (aux->rg!=n) ){                //localizar na lista
           aux2 = aux;
           aux = aux->proximo;
           } 
     if( aux == NULL ){
              erro();linhas();
              gotoxy(30,15);printf( "RG NAO ENCONTRADO !" );
              gotoxy(37,17);printf("[  OK  ]");
              gotoxy(42,16);getchar();clrscr(); 
              } 
              else{
                      if( aux2!=NULL )      
                      aux2->proximo = aux->proximo;  //ajuste de ponteiro
                      else{
                          lista = aux->proximo;
                          free(aux);                         //liberando a memória
                 tela_menu();linhas(); 
                 gotoxy(30,13);printf("CONVIDADO(A) EXCLUIDO!");
                 gotoxy(37,17);printf("[  OK  ]");
                 gotoxy(42,16);getchar();clrscr(); 
                         }
                 }
}
/************************************************************************************/
void interface_remove(){
   clrscr();textcolor(7);
   tela_menu();
   gotoxy(35,6); printf ("INFOME O RG A SER REMOVIDO");                                                                                     
   gotoxy(17,8); printf ("RG :");
                 textbackground(YELLOW);                     //cor da caixa de texto
   gotoxy(45,8); printf("                    ");
   int dado;
   gotoxy(45,8);scanf("%d",&dado);
   fflush(stdin);
   remocao(dado);   //problemas na remocao verificar  
   textbackground(BLACK);
}
/*----------------------------------------------------------------------------------*/
/*|              Preenchimento dos camarotes livres Item IV                        |*/
/*|preechimento dos camarotes livres com as pessoas da lista, a qualquer momento   |*/
/*|que oorganizador desejar.                                                       |*/
/*----------------------------------------------------------------------------------*/
void preencherCamaroteLivre(){
      int y=8;
       for (i=0; i<TAM; i++){
           if(convidado[i].rg <0){
              struct convidados * aux, *aux2;                                                 
              if (lista){                            
                 aux = lista;                                  
                 convidado[i].rg = aux->rg;      
                 strcpy(convidado[i].nome,aux->nome);                         
                 lista = aux->proximo; 
                 free(aux);                      
                 }                                             
             }
             else{
             linhas();
             gotoxy(16,y++);printf("O CAMAROTES [000%d] ESTA OCUPADO",i);
             }                                              
       }
       printf("\n\t\t\[  OK  ]\n");  
       getchar(); 
}

/*----------------------------------------------------------------------------------*/
/*|         RELATORIOS  & FRESCURAS NAO FAZEM PARTE DAS ESPECIFICAOES              |*/
/*----------------------------------------------------------------------------------*/
void imprime_relatorio(){
     relatorio();
     getchar(); 
    // clrscr();
     system("cls"); 
      
}
/*************|Relatorio Imprime o numero do camarote o nome do comvidado e o rg |**/     
void relatorio(){                               //esta funcao imprime o vetor e  a 1
     tela_verde(); 
     gotoxy(16,5);printf("-------------------------------------------------------");
     gotoxy(16,6); printf("[Camarote]-[           Convidado        ]-[    RG     ]");
     gotoxy(16,7);printf("-------------------------------------------------------");
     for (i=0; i<TAM; i++){
     gotoxy(16,9+i);
     printf("[%08d]-[%-28s]-[%10d]",i, convidado[i].nome, convidado[i].rg);    
     }
     relatorio_lista();                            //Chamada da funcao 2 logo abaixo 
     textbackground(BLACK);     
} 
/*********************|Cabeçario do relatorio que imprime a Lista |*****************/
void relatorio_lista(){ //esta funcao e o cabecario funcao que imprime a lista e a 2
   textbackground(BLACK);
   gotoxy(17,21);printf("\t\tRELATORIO  -  FILA DE ESPERA");
   gotoxy(17,22);printf("-----------------------------------------------------");
   gotoxy(17,23);printf("[Situacao  ]-[ Nome                     ]-[    Rg   ]");
   gotoxy(17,24);printf("-----------------------------------------------------");
   listagem(lista);         //funcao que percorre a lista imprimindo seus elementos     
}
/*************************|Funcao recursiva pra imprimir a lista |*******************/              
void listagem(struct convidados *lista){  //esta funcao imprimi os elementos da lista
     struct convidados * aux;                 
     aux = lista; 
           if(aux){ 
           textbackground(BLACK); 
           printf("\n\t\t[Aguardando]-[%26s]-[%8d]",aux->nome,aux->rg);
           aux = aux->proximo;
           listagem(aux);
           textbackground(BLACK);   
           }
           else{ 
           printf("\n\t\t-----------------------------------------------------");
           }
           return ;
}
/******************| Floricultura |*************************************************/        
void campos(){
             system("cls"); 
             textbackground(GREEN);               //tela para preenchimento dos dados             
             tela_verde();                                  //desenha um quadro verde
             gotoxy(35,6); printf ("DADOS DO CONVIDADO");                                                                                     
             gotoxy(17,8); printf ("Nome :");
                           textbackground(YELLOW);            //cor da caixa de texto
             gotoxy(45,8); printf("                    ");
                           textbackground(GREEN);                      //cor do fundo       
             gotoxy(17,10);printf ("Registro Geral [RG] :");
                           textbackground(YELLOW); 
             gotoxy(45,10);printf("                    ");                    
             textbackground(BLACK);       
            }
/***********************************************************************************/
void tela_verde(){
          int j,i;
          textbackground(GREEN);
          for(j=5;j<=20;j++){                   
                            for(i=15;i<=71;i++){
                                               gotoxy(i,j); printf(" ");
                                               }
                            }                            
                 }
/************************************************************************************/
void sair()
           {  
           tela_verde();                                                     
           textbackground(GREEN);  
           gotoxy(28,8); printf(" Aplicacao Finalizada ! ");
           gotoxy(20,10);printf(" Desenvolvido Por "); 
           gotoxy(20,11);printf(" Ronaldo, Rodolfo e Luciano");
           gotoxy(20,12);printf(" ");  
           gotoxy(20,13);printf(" E-mail para contato: "); 
           gotoxy(20,14);printf(" ronaldinho.evangelista@gmail.com "); 
           gotoxy(20,15);printf(" "); 
           gotoxy(35,19);printf(" EDII - 2007.1 ");    
           getchar();
           exit(1);             
           return;
           }
//**********************************************************************************//
void menu(){ //menu principal
           int op;
           clrscr();    
           textbackground(BLACK); 
           tela_menu(); 
           do{  
             do{textcolor(7);
             tela_menu();
             gotoxy(23,7);  cprintf("[0] - [MENU - Escolha uma Opcao  ]");
             gotoxy(23,9);  cprintf("[1] - [Inserir novo Convidado    ]");
             gotoxy(23,11); cprintf("[2] - [Excluir um   Convidado    ]");
             gotoxy(23,13); cprintf("[3] - [Pesquisar um Convidado    ]");
             gotoxy(23,15); cprintf("[4] - [Preencher Camarotes vagos ]");  
             gotoxy(23,17); cprintf("[5] - [Relatorio                 ]");
             gotoxy(23,19); cprintf("[6] - [Sair  da Aplicacao        ]");           
             gotoxy(23,21); cprintf("[ ] - [Opcao + Enter             ]");
             gotoxy(24,21); scanf("%d", &op);                 
             gotoxy(10,25);getchar();                                //limpa sujeira
             textcolor(7);
             textbackground(BLACK);clrscr();            
             }    
              while((op<1)||(op>6));
              clrscr();   
              switch (op){
                         case 1:clrscr();
                             insere_convidado();  
                             Sub_menu_Inseri();
                             break;
                         case 2:clrscr();
                              interface_remove();
                              clrscr(); 
                              break;
                         case 3:clrscr();
                              leituraparaConsulta();
                              clrscr();
                              break;
                         case 4:clrscr();
                              preencherCamaroteLivre();
                              clrscr();                  
                              break;
                         case 5:clrscr();
                              imprime_relatorio();      
                              clrscr();
                              break;
                         case 6: sair();    
                              break;                                                                                        
                        } 
           textbackground(BLACK); 
           } while (op != 6);
           textbackground(BLACK); 
           }
/************************************************************************************/           
void Sub_menu_Inseri(){//cria um sub menu so isso para incluir ou sair
           int op; 
           do{  
             do{
             clrscr();textcolor(7);
             tela_menu();linhas();
                          gotoxy(22,7);cprintf("DESEJA CADASTRA NOVO CONVIDADO");
                          gotoxy(32,9);  cprintf("[1] - [ SIM  ]");
                          gotoxy(32,10);  cprintf("[2] - [ NAO  ]");        
                          gotoxy(32,12); cprintf("[ ] - [ Enter]");
                          gotoxy(33,12); scanf("%d", &op);                 
                          gotoxy(12,37);getchar();//limpa sujeira
                          textcolor(7); //cor da letra
                          clrscr();
                          textbackground(BLACK);           
               }    
               while((op<1)||(op>2));
               switch (op){
                         case 1:clrscr();  
                            insere_convidado();//chamada para inserir
                            break;
                         case 2:clrscr();  
                               break;                                   
                           }  
           } while (op != 2);
           textbackground(BLACK); 
}
/************************************************************************************/
void tela_menu(){
          textbackground(1);
          for(j=6;j<=21;j++){                          //calcula o numero de linhas                   
                            for(i=15;i<=65;i++){      //calcula o numero de colunas
                                               gotoxy(i,j); printf(" ");  //imprime
                                               }
                            }   
                                                  
                 }
/************************************************************************************/           
void erro(){                                                 //tela vermelha de erro
          int j,i;
          textbackground(RED);
          for(j=5;j<=23;j++){                   
                            for(i=15;i<=65;i++){
                                               gotoxy(i,j); printf(" ");
                                               }
                            }                            
                 }           
//**********************************************************************************//

void linhas(){
gotoxy(16,8); printf("-----------------------------------------------");   
gotoxy(16,20);printf("-----------------------------------------------");  
}
/************************************************************************************/

       
