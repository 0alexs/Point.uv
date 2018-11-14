#include <image.h>

int
convert(image * ptr) {	

#define GET_POINT (get_point(c, ptr))
#define FILL_BLACK { for(u_int i = 0; i * 8 < size.x * size.y; i++) *(s + i) = 0; }

	byte * s = ptr->ptr;
	coords size = ptr->size;

	u_int	bx = 0, 
		by = 0, 
		ex = size.x - 1, 
		ey = size.y - 1;

	u_int	nx = 0, ny = 0;
	
	coords c;

	for(u_int i = 0; i < size.x; i++, bx++) {
		c.x = bx;
		for(u_int j = 0; j < size.y; j++) {
			c.y = j;
			if GET_POINT {
				ny = c.y;
				goto break1;
			}
		}
break1:
	}

	for(u_int i = 0; i < size.y; i++, by++) {
		c.y = bx;
		for(u_int j = 0; j < size.x; j++) {
			c.x = j;
			if GET_POINT {
				nx = c.x;
				goto break2;
			}
		}
break2:
	}

	for(u_int i = 0; i < size.x; i++, ex--) {
		c.x = ex;
		for(u_int j = 0; j < size.y; j++) {
			c.y = j;
			if GET_POINT
				goto break1;
		}
break3:
	}

	for(u_int i = 0; i < size.y; i++, ey--) {
		c.y = ey;
		for(u_int j = 0; j < size.x; j++) {
			c.x = j;
			if GET_POINT
				goto break2;
		}
break4:
	}

	c.x = 0;
	c.y = 0;
	if GET_POINT {
		FILL_BLACK
		return(1);
	}
	
	c.x = size.x - 1;
	c.y = sie.y - 1;
	if GET_POINT {
		FILL_BLACK
		return(1);
	}

	FILL_BLACK
	c.x = nx;
	c.y = ny;
	set_point(c, ptr, 1);
	return(0);
}
