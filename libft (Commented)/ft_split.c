/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hepiment < hepiment@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 20:43:21 by hepiment          #+#    #+#             */
/*   Updated: 2022/06/20 03:19:26 by hepiment         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* A cada c caractere na string usada como argumento, a função cria um novo array com a string dividida. A função por fim retorna a um ponteiro que aponta para um array de ponteiros que apontam, cada um, a uma string divida pela função */

/* A função static usada apenas nesse bloco de código, strncpy serve para passar para cada array novo a string dividia pelo delimitador */
static char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	count_size;

	count_size = 0;
	while (src[count_size] && count_size < n)
	{
		dst[count_size] = src[count_size];
		count_size++;
	}
	while (count_size < n)
	{
		dst[count_size] = '\0';
		count_size++;
	}
	return (dst);
}

/* A função counterwords vai definir quantas vezes o caractere delimitador aparece na string e vai retornar a quantidade total de arrays divididas */
static char	counterwords(const char *s, char c)
{
	int	index;
	int	count;
	int	findword;

	findword = 0;
	count = 0;
	index = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c && findword == 0)
		{
			findword = 1;
			count++;
		}
		else if (s[index] == c && findword == 1)
			findword = 0;
		index++;
	}
	return (count);
}

/* A função strndup vai ser usada para alocar na memória cada string dividida e chama a função strncpy para copiar a string */
static char	*ft_strndup(const char *s, size_t len)
{
	char	*str;

	str = (char *) malloc (sizeof(char) * len + 1);
	if (str == 0)
		return (NULL);
	str = ft_strncpy(str, s, len);
	str[len] = '\0';
	return (str);
}


char	**ft_split(char const *s, char c)
{
	int		index;
	int		posc;
	int		n;
	char	**new_str;
	/* index da posição na string */
	index = 0;
	/* Posição do primeiro caractere da string dividida */
	posc = 0;
	n = 0;
	/* A new_str vai ser um ponteiro que aponta para cada string criada na divisão da string passada como argumento. Seu tamanho alocado vai ser de acordo com o valor retornado pela função counterwords mais 1 que é o '/0' */
	new_str = (char **) malloc(sizeof (char *) * ((counterwords(s, c) + 1)));
	/* Se a nova string tiver tamanho nulo a função retorna NULL */
	if (new_str == 0)
		return (NULL);
	while (s[index] != '\0')
	{
		while (s[index] == c)
		index++;
		posc = index;
		while (s[index] != '\0' && s[index] != c)
			index++;
		if (index > posc)
			new_str[n++] = ft_strndup(s + posc, index - posc);
	}
	new_str[n] = NULL;
	return (new_str);
}