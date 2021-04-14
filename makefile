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

clean:
	@echo "Cleaning: "
	rm -rf *.o p3_e1a p3_e1b