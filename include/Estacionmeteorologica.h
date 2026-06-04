#ifndef ESTACIONMETEOROLOGICA_H
#define ESTACIONMETEOROLOGICA_H

#include "Sensor.h"
#include "PantallaLCD.h"

/**
 * @class EstacionMeteorologica
 * @brief Clase de alto nivel encargada de orquestar los sensores y la salida de datos.
 */
class EstacionMeteorologica {
private:
    Sensor** listaSensores;     
    int cantidadSensores;    
    int capacidadMax;   
    PantallaLCD* lcd;
public:
    /**
     * @brief Constructor de la EstacionMeteorologica.
     * @param capacidadMax Capacidad máxima del arreglo dinámico de sensores.
     * @param lcd Puntero a la pantalla LCD que utilizará el sistema para mostrar datos.
     */
    EstacionMeteorologica(int capacidadMax, PantallaLCD* lcd);
