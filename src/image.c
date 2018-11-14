#include "include/image.h"

point
get_point(coords * pos, image * img) {
	u_int p = pos->y * img->size.x + pos->x;
	return BIT_CONV(GET_BPOS(*
		(img + (u_int)(pos / 8)), 
		(pos % 8)));
}

int
set_point(coords * pos, image * img, point p) {
	u_int p = pos->y * img->size.x + pos->x;
	byte * ptr = img + (u_int)(pos / 8)
	*ptr = GET_BPOS(*ptr, (pos % 8));
	return(0);
	}
