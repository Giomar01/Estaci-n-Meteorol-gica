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
        
    public:
        /**
         * @brief Constructor para SensorLuz.
         * @param pin Pin analógico de conexión.
         */
        SensorLuz(int pin);

        /**
         * @brief Destructor de SensorLuz.
         */
        ~SensorLuz() override;

        /**
         * @brief Obtiene el porcentaje de luz actual.
         * @return Valor flotante entre 0.0 y 100.0.
         */
        float getPorcentajeLuz() const;

        /**
         * @brief Establece el porcentaje de luz.
         * @param luz Porcentaje de luz.
         */
        void setPorcentajeLuz(float luz);

        /**
         * @brief Lee el valor analógico y lo convierte a porcentaje de luz[cite: 124].
         */
        void leerDatos() override;

        /**
         * @brief Sobrescribe el método para obtener los datos formateados del sensor.
         * @return String con los datos formateados listos para la LCD.
         */
        string obtenerDatosFormateados() override;
    };

#endif