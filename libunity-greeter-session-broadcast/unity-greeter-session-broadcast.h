
#include <glib.h>

#ifndef __UNITY_GREETER_SESSION_BROADCAST_H__
#define __UNITY_GREETER_SESSION_BROADCAST_H__ 1

#pragma GCC visibility push(default)

G_BEGIN_DECLS

void
unity_session_greeter_broadcast_request_app_start (const gchar * username,
                                                   const gchar * app_id);

G_END_DECLS

#pragma GCC visiblity pop

#endif /* __UNITY_GREETER_SESSION_BROADCAST_H__ */
