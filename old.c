#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_strlen(const char *s)
{
	int x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

void	ft_putnbr_fd(int n, int fd)
{
	long int nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}

void	ft_putlnbr_fd(long int n, int fd)
{
	long int nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}

int ft_printf( const char * format, ... ) {

    va_list parametersInfos;
    /* Initialize the va_list structure */
    va_start( parametersInfos, format );

    char currentChar;

    while( (currentChar = *format) != '\0' ) {
        format++;
        if ( currentChar != '%' ) {
            ft_putchar_fd(currentChar, 1);
        }
        else
        {   
            // printf("letter = %c \n", *format);
             if (*format == '%')
            {
                ft_putchar_fd(*format, 1);
            }
            if (*format == 'd' || *format == 'i')
            {   
                // printf("int");
                ft_putnbr_fd((int) va_arg( parametersInfos, int ), 1);
            }
            if (*format == 'f')
            {   
                // printf("double");
                double doubleValue = (double) va_arg( parametersInfos, double );
                int leftPart = (int) doubleValue;
                ft_putnbr_fd((int) doubleValue, 1);

                doubleValue -= leftPart;
                ft_putchar_fd( '.', 1 );
                while( ( doubleValue - (int) doubleValue ) > 10e-6 ) {
                    doubleValue *= 10;
                }
                ft_putnbr_fd(doubleValue, 1);
            }
            if (*format == 'c')
            {
                ft_putchar_fd((char)va_arg( parametersInfos, int  ), 1);
            }
            if (*format == 's')
            {   
                // printf("string");
                char * string = (char *) va_arg( parametersInfos, char * );
                ft_putstr_fd(string, 1);
            }
            if (*format == 'u')
            {   
                long int i = (long int) va_arg( parametersInfos, int );
                if (i >= 0)
                {   
                    ft_putnbr_fd(i, 1);
                }
                else
                {   
                    ft_putlnbr_fd(2147483648 * 2 + i, 1);
                }
            }
            if (*format == 'p')
            {   
                printf("pt = %p \n", (void *)va_arg( parametersInfos, void* ));
                ft_putstr_fd((char *)va_arg( parametersInfos, void* ), 1);
            }
            format++;
        }   
    }

    /* Release va_list resources */
    va_end( parametersInfos );

    return 1;
}


int main( int argc, char * argv[] ) {


    // int a = 10;
    // int age = 10;

    // size_t size = ft_printf( "Begin %s %% %c %u End\n", "Middle", 'a', -33 );

    // printf( "Begin %s %% %c End\n", "Middle", 'a' );

    // size = ft_printf( "Begin %d End\n", 123 );

    // size = ft_printf( "Begin %f End\n", 123.456 );

    // size = ft_printf( "Begin %s %d %f End\n", "toto", 421, 123.456 );

    // printf("%p \n", &a);

    // ft_printf("%p \n", &a);

    // printf("%u \n", -33);

    // ft_printf("%u \n", -33);

    // int x = printf( "%*s%10d%10c%10f\n\n",10, "hello", 7, 'a', 1.23);
    // int y = printf( "%-*s%-10d%-10c%-10f\n\n",10, "hello", 7, 'a', 1.23);
    
    int z = printf( "%%-\n");
    // printf("%d \n", x);
    // printf("%d \n", y);
    printf("%d \n", z);

   // printf("La variable age vaut : %d \n", &age);
    return 0;

}