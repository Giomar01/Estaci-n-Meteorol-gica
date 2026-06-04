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
    
    void leerDatos() override;

    float leerTemperatura();
    float leerHumedad();

    float getTemperatura();

    float getHumedad();
};

#endif