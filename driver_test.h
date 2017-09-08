/*
 ****************************************************************************************
 *
 *               driver_test.h
 *
 * Filename      : driver_test.h
 * Programmer(s) : system BSP
 * Filename      : driver_test.h
 * Author        : Shuai Fengyun
 * Mail          : shuaifengyun@126.com
 * Create Time   : 2017年07月13日 星期四 11时31分20秒
 ****************************************************************************************
 */

#ifndef MOUDLE_TEST_DRIVER_H_
#define MOUDLE_TEST_DRIVER_H_




/*
 *******************************************************************************
 *                                INCLUDE FILES
 *******************************************************************************
*/
#include <assert.h>
        
#include <mpalib.h>
#include <stdlib.h>
#include <string.h>
#include <utee_defines.h>
#include <trace.h>
#include <tee_api_types.h>
#include <string_ext.h>
#include <util.h>
#include <kernel/panic.h>





/*
 *******************************************************************************
 *                  MACRO DEFINITION USED ONLY BY THIS MODULE
 *******************************************************************************
*/





/*
 *******************************************************************************
 *                STRUCTRUE DEFINITION USED ONLY BY THIS MODULE
 *******************************************************************************
*/
struct test_driver_ops_s {
    TEE_Result (*device_init)(void);
    TEE_Result (*write)(uint8_t *data, size_t len, size_t offset);
    TEE_Result (*read)(uint8_t *dst, size_t len, size_t offset);
    TEE_Result (*driver_dump)(uint8_t *data, size_t len);
};


#ifndef MOUDLE_TEST_DRIVER_C_


/*
 *******************************************************************************
 *                      VARIABLES SUPPLIED BY THIS MODULE
 *******************************************************************************
*/





/*
 *******************************************************************************
 *                      FUNCTIONS SUPPLIED BY THIS MODULE
 *******************************************************************************
*/
extern TEE_Result device_init(void);
extern TEE_Result write(uint8_t *data, size_t len, size_t offset);
extern TEE_Result read(uint8_t *dst, size_t len, size_t offset);
extern TEE_Result driver_dump(uint8_t *data, size_t len);

















#endif

#endif  /* MOUDLE_NAME_H*/
