/**
*
* <p>
* JAVA KODUNUN C DİLİNDE BENZETİMİ
* </p>
*/
#include "rastgeleTelNo.h"
#include <conio.h>
#include <time.h>
#include <string.h>

TelNo telNoOlustur(){ //struct degiskenlerine ulasilir.boyut ve yer ayrilir
	
	TelNo this;
	this = (TelNo)malloc(sizeof(struct TELNO));
	return this;
}
int telNoUret(const TelNo ata){
	
	ata->telNo = (int*)malloc(sizeof(int)*11); //dizi icin boyut ve yer ayrilir
	int randomIndex = rand()%24;
	//operatorlere uygun algoritma uygulanir tel no olusur
	ata->telNo[0]=0;
	ata->telNo[1]=5;
	int oparatorBaslangicNumaralari [] ={31,32,33,34,35,36,37,38,39,41,42,43,44,45,46,47,51,52,53,54,55,56,57,58,59};
	int operator = oparatorBaslangicNumaralari[randomIndex];
	ata->telNo[2]=(operator-operator%10)/10;
	ata->telNo[3]=operator%10;
	for(int i=4;i<11;i++)
	{
		ata->telNo[i]=rand()%10; //telno atanir
	}
}