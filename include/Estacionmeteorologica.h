#ifndef ESTACIONMETEOROLOGICA_H

#define ESTACIONMETEOROLOGICA_H

#include "Sensor.h"
#include "PantallaLCD.h"

/**
 * @class EstacionMeteorologica
 * @brief Clase de alto nivel encargada de dirigir a los sensores y la salida de datos.
 */
class EstacionMeteorologica {
    protected:
        Sensor** listaSensores;     
        int cantidadSensores;    
        int capacidadMax;   
        PantallaLCD* lcd;
        int indiceActual;

    public:
        /**
         * @brief Constructor de la EstacionMeteorologica.
         * @param capacidadMax Capacidad máxima del vector dinámico de sensores.
         * @param lcd Puntero a la pantalla LCD que utilizará el sistema para mostrar datos.
         */
        EstacionMeteorologica(int capacidadMax, PantallaLCD* lcd);

        /**
         * @brief Destructor encargado de liberar adecuadamente toda la memoria dinámica.
         * @note Borra de manera individual cada objeto sensor almacenado en el heap mediante 'delete'.
         */
        ~EstacionMeteorologica();

        /**
         * @brief Agrega dinámicamente un nuevo sensor al arreglo de la estación.
         * @param nuevoSensor Puntero de tipo Sensor.
         * @return true si el sensor se agregó con éxito, false si el arreglo está lleno.
         */
        bool agregarSensor(Sensor* nuevoSensor);

        /**
         * @brief Actualiza de manera secuencial las lecturas de todos los sensores registrados.
         * @note Aplica polimorfismo dinámico al invocar leerDatos().
         */
        void actualizarMediciones();

        /**
         * @brief Procesa y envía los datos recolectados hacia el objeto PantallaLCD.
         */
        void mostrarEnLCD();

        /**
         * @brief Mueve el índice al siguiente sensor en la lista.
         * 
         */
        void siguienteSensor();

        /**
         * @brief Mueve el índice al sensor anterior en la lista.
         */
        void anteriorSensor();

        /**
         * @brief Muestra los datos del sensor actual en la pantalla LCD.
         */
        void mostrarSensorActual();
    };

#endif