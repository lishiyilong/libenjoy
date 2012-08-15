/**********************************************
**    This file is part of libenjoy
**    https://github.com/Tasssadar/libenjoy
**
**    See README and COPYING
***********************************************/

#ifndef LIBENJOY_P_H
#define LIBENJOY_P_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

struct libenjoy_os_ctx *libenjoy_init_private(void);
void libenjoy_close_private(struct libenjoy_os_ctx *os);
uint32_t libenjoy_get_new_joyid(void);

int libenjoy_joy_info_created(libenjoy_context *ctx, uint32_t id);
void libenjoy_add_joy_info(libenjoy_context *ctx, libenjoy_joy_info *inf);
void libenjoy_destroy_joy_info(libenjoy_context *ctx, uint32_t id);
libenjoy_joy_info* libenjoy_get_joy_info(libenjoy_context *ctx, uint32_t id);

libenjoy_os_specific *libenjoy_open_os_specific(libenjoy_context *ctx, uint32_t id);
void libenjoy_close_os_specific(libenjoy_os_specific *os);

void libenjoy_add_joy_to_list(libenjoy_joystick *joy);
void libenjoy_rm_joy_from_list(libenjoy_joystick *joy);
void libenjoy_joy_set_valid_by_id(libenjoy_context *ctx, uint32_t id, char valid);
void libenjoy_joy_set_valid(libenjoy_joystick *joy, char valid);
libenjoy_joystick *libenjoy_get_joystick(libenjoy_context *ctx, uint32_t id);

libenjoy_event *libenjoy_buff_get_for_write(libenjoy_context *ctx);
void libenjoy_buff_push(libenjoy_context *ctx);
libenjoy_event libenjoy_buff_top(libenjoy_context *ctx);
void libenjoy_buff_pop(libenjoy_context *ctx);
uint16_t libenjoy_buff_inc_if_can(uint16_t val);

void libenjoy_poll_priv(libenjoy_context *ctx);

#ifdef __cplusplus
}
#endif

#endif // LIBENJOY_P_H
