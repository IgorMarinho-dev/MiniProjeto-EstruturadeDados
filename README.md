# 🏫 Mini Projeto - Sistema de Gestão de Alunos

## 📋 Requisitos do Professor
- ✅ Sala de 60 alunos (lista **SEQUENCIAL** estática)
- ✅ Disciplinas por aluno (lista **ENCADEADA** dinâmica)  
- ✅ Cadastro **ORDENADO** por RGM
- ✅ Menu: incluir/buscar/mostrar/remover
- ✅ "Mais disciplina?" no cadastro
- ✅ Remover + mostrar resultado

## 🎮 Como usar
```bash
g++ Miniprojeto1.cpp -o projeto
./projeto
```

```
=== MENU ===
1 - Cadastrar (nome + RGM + disciplinas)
2 - Mostrar todos (ordenado por RGM)
3 - Buscar por RGM ("não existe" se não achar)
4 - Remover por RGM + mostra resultado
0 - Sair
```

## 🏗️ Arquitetura
```
ListaAlunos[60] (SEQUENCIAL)
├── Aluno{RGM, Nome}
│   └── disciplinas (ENCADEADA)
│       ├── Disc1 → Disc2 → NULL
└── Aluno{...}
    └── disciplinas → ...
```

## 👥 Divisão de Tarefas
| Componente | Responsável |
|------------|-------------|
| Lista sequencial + ordenação por RGM | Tallison |
| Lista encadeada disciplinas | Igor Marinho |
| Menu interativo | Igor Marinho |
| Remoção + validações | Igor Marinho |

## 🧪 Demonstração
```
1. Cadastra: João (123) → [Matemática, Português]
2. Cadastra: Ana (456) → [Física]
3. Mostra: Ana, João (ORDENADO!)
4. Busca 789 → "não existe"
5. Remove 123 → Mostra lista sem João
```

## 📊 Estruturas de Dados
```c
// SEQUENCIAL (Aluno)
Aluno alunos[MAX_ALUNOS];

// ENCADEADA (Disciplina)
struct disc {
    char nome[50];
    struct disc* prox;
};
```

## 🔧 Makefile
```makefile
CC=g++
all:
	$(CC) Miniprojeto1.cpp -o projeto
run: all
	./projeto
clean:
	rm -f projeto
```

## 🎓 Aprendizado
- **Listas sequenciais**: Inserção ordenada O(n)
- **Listas encadeadas**: Alocação dinâmica  
- **Git colaborativo**: Branch + Pull Request

**Entrega: 07/04 ✅**