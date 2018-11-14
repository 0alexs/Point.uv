#include <image.h>

point
get_point(coords * pos, image * img) {
	u_int p = pos->y * img->size.x + pos->x;
	return BIT_CONV(GET_BPOS(*
		(img + (u_int)(pos / 8)), 
		(pos % 8)));
}
