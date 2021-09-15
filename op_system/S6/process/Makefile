process: main.c ./headers/process.h
	gcc -g main.c ./src/process.c -o ./compiled/process

run: main.c
	./compiled/process

wait: main_wait.c ./headers/process.h
	gcc -g main_wait.c ./src/process.c -o ./compiled/wait

run_wait: main_wait.c
	./compiled/wait