#ifndef VARIANT_H
#define VARIANT_H

enum eVariantType { INT,UINT,SHORT,USHORT,CHAR,UCHAR,STRING,POINTER}

struct tVariant
{
	unsigned char	_type
	unsigned int	_size;
	void			* _pMemory;
};


extern struct tVariant * var_init(eVariantType type);

extern int var_set_int(struct tVariant * variant,int val);
extern int var_get_int(struct tVariant * variant);

extern unsigned int var_set_uint(struct tVariant * variant,unsigned int val);
extern unsigned int var_get_uint(struct tVariant * variant);

extern short var_set_short(struct tVariant * variant,short val);
extern short var_get_short(struct tVariant * variant);

extern short var_set_ushort(struct tVariant * variant,short val);
extern short var_get_ushort(struct tVariant * variant);

extern char var_set_char(struct tVariant * variant,char val);
extern char var_get_char(struct tVariant * variant);

extern char var_set_uchar(struct tVariant * variant,char val);
extern char var_get_uchar(struct tVariant * variant);

extern const char * var_set_string(struct tVariant * variant,const char *val);
extern const char * var_get_string(struct tVariant * variant);

extern void * var_set_pointer(struct tVariant * variant,void * pointer);
extern void * var_get_pointer(struct tVariant * variant);

extern eVariantType var_get_type(struct tVariant * variant);
extern unsigned int var_get_size(struct tVariant * variant);

extern bool var_is_null(struct tVariant * variant);
extern void var_set_null(struct tVariant * variant);

extern void var_destroy(struct tVariant * variant);

#endif
