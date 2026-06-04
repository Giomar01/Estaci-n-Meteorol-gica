#ifndef SENSORLUZ_H
#define SENSORLUZ_H

#include "Sensor.h"

/**
 * @class SensorLuz
 * @brief Clase derivada que modela un sensor de luminosidad por entrada analógica.
 */
class SensorLuz : public Sensor {
private:
    float porcentajeLuz;