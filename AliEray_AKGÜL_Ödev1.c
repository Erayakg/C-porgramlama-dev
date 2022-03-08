/*
Ali Eray AKG�L 
02210224056
�dev--1
*/

#include <stdbool.h> 
#include<stdio.h>
#define MAX 9
int Kuyruk[MAX], front = -1, rear = -1;

void enQueue(int a) {
	//kuyru�a eleman ekleme fonksiyonudur.
	
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
//burada de�er silme fonksiyonu yap�l�rken ayn� zamanda silinen de�er
// d�nd�r�lerek d��ar�ya verilmi� ve main i�inde
//  bu de�erle kar��la�t�rma ysp�lm��t�r.
 int k;
// k de�i�keni tan�mlanm��t�r ��nk� frontun o anki de�eri bize laz�md�r
 if (front == -1)
    printf("\nkuyruk bo�");
  else {
	k=front;
    front++;
    if (front > rear)
      front = rear = -1;
  }
  return Kuyruk[k];
}

void yazdirkuyruk() {
  //kuyruk yazd�rmaa i�lemidir
  if (rear == -1)
    printf("\nkuyruk bo�");
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
	//bo� oldu�unu kontrol eder
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

void push(int a){
	//y���ta eleman ekleme fonksiyonudur
	if (Dolumu()==1){
			printf("Yigit doludur! \n");
			}
	else{
	    top++;
	    dizi[top]=a;
	}
}

int pop(){
	//y���tdan eleman siler ve silinen
	// de�eri d�nderirki ilerde kar��la�t�rma yap�labilsin
return	dizi[top--] ;	
}

void Yazdiryigit(){
	//yazd�r�r
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
//yukar�daki if ile maxtan fazla say� al�nmas� engellenmi�tir.
	
	if(sayiAdet%2==0){
//girilen say� adedi �ift ise bu sat�r �al���r,
//buradak� mant�k al�nan de�erler bir diziye aktar�l�r
//ve diziden kuyruk ve y���ta push ve enQueue fonksiyonlar�yla aktar�l�r
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
		
		//e�erki tek say� ise ortadaki de�eri i�leme katmamak i�in
		// kuyru�a ekleme yaparken ortadaki eleman�n 1 fazlas�ndan
		//ekleme yap�larak ortadaki eleman i�leme al�nmaz.
		//ayn� �stteki mant�kla elemanlar eklenir.
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

//a��a��da bir boolean de�i�keni tan�mlayarak
//if i�indeki �art sa�land���nda de�i�kenin de�eride 
//de�i�ir ve b�ylece for d�ng�s� i�inde s�rekli olarak
//palindromdur yaz�s� yazmaz :)
bool a =false;
for(s=1;s<sayiAdet/2;s++){
	if(pop()==deQueue()){
//silme fonksiyonlar�m�z� yazarken silinen de�erleri 
//return ifadesiyle d�nd�rm�t�k
//�stekki ifadede ise girilen say�lar�n yar�s�na kadarki
//de�erler kar��la�t�r�l�r
//zaten yar�s�n� kuyru�a yar�s�n� y���ta atm��t�k 
//o y�zden b�t�n elemanlar� kar��la�t�r�r.
		a=true;
	}
	
}



	if(a){
		printf("palindromdur");
	}	
	else
	printf("palindrom degildir");													

//�art true ya d�nm��se palindromdur
	}
	else
	printf("Max 9 sayi girebilirsiniz!!");

}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

