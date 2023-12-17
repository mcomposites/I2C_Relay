#include <RelayBoard.h>

RelayBoard relayBoard(0x27);

void setup() {
    relayBoard.begin();
    relayBoard.allRelays(false); // Turn all relays off
}

void loop() {
    // Example to toggle relay 1
    relayBoard.setRelay(1, true); // Turn on relay 1
    delay(1000);
    relayBoard.setRelay(1, false); // Turn off relay 1
    delay(1000);
}
