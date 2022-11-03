/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:16:18 by marvin            #+#    #+#             */
/*   Updated: 2022/10/29 14:16:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	ft_fill_arr(t_stack *a, int nb, ...)
{
	int		index;
	va_list	ap;

	a->size = 0;
	a->arr = malloc(sizeof(*a->arr) * nb);
	if (!a->arr)
		return ;
	a->size = nb;
	va_start(ap, nb);
	index = 0;
	while (index < nb)
		a->arr[index++] = va_arg(ap, int);
	va_end(ap);
}

void	ft_test_case(t_stack *a, int section)
{
	t_stack b;

	b.arr = malloc(sizeof(*b.arr) * a->size);
	if (!b.arr)
		return ;
	b.size = 0;
	b.r = 0;
	b.rr = 0;
	a->r = 0;
	a->rr = 0;
	a->s_size = section;
	ft_sort_big(a, &b);
	free(b.arr);
}

void	ft_test_case_small(t_stack *a)
{
	t_stack b;

	b.arr = malloc(sizeof(*b.arr) * a->size);
	if (!b.arr)
		return ;
	b.size = 0;
	ft_sort_small(a, &b);
	free(b.arr);
}

int	ft_load_test_small(t_stack *a, int nb)
{
	if (nb == 0)
		ft_fill_arr(a, 2, 2, 1);
	else if (nb == 1)
		ft_fill_arr(a, 3, 1, 0, 2);
	else if (nb == 2)
		ft_fill_arr(a, 3, 1, 2, 0);
	else if (nb == 3)
		ft_fill_arr(a, 3, 0, 2, 1);
	else if (nb == 4)
		ft_fill_arr(a, 3, 2, 0, 1);
	else if (nb == 5)
		ft_fill_arr(a, 3, 2, 1, 0);
	else if (nb == 6)
		ft_fill_arr(a, 4, 0, 1, 3, 2);
	else if (nb == 7)
		ft_fill_arr(a, 4, 0, 2, 1, 3);
	else if (nb == 8)
		ft_fill_arr(a, 4, 0, 2, 3, 1);
	else if (nb == 9)
		ft_fill_arr(a, 4, 0, 3, 1, 2);
	else if (nb == 10)
		ft_fill_arr(a, 4, 0, 3, 2, 1);
	else if (nb == 11)
		ft_fill_arr(a, 4, 1, 0, 2, 3);
	else if (nb == 12)
		ft_fill_arr(a, 4, 1, 0, 3, 2);
	else if (nb == 13)
		ft_fill_arr(a, 4, 1, 2, 0, 3);
	else if (nb == 14)
		ft_fill_arr(a, 4, 1, 2, 3, 0);
	else if (nb == 15)
		ft_fill_arr(a, 4, 1, 3, 0, 2);
	else if (nb == 16)
		ft_fill_arr(a, 4, 1, 3, 2, 0);
	else if (nb == 17)
		ft_fill_arr(a, 4, 2, 0, 1, 3);
	else if (nb == 18)
		ft_fill_arr(a, 4, 2, 0, 3, 1);
	else if (nb == 19)
		ft_fill_arr(a, 4, 2, 1, 0, 3);
	else if (nb == 20)
		ft_fill_arr(a, 4, 2, 1, 3, 0);
	else if (nb == 21)
		ft_fill_arr(a, 4, 2, 3, 0, 1);
	else if (nb == 22)
		ft_fill_arr(a, 4, 2, 3, 1, 0);
	else if (nb == 23)
		ft_fill_arr(a, 4, 3, 0, 1, 2);
	else if (nb == 24)
		ft_fill_arr(a, 4, 3, 0, 2, 1);
	else if (nb == 25)
		ft_fill_arr(a, 4, 3, 1, 0, 2);
	else if (nb == 26)
		ft_fill_arr(a, 4, 3, 1, 2, 0);
	else if (nb == 27)
		ft_fill_arr(a, 4, 3, 2, 0, 1);
	else if (nb == 28)
		ft_fill_arr(a, 4, 3, 2, 1, 0);	
	else
		return (1);
	return (0);
}

int	ft_load_test_big(t_stack *a, int nb)
{
	if (nb == 0)
		ft_fill_arr(a, 2, 2, 1);
	else if (nb == 1)
		ft_fill_arr(a, 3, 2, 1, 0);
	else if (nb == 2)
		ft_fill_arr(a, 4, 3, 2, 0, 1);
	else if (nb == 3)
		ft_fill_arr(a, 5, 4, 2, 3, 0, 1);
	else if (nb == 4)
		ft_fill_arr(a, 10, 1, 6, 0, 2, 7, 4, 8, 3, 9, 5);
	else if (nb == 5)
		ft_fill_arr(a, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0);
	else if (nb == 6)
		ft_fill_arr(a, 20, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 19, 18);
	else if (nb == 7)
		ft_fill_arr(a, 20, 5, 12, 3, 19, 1, 4, 16, 2, 7, 18, 15, 11, 10, 0, 9, 6, 17, 8, 14, 13);
	else if (nb == 8)
		ft_fill_arr(a, 100, 48, 83, 2, 13, 36, 17, 45, 15, 30, 1, 33, 44, 7, 25, 56, 27, 24, 32,
					96, 46, 43, 85, 66, 67, 31, 82, 57, 5, 21, 59, 9, 71, 76, 72, 3, 70, 87, 16,
					22, 93, 14, 61, 0, 8, 12, 55, 69, 28, 54, 47, 77, 94, 98, 18, 53, 88, 37, 40,
					23, 39, 81, 20, 6, 64, 10, 79, 19, 11, 38, 58, 42, 29, 34, 41, 52, 49, 4, 80,
					68, 62, 86, 90, 51, 26, 35, 92, 89, 74, 78, 95, 60, 73, 50, 91, 84, 63, 99, 97, 65, 75);
	else if (nb == 9)
		ft_fill_arr(a, 100, 23, 43, 96, 22, 55, 37, 65, 57, 88, 36, 87, 64, 34, 69, 49, 40, 42, 31,
					68, 29, 82, 74, 21, 81, 26, 16, 63, 61, 10, 73, 89, 78, 70, 53, 84, 99, 20, 91,
					3, 39, 75, 54, 86, 92, 93, 2, 97, 38, 24, 67, 35, 56, 85, 41, 4, 58, 12, 90, 62,
					45, 72, 19, 7, 94, 33, 25, 52, 77, 6, 48, 51, 76, 17, 8, 30, 98, 66, 95, 44, 60,
					13, 50, 14, 11, 83, 5, 71, 47, 28, 80, 59, 79, 15, 1, 0, 27, 32, 18, 9, 46);
	else if (nb == 10)
		ft_fill_arr(a, 200, 34, 64, 6, 80, 88, 79, 63, 3, 14, 58, 55, 67, 15, 56, 98, 20, 86, 52, 69,
					81, 17, 97, 16, 40, 65, 96, 89, 24, 99, 105, 74, 144, 117, 73, 2, 43, 118, 1, 29,
					12, 51, 124, 133, 109, 84, 30, 57, 139, 111, 121, 106, 155, 161, 192, 62, 162, 11,
					182, 154, 199, 33, 61, 35, 13, 188, 181, 184, 9, 49, 28, 95, 71, 175, 100, 136, 143,
					177, 45, 116, 101, 37, 26, 170, 110, 168, 172, 158, 4, 47, 114, 78, 156, 127, 31, 38,
					77, 171, 134, 146, 41, 94, 112, 102, 18, 66, 25, 53, 152, 191, 85, 194, 141, 92, 59,
					169, 120, 179, 193, 131, 48, 91, 8, 68, 60, 176, 129, 148, 173, 44, 183, 189, 83, 75,
					195, 159, 186, 119, 0, 167, 90, 142, 151, 125, 165, 87, 149, 39, 5, 50, 113, 32, 23,
					54, 163, 19, 27, 185, 42, 70, 76, 150, 36, 82, 46, 198, 72, 115, 22, 160, 153, 135,
					7, 123, 187, 126, 10, 196, 157, 197, 21, 128, 174, 104, 108, 190, 140, 107, 103, 132,
					147, 145, 180, 122, 164, 178, 138, 137, 130, 93, 166);
	else if (nb == 11)
		ft_fill_arr(a, 200, 46, 42, 72, 5, 44, 50, 2, 76, 75, 1, 68, 47, 69, 29, 51, 129, 179, 16, 56, 43,
					54, 118, 199, 7, 32, 143, 81, 93, 13, 101, 79, 161, 124, 60, 82, 121, 24, 39, 61, 108,
					27, 192, 125, 0, 158, 120, 18, 77, 49, 141, 41, 66, 195, 132, 171, 87, 116, 25, 117,
					100, 37, 36, 63, 71, 34, 146, 95, 35, 12, 99, 198, 40, 15, 96, 62, 23, 197, 138, 148,
					48, 110, 175, 184, 115, 10, 111, 150, 57, 174, 180, 64, 3, 159, 19, 70, 142, 102, 181,
					84, 8, 104, 52, 90, 26, 58, 153, 128, 78, 9, 67, 151, 135, 163, 31, 178, 103, 130, 91,
					106, 112, 28, 140, 144, 86, 166, 4, 88, 59, 97, 173, 11, 80, 53, 133, 33, 154, 6, 177,
					45, 119, 145, 191, 188, 14, 89, 152, 149, 92, 73, 107, 109, 186, 98, 17, 22, 168, 113,
					85, 65, 55, 94, 155, 74, 114, 30, 83, 164, 137, 185, 157, 190, 147, 38, 21, 182, 123,
					183, 127, 134, 131, 122, 189, 172, 126, 196, 169, 176, 156, 193, 160, 136, 187, 105,
					170, 162, 165, 20, 167, 194, 139);
	else if (nb == 12)
		ft_fill_arr(a, 200, 77, 117, 103, 160, 181, 179, 172, 126, 122, 153, 159, 129, 185, 119, 157, 132,
					139, 188, 173, 158, 183, 150, 184, 50, 24, 66, 106, 138, 25, 39, 27, 10, 151, 152, 44,
					143, 85, 93, 155, 118, 71, 131, 37, 13, 198, 19, 91, 111, 12, 144, 166, 199, 142, 108,
					104, 177, 174, 74, 130, 116, 162, 110, 18, 147, 33, 171, 95, 156, 124, 36, 8, 2, 51,
					127, 148, 165, 69, 192, 190, 109, 94, 61, 187, 99, 170, 78, 70, 60, 87, 86, 62, 52, 65,
					48, 35, 73, 34, 125, 64, 141, 75, 58, 47, 182, 9, 154, 194, 1, 32, 163, 137, 67, 168,
					92, 167, 82, 20, 140, 11, 102, 63, 72, 54, 43, 121, 0, 145, 193, 186, 178, 30, 76, 161,
					23, 3, 100, 16, 133, 57, 5, 112, 98, 4, 101, 7, 41, 128, 136, 53, 90, 123, 49, 115, 26,
					96, 15, 42, 89, 149, 175, 84, 46, 197, 40, 31, 79, 68, 169, 81, 88, 114, 17, 120, 97,
					55, 29, 176, 83, 195, 6, 56, 80, 191, 107, 134, 59, 135, 105, 21, 113, 28, 45, 164, 38,
					22, 189, 180, 14, 146, 196);
	else if (nb == 13)
		ft_fill_arr(a, 500, 402, 9, 103, 60, 11, 52, 16, 134, 59, 191, 47, 192, 119, 91, 17, 161, 168, 126,
					70, 183, 124, 27, 377, 212, 157, 224, 209, 221, 211, 338, 369, 272, 318, 235, 296, 269,
					348, 56, 438, 354, 200, 230, 153, 311, 391, 340, 408, 469, 320, 29, 194, 444, 77, 244,
					146, 173, 93, 248, 110, 422, 301, 315, 300, 454, 35, 308, 182, 331, 485, 470, 37, 220,
					265, 461, 263, 197, 410, 381, 430, 494, 267, 75, 31, 201, 445, 15, 255, 160, 330, 0,
					447, 39, 72, 76, 412, 6, 405, 479, 222, 96, 349, 19, 86, 264, 297, 41, 480, 180, 90,
					109, 138, 341, 215, 32, 317, 229, 423, 373, 342, 196, 208, 356, 441, 253, 184, 453,
					336, 413, 241, 42, 243, 169, 478, 455, 290, 156, 440, 366, 284, 417, 225, 50, 114, 334,
					177, 419, 167, 113, 285, 418, 258, 66, 166, 483, 198, 219, 144, 371, 415, 193, 171,
					482, 104, 49, 242, 309, 95, 233, 404, 23, 353, 424, 79, 38, 118, 131, 407, 240, 332,
					163, 65, 443, 328, 386, 107, 122, 249, 490, 99, 80, 355, 484, 329, 293, 432, 199, 216,
					313, 78, 25, 452, 205, 48, 179, 492, 425, 498, 53, 466, 247, 282, 358, 397, 468, 149,
					421, 434, 388, 278, 21, 36, 316, 30, 460, 33, 370, 143, 273, 2, 7, 20, 394, 40, 448,
					155, 22, 497, 210, 227, 276, 111, 326, 250, 125, 458, 277, 81, 495, 449, 257, 190, 327,
					428, 152, 231, 400, 291, 234, 464, 360, 314, 112, 335, 12, 363, 14, 295, 292, 379, 383,
					475, 43, 71, 145, 188, 436, 172, 98, 236, 491, 223, 306, 1, 433, 286, 4, 427, 261, 476,
					275, 368, 127, 456, 217, 73, 228, 389, 87, 202, 61, 203, 158, 8, 487, 128, 252, 246,
					287, 239, 289, 346, 477, 140, 321, 189, 392, 83, 28, 174, 442, 170, 13, 256, 396, 69,
					45, 186, 54, 117, 429, 18, 162, 141, 376, 333, 102, 323, 260, 51, 352, 266, 10, 237,
					238, 3, 270, 307, 108, 416, 384, 350, 288, 374, 271, 378, 58, 406, 268, 105, 462, 120,
					94, 280, 481, 385, 324, 181, 55, 64, 298, 459, 380, 325, 92, 150, 486, 409, 57, 343,
					339, 362, 435, 367, 401, 304, 129, 63, 34, 85, 426, 420, 218, 5, 88, 446, 123, 398, 395,
					136, 26, 187, 185, 351, 283, 62, 213, 74, 115, 457, 24, 274, 44, 303, 245, 121, 207,
					305, 437, 372, 84, 97, 294, 411, 499, 68, 488, 281, 132, 361, 232, 151, 393, 254, 165,
					116, 467, 67, 214, 251, 262, 489, 451, 319, 259, 137, 279, 399, 82, 299, 474, 89, 139,
					101, 106, 195, 357, 310, 46, 375, 206, 345, 130, 347, 226, 142, 359, 133, 175, 465, 403,
					135, 344, 493, 178, 450, 302, 148, 312, 147, 390, 472, 322, 439, 164, 154, 382, 159,
					463, 387, 176, 471, 431, 204, 473, 337, 496, 100, 414, 364, 365);
	else if (nb == 14)
		ft_fill_arr(a, 500, 140, 102, 50, 42, 159, 293, 394, 263, 262, 267, 288, 90, 126, 271, 5, 165, 368,
					292, 129, 377, 252, 127, 153, 346, 424, 443, 8, 379, 161, 343, 253, 65, 301, 408, 147, 178, 145,
					130, 438, 309, 242, 132, 196, 284, 315, 167, 17, 407, 423, 427, 160, 403, 36, 247, 395, 146, 355,
					174, 77, 392, 393, 107, 187, 370, 177, 244, 184, 0, 300, 352, 12, 78, 1, 125, 29, 314, 88, 405, 158,
					106, 86, 207, 404, 192, 285, 279, 248, 310, 249, 384, 245, 69, 435, 96, 282, 91, 193, 7, 411, 420,
					414, 345, 274, 28, 399, 163, 151, 137, 337, 217, 215, 437, 162, 33, 332, 176, 181, 432, 440, 119,
					287, 139, 239, 336, 417, 421, 164, 273, 386, 412, 422, 18, 378, 209, 396, 188, 381, 326, 254, 171,
					409, 425, 74, 323, 71, 13, 216, 46, 94, 465, 250, 325, 3, 484, 358, 23, 55, 112, 21, 225, 454, 246,
					473, 479, 227, 67, 391, 324, 98, 148, 191, 205, 143, 429, 402, 109, 313, 82, 265, 175, 49, 342, 183,
					138, 464, 276, 30, 37, 84, 349, 72, 31, 60, 416, 206, 111, 243, 255, 436, 459, 19, 318, 133, 208,
					236, 281, 179, 456, 482, 410, 259, 372, 328, 43, 434, 353, 363, 210, 389, 283, 390, 99, 428, 54,
					376, 156, 380, 27, 154, 280, 233, 364, 442, 83, 291, 286, 256, 53, 299, 466, 289, 6, 136, 418, 222,
					460, 166, 382, 430, 260, 16, 116, 211, 79, 101, 426, 383, 118, 406, 327, 173, 322, 47, 15, 62, 123,
					231, 388, 387, 134, 359, 4, 170, 431, 451, 261, 157, 73, 149, 488, 150, 186, 360, 335, 195, 278,
					199, 295, 340, 51, 476, 269, 483, 182, 331, 57, 40, 230, 361, 397, 398, 41, 144, 223, 415, 38, 240,
					475, 400, 365, 168, 385, 212, 294, 141, 419, 180, 338, 413, 100, 213, 97, 448, 433, 135, 172, 354,
					25, 439, 401, 457, 185, 481, 489, 128, 34, 303, 455, 306, 235, 302, 52, 228, 467, 341, 11, 24, 152,
					478, 110, 45, 76, 480, 272, 20, 298, 311, 469, 241, 89, 39, 75, 202, 450, 124, 330, 308, 142, 131,
					463, 2, 219, 93, 70, 198, 257, 169, 441, 499, 453, 64, 444, 203, 197, 232, 357, 320, 344, 447, 58,
					200, 214, 226, 461, 492, 334, 190, 221, 458, 375, 362, 367, 238, 251, 296, 204, 333, 452, 32, 258,
					122, 319, 224, 374, 264, 201, 339, 497, 266, 486, 66, 237, 493, 277, 371, 305, 113, 487, 120, 194,
					290, 366, 270, 229, 95, 105, 117, 312, 189, 108, 234, 220, 68, 92, 10, 218, 307, 490, 496, 155, 462,
					297, 449, 56, 63, 304, 268, 26, 356, 87, 329, 491, 115, 445, 316, 80, 474, 373, 446, 48, 35, 81, 59,
					369, 44, 9, 114, 468, 498, 121, 351, 470, 14, 61, 104, 103, 22, 471, 350, 347, 477, 472, 485, 494,
					321, 495, 348, 317, 85, 275);
	else
 		return (1);
	return (0);
}