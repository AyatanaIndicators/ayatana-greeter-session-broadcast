#!/bin/bash

gdbus call --system --dest com.canonical.Unity.Greeter.Broadcast --object-path /com/canonical/Unity/Greeter/Broadcast --method com.canonical.Unity.Greeter.Broadcast.RequestUrlStart $1 $2
