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
     /**
     * @brief Destructor de SensorAire.
     */
    ~SensorAire() override;

    /**
     * @brief Obtiene la concentración de gas medida en ppm.
     * @return Valor en partes por millón.
     */
    float getPpmCalidad() const;

    /**
     * @brief Establece las partes por millón de la calidad del aire.
     * @param ppm Valor en partes por millón.
     */
    void setPpmCalidad(float ppm);

    /**
     * @brief Lee el sensor y calcula la presencia de gases en el aire.
     */
    void leerDatos() override;
};

#endif