#include "guard.h"

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_open_guard(can_ctrl_t *const p_api_ctrl, can_cfg_t const *const p_cfg)
{
    /* TODO: add your own security checks here */

    FSP_PARAMETER_NOT_USED (p_api_ctrl);
    FSP_PARAMETER_NOT_USED (p_cfg);

    return R_CAN_Open (&g_can_ctrl, &g_can_cfg);
}

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_close_guard(can_ctrl_t *const p_api_ctrl)
{
    /* TODO: add your own security checks here */

    FSP_PARAMETER_NOT_USED (p_api_ctrl);

    return R_CAN_Close (&g_can_ctrl);
}

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_write_guard(can_ctrl_t *const p_api_ctrl, uint32_t mailbox,
        can_frame_t *const p_frame)
{
    /* Verify all pointers are in non-secure memory. */
    can_frame_t *const p_frame_checked = cmse_check_pointed_object (p_frame, CMSE_AU_NONSECURE);
    FSP_ASSERT (p_frame_checked != NULL);

    /* TODO: add your own security checks here */

    FSP_PARAMETER_NOT_USED (p_api_ctrl);

    return R_CAN_Write (&g_can_ctrl, mailbox, p_frame_checked);
}

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_read_guard(can_ctrl_t *const p_api_ctrl, uint32_t mailbox,
        can_frame_t *const p_frame)
{
    /* Verify all pointers are in non-secure memory. */
    can_frame_t *const p_frame_checked = cmse_check_pointed_object (p_frame, CMSE_AU_NONSECURE);
    FSP_ASSERT (p_frame_checked != NULL);

    /* TODO: add your own security checks here */

    FSP_PARAMETER_NOT_USED (p_api_ctrl);

    return R_CAN_Read (&g_can_ctrl, mailbox, p_frame_checked);
}

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_mode_transition_guard(can_ctrl_t *const p_api_ctrl,
        can_operation_mode_t operation_mode, can_test_mode_t test_mode)
{
    /* TODO: add your own security checks here */

    FSP_PARAMETER_NOT_USED (p_api_ctrl);

    return R_CAN_ModeTransition (&g_can_ctrl, operation_mode, test_mode);
}

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_info_get_guard(can_ctrl_t *const p_api_ctrl, can_info_t *const p_info)
{
    /* Verify all pointers are in non-secure memory. */
    can_info_t *const p_info_checked = cmse_check_address_range ((void*) p_info, sizeof(can_info_t), CMSE_AU_NONSECURE);
    FSP_ASSERT (p_info_checked != NULL);

    /* TODO: add your own security checks here */

    FSP_PARAMETER_NOT_USED (p_api_ctrl);

    return R_CAN_InfoGet (&g_can_ctrl, p_info_checked);
}

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_callback_set_guard(can_ctrl_t *const p_api_ctrl,
        void (*p_callback)(can_callback_args_t*), void const *const p_context,
        can_callback_args_t *const p_callback_memory)
{
    /* Verify all pointers are in non-secure memory. */
    void (*p_callback_checked)(
            can_callback_args_t*) = (void(*)(can_callback_args_t *)) cmse_check_address_range((void *) p_callback, sizeof(void *), CMSE_AU_NONSECURE);
    FSP_ASSERT(p_callback_checked != NULL);
    can_callback_args_t *const p_callback_memory_checked = cmse_check_pointed_object(p_callback_memory, CMSE_AU_NONSECURE);
    FSP_ASSERT(p_callback_memory_checked != NULL);

    /* TODO: add your own security checks here */

    FSP_PARAMETER_NOT_USED(p_api_ctrl);
    FSP_PARAMETER_NOT_USED(p_context);

    return R_CAN_CallbackSet(&g_can_ctrl, p_callback_checked, p_context, p_callback_memory_checked);
}
