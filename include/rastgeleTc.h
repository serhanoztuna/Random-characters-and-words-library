/**
* <p>
* JAVA KODUNUN C DİLİNDE BENZETİMİ
* </p>
*/
#ifndef RASTGELETC_H
#define RASTGELETC_H
#include "stdio.h"
#include "stdlib.h"

struct TCNO{//degiskenler tanimlanir
	int *tcNo;
	int kontrol;
};
//metod yapilari tanimlanir
typedef struct TCNO* tcNo;
tcNo tcNoOlustur();
int tcNoUret(const tcNo);
void tcKontrol(const tcNo);


#endif