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


#include "rational_t.hpp"
#include <cmath>

rational_t::rational_t(const int n, const int d)
{
  assert(d != 0);
  num_ = n, den_ = d;
}

// pauta de estilo [87]: 3 líneas de separación entre métodos
// Las listas de inicializadores de constructores pueden estar todas 
// en una línea o con líneas subsiguientes con sangría de cuatro espacios


// pauta de estilo [83]: tipo retornado en línea anterior al método
// El tipo de retornado en la mmisma línea que el nombre de la 
// función, los parámetros en la misma línea si caben. 


// getter numerador
int
rational_t::get_num() const
{
  return num_;
}



// getter denominador
int
rational_t::get_den() const
{
  return den_;
}



// setter numerador
void
rational_t::set_num(const int n)
{
  num_ = n;
}



// setter denominador 
void
rational_t::set_den(const int d)
{
  assert(d != 0);
  den_ = d;
}



// método que resuelve la fracción
double
rational_t::value() const
{
  return double(get_num()) / get_den();
}


// comparaciones
bool
rational_t::is_equal(const rational_t& r, const double precision) const
{
  if (fabs(r.value() - this->value() < precision)) {
    return true;
  }
  else {
    return false;
  }
}



bool
rational_t::is_greater(const rational_t& r, const double precision) const
{
  if (r.value() - this->value() > precision) {
    return true;
  }
  return false;
}



bool
rational_t::is_less(const rational_t& r, const double precision) const
{
  if (this->value() - r.value() > precision) {
    return true;
  }
  else {
    return false;
  }
}


// operaciones
//suma
rational_t
rational_t::add(const rational_t& r)
{
  rational_t sum;
  sum.num_ = ((r.get_num() * this->get_den()) + (r.get_den() * this->get_num()));
  sum.den_ = (r.get_den() * this->get_den());
  return sum;
}



// resta
rational_t
rational_t::substract(const rational_t& r)
{
  rational_t sum;
  sum.num_ = ((r.get_num() * this->get_den()) - (r.get_den() * this->get_num()));
  sum.den_ = (r.get_den() * this->get_den());
  return sum;
}



// multiplicación
rational_t
rational_t::multiply(const rational_t& r)
{
  rational_t multiply;
  multiply.num_ = r.get_num() * this->get_num();
  multiply.den_ = r.get_den() * this->get_den();
  return multiply;
}



// division
rational_t
rational_t::divide(const rational_t& r)
{
  rational_t division;
  division.num_ = this->get_num() * r.get_den();
  division.den_ = this->get_den() * r.get_num();
  return division;
}

// modificación
rational_t
rational_t::pow1()
{
  int num = pow(this->num_, 2);
  int den = pow(this->den_, 2);
  rational_t result{ num, den };
  return result;
}


// E/S
void
rational_t::write(ostream& os) const
{
  os << get_num() << "/" << get_den() << "=" << value() << endl;
}



void
rational_t::read(istream& is)
{
  cout << "Numerador? ";
  is >> num_;
  cout << "Denominador? ";
  is >> den_;
  assert(den_ != 0);
}
