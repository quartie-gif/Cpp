#pragma once
#include "Visitor.h"


// wizytowalny konetener na liczbe typu int
class IntData : public Data {
public:
  IntData( int d ) : m_d( d ){}
  // zmienia zawartosc kontenera
  void operator<<( int d ) { m_d = d; }
  // zawartosc kontenera
  int get() const { return m_d; }
  
  void acceptVisitor( Visitor& v) { v.visit( this ); };
private:
  int m_d;
};

// see IntData
class FloatData : public Data {
public:
  FloatData( float d ) : m_d( d ){}
  void operator<<( float d ) { m_d = d; }
  float getFloat() const { return m_d; }
  void acceptVisitor( Visitor& v) { v.visit( this ); };
private:
  float m_d; 
};
