/*
 ****************************************************************************************
 *
 *               driver_test.c
 *
 * Filename      : driver_test.c
 * Programmer(s) : system BSP
 * Filename      : driver_test.c
 * Author        : Shuai Fengyun
 * Mail          : shuaifengyun@126.com
 * Create Time   : 2017年07月13日 星期四 11时30分24秒
 ****************************************************************************************
 */

#define MOUDLE_TEST_DRIVER_C_

/** @defgroup MODULE_NAME_INFOR
* @{
*/

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
#include <tee/tee_svc.h>
#include <trace.h>





/*
 *******************************************************************************
 *                         FUNCTIONS SUPPLIED BY THIS MODULE
 *******************************************************************************
*/
TEE_Result device_init(void);
TEE_Result write(uint8_t *data, size_t len, size_t offset);
TEE_Result read(uint8_t *dst, size_t len, size_t offset);
TEE_Result driver_dump(uint8_t *data, size_t len);






/*
 *******************************************************************************
 *                          VARIABLES SUPPLIED BY THIS MODULE
 *******************************************************************************
*/





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

uint8_t g_buffer[128] = {0};




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

TEE_Result device_init(void)
{
    DMSG("Device init: Clear Buffer\n");
    memset(g_buffer, 0, 128);
    return TEE_SUCCESS;
}

TEE_Result write(uint8_t *data, size_t len, size_t offset)
{
    DMSG("Start to write\n");
    memcpy(&(g_buffer[offset]), data, len);
    DHEXDUMP(&(g_buffer[offset]), len);
    return TEE_SUCCESS;
}

TEE_Result read(uint8_t *dst, size_t len, size_t offset)
{
    DMSG("Start to read\n");
    memcpy(dst, &(g_buffer[offset]), len);
    DHEXDUMP(&(g_buffer[offset]), len);
    return TEE_SUCCESS;
}

TEE_Result driver_dump(uint8_t *data, size_t len)
{
    DMSG("Start to dump\n");
    memcpy(data,&(g_buffer[0]), len);
    DHEXDUMP(&(g_buffer[0]), len);
    return TEE_SUCCESS;
}



















/**
 * @}
 */
