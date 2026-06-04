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

    /**
     * @brief Obtiene la humedad del suelo medida.
     * @return Porcentaje de humedad (0% - 100%).
     */
    float getHumedadSuelo() const;

    /**
     * @brief Establece el valor de humedad del suelo.
     * @param humedad Porcentaje de humedad.
     */
    void setHumedadSuelo(float humedad);

    /**
     * @brief Lee la entrada analógica y calcula el porcentaje de humedad del suelo.
     */
    void leerDatos() override;
};

#endif