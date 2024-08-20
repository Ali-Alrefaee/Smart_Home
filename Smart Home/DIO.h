/**************************************************/
/*Desc   : interface file for DIO                 */
/*Author :3li Al_Refaee                        */
/*Date   : 25 Aug 2023                            */
/*Version: 1.0V                                   */
/**************************************************/

#ifndef DIO_H
#define DIO_H

void DIO_vidInit(void);

tenuErrorStatus DIO_enuSetPinDir        (uint8 u8PinNumCpy ,uint8  u8PinDirCpy);
tenuErrorStatus DIO_enuSetPinValue    (uint8 u8PinNumCpy ,uint8  u8PinStatusCpy);
tenuErrorStatus DIO_enuReadPinValue(uint8 u8PinNumCpy ,uint8* pu8PinValueCpy);
tenuErrorStatus DIO_enuSetPinPullUp  (uint8 u8PinNumCpy ,uint8  u8PullupStatusCpy);


#endif /*Gaurd*/
