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
	
	//Baþlangýçta düðüm yoksa ilk düðüm olarak oluþturacak.
	if(start ==NULL)
	{	
		start = eklenecekDeger;	
	}
	else
	{
		//Traverse iþlemi burada yapýlýyor. Baðlý liste içerisinde gezilip sona eleman ekleniyor.
		q=start;
		while(q->next != NULL)
		{
			q=q->next;	
		}
		q->next = eklenecekDeger;
		
	}
	
}

void Yazdir(){
	
	//Yazdýrmak için de Traverse (Dolaþým) iþlemi yapýlýr.
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
	//Eklenecek deðerin baþa geçmesi için next'ine start deðeri verilir.
	basaEklenecek->next = start;
	//start deðeri yeni eklenen deðer olarak güncellenir.
	start = basaEklenecek;
	
}

void sondanSil(){
	
	q=start;
	while(q->next->next != NULL){
		q = q->next;
	}
	// son düðüm için hafýzada oluþturulan alaný siler.
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
