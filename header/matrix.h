#ifndef MATRIX_H
#define MATRIX_H

struct tMatrix
{
	unsigned int _nRow;
	unsigned int _nCol;
	float * pMatrixItem;
}


extern struct tMatrix mat_init(unsigned int nRow,unsigned int nCol)
{

}

extern struct tMatrix * mat_identity(struct tMatrix * matrix);
extern void mat_fill_row(struct tMatrix * matrix, unsigned int nRow,...);
extern void mat_fill_col(struct tMatrix * matrix,unsigned int nCol,...);
extern struct tMatrix * mat_multiply(struct tMatrix * pMatrixA,struct tMatrix * pMatrixB);
extern struct tMatrix * mat_multiply(struct tMatrix * pMatrix,float scalar);


extern unsigned int mat_get_row_count(struct tMatrix * pMatrix);
extern unsigned int mat_get_col_count(struct tMatrix * pMatrix);

extern void mat_destroy(struct tMatrix * pMatrix);

#endif
