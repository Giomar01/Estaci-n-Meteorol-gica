#ifndef PANTALLALCD_H
#define PANTALLALCD_H

#include "Librerias.h"
/**
 * @class PantallaLCD
 * @brief Encapsula las funciones de la pantalla LCD de forma modular.
 */
class PantallaLCD {
private:
    LiquidCrystal_I2C lcd; 
    int columnas;
    int filas;

public:
    /**
     * @brief Constructor de la clase PantallaLCD.
     * @param lcdAddr Dirección física del bus I2C.
     * @param columnas Número de columnas de la pantalla.
     * @param filas Número de filas de la pantalla.
     */
    PantallaLCD(uint8_t lcdAddr, int _columnas, int _filas);

    /**
     * @brief Enciende la luz de fondo de la pantalla.
     */
    void encenderLuz();

    /**
     * @brief Apaga la luz de fondo de la pantalla para ahorro de energía.
     */
    void apagarLuz();
    
    /**
     * @brief Muestra un mensaje genérico estático divido en dos líneas.
     * @param linea1 Texto para la fila superior.
     * @param linea2 Texto para la fila inferior.
     */
    void mostrarMensaje(string linea1, string linea2);

    /**
     * @brief Muestra de forma formateada el nombre de un sensor y sus datos medidos[cite: 124].
     * @param nombreSensor Nombre legible del dispositivo.
     * @param datos Cadena con los datos y sus unidades métricas.
     */
    void mostrarSensor(string nombreSensor, string datos);
};

#endif