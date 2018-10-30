/*
 * TVector.hpp
 *
 *  Created on: Dec 4, 2015
 *      Author: twiemann
 */

#ifndef SRC_VECTOR_HPP_
#define SRC_VECTOR_HPP_

#include <ostream>



namespace jumper
{
template<typename T>
class Vector2;

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector2<T>& vec);


template<typename T>
class Vector2
{
    private:
    T m_x;
    T m_y;
    
    public:
    /* Constructor */
    Vector2(T x = 0, T y = 0);
    
    /* Copy constructor */
    Vector2(const Vector2& other);
    
    /* Assignment operator */
    Vector2 operator=(const Vector2& other);
    
    /* Destructor */
    ~Vector2();
    
    /* Addition operators */
    Vector2 operator+(const Vector2& other) const;
    void operator+=(const Vector2& other);
    
    /* Subtraction operators */
    Vector2 operator-(const Vector2& other) const;
    void operator-=(const Vector2& other);
	
	/* Multiplying operators for 2 vectors */
    T operator*(const Vector2& other) const;
    void operator*=(const Vector2& other);

    /* Multiplying operators for vector and T */
    Vector2 operator*(const T& other) const;
    void operator*=(const T& other);
    
    /* Getter */
	T x() const;
	T y() const;
	
	/* Setter */
    void setX(T x);
    void setY(T y);
    
    /* Index operator */
    T& operator[](const int i);
    
    friend std::ostream& operator<< <>(std::ostream& os, const Vector2& vec);
    
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector2<T>& vec);

#include "Vector.tcc"

typedef Vector2 <int> Vector2i;
typedef Vector2 <float> Vector2f;


} /* namespace jumper */



#endif /* SRC_VECTOR_HPP_ */
