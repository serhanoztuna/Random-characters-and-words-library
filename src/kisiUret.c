/**
* <p>
* JAVA KODUNUN C DİLİNDE BENZETİMİ
* </p>
*/
//headerlar cagirilir
#include "kisiUret.h"
#include "rastgeleKisi.h"
#include "rastgeleImeiNo.h"
#include "rastgeleTc.h"
#include "rastgeleTelNo.h"
#include <conio.h>
#include <time.h>
#include <string.h>

kisiUret kisiUretOlustur(){//struct yapisindaki degiskenlere ulasilir
	kisiUret this;
	this = (kisiUret)malloc(sizeof(struct KISIURET));//boyut ve yer ayrilir
	return this;
	
	
}

int YasUret(const kisiUret ata){
	//rand yaş olusturulup degiskene atanir
	ata->yas=(int*)malloc(sizeof(int)*2);
	int gecici=0;
	gecici=rand()%90+10;
	ata->yas[1]=(gecici-gecici%10)/10;
	ata->yas[0]=gecici%10;
	
}

void kisiOlusturVeKaydet(const kisiUret ata, int adet){
	//istenilen adet kadar tum yapilar cagirilip yan yana kisiler.txt icine yazdirilir
	for(int j=0;j<adet;j++)
	{
		//yapiar cagiriliyor
		Kisi ar = KisiOlustur();
		Imei can=ImeiOlustur();
		tcNo basak=tcNoOlustur();
		TelNo rnd = telNoOlustur();
		kisiUret uret=kisiUretOlustur();
		IsimSoyisimAta(ar);
		imeiNoUret(can);
		tcNoUret(basak);
		telNoUret(rnd);
		YasUret(uret);
		FILE *fp=fopen("kisiler.txt","a");//yazma modunda acilir
	    //atanan degerler yazdirilir
		for(int i=0;i<11;i++)
			fprintf(fp,"%d",basak->tcNo[i]);
		fprintf(fp," ");
		fprintf(fp,"%s",ar->isim);
		fprintf(fp," ");
		fprintf(fp,"%s",ar->soyisim);
		fprintf(fp," ");
		for(int i=0;i<2;i++)
			fprintf(fp,"%d",uret->yas[i]);
		fprintf(fp," ");
		for(int i=0;i<11;i++)
			fprintf(fp,"%d",rnd->telNo[i]);
		fprintf(fp," ");
		for(int i=0;i<15;i++){
			if(i==0){
				fprintf(fp,"(");
			}
			fprintf(fp,"%d",can->imei[i]);
			if(i==14){
				fprintf(fp,")\n");
		}
	}
	
	fclose(fp);
	//cop oluşmamasi icin kullanilir
	free(ar);
	free(can);
	free(basak);
	free(rnd);
	free(uret);
		
	}
	
}