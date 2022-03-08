/*
Ali Eray AKGÜL 
02210224056
Ödev--1
*/

#include <stdbool.h> 
#include<stdio.h>
#define MAX 9
int Kuyruk[MAX], front = -1, rear = -1;

void enQueue(int a) {
	//kuyruða eleman ekleme fonksiyonudur.
	
  if (rear == MAX - 1)
    printf("kuyruk dolu");
  else {
    if (front == -1)
      front = 0;
    rear++;
    Kuyruk[rear] = a;
   
  }
}

int deQueue() {
 //kuyruktan eleman silme fonksyonudur.
//burada deðer silme fonksiyonu yapýlýrken ayný zamanda silinen deðer
// döndürülerek dýþarýya verilmiþ ve main içinde
//  bu deðerle karþýlaþtýrma yspýlmýþtýr.
 int k;
// k deðiþkeni tanýmlanmýþtýr çünkü frontun o anki deðeri bize lazýmdýr
 if (front == -1)
    printf("\nkuyruk boþ");
  else {
	k=front;
    front++;
    if (front > rear)
      front = rear = -1;
  }
  return Kuyruk[k];
}

void yazdirkuyruk() {
  //kuyruk yazdýrmaa iþlemidir
  if (rear == -1)
    printf("\nkuyruk boþ");
  else {
    int i;
    printf("\nKuyruk elemanlari\n");
    for (i = front; i <= rear; i++)
      printf("%d  ", Kuyruk[i]);
  }
  printf("\n");
}

//stack(yigit) listeleme programi
int dizi[MAX];
int top=-1;

int Dolumu(){
	//dolumu kontrol eden fonksyondur 
	if(top==MAX-1){
		return 1;
	}
	else{
		return 0;
	}
}
int Bosmu(){
	//boþ olduðunu kontrol eder
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

void push(int a){
	//yýðýta eleman ekleme fonksiyonudur
	if (Dolumu()==1){
			printf("Yigit doludur! \n");
			}
	else{
	    top++;
	    dizi[top]=a;
	}
}

int pop(){
	//yýðýtdan eleman siler ve silinen
	// deðeri dönderirki ilerde karþýlaþtýrma yapýlabilsin
return	dizi[top--] ;	
}

void Yazdiryigit(){
	//yazdýrýr
	if(Bosmu()){
		printf("Yigit bostur!\n");
	}
	else{
		int i;
		printf("yigit elemanlari\n");
		for(i=0;i<=top;i++){
			printf(" %d \n",dizi[i]);
		}
		printf("\n");
	}
}



main(){
	printf("kac adet sayi gireceksiniz:(0-9 adet girebilirsiniz)");
	int sayiAdet;
	scanf("%d",&sayiAdet);
	if(sayiAdet<=9){
//yukarýdaki if ile maxtan fazla sayý alýnmasý engellenmiþtir.
	
	if(sayiAdet%2==0){
//girilen sayý adedi çift ise bu satýr çalýþýr,
//buradakþ mantýk alýnan deðerler bir diziye aktarýlýr
//ve diziden kuyruk ve yýðýta push ve enQueue fonksiyonlarýyla aktarýlýr
	int i;
	int numberArray[sayiAdet];	
	for(i=0;i<sayiAdet;i++){
		scanf("%d",&numberArray[i]);
	}
	int j;
	for(j=0;j<sayiAdet/2;j++){
	enQueue(numberArray[j]);
	}
int k;
for(k=sayiAdet/2;k<sayiAdet;k++){
push(numberArray[k]);
}
	}
	
	
	else {
		
		//eðerki tek sayý ise ortadaki deðeri iþleme katmamak için
		// kuyruða ekleme yaparken ortadaki elemanýn 1 fazlasýndan
		//ekleme yapýlarak ortadaki eleman iþleme alýnmaz.
		//ayný üstteki mantýkla elemanlar eklenir.
		int i;
	int numberArray[sayiAdet];	
	for(i=0;i<sayiAdet;i++){
		scanf("%d",&numberArray[i]);
	}
	int j;
	for(j=0;j<sayiAdet/2;j++){
	enQueue(numberArray[j]);
	}
int k;
for(k=sayiAdet/2+1;k<sayiAdet;k++){
push(numberArray[k]);
}	
	}
yazdirkuyruk();
 Yazdiryigit();
int s;

//aþþaðýda bir boolean deðiþkeni tanýmlayarak
//if içindeki þart saðlandýðýnda deðiþkenin deðeride 
//deðiþir ve böylece for döngüsü içinde sürekli olarak
//palindromdur yazýsý yazmaz :)
bool a =false;
for(s=1;s<sayiAdet/2;s++){
	if(pop()==deQueue()){
//silme fonksiyonlarýmýzý yazarken silinen deðerleri 
//return ifadesiyle döndürmþtük
//üstekki ifadede ise girilen sayýlarýn yarýsýna kadarki
//deðerler karþýlaþtýrýlýr
//zaten yarýsýný kuyruða yarýsýný yýðýta atmýþtýk 
//o yüzden bütün elemanlarý karþýlaþtýrýr.
		a=true;
	}
	
}



	if(a){
		printf("palindromdur");
	}	
	else
	printf("palindrom degildir");													

//þart true ya dönmüþse palindromdur
	}
	else
	printf("Max 9 sayi girebilirsiniz!!");

}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

