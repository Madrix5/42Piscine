#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_print(int len, char *str, char **m_bef, char **m_aft);
int	ft_calc_len(int *len, char *str);
int	ft_openfile(char *argv1);
void	ft_print_matrix(char *buffer, char **matrix);
int	find_string_in_matrix(char *src, char **matrix);
int	ft_strcmp(const char *s1, const char *s2);
void	ft_print_unidades(char *str, int x,char **m_bef, char **m_aft);
void	ft_print_teens(char *str, int x, char **m_bef, char **m_aft);
void	ft_print_decenas(char *str, int x, char **m_bef, char **m_aft);
void	ft_print_centenas(char *str, int x, char **m_bef, char **m_aft);
void	ft_apellidos(int m, char **m_bef, char **m_aft);
void	ft_write_in_matrix(char **matrix, char *buffer);
char	**ft_create_matrix(char *buffer, int DescriptorFile);
int	ft_count_cols(char *buffer);
int	ft_count_rows(char *buffer);
char	ft_read(char *buffer, int file_descriptor);
char	*ft_buffer(int file_descriptor);
void	split_matrix(char **original, char ***before, char ***after, int rows, int cols);
void	freee(char **matrix, char **matrix_before, char **matrix_after, int rows);

void ft_print_centenas(char *str, int x, char **m_bef, char **m_aft)
{
    int i;
    int j;

    i = 0;
    while (str[x] != m_bef[i][0] && !(m_bef[i][1] >= '0' && m_bef[i][1] <= '9')) 
    {
        i++;
    }
    j = 0;
    while (m_aft[i][j])
    {
        write(1, &m_aft[i][j],1);
        j++;
    }
    write(1, " hundred ", 9);
    if (str[x + 1] != '0' && str[x + 2] != '0')
    {
        write(1, "and ", 4);
    }
}

void ft_print_decenas(char *str, int x, char **m_bef, char **m_aft)
{
    int i;
    int j;

    i = 0;
    while (str[x] != m_bef[i][0] || m_bef[i][1] != '0') 
    {
        i++;
    }
    j = 0;
    while (m_aft[i][j])
    {
        write(1, &m_aft[i][j],1);
        j++;
    }
    if (str[x+1] == '0')
    {
        write(1, " ", 1);
    }
    else
    {
        write(1, "-", 1);
    }
}
void ft_print_teens(char *str, int x, char **m_bef, char **m_aft)
{
    int i;
    int j;

    i = 0;
    while (str[x+1] != m_bef[i][1]) 
    {
        i++;
    }
    j = 0;
    while (m_aft[i][j])
    {
        write(1, &m_aft[i][j],1);
        j++;
    }
    if (str[x + 2] != '\0')
        write(1, " ", 1);
}
void ft_print_unidades(char *str, int x,char **m_bef, char **m_aft)
{
    int i;
    int j;

    i = 0;
    while ((str[x] != m_bef[i][0]) && !(m_bef[i][1] >= '0' && m_bef[i][1] <= '9'))
    {
        i++;
    }
    j = 0;
    while (m_aft[i][j])
    {
        write(1, &m_aft[i][j],1);
        j++;
    }
    if (str[x + 1] != '\0')
        write(1, " ", 1);
}