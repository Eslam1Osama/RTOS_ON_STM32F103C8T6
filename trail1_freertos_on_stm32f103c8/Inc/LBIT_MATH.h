#ifndef LBIT_MATH_H
#define LBIT_MATH_H

//===============================================================
#define SET_BIT(REG , BIT_NUM) REG |= (1 << BIT_NUM)

#define CLR_BIT(REG , BIT_NUM) REG &= ~(1 << BIT_NUM)

#define GET_BIT(REG , BIT_NUM) ( (REG >> BIT_NUM) & 0X0001 )

#define TOG_BIT(REG , BIT_NUM) REG ^= (1 << BIT_NUM)
//===============================================================

#endif