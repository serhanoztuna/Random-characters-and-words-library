/**
* <p>
* JAVA KODUNUN C DİLİNDE BENZETİMİ
* </p>
*/
#ifndef KISIURET_H
#define KISIURET_H
#include "stdio.h"
#include "stdlib.h"

struct KISIURET{//degiskenler tanimlanir
	int *yas;
};
//metod yapilari tanimlanir
typedef struct KISIURET* kisiUret;
kisiUret kisiUretOlustur();
int YasUret(const kisiUret);
void kisiOlusturVeKaydet(const kisiUret,int );

#endif