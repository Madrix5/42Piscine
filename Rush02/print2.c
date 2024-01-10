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

void ft_print(int len, char *str, char **m_bef, char **m_aft)
{
    int x;
    int y;
    int teens;
    int m;

    m = (len - 1) / 3;
    x = 0;
    y = 0;
    teens = 0;
    if (len % 3 == 1)
    {
        y = 2;
    }
    else if (len % 3 == 2)
    {
        y = 1;
    }
    while (str[x])
    {
        // MOVERLO A OTRA FUNCION
        if (y == 0)
        {
            if (str[x] != '0')
            {
                ft_print_centenas(str,x,m_bef,m_aft);
            }
            y++;
            x++;
        }
        // MOVERLO A OTRA FUNCION
        if (y == 1)
        {
            if (str[x] == '1')
            {
                teens = 1;
                ft_print_teens(str,x,m_bef,m_aft);
            }
            else if (str[x] != '0')
            {
                ft_print_decenas(str,x,m_bef,m_aft);
            }
            y++;
            x++;
        }
        // MOVERLO A OTRA FUNCION
        if (y == 2)
        {
            if (teens == 1)
            {
                teens = 0;
            }
            else if (str[x] != '0')
            {
                ft_print_unidades(str,x,m_bef,m_aft);
 
            }
            if (m > 0)
            {
                ft_apellidos(m, m_bef, m_aft);
                m--;
            }
            x++;
        }
        y = 0;
    }
}