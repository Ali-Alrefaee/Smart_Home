/**********************************************************************************************/
/** Desc    : bit math header file                                                           */
/** Author  : 3li Al_Refaee                                                                           */
/** Date    : 5 Aug 2023                                                                   */
/** version : 1.0v                                                                        */
/*****************************************************************************************/

/*******if not define *****/

#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(Reg , bit_No)        Reg |= (1<<(bit_No))
#define CLR_BIT(Reg , bit_No)       Reg &= ~(1<<(bit_No))
#define TGL_BIT(Reg , bit_No)       Reg ^= (1<<(bit_No))
#define GET_BIT(Reg , bit_No)      (((Reg) >> (bit_No))& 1)


#endif /** End Gaurd */
