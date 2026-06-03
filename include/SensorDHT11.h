#ifndef SENSORDHT11_H
#define SENSORDHT11_H

#include "Sensor.h"
#include <DHT.h>

class SensorDHT11 : public Sensor {
private:
    float temperatura;
    float humedad;
    DHT dht;