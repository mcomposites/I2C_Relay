#include "RelayBoard.h"

RelayBoard::RelayBoard(uint8_t address) {
    _address = address;
    _relayStatus = 0xFF; // All relays off initially
}

void RelayBoard::begin() {
    Wire.begin();
}

void RelayBoard::setRelay(uint8_t relay, bool state) {
    uint8_t bitPosition = 7 - relay; // Reverse the bit order

    if(state) {
        bitClear(_relayStatus, bitPosition); // Turn relay on
    } else {
        bitSet(_relayStatus, bitPosition); // Turn relay off
    }
    Wire.beginTransmission(_address);
    Wire.write(_relayStatus);
    Wire.endTransmission();
}

void RelayBoard::allRelays(bool state) {
    _relayStatus = state ? 0x00 : 0xFF;
    Wire.beginTransmission(_address);
    Wire.write(_relayStatus);
    Wire.endTransmission();
}

// ... Implementation of other methods
