/**************************************************************************************************
  Filename:       18b20.c
  Revised:        $Date: 2013-4-4 21:26$
  Revision:       $Revision: 00001 $

  Description:    

**************************************************************************************************/

/*********************************************************************
 * INCLUDES
 */
#include "hal_types.h"
#include "18b20.h"
#include "SampleApp.h"
#include "timer.h"

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * CONSTANTS
 */

/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * GLOBAL VARIABLES
 */

/*********************************************************************
 * LOCAL VARIABLES
 */

/*********************************************************************
 * LOCAL FUNCTIONS
 */
uint8 ds18b20_reset( void );
void ds18b20_writeByte( uint8 _byte );
uint8 ds18b20_readByte( void );

/*********************************************************************
 * @fn      ds18b20_reset
 *
 * @brief   Reset ds18b20
 *
 * @param   none
 * @return  0:succes
            1:false
 */
uint8 ds18b20_reset( void ){
  uint8 error;
  
  DQ_0;
  timer_delayUm(250);
  timer_delayUm(250);
  DQ_1;
  timer_delayUm(55);
  DQ_IN;
  timer_delayUm(1);
  if(DQ == 0){
    error = 0;
    DQ_OUT;
    DQ_1;
  }else{
    error = 1;
    DQ_OUT;
  }
  
  timer_delayUm(200);
  timer_delayUm(200);
 
  return error;
}

/*********************************************************************
 * @fn      ds18b20_writeByte
 *
 * @brief   write a byte to ds18b20
 *
 * @param   _byte -a byte to be written 
 * @return  none
 */
void ds18b20_writeByte( uint8 _byte ){
  uint8 i;
  
  for(i=0; i<8; i++){
    DQ_0;
    timer_delayUm(6);
    if(_byte & 0x01)  DQ_1;
    else              DQ_0;
    _byte >>= 1;
    timer_delayUm(50);
    DQ_1;
    timer_delayUm(10);
  }
}

/*********************************************************************
 * @fn      ds18b20_readByte
 *
 * @brief   Read a byte from ds18b20
 *
 * @param   none
 * @return  The byte read
 */
uint8 ds18b20_readByte( void ){
  uint8 i,tmpRd=0;
  
  for(i=0; i<8; i++){
    tmpRd >>= 1;
    DQ_0;
    timer_delayUm(6);
    DQ_1;
    timer_delayUm(8);
    DQ_IN;
    timer_delayUm(1);
    if(DQ)  tmpRd |= 0x80;
    timer_delayUm(45);
    DQ_OUT;
    DQ_1;
    timer_delayUm(10);
  }
  return tmpRd;
}
/*********************************************************************
 * PUBLIC FUNCTIONS
 */
uint8 ds18b20_init( void );
uint16 getTmp( void );
/*********************************************************************
 * @fn      ds18b20_init
 *
 * @brief   Initialize model ds18b20
 *
 * @param   none
 * @return  The same as "ds18b20_reset" function
 */
uint8 ds18b20_init( void ){
  DQ_OUT;
  return ds18b20_reset();
}
/*********************************************************************
 * @fn      Module_PublicFunc
 *
 * @brief   
 *
 * @param   none
 * @return  none
 */
uint16 getTmp( void ){
  uint8 val;
  uint8 tmpLow;
  uint16 tmp,i;
  
  do{
    val = ds18b20_reset();
  }
  while(val);
  ds18b20_writeByte(SkipROM);
  ds18b20_writeByte(ConvertT);
  for(i=800; i>0; i--){
    timer_delayUm(250);
    timer_delayUm(250);
    timer_delayUm(250);
    timer_delayUm(250);
  }
  do{
    val = ds18b20_reset();
  }
  while(val);
  ds18b20_writeByte(SkipROM);
  ds18b20_writeByte(ReadScratchpad);
  tmpLow = ds18b20_readByte();
  tmp = ds18b20_readByte();
  tmp = (tmp<<8) | tmpLow;
  return tmp;
}

/*********************************************************************
 * @fn      Module_PublicFunc
 *
 * @brief   
 *
 * @param   none
 * @return  none
 */
float getTemperature( void ){
  float tmp;
  uint16 value;
  ADCCON3 = 0x3e;
  ADCCON1 |= 0x30;
  ADCCON1 |= 0x40;
  while(!(ADCCON1 & 0x80));
  value = ADCL >> 4;
  value |= ((uint16)ADCH) << 4;
  tmp = (float)((value-1367.5)/4.5-20);
  return tmp;
}
/*********************************************************************
 * @fn      Module_PublicFunc
 *
 * @brief   
 *
 * @param   none
 * @return  none
 */

/*********************************************************************
*********************************************************************/
