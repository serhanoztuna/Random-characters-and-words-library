#include "rastgeleKisi.h"
#include <conio.h>
/**
*
* <p>
* JAVA KODUNUN C DİLİNDE BENZETİMİ
* </p>
*/
#include <time.h>
#include <string.h>

Kisi KisiOlustur(){//struct yapisindaki degiskenlere ulasilir
	
	Kisi this;
	this=(Kisi)malloc(sizeof(struct KISI));
	return this;
	
}

void IsimSoyisimAta(const Kisi ata){ 
	//structtaki degiskene atanacak olan gecici degiskenler tanimlanir
	char *g_isim;
	char *g_soyisim;
	//boyut ve yer ayrilir
	g_isim=(char*)malloc(sizeof(char)*100);
	g_soyisim=(char*)malloc(sizeof(char)*100);
	
	int gecici=rand()%2999+1;
	int sayac=0;
	
	FILE *fp = fopen("randisimler.txt","r");//randisimler.txt okuma modunda acilir
	while(!feof(fp)){//dosya okunurken 
		fscanf(fp,"%s %s",g_isim,g_soyisim); //dosyadakiler degiskenler okunur
		sayac++;
		if(sayac==gecici){//random sayiy sayac  esit olursa
			//dosyanan alinan degisken structtaki degiskenimize göstericiyle atanir
			ata->isim=g_isim; 
			ata->soyisim=g_soyisim;
			break;
		}
	}
	fclose(fp);	//dosya kapama
}

	

