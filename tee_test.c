
/*
 ****************************************************************************************
 *
 *               tee_test.c
 *
 * Filename      : tee_test.c
 * Programmer(s) : system BSP
 * Filename      : tee_test.c
 * Author        : Shuai Fengyun
 * Mail          : shuaifengyun@126.com
 * Create Time   : 2017年07月13日 星期四 11时32分23秒
 ****************************************************************************************
 */

#define MOUDLE_TEST_SERVICE_C_

/** @defgroup MODULE_NAME_INFOR
* @{
*/

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
#include <tee/tee_test.h>
#include <tee/tee_svc.h>
#include <trace.h>


/*
 *******************************************************************************
 *                         FUNCTIONS SUPPLIED BY THIS MODULE
 *******************************************************************************
*/
TEE_Result syscall_testDriver_write(void *buf, size_t blen, size_t offset);
TEE_Result syscall_testDriver_read(void *buf, size_t blen, size_t offset);
TEE_Result syscall_testDriver_dump(void *buf, size_t blen);






/*
 *******************************************************************************
 *                          VARIABLES SUPPLIED BY THIS MODULE
 *******************************************************************************
*/
struct test_service_ops tes_ops = {
    .name = "TestDriver",
	.test_driver = {
        .device_init = device_init,
        .write = write,
        .read = read,
        .driver_dump = driver_dump,
	},
};





/*
 *******************************************************************************
 *                          FUNCTIONS USED ONLY BY THIS MODULE
 *******************************************************************************
*/





/*
 *******************************************************************************
 *                          VARIABLES USED ONLY BY THIS MODULE
 *******************************************************************************
*/





/*
 *******************************************************************************
 *                               FUNCTIONS IMPLEMENT
 *******************************************************************************
*/
/** @ingroup MOUDLE_NAME_C_
 *- #Description  This function for handle command.
 * @param   pMsg           [IN] The received request message
 *                               - Type: MBX_Msg *
 *                               - Range: N/A.
 *
 * @return     void
 * @retval     void
 *
 *
 */






TEE_Result syscall_testDriver_write(void *buf, size_t blen, size_t offset)
{
    uint8_t* src = NULL;

    src = malloc(blen);

    tee_svc_copy_from_user(src, buf, blen);
    tes_ops.test_driver.write(src, blen, offset);
    free(src);

   
    return TEE_SUCCESS;
}




TEE_Result syscall_testDriver_read(void *buf, size_t blen, size_t offset)
{
    uint8_t* dst = NULL;
    dst = malloc(blen);
    tes_ops.test_driver.read(dst, blen, offset);
    tee_svc_copy_to_user(buf, dst, blen);

    free(dst);
    return TEE_SUCCESS;

}



TEE_Result syscall_testDriver_dump(void *buf, size_t blen)
{
    uint8_t* dst = NULL;
    dst = malloc(blen);
    tes_ops.test_driver.driver_dump(dst, blen);
    tee_svc_copy_to_user(buf, dst, blen);

    free(dst);
    return TEE_SUCCESS;
}





static TEE_Result tee_test_init(void)
{
    DMSG("Strat to start test servie\n");
	if (tes_ops.test_driver.device_init)
		tes_ops.test_driver.device_init();
    DMSG("Init servcie is ok\n");
	return TEE_SUCCESS;
}






service_init(tee_test_init);


/**
 * @}
 */
