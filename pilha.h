#ifndef pilha_h
#define pilha_h 
#include <stdio.h>
#define PILHA_MAX 100

typedef int tp_item;

typedef struct{
int topo;
	tp_item item[PILHA_MAX];
	}tp_pilha;

void inicializa_pilha(tp_pilha *p){
	p->topo=-1;
}
// vê se a pilha ta vazia
int pilha_vazia(tp_pilha *p){
	if(p->topo == -1) return 1;
	return 0;
}
//vê se a pilha ta cheia
int pilha_cheia(tp_pilha *p){
	if(p->topo == PILHA_MAX-1){
	return 1;}
	else return 0;
}
//empilha um elemento
int push(tp_pilha *p,tp_item e){
	if (pilha_cheia(p)) return 0;
	p->topo++;
	p->item[p->topo] = e;
	return 1;
}

int pop(tp_pilha *p, tp_item *e){
	if (pilha_vazia(p)) return 0;
	*e=p->item[p->topo];
	p->topo--;
	return 1;
}

int top(tp_pilha *p, tp_item *e){
	if (pilha_vazia(p)) return 0;
	*e=p->item[p->topo];
	return 1;
}

int altura_pilha(tp_pilha *p){
	return p-> topo + 1;
}

void imprime_pilha(tp_pilha p){
	tp_item e;
	while (pilha_vazia(&p) == 0){
		pop(&p, &e);
		printf("%d\n", e);
		
	}
}

void retira_impar(tp_pilha *p){
  tp_item e;
  tp_pilha pilha2;
  inicializa_pilha(&pilha2);
  
  while(!pilha_vazia(p)){
    pop(p,&e);
    if (e%2 == 0)
      push(&pilha2, e);
  }

  while(!pilha_vazia(&pilha2)){
    pop(&pilha2, &e);
    push(p,e);
}
  
}
int pilhas_iguais(tp_pilha p1, tp_pilha p2){
  tp_item e1, e2;
  if(altura_pilha(&p1) != altura_pilha(&p2))
    return 0;
  
  while(!pilha_vazia(&p1)){
    pop(&p1,&e1);
    pop(&p2,&e2);
    if 
    (e1 != e2)
    return 0;
  }
  return 1;
}

int empilha_pilhas (tp_pilha *p1, tp_pilha *p2){
  tp_item e;
  tp_pilha pilha2;
  inicializa_pilha(&pilha2);
  
  if(altura_pilha(p1)+altura_pilha(p2) > PILHA_MAX) return 0;
  
  
  while(!pilha_vazia(p2)) {
    pop(p2, &e);
    push(&pilha2, e);
  }
  while(!pilha_vazia(&pilha2)){
    pop(&pilha2,&e);
    push(p1,e);
  }
  return 1;
    
}

#endif

