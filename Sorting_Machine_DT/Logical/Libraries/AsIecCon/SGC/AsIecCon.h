/* Automation Studio Generated Header File, Format Version 1.00 */
/* do not change */
#ifndef ASIECCON_H_
#define ASIECCON_H_
#ifdef __cplusplus
extern "C" {
#endif
                                           

#include <bur/plc.h>



/* Constants */


/* Datatypes */


/* Datatypes of function blocks */


/* Prototyping of functions and function blocks */
signed short H_TO_NINT(signed short IN);
unsigned short H_TO_NUINT(unsigned short IN);
signed long H_TO_NDINT(signed long IN);
unsigned long H_TO_NUDINT(unsigned long IN);
float H_TO_NREAL(float IN);
plctime H_TO_NTIME(plctime IN);
DATE_AND_TIME H_TO_NDT(DATE_AND_TIME IN);
DATE H_TO_NDATE(DATE IN);
TOD H_TO_NTOD(TOD IN);
signed short N_TO_HINT(signed short IN);
unsigned short N_TO_HUINT(unsigned short IN);
signed long N_TO_HDINT(signed long IN);
unsigned long N_TO_HUDINT(unsigned long IN);
float N_TO_HREAL(float IN);
plctime N_TO_HTIME(plctime IN);
DATE_AND_TIME N_TO_HDT(DATE_AND_TIME IN);
DATE N_TO_HDATE(DATE IN);
TOD N_TO_HTOD(TOD IN);
signed short swapINT(signed short IN);
unsigned short swapUINT(unsigned short IN);
WORD swapWORD(WORD IN);
signed long swapDINT(signed long IN);
unsigned long swapUDINT(unsigned long IN);
DWORD swapDWORD(DWORD IN);
TIME swapTIME(TIME IN);
DATE_AND_TIME swapDT(DATE_AND_TIME IN);
DATE swapDATE(DATE IN);
TOD swapTOD(TOD IN);
float swapREAL(float IN);

/* The interface declarations of the AsIecCon functions are not included here
 * because they are inline in IEC languages. The x_TO_STRING and the
 * STRING_TO_x functions are not available for C programms. */

#ifdef __cplusplus
};
#endif
#endif /* ASIECCON_H_ */

