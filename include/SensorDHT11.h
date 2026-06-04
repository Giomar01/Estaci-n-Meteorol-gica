#ifndef SENSORDHT11_H
#define SENSORDHT11_H

#include "Sensor.h"
#include <DHT.h>

/**
 * @class SensorDHT11
 * @brief clase sensorDHT11 derivada de sensor
 */
class SensorDHT11 : public Sensor {
private:
    float temperatura;
    float humedad;
    DHT dht;
    public:
    /**
     * @brief Constructor de la clase Sensor.
     * @param _pin Pin físico al que está conectado el sensor.
     */
    SensorDHT11(int pin);
    /**
    * @brief Lee los datos del sensor DHT11.
    *
    * Obtiene los valores actuales de temperatura y humedad
    * almacenándolos en los atributos correspondientes.
    */
    void leerDatos() override;
    /**
    * @brief Obtiene la temperatura medida por el sensor.
    *
    * Realiza una lectura de temperatura desde el DHT11.
    *
    * @return Temperatura en grados Celsius (°C).
    */
    float leerTemperatura();
    /**
    * @brief Obtiene la humedad relativa medida por el sensor.
    *
    * Realiza una lectura de humedad desde el DHT11.
    *
    * @return Humedad relativa en porcentaje (%).
    */
    float leerHumedad();
    /**
    * @brief Retorna el último valor de temperatura almacenado.
    *
    * @return Temperatura en grados Celsius (°C).
    */
    float getTemperatura();
    /**
    * @brief Retorna el último valor de humedad almacenado.
    *
    * @return Humedad relativa en porcentaje (%).
    */
    float getHumedad();
};

#endif