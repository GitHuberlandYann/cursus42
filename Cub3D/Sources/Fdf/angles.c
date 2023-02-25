#include "cub3d.h"

double	ft_rotation_x(t_angles *a, t_vertice *node)
{
	double	res;

	res = a->cb * a->cg * node->x;
	res += (a->sa * a->sb * a->cg - a->ca * a->sg) * node->y;
	res += (a->ca * a->sb * a->cg + a->sa * a->sg) * node->z;
	return (res);
}

double	ft_rotation_y(t_angles *a, t_vertice *node)
{
	double	res;

	res = a->cb * a->sg * node->x;
	res += (a->sa * a->sb * a->sg + a->ca * a->cg) * node->y;
	res += (a->ca * a->sb * a->sg - a->sa * a->cg) * node->z;
	return (res);
}

void	set_fdfangles(t_angles *a, double alpha, double beta, double gamma)
{
	a->alpha = alpha;
	a->sa = sin(alpha);
	a->ca = cos(alpha);
	a->beta = beta;
	a->sb = sin(beta);
	a->cb = cos(beta);
	a->gamma = gamma;
	a->sg = sin(gamma);
	a->cg = cos(gamma);
}
