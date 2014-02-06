/**************************************************************************************************
  Filename:       timer.h
  Revised:        $Date: 2013-4-12 21:30 $
  Revision:       $Revision: 00001 $

  Description:    timer3 definitions and declaration.

**************************************************************************************************/

#ifndef __timer_h__
#define __timer_h__

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

extern void timer_init( void );
extern void timer_delayUm( uint16 _um );

  
/*********************************************************************
*********************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* timer_h */