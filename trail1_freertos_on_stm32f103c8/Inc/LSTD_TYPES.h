#ifndef LSTD_TYPES_H
#define LSTD_TYPES_H

//===============================================================
typedef signed 	       char    s8   ;
typedef unsigned       char    u8   ; 

typedef signed   short int     s16  ;
typedef unsigned short int     u16  ;
typedef unsigned long  int     s32  ;
typedef unsigned long  int     u32  ;

typedef 	           float   f32  ;
typedef 	           double  f64  ;
typedef          long  double  f128 ;

#define LSTD_TYPES_OK 		1
#define LSTD_TYPES_NOK 		0

#define NULL 				((void*)0)
//===============================================================

#endif