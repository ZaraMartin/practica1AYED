// AUTOR: Zara Martín Bolaños
// FECHA: 8/02/24
// EMAIL: alu0101493381@ull.edu.es
// VERSION: 1.0
// ASIGNATURA: Algoritmos y Estructuras de Datos
// PRÁCTICA Nº: 1
// COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
//              "C++ Programming Style Guidelines"
//              https://geosoft.no/development/cppstyle.html
// COMPILACIÓN: g++ -g rational_t.cpp main_rational_t.cpp -o main_rational_t

// pauta de estilo [92]: comentarios multilínea usando solo "//"
// Uso de la guía de estilo de Google, comentario barra barra. 


#pragma once

#include <iostream>
#include <cassert>
#include <cmath>

// pauta de estilo [5]
// los nombres de las constantes se escriben en mayúsculas y sin espacios
// las funciones deben empezar con mayúscula y tener 
// una minúscula para cada palabra nueva 


# define EPSILON 1e-6

using namespace std;

class rational_t
{
  // pautas de estilos [44] y [73]: primero "public" y después "private"
  // Secciones en órden público, protegido y 
  // privado, cada una sangrada un espacio.

public:
  rational_t(const int = 0, const int = 1);
  ~rational_t() {}

  // pauta de estilo [71]: indentación a 2 espacios
  // la identación es una sangría de dos espacios

  // getters, métodos que devuelven los valores de una variable privada 
  int get_num() const;
  int get_den() const;

  // setters, métodos que modifican los valores de una variable privada 
  void set_num(const int);
  void set_den(const int);
  // Es un método que devuleve el valor del objeto en forma flotante, es decir,
  // pasa de una fracción a un número decimal.
  double value(void) const;

  // FASE II
  // Es un método que sobrecarga el operador ==, lo que hará que podamos saber
  // si dos objetos son iguales.
  bool is_equal(const rational_t&, const double precision = EPSILON) const;
  // Es un método que sobrecarga el operador >, lo que hará que podamos saber
  // si un objeto es mayor que otro objeto. 
  bool is_greater(const rational_t&, const double precision = EPSILON) const;
  // Es un método que sobrecarga el operador <, lo que hará que podamos saber
  // si un objeto es menor que otro objeto.
  bool is_less(const rational_t&, const double precision = EPSILON) const;

  // FASE III
  // Es un método que hace la suma entre dos racionales.
  rational_t add(const rational_t&);
  // Es un método que hace la resta entre dos racionales.
  rational_t substract(const rational_t&);
  // Es un método que hace la multiplicación entre dos racionales.
  rational_t multiply(const rational_t&);
  //  Es un método que hace la división entre dos racionales.
  rational_t divide(const rational_t&);
  
  // modificaciones
  rational_t pow1();
  rational_t substract2();
  // void substract3(const rational_t& r);

  // Método que escribe el valor del objeto, es un out put. Se usa con std::cout, 
  // std::ostream, etc.
  void write(ostream & = cout) const;

  // Método que lee el valor añadido por el usuario y lo añade al objeto, es un 
  // in put. Se usa con std::cin, std::istream, etc.o 
  void read(istream & = cin);

private:
  // pauta de estilo [11]: nombre de los atributos seguido de "_"
  // Se añade una k minuscula al principio, se le pone un nombre 
  // significativo y en formato Dromedario. Ejemplo: kBaseDeLaMatriz

  int num_, den_;
};
