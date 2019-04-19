/**
* <p>
* JAVA KODUNUN C DİLİNDE BENZETİMİ
* </p>
*/
#include "rastgeleImeiNo.h"
#include <conio.h>
#include <time.h>
#include <string.h>

Imei ImeiOlustur(){//struct yapisindaki degiskenlere ulasilir
	Imei this;
	this=(Imei)malloc(sizeof(struct IMEI));
	this->imei = (int*)malloc(sizeof(int)*15);
	return this;
	
	
}

int imeiNoUret(const Imei ata){
	int toplam=0;
    int *gimei= (int*)malloc(sizeof(int)*15);//boyutu 15 olan dizi olusturulur
    int carp=1;
    for(int i=0;i<14;i++){ //ilk 14 deger random atanir
        gimei[i]=rand()%9;
	}
	for(int i=1;i<14;i+=2){ //cift sirada olan sayilari alir
          
              carp=gimei[i]*2; //2 ile carpar
              toplam+=(carp/10)+(carp%10); //10 a bolumden kalan ve 10 a modunu toplayip toplam degiskenine ekler          
          
    }
	for(int i=0;i<13;i+=2){
        toplam+=gimei[i]; //tek siradaki sayilari toplama ekler
    }
    gimei[14]=(10-(toplam%10))%10;//son elemanin degerini bulur
    ata->imei=gimei;   
    
	   
	
}


void imeiKontrol(const Imei ata){
	FILE *fp = fopen("kisiler.txt","r");//kisiler.txt okuma modunda acilir
	//atanacak gecici degiskenler olusturulur
	char *g_isim;
	char *g_soyisim;
	char *g_tc;
	char *g_yas;
	char *g_imei;
	char *g_telno;
	int *sorgu_imei;
	//boyutlar ve bellekte ayrilacak olan yer ayrilir
	sorgu_imei=(int*)malloc(sizeof(int)*15);
	g_isim=(char*)malloc(sizeof(char)*100);
	g_soyisim=(char*)malloc(sizeof(char)*100);
	g_tc=(char*)malloc(sizeof(char)*11);
	g_yas=(char*)malloc(sizeof(char)*100);
	g_imei=(char*)malloc(sizeof(char)*15);
	g_telno=(char*)malloc(sizeof(char)*100);
	int gecerli=0;
	int gecersiz=0;
	
	printf("IMEI Kontrol\n");
	while(!feof(fp)){
		fscanf(fp,"%s %s %s %s %s (%s)\n",g_tc,g_isim,g_soyisim,g_yas,g_telno,g_imei);
		if(!feof(fp)==1){
			int toplam=0;
			int carp=1;
			int kontrol_hane=0;
			for(int i=0;i<15;i++){
				sorgu_imei[i]=g_imei[i]-'0';
			}
			
			//kontrol kısmı
			for(int i=1;i<14;i+=2){ //cift sirada olan sayilari alir
          
				carp=sorgu_imei[i]*2; //2 ile carpar
				toplam+=(carp/10)+(carp%10); //10 a bolumden kalan ve 10 a modunu toplayip toplam degiskenine ekler          
          
			}
			for(int i=0;i<13;i+=2){
				toplam+=sorgu_imei[i]; //tek siradaki sayilari toplama ekler
			}
			kontrol_hane=(10-(toplam%10))%10;
			
			if(kontrol_hane==sorgu_imei[14]){
				//gecerli ise
				gecerli++;
					
			}
			else{
				//gecersiz ise
				gecersiz++;
			
			}	
			
		}
		
		
	}
	fclose(fp);	//dosya kapama
	//gecerli gecersiz yazimi
	printf("%d Gecerli\n",gecerli);
	printf("%d Gecersiz\n",gecersiz);
	
}
