/* generated guard header file - do not edit */
#ifndef GUARD_H_
#define GUARD_H_
#include "hal_data.h"
BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_open_guard(can_ctrl_t *const p_api_ctrl, can_cfg_t const *const p_cfg);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_close_guard(can_ctrl_t *const p_api_ctrl);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_write_guard(can_ctrl_t *const p_api_ctrl, uint32_t mailbox,
        can_frame_t *const p_frame);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_read_guard(can_ctrl_t *const p_api_ctrl, uint32_t mailbox,
        can_frame_t *const p_frame);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_mode_transition_guard(can_ctrl_t *const p_api_ctrl,
        can_operation_mode_t operation_mode, can_test_mode_t test_mode);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_info_get_guard(can_ctrl_t *const p_api_ctrl, can_info_t *const p_info);

BSP_CMSE_NONSECURE_ENTRY fsp_err_t g_can_callback_set_guard(can_ctrl_t *const p_api_ctrl,
        void (*p_callback)(can_callback_args_t*), void const *const p_context,
        can_callback_args_t *const p_callback_memory);
#endif /* GUARD_H_ */
