/**
 * Copyright (C) 2013 Canonical, Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License version 3, as published by
 * the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranties of MERCHANTABILITY,
 * SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <gio/gio.h>
#include <unistd.h>
#include "service-iface.h"

static gboolean
on_handle_request_url_start (ServiceIfaceOrgAyatanaDesktopGreeterBroadcast *object,
                             GDBusMethodInvocation *invocation,
                             const gchar *arg_username,
                             const gchar *arg_url)
{
    /* Simply pass the request on */
    service_iface_org_ayatana_desktop_greeter_broadcast_emit_start_url (object,
                                                                        arg_username,
                                                                        arg_url);
    service_iface_org_ayatana_desktop_greeter_broadcast_complete_request_url_start (object,
                                                                                    invocation);
    return TRUE;
}

static gboolean
on_handle_request_home_shown (ServiceIfaceOrgAyatanaDesktopGreeterBroadcast *object,
                              GDBusMethodInvocation *invocation,
                              const gchar *arg_username)
{
    /* Simply pass the request on */
    service_iface_org_ayatana_desktop_greeter_broadcast_emit_show_home (object,
                                                                        arg_username);
    service_iface_org_ayatana_desktop_greeter_broadcast_complete_request_home_shown (object,
                                                                                     invocation);
    return TRUE;
}

static gboolean
on_handle_request_sound_play_pause (ServiceIfaceOrgAyatanaDesktopGreeterBroadcast *object,
                                    GDBusMethodInvocation *invocation,
                                    const gchar *arg_username)
{
    /* Simply pass the request on */
    service_iface_org_ayatana_desktop_greeter_broadcast_emit_sound_play_pause (object,
                                                                               arg_username);
    service_iface_org_ayatana_desktop_greeter_broadcast_complete_request_sound_play_pause (object,
                                                                                           invocation);
    return TRUE;
}

static gboolean
on_handle_request_sound_next (ServiceIfaceOrgAyatanaDesktopGreeterBroadcast *object,
                              GDBusMethodInvocation *invocation,
                              const gchar *arg_username)
{
    /* Simply pass the request on */
    service_iface_org_ayatana_desktop_greeter_broadcast_emit_sound_next (object,
                                                                         arg_username);
    service_iface_org_ayatana_desktop_greeter_broadcast_complete_request_sound_next (object,
                                                                                     invocation);
    return TRUE;
}

static gboolean
on_handle_request_sound_prev (ServiceIfaceOrgAyatanaDesktopGreeterBroadcast *object,
                              GDBusMethodInvocation *invocation,
                              const gchar *arg_username)
{
    /* Simply pass the request on */
    service_iface_org_ayatana_desktop_greeter_broadcast_emit_sound_prev (object,
                                                                         arg_username);
    service_iface_org_ayatana_desktop_greeter_broadcast_complete_request_sound_prev (object,
                                                                                     invocation);
    return TRUE;
}

static void
on_bus_acquired (GDBusConnection *connection,
                 const gchar     *name,
                 gpointer         user_data)
{
    GError *error = NULL;
    ServiceIfaceOrgAyatanaDesktopGreeterBroadcast *interface;

    interface = (ServiceIfaceOrgAyatanaDesktopGreeterBroadcast *)user_data;

    if (!g_dbus_interface_skeleton_export (G_DBUS_INTERFACE_SKELETON (interface),
                                           connection,
                                           "/org/ayatana/Desktop/Greeter/Broadcast",
                                           &error))
    {
        g_error ("Unable to export interface: %s, exiting", error->message);
    }
}

static void
on_name_lost (GDBusConnection *connection,
              const gchar     *name,
              gpointer         user_data)
{
    g_error ("Lost bus name, exiting");
}

int
main (int argc, char * argv[])
{
    guint owner_id;
    GMainLoop *loop;
    ServiceIfaceOrgAyatanaDesktopGreeterBroadcast *interface;

    interface = service_iface_org_ayatana_desktop_greeter_broadcast_skeleton_new ();

    /* Application Launching */
    g_signal_connect (interface,
                      "handle-request-url-start",
                      G_CALLBACK (on_handle_request_url_start),
                      NULL);
    g_signal_connect (interface,
                      "handle-request-home-shown",
                      G_CALLBACK (on_handle_request_home_shown),
                      NULL);

    /* Sound stuff */
    g_signal_connect (interface,
                      "handle-request-sound-play-pause",
                      G_CALLBACK (on_handle_request_sound_play_pause),
                      NULL);
    g_signal_connect (interface,
                      "handle-request-sound-next",
                      G_CALLBACK (on_handle_request_sound_next),
                      NULL);
    g_signal_connect (interface,
                      "handle-request-sound-prev",
                      G_CALLBACK (on_handle_request_sound_prev),
                      NULL);

    owner_id = g_bus_own_name (G_BUS_TYPE_SYSTEM,
                               "org.ayatana.Desktop.Greeter.Broadcast",
                               G_BUS_NAME_OWNER_FLAGS_NONE,
                               on_bus_acquired,
                               NULL,
                               on_name_lost,
                               g_object_ref (interface),
                               g_object_unref);

    loop = g_main_loop_new (NULL, FALSE);
    g_main_loop_run (loop);

    g_bus_unown_name (owner_id);
    g_object_unref (interface);
    g_object_unref (loop);

    return 0;
}
