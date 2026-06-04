#ifndef SENSORSUELO_H
#define SENSORSUELO_H

#include "Sensor.h"

/**
 * @class SensorSuelo
 * @brief Clase derivada para medir la humedad en terrenos.
 */
class SensorSuelo : public Sensor {
private:
    float humedadSuelo;

public:
    /**
     * @brief Constructor para SensorSuelo.
     * @param pin Pin analógico de conexión.
     */
    SensorSuelo(int pin);

    /**
     * @brief Destructor de SensorSuelo.
     */
    ~SensorSuelo() override;