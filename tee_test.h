/*
 ****************************************************************************************
 *
 *               tee_test.h
 *
 * Filename      : tee_test.h
 * Programmer(s) : system BSP
 * Filename      : tee_test.h
 * Author        : Shuai Fengyun
 * Mail          : shuaifengyun@126.com
 * Create Time   : 2017年07月13日 星期四 12时29分43秒
 ****************************************************************************************
 */

#ifndef MOUDLE_TEST_SERVICE_H_
#define MOUDLE_TEST_SERVICE_H_




/*
 *******************************************************************************
 *                                INCLUDE FILES
 *******************************************************************************
*/
#include <stdlib.h>
#include <string.h>
#include <string_ext.h>
#include <utee_defines.h>
#include <tee/tee_cryp_utl.h>
#include <kernel/tee_time.h>
#include <rng_support.h>
#include <initcall.h>
    
#include <drivers/driver_test.h>





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
struct test_service_ops {
    const char* name;
    struct test_driver_ops_s test_driver;
};



#ifndef MOUDLE_TEST_SERVICE_C_


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
extern TEE_Result syscall_testDriver_write(void *buf, size_t blen, size_t offset);
extern TEE_Result syscall_testDriver_read(void *buf, size_t blen, size_t offset);
extern TEE_Result syscall_testDriver_dump(void *buf, size_t blen);


















#endif

#endif  /* MOUDLE_NAME_H*/
