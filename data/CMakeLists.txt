
###########################
# Dbus Interfaces
###########################

install(
FILES
org.ayatana.Desktop.Greeter.Broadcast.xml
DESTINATION ${DBUSIFACEDIR}
)

###########################
# DBus Policy Files
###########################

install(
FILES
org.ayatana.Desktop.Greeter.Broadcast.conf
DESTINATION ${DBUSSYSCONFDIR}/dbus-1/system.d
)

###########################
# Dbus Services
###########################

set(BROADCAST_SERVICE
"${CMAKE_CURRENT_BINARY_DIR}/org.ayatana.Desktop.Greeter.Broadcast.service"
)

set(pkglibexecdir "${CMAKE_INSTALL_FULL_LIBEXECDIR}/ayatana-greeter-session-broadcast")
configure_file("org.ayatana.Desktop.Greeter.Broadcast.service.in"
  "${BROADCAST_SERVICE}"
  @ONLY
)

install(
FILES
"${BROADCAST_SERVICE}"
DESTINATION ${DBUSSERVICEDIR}
)

###########################
# Upstart Job
###########################

set(SESSION_UPSTART
"${CMAKE_CURRENT_SOURCE_DIR}/ayatana-greeter-session-broadcast-session.conf"
)

install(
FILES
"${SESSION_UPSTART}"
DESTINATION "/usr/share/upstart/sessions"
)

###########################
# GSettings
###########################

add_schema ("org.ayatana.Desktop.Greeter.Broadcast.gschema.xml")
