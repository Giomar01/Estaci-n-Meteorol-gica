#ifndef PANTALLALCD_H
#define PANTALLALCD_H

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