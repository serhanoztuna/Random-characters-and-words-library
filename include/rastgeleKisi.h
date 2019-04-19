/**
* <p>
* JAVA KODUNUN C DİLİNDE BENZETİMİ
* </p>
*/
#ifndef RASTGELEKISI_H
#define RASTGELEKISI_H
#include "stdio.h"
#include "stdlib.h"

struct KISI{//degiskenler tanimlanir
	char *isim;
	char *soyisim;
	
	
};
//metod yapilari tanimlanir
typedef struct KISI* Kisi;
Kisi KisiOlustur();
void IsimSoyisimAta(const Kisi);


#endif