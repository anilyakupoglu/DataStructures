#include <stdio.h>
#include <stdlib.h>

struct node {
	
	int data;
	struct node *next;
	
};


struct node* start = NULL;
struct node* temp = NULL;
struct node* q = NULL;



void sonaEkle(int veri){
	
	struct node *eklenecekDeger = (struct node*)malloc(sizeof(struct node));
	eklenecekDeger->data = veri;
	eklenecekDeger->next = NULL;
	
	//Ba�lang��ta d���m yoksa ilk d���m olarak olu�turacak.
	if(start ==NULL)
	{	
		start = eklenecekDeger;	
	}
	else
	{
		//Traverse i�lemi burada yap�l�yor. Ba�l� liste i�erisinde gezilip sona eleman ekleniyor.
		q=start;
		while(q->next != NULL)
		{
			q=q->next;	
		}
		q->next = eklenecekDeger;
		
	}
	
}

void Yazdir(){
	
	//Yazd�rmak i�in de Traverse (Dola��m) i�lemi yap�l�r.
	q=start;
	while(q->next !=NULL){
		
		printf("%d => ", q->data);
		q=q->next;
	}
	printf("%d => \n", q->data);
}


void basaEkle(int basa){
	
	struct node *basaEklenecek = (struct node*)malloc(sizeof(struct node));
	basaEklenecek->data = basa;
	//Eklenecek de�erin ba�a ge�mesi i�in next'ine start de�eri verilir.
	basaEklenecek->next = start;
	//start de�eri yeni eklenen de�er olarak g�ncellenir.
	start = basaEklenecek;
	
}

void sondanSil(){
	
	q=start;
	while(q->next->next != NULL){
		q = q->next;
	}
	// son d���m i�in haf�zada olu�turulan alan� siler.
		free(q->next); 
		q->next = NULL;

}

void bastanSil(){
	
	struct node* ikinciEleman = NULL;
	ikinciEleman = start->next;
	free(start);
	start = ikinciEleman;
	
}


void aradanSil(int x){
	
		struct node* PrevNode = NULL;
		struct node* NextNode = NULL;
		if(start->data == x){
			bastanSil();
		}
	
		q=start;
		while(q->next->data != x){
			q=q->next;
		}
		if(q->next == NULL){
			sondanSil();
		}
		
		PrevNode = q;
		NextNode = q->next->next;
		free(q->next);
		PrevNode->next = NextNode;
	
	
	
}



int main(){
	
	
	int secim,sona,basa,x,y;
	while(1==1){
	
	printf("\n [1] Basa eleman ekleme islemi");
	printf("\n [2] Sona eleman ekleme islemi");
	printf("\n [3] Aradan eleman silme islemi");  
	printf("\n Bir islem secin :");
	scanf("%d", &secim);
	
	switch(secim){
		
		case 1:
			printf("Basa eklenecek sayiyi giriniz : ");
			scanf("%d", &basa);
			basaEkle(basa);
			Yazdir();
			break;	
		
		case 2:
			printf("Sona eklenecek sayiyi giriniz : ");
			scanf("%d", &sona);
			sonaEkle(sona);
			Yazdir();
			break;	
		case 3:
			printf("Silinecek sayiyi giriniz : ");
			scanf("%d", &x);
			aradanSil(x);
			Yazdir();
			break;	
	
		
	}
	
	

	}
	
}
