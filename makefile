CFLAGS = -g -Wall -pedantic
CC = gcc
LDFLAGS = -L.
IDFLAGS = -I.
LDLIBS = -ldelivery

p3_e1a: p3_e1a.o libdelivery.a libqueue.a vertex.o
	$(CC) $(CFLAGS) -o $@ $< vertex.o $(LDFLAGS) $(IDFLAGS) $(LDLIBS) $(LDFLAGS) $(IDFLAGS) -lqueue

p3_e1a.o: p3_e1a.c types.h vertex.h product.h delivery.h
	$(CC) $(CFLAGS) -c $<

p3_e1b: p3_e1b.o libdelivery.a libqueue.a vertex.o
	$(CC) $(CFLAGS) -o $@ $< vertex.o $(LDFLAGS) $(IDFLAGS) $(LDLIBS) $(LDFLAGS) $(IDFLAGS) -lqueue

p3_e1b.o: p3_e1b.c types.h vertex.h product.h delivery.h
	$(CC) $(CFLAGS) -c $<

vertex.o: vertex.c vertex.h types.h
	$(CC) $(CFLAGS) -c $<

p3_e2a: p3_e2a.o vertex.o queue.o libdelivery.a
	$(CC) $(CFLAGS) -o $@ $< vertex.o queue.o $(LDFLAGS) $(IDFLAGS) $(LDLIBS)

p3_e2a.o: p3_e2a.c types.h vertex.h product.h delivery.h queue.h
	$(CC) $(CFLAGS) -c $<

p3_e2b: p3_e2b.o vertex.o queue.o libdelivery.a
	$(CC) $(CFLAGS) -o $@ $< vertex.o queue.o $(LDFLAGS) $(IDFLAGS) $(LDLIBS)

p3_e2b.o: p3_e2b.c types.h vertex.h product.h delivery.h queue.h
	$(CC) $(CFLAGS) -c $<

queue.o: queue.c types.h queue.h
	$(CC) $(CFLAGS) -c $<

clean:
	@echo "Cleaning: "
	rm -rf *.o p3_e1a p3_e1b p3_e2a p3_e2b