hepsi:derle calistir

derle:

	gcc -I ./include/ -o ./lib/rastgeleKisi.o -c ./src/rastgeleKisi.c
	gcc -I ./include/ -o ./lib/rastgeleImeiNo.o -c ./src/rastgeleImeiNo.c
	gcc -I ./include/ -o ./lib/rastgeleTc.o -c ./src/rastgeleTc.c
	gcc -I ./include/ -o ./lib/rastgeleTelNo.o -c ./src/rastgeleTelNo.c
	gcc -I ./include/ -o ./lib/kisiUret.o -c ./src/kisiUret.c
	gcc -I ./include/ -o ./bin/main ./lib/rastgeleKisi.o ./lib/rastgeleImeiNo.o ./lib/rastgeleTc.o ./lib/rastgeleTelNo.o ./lib/kisiUret.o ./src/main.c
	
calistir:

	./bin/main