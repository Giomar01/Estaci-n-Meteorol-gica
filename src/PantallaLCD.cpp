#include "PantallaLCD.h"

PantallaLCD::PantallaLCD(uint8_t lcdAddr, int columnas, int filas) : lcd(lcdAddr, columnas, filas) {
    this->columnas = columnas;
    this->filas = filas;
}

PantallaLCD::~PantallaLCD() {
    // No se requieren acciones específicas para el destructor
}

void PantallaLCD::inicializar() {
    lcd.init();
    lcd.backlight();
}

void PantallaLCD::limpiar() {
    lcd.clear();
}

void PantallaLCD::encenderLuz() {
    lcd.backlight();
}

void PantallaLCD::apagarLuz() {
    lcd.noBacklight();
}

void PantallaLCD::mostrarMensaje(string linea1, string linea2) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(linea1.c_str());
    lcd.setCursor(0, 1);
    lcd.print(linea2.c_str());
}

void PantallaLCD::mostrarSensor(string nombreSensor, string datos) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(nombreSensor.c_str());
    lcd.setCursor(0, 1);
    lcd.print(datos.c_str());
}