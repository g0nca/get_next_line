/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggomes-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:15:02 by ggomes-v          #+#    #+#             */
/*   Updated: 2024/11/13 13:15:03 by ggomes-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static char    *extract_line(char *str)
{
    int i;
    char *line;

    while (str[i] && str[i] != '\n')
        i++;
    line = (char *)malloc(sizeof(char) * i + 1);
    if (!line)
        return (NULL);
    
    return (line);
}
static char *read_file(int fd, char *str)
{
    char *buffer;
    int read_bytes;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    read_bytes = 1;
    while(!ft_strchr(str, '\n') && read_bytes != 0)
    {
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        if (read_bytes <= 0)
        {
            free(buffer);
            return (NULL);
        }
        
        buffer[read_bytes] = '\0';
        str = ft_strjoin(str, buffer);
    }
    free(buffer);
    return (str);
}

char    *get_next_line(int fd)
{
    static char *str;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = read_file(fd, str);
    if (!str)
        return (NULL);
    if (str[0] == '\0')
    {
        free(str);
        str = NULL;
        return (NULL);
    }
    line = extract_line(str);

    return (line);
}

int main(void)
{
    int i;
    char *line;

    int fd = open("text.txt", O_RDONLY);
    if (fd == -1)
    {
        write(1, "\nErro ao Abrir o Ficheiro\n", 1);
        return (0);
    }
    i = 0;
    line = get_next_line(fd);
    printf("%s\n", line);
    /*while (line != NULL)
    {
        printf("LINE[%d]:%s", i, line);
        free(line);
        line = get_next_line(fd);
        i++;
    }*/
    close(fd);
    return (0);
}

