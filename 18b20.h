/**************************************************************************************************
  Filename:       18b20.h
  Revised:        $Date: 2013-4-2 21:15 $
  Revision:       $Revision: 00001 $

  Description:    DS18B20 definitions and declaration.

**************************************************************************************************/

#ifndef __18b20_h__
#define __18b20_h__

#ifdef __cplusplus
extern "C"
{
#endif

/*********************************************************************
 * INCLUDES
 */
#include "ioCC2530.h"
  
/*********************************************************************
 * CONSTANTS
 */
// Bit define
#define BIT0                0x0001
#define BIT1                0x0002
#define BIT2                0x0004
#define BIT3                0x0008
#define BIT4                0x0010
#define BIT5                0x0020
#define BIT6                0x0040
#define BIT7                0x0080
#define BIT8                0x0100
#define BIT9                0x0200
#define BITA                0x0400
  
// IO Port define based on hardware
#define DQ                  P0_7
#define DQ_1                (P0_7 = 1)
#define DQ_0                (P0_7 = 0)
#define DQ_IN               (P0DIR &=~ BIT7)
#define DQ_OUT              (P0DIR |=  BIT7)
  
// Special Command
#define ReadROM             0x33
#define MatchROM            0x55
#define SearchROM           0xf0 
#define AlartSearch         0xec
#define SkipROM             0xcc
  
#define ConvertT            0x44
#define ReadScratchpad      0xbe
#define WriteScratchpad     0x4e
#define CopyScratchpad      0x48
#define RecallE2            0xb8
#define ReadPowerSupply     0xb4
  
/*********************************************************************
 * TYPEDEFS
 */

  
/*********************************************************************
 * EXTERN VARIABLES
 */

/*********************************************************************
 * MACROS
 */

/*********************************************************************
 * FUNCTIONS
 */
extern uint8 ds18b20_init( void );
extern uint16 getTmp( void );
extern float getTemperature( void );

  
/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* 18B20_H */
