#!/bin/bash

gdbus call --system --dest com.canonical.Unity.Greeter.Broadcast --object-path /com/canonical/Unity/Greeter/Broadcast --method com.canonical.Unity.Greeter.Broadcast.RequestApplicationStart $1 $2
