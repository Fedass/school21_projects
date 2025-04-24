#!/bin/bash

echo "Building project..."
mkdir -p build
cd build
cmake .. && make -j$(nproc)

if [ $? -ne 0 ]; then
    echo "Build failed!"
    exit 1
fi

echo "Launching servers and client..."

DISPLAY_SERVER=./display_server/display_server
PROCESSOR_SERVER=./processor_server/processor_server
CLIENT_APP=./client/client_app

if [[ ! -f "$DISPLAY_SERVER" || ! -f "$PROCESSOR_SERVER" || ! -f "$CLIENT_APP" ]]; then
    echo "One or more executables not found."
    exit 1
fi

gnome-terminal -- bash -c "$DISPLAY_SERVER 8081; exec bash"
sleep 1

gnome-terminal -- bash -c "$PROCESSOR_SERVER 8080 127.0.0.1 8081; exec bash"
sleep 1

gnome-terminal -- bash -c "$CLIENT_APP 127.0.0.1 8080; exec bash"