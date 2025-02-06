# Get Next Line

## Descrição

O **get_next_line** é um projeto que visa a implementação de uma função capaz de ler uma linha de um descritor de arquivo (file descriptor) de forma eficiente. Essa função é amplamente utilizada em programas que exigem leitura de arquivos ou entrada padronizada (stdin) linha por linha.

## Funcionamento

A função `get_next_line(int fd)` retorna uma linha do arquivo especificado pelo descritor `fd` sempre que for chamada. A leitura é feita de maneira incremental e utiliza um buffer dinâmico para armazenar os dados.

Ela segue as seguintes regras:
- Retorna uma linha do arquivo, incluindo o `\n` caso esteja presente.
- Retorna `NULL` ao final do arquivo ou em caso de erro.
- Funciona corretamente com qualquer tipo de arquivo.
- Utiliza uma variável estática para armazenar dados entre chamadas sucessivas.

## Como Compilar

O `get_next_line` pode ser compilado junto com seu projeto utilizando um compilador como o **gcc**:

```sh
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

Aqui, `BUFFER_SIZE` é uma macro que define o tamanho do buffer utilizado para leitura do arquivo. O valor pode ser ajustado conforme necessidade.

## Uso

Exemplo de uso do `get_next_line` para ler um arquivo linha por linha:

```c
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("arquivo.txt", O_RDONLY);
    char *line;
    
    if (fd == -1)
        return (1);
    
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Estrutura do Projeto

- `get_next_line.c` → Contém a implementação principal da função `get_next_line`.
- `get_next_line_utils.c` → Funções auxiliares utilizadas pelo `get_next_line`.
- `get_next_line.h` → Arquivo de cabeçalho com as declarações das funções.
- `arquivo.txt` → Arquivo de teste para leitura linha por linha.

## Regras e Restrições

- O código deve estar em conformidade com a **Norminette**.
- O uso de funções de alocação dinâmica (à exceção de `malloc`, `free` e `read`) é proibido.
- A função deve funcionar com diferentes tamanhos de `BUFFER_SIZE`.

## Autores

- [Seu Nome](https://github.com/seu_usuario)

---

Sinta-se à vontade para modificar este README conforme necessário. 🚀

