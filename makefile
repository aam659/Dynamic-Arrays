DOBJS = real.o integer.o da.o test-da.o
COBJS = real.o integer.o cda.o test-cda.o
SOBJS = real.o integer.o da.o stack.o test-stack.o
QOBJS = real.o integer.o cda.o queue.o test-queue.o
OOPTS = -Wall -Wextra -std=c99 -c -g
EOPTS = -Wall -Wextra -std=c99 -g

all : test-da test-cda test-stack test-queue

test-da : $(DOBJS)
	gcc $(EOPTS) -o test-da $(DOBJS)

test-cda : $(COBJS)
	gcc $(EOPTS) -o test-cda $(COBJS)

test-stack : $(SOBJS)
	gcc $(EOPTS) -o test-stack $(SOBJS)

test-queue : $(QOBJS)
	gcc $(EOPTS) -o test-queue $(QOBJS)

da.o : da.c da.h
	gcc $(OOPTS) da.c

cda.o : cda.c cda.h
	gcc $(OOPTS) cda.c

stack.o : stack.c stack.h da.h
	gcc $(OOPTS) stack.c

queue.o : queue.c queue.h cda.h
	gcc $(OOPTS) queue.c

integer.o : integer.c integer.h
	gcc $(OOPTS) integer.c

real.o : real.c real.h
	gcc $(OOPTS) real.c

test-da.o : test-da.c integer.h real.h da.h
	gcc $(OOPTS) test-da.c

test-cda.o : test-cda.c integer.h real.h cda.h
	gcc $(OOPTS) test-cda.c

test-stack.o : test-stack.c integer.h real.h da.h stack.h
	gcc $(OOPTS) test-stack.c

test-queue.o : test-queue.c integer.h real.h cda.h queue.h
	gcc $(OOPTS) test-queue.c

test :
	#testing da#
	./test-da
	@echo
	@echo
	#testing cda#
	./test-cda
	@echo
	@echo
	#testing stack#
	./test-stack
	@echo
	@echo
	#testing queue#
	./test-queue
	@echo

clean   :
	rm -f *.o test-da test-cda test-stack test-queue


