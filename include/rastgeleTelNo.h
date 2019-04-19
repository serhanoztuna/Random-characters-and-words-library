/**
* <p>
* JAVA KODUNUN C DİLİNDE BENZETİMİ
* </p>
*/
#ifndef RASTGELETELNO_H
#define RASTGELETELNO_H
#include "stdio.h"
#include "stdlib.h"

struct TELNO{//degiskenler tanimlanir
	int *telNo;
};
//metod yapilari tanimlanir
typedef struct TELNO* TelNo;
TelNo telNoOlustur();
int telNoUret(const TelNo);

#endif