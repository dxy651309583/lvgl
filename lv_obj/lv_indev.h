/**
 * @file lv_indev_proc.h
 * 
 */

#ifndef LV_INDEV_H
#define LV_INDEV_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lv_obj.h"
#include "../lv_hal/lv_hal_indev.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef enum
{
    LV_RES_INV = 0,      /*Typically indicates that the object is deleted (become invalid) in the action function*/
	LV_RES_OK,           /*The object is valid (no deleted) after the action*/
}lv_res_t;

typedef lv_res_t (*lv_action_t) (struct __LV_OBJ_T * obj);

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Initialize the display input subsystem
 */
void lv_indev_init(void);

/**
 * Get the currently processed input device. Can be used in action functions too.
 * @return pointer to the currently processed input device or NULL if no input device processing right now
 */
lv_indev_t * lv_indev_get_act(void);

/**
 * Reset all display inputs
 */
void lv_indev_reset(lv_indev_t * indev);

/**
 * Reset the long press state of a display input
 * @param indev_proc pointer to a display input
 */
void lv_indev_reset_lpr(lv_indev_t * indev_proc);

/**
 * Enable input devices device by type
 * @param indev pointer to an input device
 * @param cur_obj pointer to an object to be used as cursor
 */
void lv_indev_set_cursor(lv_indev_t * indev, lv_obj_t * cur_obj);

/**
 * Get the last point on display input
 * @param indev_proc pointer to a display input
 * @param point pointer to a point to store the result
 */
void lv_indev_get_point(lv_indev_t * indev_proc, point_t * point);

/**
 * Check if there is dragging on display input or not
 * @param indev_proc pointer to a display input
 * @return true: drag is in progress
 */
bool lv_indev_is_dragging(lv_indev_t * indev_proc);

/**
 * Get the vector of dragging on a display input
 * @param indev_proc pointer to a display input
 * @param point pointer to a point to store the vector
 */
void lv_indev_get_vect(lv_indev_t * indev_proc, point_t * point);

/**
 * Do nothing until the next release
 * @param indev_proc pointer to a display input
 */
void lv_indev_wait_release(lv_indev_t * indev_proc);

/**********************
 *      MACROS
 **********************/


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif  /*LV_INDEV_H*/