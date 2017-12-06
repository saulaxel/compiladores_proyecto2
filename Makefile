# Instrucciones de compilacion para el analizador lexico
# en aleman

# Compilador de C
CC = gcc

# Compilador de flex
FC = flex

# Banderas
CFLAGS = -std=gnu11 -Wall -Wextra -O3 -Wno-unused-parameters -Wno-sign-compare -Wno-unused-function -I. -D NDEBUG

analizador: salida_compilacion/analizador_lex.yy.o salida_compilacion/pila.o
	$(CC) -o $@ $^ $(CFLAGS)

salida_compilacion/analizador_lex.yy.o: salida_compilacion/analizador_lex.yy.c
	$(CC) -c -o $@ $^ $(CFLAGS)

salida_compilacion/pila.o: pila.c pila.h
	$(CC) -c -o $@ pila.c $(CFLAGS)

salida_compilacion/analizador_lex.yy.c: analizador.l
	$(FC) -o $@ $^

clean:
	rm salida_compilacion/*.yy.c salida_compilacion/*.o analizador
