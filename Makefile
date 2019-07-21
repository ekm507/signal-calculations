play: function.o convolution.o play-main.o
	gcc play-main.o convolution.o function.o -o play

function.o: function.c function.h
	gcc -c function.c

convolution.o: convolution.c convolution.h
	gcc -c convolution.c

play-main.o: play-main.c
	gcc -c play-main.c

clean:
	rm *.o play
