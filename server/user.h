/*
 * Wine server USER definitions
 *
 * Copyright (C) 2001 Alexandre Julliard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __WINE_SERVER_USER_H
#define __WINE_SERVER_USER_H

#include "wine/server_protocol.h"

struct thread;
struct region;
struct window;
struct msg_queue;
struct hook_table;
struct window_class;

enum user_object
{
    USER_WINDOW = 1,
    USER_HOOK
};

/* user handles functions */

extern user_handle_t alloc_user_handle( void *ptr, enum user_object type );
extern void *get_user_object( user_handle_t handle, enum user_object type );
extern void *get_user_object_handle( user_handle_t *handle, enum user_object type );
extern user_handle_t get_user_full_handle( user_handle_t handle );
extern void *free_user_handle( user_handle_t handle );
extern void *next_user_handle( user_handle_t *handle, enum user_object type );

/* clipboard functions */

extern void cleanup_clipboard_thread( struct thread *thread );

/* hook functions */

extern void close_global_hooks(void);
extern void remove_thread_hooks( struct thread *thread );

/* queue functions */

extern void free_msg_queue( struct thread *thread );
extern struct hook_table *get_queue_hooks( struct thread *thread );
extern void set_queue_hooks( struct thread *thread, struct hook_table *hooks );
extern void inc_queue_paint_count( struct thread *thread, int incr );
extern void queue_cleanup_window( struct thread *thread, user_handle_t win );
extern int attach_thread_input( struct thread *thread_from, struct thread *thread_to );
extern void post_message( user_handle_t win, unsigned int message,
                          unsigned int wparam, unsigned int lparam );

/* region functions */

extern struct region *create_region( const rectangle_t *rects, unsigned int nb_rects );
extern struct region *create_region_from_req_data( const void *data, size_t size );
extern void free_region( struct region *region );
extern void set_region_rect( struct region *region, const rectangle_t *rect );
extern rectangle_t *get_region_data( const struct region *region, size_t max_size,
                                     size_t *total_size );
extern rectangle_t *get_region_data_and_free( struct region *region, size_t max_size,
                                              size_t *total_size );
extern int is_region_empty( const struct region *region );
extern void get_region_extents( const struct region *region, rectangle_t *rect );
extern void offset_region( struct region *region, int x, int y );
extern struct region *copy_region( struct region *dst, const struct region *src );
extern struct region *intersect_region( struct region *dst, const struct region *src1,
                                        const struct region *src2 );
extern struct region *subtract_region( struct region *dst, const struct region *src1,
                                       const struct region *src2 );
extern struct region *union_region( struct region *dst, const struct region *src1,
                                    const struct region *src2 );
extern struct region *xor_region( struct region *dst, const struct region *src1,
                                  const struct region *src2 );
extern int point_in_region( struct region *region, int x, int y );
extern int rect_in_region( struct region *region, const rectangle_t *rect );
static inline struct region *create_empty_region(void) { return create_region( NULL, 0 ); }

/* window functions */

extern void destroy_thread_windows( struct thread *thread );
extern int is_child_window( user_handle_t parent, user_handle_t child );
extern int is_top_level_window( user_handle_t window );
extern int is_window_visible( user_handle_t window );
extern int make_window_active( user_handle_t window );
extern struct thread *get_window_thread( user_handle_t handle );
extern user_handle_t window_from_point( int x, int y );
extern user_handle_t find_window_to_repaint( user_handle_t parent, struct thread *thread );
extern struct window_class *get_window_class( user_handle_t window );

/* window class functions */

extern void destroy_process_classes( struct process *process );
extern struct window_class *grab_class( struct process *process, atom_t atom,
                                        void *instance, int *extra_bytes );
extern void release_class( struct window_class *class );
extern atom_t get_class_atom( struct window_class *class );
extern void *get_class_client_ptr( struct window_class *class );

#endif  /* __WINE_SERVER_USER_H */
