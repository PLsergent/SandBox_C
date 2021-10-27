tp1_system: tp1_system.c
	gcc -g tp1_system.c -o ./compiled/tp1_system -lpthread

tp2_system2-1,2,3: tp2_system2-1,2,3.c
	gcc -g tp2_system2-1,2,3.c -o ./compiled/tp2_system2-1,2,3 -lpthread

tp2_system2-4: tp2_system2-4.c
	gcc -g tp2_system2-4.c -o ./compiled/tp2_system2-4 -lpthread

tp2_system3-6: tp2_system3-6.c
	gcc -g tp2_system3-6.c -o ./compiled/tp2_system3-6 -lpthread

tp2_system3-7: tp2_system3-7.c
	gcc -g tp2_system3-7.c -o ./compiled/tp2_system3-7 -lpthread -lrt

run1: tp1_system.c
	./compiled/tp1_system

run2-3: tp2_system2-1,2,3.c
	./compiled/tp2_system2-1,2,3

run2-4: tp2_system2-4.c
	./compiled/tp2_system2-4

run3-6: tp2_system3-6.c
	./compiled/tp2_system3-6

run3-7: tp2_system3-7.c
	./compiled/tp2_system3-7