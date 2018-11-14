typedef unsigned char byte;
typedef byte point;
typedef unsigned int u_int;

typedef struct { 
	u_int x, y; 
} coords;

typedef struct { 
	byte * ptr;
	coords size;
} image;

#define GET_BPOS(x, _pos) (x & (0x1 << (7 - _pos)))
#define BIT_CONV(x) (x && x)

point get_point(coords * pos, image * img);
int set_point(coords * pos, image * img, point p);

int convert(image * ptr);

typedef unsigned BOOL;
#define TRUE 1
#define FALSE 2
