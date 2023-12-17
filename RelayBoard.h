#ifndef RelayBoard_h
#define RelayBoard_h

#include "Arduino.h"
#include <Wire.h>

class RelayBoard {
public:
    RelayBoard(uint8_t address);
    void begin();
    void setRelay(uint8_t relay, bool state);
    void allRelays(bool state);
    // ... Other utility methods like getStatus, etc.

private:
    uint8_t _address;
    uint8_t _relayStatus;
};

#endif
