/**********************************************************************************************/
/** Desc : standard types header file                                                                                     */
/** Author : 3li Al_Refaee                                                                                                                         */
/** Date : 4 Aug 2023                                                                                                            */
/** version : 1.0v                                                                                                                 */
/****************************************************************************************/

#ifndef STD_TYPES_H
#define STD_TYPES_H
#define NULL                     ((void *)0)

typedef signed char             sint8;
typedef unsigned char        uint8;
typedef signed short int     sint16;
typedef unsigned short int uint16;
typedef signed long int       sint32;
typedef unsigned long int   uint32;
typedef float                        float32;
typedef double                    float64;


typedef enum{
	E_OK,
	E_NOK,
	OUT_OF_RANG,
	IS_NULL_POINTER
	
}tenuErrorStatus;

#endif /** End Gaurd */
