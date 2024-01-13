#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>

struct State {
    char state;
    struct State* next;
    struct State* next0;
    struct State* next1;
    int garb;
};

void printList(struct State* n)
{
    while (n != NULL) {
        printf("%c %c %c", n->state,n->next0->state,n->next1->state);
        printf("\n");
        n = n->next;
    }
}

void change(struct State* n,char arr[],struct State* p)
{
    int data=(int)(arr[1])-48;
    struct State* steady_state;
    steady_state = n;
    while (n != NULL) {
        if(n->state == arr[2]){
                if(data == 0){
                    p->next0 = n;
                }
                else if(data ==1){
                     p->next1 = n;
                }
                
            }
        
        
        n = n->next;
    }
    n = steady_state;
    
}

void garbage(struct State* n,char arr[])
{
    struct State* steady_state;
    struct State* temp_state;
    steady_state = n;
    char input[30];
    while (n != NULL) {
        temp_state =steady_state;
        while(temp_state != NULL ){
            if(temp_state == n ){
                temp_state = temp_state->next;
            }
            else if(temp_state->next0->state == n->state || temp_state->next1->state == n->state){
                n->garb = 0;
                temp_state = NULL;
            }
            else{
                temp_state = temp_state->next;
            }
        }
        n = n->next;
         }
        
    n= steady_state;
    static int a = 0;
    while(n!=NULL){
        if(n->garb !=0){
            n->garb = 2;
            arr[a] = n->state;
            a++;
        }
        n = n->next;
    }   
        
       

}

void delete(struct State* n)
{
    while (n != NULL) {
        if(n->next->garb ==2){
            printf("Deleted: %c",n->next->state);
            /* speacial condition for state A */
            n->next = n->next->next;
        }
       n = n->next;
    }
    
}

int main()
{
    struct State* current_state;
    struct State* starting_state;
    char *input = malloc(10 * sizeof(char));
    char *garbage_state = malloc(10 * sizeof(char));
    int data;

    struct State A;
    A.state = 'A';
    A.garb = 1;
    
    struct State B;
    B.state = 'B';
    B.garb = 1;
    
    struct State C;
    C.state = 'C';
    C.garb = 1;
    
    struct State D;
    D.state = 'D';
    D.garb = 1;
    
    struct State E;
    E.state = 'E';
    E.garb = 1;
    
    struct State F;
    F.state = 'F';
    F.garb = 1;
    
    struct State G;
    G.state = 'G';
    G.garb = 1;
    
    struct State H;
    H.state = 'H';
    H.garb = 1;
   
   current_state = &C;
   
   A.next0 = &H;
   A.next1 = &B;
   
   B.next0 = &G;
   B.next1 = &E;
   
   C.next0 = &F;
   C.next1 = &C;
   
   D.next0 = &A;
   D.next1 = &G;
   
   E.next0 = &B;
   E.next1 = &C;
   
   F.next0 = &D;
   F.next1 = &H;
   
   G.next0 = &C;
   G.next1 = &A;
   
   H.next0 = &E;
   H.next1 = &D;
   
   A.next = &B;
   B.next = &C;
   C.next = &D;
   D.next = &E;
   E.next = &F;
   F.next = &G;
   G.next = &H;
   H.next = NULL;
   starting_state = &A;
   int a = 1;
  printf("%c \n",current_state->state);
  while(1!=0){
      int k =0;
      fgets(input,sizeof(input),stdin);
      if(isdigit(input[0])){
           data=(int)(input[0])-48;
           if(data ==0){
               current_state = current_state->next0;
               printf("%c \n",current_state->state);
           }
           else if(data == 1){
               current_state = current_state->next1;
               printf("%c \n",current_state->state);
           }
           else{
             printf("Incorrect value");
           }
      }
      
       if(input[0]=='c'){
           
            for(int i =0;i<sizeof(input);i++){
                if(!isspace(input[i])){
                    input[k]=input[i];
                    k++;}
                }
            change(starting_state,input,current_state);
            
       }
       
       if(input[0]=='p'){
           printList(starting_state);
       }
      if(input[0] == 'g'){
         garbage(starting_state,garbage_state);
         if(garbage_state[0] == '\0'){
             printf("garbage is empty");
         }
         else{
            for(int i = 0; i<8;i++){
                if(garbage_state[i] != '\0'){
                    printf(" Garbage : %c ",garbage_state[i]);
                }
            }
         }
      }
      
      if(input[0] == 'd'){
         if(starting_state->garb == 2 ){
             printf("Deleted: %c",starting_state->state);
             starting_state = starting_state->next;
         }
         delete(starting_state);
      }
      
  }

 
      

  
    return 0;
}
