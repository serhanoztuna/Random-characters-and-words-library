/**
* <p>
* JAVA KODUNUN C DİLİNDE BENZETİMİ
* </p>
*/
#ifndef RASTGELEIMEINO_H
#define RASTGELEIMEINO_H
#include "stdio.h"
#include "stdlib.h"

struct IMEI{//degiskenler tanimlanir
	int *imei;
	int kontrol;	
};
//metod yapilari tanimlanir
typedef struct IMEI* Imei;
Imei ImeiOlustur();
int imeiNoUret(const Imei);
void imeiKontrol(const Imei);
#endif