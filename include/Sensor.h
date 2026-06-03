#ifndef SENSOR_H
#define SENSOR_H

#include "librerias.h"

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
    Sensor(int pin, string tipo);

    virtual ~Sensor();
    /**
     * @brief Obtiene el pin de conexión del sensor.
     * @return Entero que representa el pin.
     */
    int getPin() const;
    /**
     * @brief Define un nuevo pin para el sensor.
     * @param _pin Nuevo pin físico de conexión.
     */
    void setPin(int pin);
    /**
     * @brief Obtiene el tipo o nombre del sensor.
     * @return String con el tipo de sensor.
     */
    string getTipoSensor() const;
    /**
     * @brief Define el tipo o nombre del sensor.
     * @param _tipo Cadena de texto con el nuevo tipo.
     */
    void setTipoSensor(string tipo);

    virtual void leerDatos() = 0;

};
#endif