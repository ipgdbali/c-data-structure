#ifndef RASTER_H
#define RASTER_H

extern void draw_line(struct tBitMap *,struct tPoint[1],struct tPoint[1],struct tColor[1],struct tColor[1]);
extern void draw_hline(struct tBitMap *,int y,int x1,int x2);
extern void fill_triangle(struct tBitMap *,struct tPoint[3],struct tColor *);
extern void fill_triangle(struct tBitMap *,struct tPoint[3],struct tColor[3]);

#endif
