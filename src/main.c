/**
* <p>
* JAVA KODUNUN C DİLİNDE BENZETİMİ
* </p>
*/
//headerlar cagirilir
#include "stdio.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "rastgeleKisi.h"
#include "rastgeleImeiNo.h"
#include "rastgeleTc.h"
#include "rastgeleTelNo.h"
#include "kisiUret.h"


int main(){
	srand(time(0));
	while(1){
		int adet=0;
		int secim=0;
      //menu olusturulur
		printf("-----------------Menu---------------\n");
		printf("1-Rastgele Kisi Uret\n2-Uretilmis Dosyayi Kontrol Et\n3-Cikis\nSecim..:");
		scanf("%d",&secim);
		if(secim==1){
			//1 secilirse kac adet kisi olusmasini istersen girilen sayida kisi olusur
			printf("\nKac Adet Kisi Uretilsin..:");
			scanf("%d",&adet);
			kisiUret uret=kisiUretOlustur();
			kisiOlusturVeKaydet(uret,adet);
			//copler yok edilir
			free(uret);
		}
		else if(secim==2){
			//2 secilirse olusturulan tc ve imeinolar kontrol edilir
			tcNo basak=tcNoOlustur();
			tcKontrol(basak);
			Imei can=ImeiOlustur();
			imeiKontrol(can);
			//copler yok edilir
			free(can);
			free(basak);
		}
		else if(secim==3){
			//3 secilirse cikis yapilir
			break;
		}
		else{
			printf("Yanlis Deger Girdiniz..!!");
		}
	}

	return 0;

	
	
	
}







