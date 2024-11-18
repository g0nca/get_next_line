/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:29:32 by marvin            #+#    #+#             */
/*   Updated: 2024/11/13 22:29:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file_lines(int file, char *str)
{
	char *buffer;
	int	count_bytes;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	
	count_bytes = 1;
	while (!ft_strchr(str, '\n') && count_bytes != 0)
	{
		count_bytes = read(file, buffer, BUFFER_SIZE);
		if (count_bytes == -1)
		{
			free (buffer);
			return (0);
		}
		buffer[count_bytes] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int file)
{
	static char *str;
	//char *reader;

	str = read_file_lines(file, str);
	if (!str)
		return (NULL);
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	
	return (str);

}

int main(void)
{
	char *line;
	int i;
	int file;

	file = open("test1.txt", O_RDONLY);
	if (file == -1) {
		perror("Error opening file");
		return (1);
	}
	i = 1;
	printf("buffer size > %d\n", BUFFER_SIZE);
	line = get_next_line(file);
	while (line != 0)
	{
		printf("LINE[%02d]: %s\n", i, line);
		free(line);
		line = get_next_line(file);
		i++;
	}
	close(file);
	return (0);
}
