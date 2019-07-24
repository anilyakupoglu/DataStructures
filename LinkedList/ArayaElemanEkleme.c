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



void arayaEkleme(int x, int y){
	
	struct node* arayaEklenecek = (struct node*)malloc(sizeof(struct node));
	arayaEklenecek->data = y;
	
	q=start;
	while(q->next->data != x){
		q=q->next;
	}
	struct node* onune = (struct node*)malloc(sizeof(struct node));
	onune = q->next;
	q->next = arayaEklenecek;
	arayaEklenecek->next = onune;
	
	
	
}



int main(){
	
	
	int secim,sona,basa,x,y;
	while(1==1){
	
	printf("\n [1] Basa eleman ekleme islemi");
	printf("\n [2] Sona eleman ekleme islemi");
	printf("\n [3] Araya eleman ekleme islemi");  
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
			printf("Hangi sayinin oncesine eleman eklenecek : ");
			scanf("%d", &x);
			printf("Eklenecek sayiyi giriniz : ");
			scanf("%d", &y);
			arayaEkleme(x,y);
			Yazdir();
			break;	
	
		
	}
	
	

	}
	
}
