#ifndef TYPWD_DEF_H
#define TYPWD_DEF_H

typedef struct
{
	unsigned char h;
	unsigned char l;
} typBYTE;
typedef union
{
	unsigned int word;
	typBYTE byte;
}typFREQ;


////////////////////////////////////////////////////////////////////////////////////
#endif
