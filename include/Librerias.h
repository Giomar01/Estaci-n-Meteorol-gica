#ifndef LIBRERIAS_H

#define LIBRERIAS_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using std::string;
using std::vector;

// Declaraciones de clases a utilizar adelantadas para evitar errores de tipo en los vectores globales
class Sensor;
class SensorAmbiental;
class SensorSuelo;
class SensorLuz;
class SensorAire;
class PantallaLCD;

#endif