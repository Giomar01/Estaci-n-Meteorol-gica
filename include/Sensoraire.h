#ifndef SENSORAIRE_H
#define SENSORAIRE_H

#include "Sensor.h"

/**
 * @class SensorAire
 * @brief Clase derivada que modela un sensor de gas/calidad del aire.
 */
class SensorAire : public Sensor {
private:
float ppmCalidad;
public:
    /**
     * @brief Constructor para SensorAire.
     * @param pin Pin analógico de lectura.
     */
    SensorAire(int pin);