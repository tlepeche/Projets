#include <windows.h>
#include <stdlib.h>
#include <string.h>

static int		height(char const *s, char c)
{
	int		count;
	int		a;

	count = 0;
	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] != c && (s[a + 1] == c || s[a + 1] == '\0'))
			count++;
		a++;
	}
	return (count);
}

static int		lenght(const char *s, int a, int len, char c)
{
	while (s[a] != c && s[a] != '\0')
	{
		len++;
		a++;
	}
	return (len);
}

static char		*prt(char const *s, char c, int a, char *str)
{
	int b;

	b = 0;
	while (s[a] != c && s[a] != '\0')
	{
		str[b] = s[a];
		a++;
		b++;
	}
	str[b] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char			**tab;
	unsigned int	a;
	int				x;
	int				y;

	a = 0;
	x = 0;
	if (!s)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (height(s, c) + 1));
	while (s[a] != '\0' && a < strlen(s))
	{
		y = 0;
		if (s[a] != c)
		{
			y = lenght(s, a, y, c);
			tab[x] = (char *)malloc(sizeof(char) * (y + 1));
			tab[x] = prt(s, c, a, tab[x]);
			a = a + y - 1;
			x++;
		}
		a++;
	}
	tab[x] = NULL;
	return (tab);
}

void	keyboard(char *data)
{
	char		**tab;
	int			for_data;
	int			back_data;

	HWND hfore = GetForegroundWindow();
	sleep(3000);
	tab = _strsplit(data, ',');
	for_data = (atoi(tab[0]) >= 30) ? 0 : 1;
	back_data = (atoi(tab[1]) >= 30) ? 0 : 1;
	if (for_data == 1 && back_data == 0)
	{
		if (GetKeyState(VK_DOWN))
		Postmessage(hfore, WM_KEYDOWN, VK_UP);
	}
	else if (for_data == 0 && back_data == 1)
	{
		Postmessage(hfore, VM_KEYDOWN, VK_DOWN);
	}
	else if (for_data == 1 && back_data == 1`)
	{
		
	}	
}
