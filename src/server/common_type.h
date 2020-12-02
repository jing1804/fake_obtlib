#ifndef _COMMON_TYPE_H_
#define _COMMON_TYPE_H_
/******************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif


/******************************************************************************
             INCLUDE FILES SECTION
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>


/******************************************************************************
             GLOBAL EXPORTED TYPE, CONSTANT, MACRO DEFINITIONS SECTION
******************************************************************************/
/* Platform int length */
#define PLATFORM_INT_LEN    32

/* Common data types */
#ifndef BOOL
#define BOOL                unsigned char/*int*/
#endif

#ifndef CHAR
#define CHAR                char
#endif

#ifndef UCHAR
#define UCHAR               unsigned char
#endif

#ifndef INT8
#define INT8                signed char
#endif

#ifndef UINT8
#define UINT8               unsigned char
#endif

#ifndef INT16
#define INT16               short
#endif

#ifndef UINT16
#define UINT16              unsigned short
#endif

#ifndef DWORD
#define DWORD                unsigned int
#endif

#if (PLATFORM_INT_LEN == 16)

#ifndef INT32
#define INT32               long
#endif

#ifndef UINT32
#define UINT32              unsigned long
#endif

#elif (PLATFORM_INT_LEN == 32)

#ifndef INT32
#define INT32               int
#endif

#ifndef UINT32
#define UINT32              unsigned int
#endif

#endif /* PLATFORM_INT_LEN */

#ifndef UINT64
#define UINT64              unsigned long long
#endif

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#ifndef MAX
#define MAX(x,y)            ((x>y)?x:y)
#endif

#ifndef MIN
#define MIN(x,y)            ((x<y)?x:y)
#endif

//#ifndef NULL
//#define NULL                ((void *)0)
//#endif

#ifndef ARR_SIZE
#define ARR_SIZE( a )  ( sizeof( (a) ) / sizeof( (a[0]) ) )
#endif

typedef void                IGNORE_TYPE;

#ifndef offsetof
#define offsetof(type, member) ((long unsigned int) &((type *) 0)->member)
#endif


/* YYU:
typedef void (*FMC_PROC_MSG_FUNC)(UINT16, UINT8 *);

typedef struct{
    UINT8 ExternelMsg;
    FMC_PROC_MSG_FUNC  pProcMsg;
}FmcOsInMsgTable_t;
*/

/******************************************************************************
             GLOBAL EXPORTED VARIABLES DEFINITIONS SECTION
******************************************************************************/


/******************************************************************************
             GLOBAL EXPORTED FUNCTIONS DEFINITIONS SECTION
******************************************************************************/


/******************************************************************************/

#ifdef __cplusplus  // close out "C" linkage in case of c++ compiling
}
#endif

/******************************************************************************/
#endif /* _FMC_COMMON_TYPE_H_ */
