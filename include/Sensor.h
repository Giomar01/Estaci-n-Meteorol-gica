#ifndef SENSOR_H
#define SENSOR_H

#include "libreries.h"

/**
 * @class Sensor
 * @brief Clase abstracta que define la interfaz común para todos los sensores.
 */
class Sensor {
    protected:
    int pin;
    string tipoSensor;

    public:
    /**
     * @brief Constructor de la clase Sensor.
     * @param _pin Pin físico al que está conectado el sensor.
     * @param _tipo Cadena de texto con el nombre del tipo de sensor.
     */
    Sensor(int pin, String tipo);

    virtual ~Sensor();