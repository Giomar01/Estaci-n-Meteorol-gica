#ifndef SENSORAMBIENTAL_H

#define SENSORAMBIENTAL_H

#include "Sensor.h"

/**
 * @class SensorAmbiental (Temperatura y Humedad)
 * @brief Clase SensorAmbiental derivada de Sensor
 */
class SensorAmbiental : public Sensor {
    private:
        float temperatura;
        float humedad;
        DHT dht;

    public:
        /**
         * @brief Constructor de la clase Sensor.
         * @param pin Pin físico al que está conectado el sensor.
         */
        SensorAmbiental(int pin);

        /**
         * @brief Destructor de SensorAmbiental.
         */
        ~SensorAmbiental() override;

        /**
         * @brief Establece la temperatura medida por el sensor DHT11.
         * @param temperatura Temperatura en grados Celsius (°C).
         */
        void setTemperatura(float temperatura);

        /**
         * @brief Establece la humedad relativa medida por el sensor DHT11.
         * @param humedad Humedad relativa en porcentaje (%).
         */
        void setHumedad(float humedad);

        /**
         * @brief Retorna el último valor de temperatura almacenado.
         * @return Temperatura en grados Celsius (°C).
         */
        float getTemperatura() const;
        
        /**
         * @brief Retorna el último valor de humedad almacenado.
         * @return Humedad relativa en porcentaje (%).
         */
        float getHumedad() const;

        /**
         * @brief Lee los datos obtenidos de temperatura y humedad por el sensor DHT11
         * @return no retorna nada, pero actualiza los atributos temperatura y humedad de la clase.
         */
        void leerDatos() override;

        /**
         * @brief Sobrescribe el método para obtener los datos formateados del sensor.
         * @return String con los datos formateados listos para la LCD.
         */
        string obtenerDatosFormateados() override;
};

#endif