#!/bin/bash

gdbus call --system --dest org.ayatana.Desktop.Greeter.Broadcast --object-path /org/ayatana/Desktop/Greeter/Broadcast --method org.ayatana.Desktop.Greeter.Broadcast.RequestUrlStart $1 $2
