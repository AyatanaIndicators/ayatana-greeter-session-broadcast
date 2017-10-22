/**
 * Copyright (C) 2013 Canonical, Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranties of MERCHANTABILITY,
 * SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <glib.h>

#ifndef __AYATANA_GREETER_SESSION_BROADCAST_H__
#define __AYATANA_GREETER_SESSION_BROADCAST_H__ 1

#pragma GCC visibility push(default)

G_BEGIN_DECLS

void
ayatana_session_greeter_broadcast_request_app_start (const gchar * username,
                                                     const gchar * app_id);

G_END_DECLS

#pragma GCC visibility pop

#endif /* __AYATANA_GREETER_SESSION_BROADCAST_H__ */
