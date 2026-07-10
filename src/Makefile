#  Autor: Matheus Pires Kaster

PROJ_NAME := ted
CC        := gcc
CFLAGS    := -W -Wall -Wextra -ggdb -std=c99 -fstack-protector-all
LIBS      := -lm

SOURCES   := $(wildcard *.c)
OBJETOS   := $(SOURCES:.c=.o)

# --- Variáveis para o Teste ---
TEST_EXEC := ../executavel/rodar_testes
UNITY_SRC := ../unity/unity.c
SRC_TESTE := ../tests/teste_dijkstra.c ../src/dijkstra.c ../src/fila_de_prioridade.c ../src/grafo.c ../src/vertice.c ../src/aresta.c ../src/vetor.c ../src/mapa.c ../src/lista.c

	# Módulos para colocar no SRC_TESTE para fazer rodar:
		# Vertice: ../tests/teste_vertice.c ../src/vertice.c
		# Aresta: ../tests/teste_aresta.c ../src/aresta.c ../src/vertice.c
		# Lista: ../tests/teste_lista.c ../src/lista.c ../src/aresta.c ../src/vertice.c
		# Mapa: ../tests/teste_mapa.c ../src/mapa.c
		# Grafo: ../tests/teste_grafo.c ../src/grafo.c ../src/vertice.c ../src/aresta.c ../src/vetor.c ../src/lista.c
		# Fila: ../tests/teste_fila_de_prioridade.c ../src/fila_de_prioridade.c
		# Dijkstra: ../tests/teste_dijkstra.c ../src/dijkstra.c ../src/fila_de_prioridade.c ../src/grafo.c ../src/vertice.c ../src/aresta.c ../src/mapa.c ../src/lista.c
# ------------------------------

# Regras de compilação:
all: $(PROJ_NAME)

$(PROJ_NAME): $(OBJETOS)
	@echo "Linkando $(PROJ_NAME)..."
	@$(CC) -o $@ $^ $(LIBS)
	@echo "✓ Build completo!"

%.o: %.c
	@echo "Compilando $<..."
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "Limpando arquivos..."
	@rm -f *.o $(PROJ_NAME)
	@echo "✓ Limpeza concluída!"

# --- Regra para Rodar os Testes ---
test:
	@echo "Compilando e linkando os testes..."
	@$(CC) $(CFLAGS) -o $(TEST_EXEC) $(SRC_TESTE) $(UNITY_SRC) $(LIBS)
	@echo "✓ Build de testes completo! Executando:"
	@echo "----------------------------------------"
	@./$(TEST_EXEC)

# --- Regra para rodar junto com o valgrind ---
valgrind:
	@echo "Compilando e preparando para o Valgrind..."
	@$(CC) $(CFLAGS) -o $(TEST_EXEC) $(SRC_TESTE) $(UNITY_SRC) $(LIBS)
	@echo "✓ Build completo! Iniciando Valgrind:"
	@echo "----------------------------------------"
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_EXEC)

.PHONY: all clean test valgrind

# código para rodar: make -C src test
# código para rodar os testes com o valgrind: make -C src valgrind