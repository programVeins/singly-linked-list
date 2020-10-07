#Makefile

slist:	main.o slist.o
	gcc main.c slist.c -o slist

clean:
	rm *.o slist