#include <stdio.h>
#include <stdlib.h>


struct node{
	
	int data;
	struct node *next;
	
};

struct node* start = NULL;
struct node* temp  = NULL;
struct node* q     = NULL;


void basaEkle(int basa){
	
	struct node *basaEklenecek = (struct node*)malloc(sizeof(struct node));
	basaEklenecek->data = basa;
	basaEklenecek->next = start;
	start = basaEklenecek;
	
}

void Yazdir(){
	
	q=start;
	while(q->next != NULL){
		
		printf("%d =>", q->data);
		q=q->next;

	}
	printf("%d =>", q->data);
	
}


int main(){
	
	int secim;
	while(1==1){
		
		printf("\n Bir sayi giriniz :");
		scanf("%d", &secim);
		basaEkle(secim);
		Yazdir();
	
	}
	
	
	
}
