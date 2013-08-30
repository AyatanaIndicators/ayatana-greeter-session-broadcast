
###########################
# Dbus Interfaces
###########################

install(
FILES
com.canonical.Unity.Greeter.Broadcast.xml
DESTINATION ${DBUSIFACEDIR}
)

###########################
# DBus Policy Files
###########################

install(
FILES
com.canonical.Unity.Greeter.Broadcast.conf
DESTINATION ${DBUSSYSCONFDIR}/dbus-1/system.d
)

###########################
# Dbus Services
###########################

set(BROADCAST_SERVICE
"${CMAKE_CURRENT_BINARY_DIR}/com.canonical.Unity.Greeter.Broadcast.service"
)

set(pkglibexecdir "${CMAKE_INSTALL_FULL_LIBEXECDIR}/unity-greeter-session-broadcast")
configure_file("com.canonical.Unity.Greeter.Broadcast.service.in"
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
"${CMAKE_CURRENT_SOURCE_DIR}/unity-greeter-session-broadcast-session.conf"
)

install(
FILES
"${SESSION_UPSTART}"
DESTINATION "/usr/share/upstart/sessions"
)

###########################
# GSettings
###########################

add_schema ("com.canonical.Unity.Greeter.Broadcast.gschema.xml")
