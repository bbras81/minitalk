# 42_libft

Este projeto consiste na implementação da biblioteca `libft`, uma coleção de funções da linguagem C, juntamente com as implementações de `get_next_line` e `ft_printf`, seguindo as normas da 42.

## Estrutura do Projeto

- `ft_libft/` — Funções da libft (ex: `ft_strlen`, `ft_memcpy`, etc.)
- `ft_get_next_line/` — Implementação da função `get_next_line` e utilitários
- `ft_printf/` — Implementação da função `ft_printf`
- `includes/` — Ficheiros de cabeçalho (`.h`)
- `Makefile` — Permite compilar as diferentes bibliotecas

## Como compilar

```sh
make            # Compila a libft (libft.a)
make get_next_line  # Compila get_next_line (get_next_line.a)
make ft_printf      # Compila ft_printf (libftprintf.a)
make fclean     # Limpa todos os ficheiros objeto e bibliotecas
```

## Utilização

Inclui os headers necessários do diretório `includes/` no teu projeto e linka as bibliotecas desejadas (`libft.a`, `get_next_line.a`, `libftprintf.a`).

## Autoria

- brunmigu — <brunmigu@student.42.fr>

---

Projeto desenvolvido para a 42 Porto.
