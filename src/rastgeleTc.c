/**
*
* <p>
* JAVA KODUNUN C DİLİNDE BENZETİMİ
* </p>
*/
#include "rastgeleTc.h"
#include <conio.h>
#include <time.h>
#include <string.h>

tcNo tcNoOlustur(){//struct yapisindaki degiskenlere ulasilir
	
	tcNo this;
	this=(tcNo)malloc(sizeof(struct TCNO));//boyut ve yer ayrilir
	this->tcNo = (int*)malloc(sizeof(int)*15);
	return this;
}
int tcNoUret(const tcNo ata){ 
	int toplam=0;
	int gtoplam=0;
	int gecici=0;
	int *tcno= (int*)malloc(sizeof(int)*15);
	//tc algoritmasi uygulanir
	for(int i=0;i<9;i++){ 
			
		tcno[i]=rand()%8+1;
			
	}
	for(int i=0;i<9;i+=2){
		toplam+=tcno[i];
			
	}
	for(int i=1;i<9;i+=2){
		gtoplam+=tcno[i];
		
			
	}
	tcno[9]=(toplam*7-gtoplam)%10;
	for(int i=0;i<10;i++){
		gecici+=tcno[i]; 
			
	}
	tcno[10]=gecici%10; 
	ata->tcNo=tcno; //tc noyu gösterir.Atama islemi yapilir
		
}

void tcKontrol(const tcNo ata){
	
	FILE *fp = fopen("kisiler.txt","r");//kisiler.txt okuma modunda acilir
	//atanacak gecici degiskenler olusturulur
	char *g_isim;
	char *g_soyisim;
	char *g_tc;
	char *g_yas;
	char *g_imei;
	char *g_telno;
	int *sorgu_tc;
	//boyutlar ve bellekte ayrilacak olan yer ayrilir
	sorgu_tc=(int*)malloc(sizeof(int)*11); 
	g_isim=(char*)malloc(sizeof(char)*100);
	g_soyisim=(char*)malloc(sizeof(char)*100);
	g_tc=(char*)malloc(sizeof(char)*11);
	g_yas=(char*)malloc(sizeof(char)*100);
	g_imei=(char*)malloc(sizeof(char)*15);
	g_telno=(char*)malloc(sizeof(char)*100);
	int gecerli=0;
	int gecersiz=0;
	
	printf("T.C Kimlik Kontrol\n");
	while(!feof(fp)){
		fscanf(fp,"%s %s %s %s %s (%s)\n",g_tc,g_isim,g_soyisim,g_yas,g_telno,g_imei);//kisiler.txt den bir satirda bulunan degiskenler alinir
		if(!feof(fp)==1){
			int toplam=0;
			int gtoplam=0;
			int gecici=0;
			int kontrol_hane=0;
			int kontrol_hane2=0;
			for(int i=0;i<11;i++){
				sorgu_tc[i]=g_tc[i]-'0'; //cekilen tc sorgulama icin diziye atanir
			}
			
			//kontrol kısmı
			for(int i=0;i<9;i+=2){
				toplam+=sorgu_tc[i];
			
			
			}
			for(int i=1;i<9;i+=2){
				gtoplam+=sorgu_tc[i];
			
			}
			kontrol_hane=(toplam*7-gtoplam)%10;
			for(int i=0;i<10;i++){
			gecici+=sorgu_tc[i];
			}
			kontrol_hane2=gecici%10;
			if(kontrol_hane==sorgu_tc[9]&&kontrol_hane2==sorgu_tc[10]){
				//gecerli ise
				gecerli++;
			}
			else{
				//gecersiz ise
				gecersiz++;
			}	
		}
	}
	fclose(fp);	
	//gecerli gecersiz yazimi
	printf("%d Gecerli\n",gecerli);
	printf("%d Gecersiz\n",gecersiz);

}
	
