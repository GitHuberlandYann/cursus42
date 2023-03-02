#include "libft.h"

static double	ft_truncate(double c)
{
	if (c < 0)
		return (ceil(c));
	return (floor(c));
}

double ft_fmod(double a, double b)
{
	return (a - ft_truncate(a / b) * b);
}

// double truncate(double x) {
//   return x < 0 ? -Math.floor(-x) : Math.floor(x);
//   //or return x < 0 ? Math.ceil(x) : Math.floor(x);
// }

// double MyFmod(double x, double y) {
//   return x - truncate(x / y) * y;
// }