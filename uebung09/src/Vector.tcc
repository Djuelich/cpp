#ifndef Vector_HPP
#endif

template<typename T>
Vector2<T>::Vector2(T x, T y)
	:	m_x(x), m_y(y)
{
}

template<typename T>
Vector2<T>::Vector2(const Vector2& other)
{
	m_x = other.m_x;
	m_y = other.m_y;
}

template<typename T>
Vector2<T>::~Vector2()
{

}

template<typename T>
Vector2<T> Vector2<T>::operator =(const Vector2& other)
{
	if(this != &other)
	{
		m_x = other.m_x;
		m_y = other.m_y;
	}
}

template<typename T>
Vector2<T> Vector2<T>::operator +(const Vector2& other) const
{
	Vector2 v(*this);
	v += other;
	return v;
}

template<typename T>
Vector2<T> Vector2<T>::operator -(const Vector2& other) const
{
	Vector2 v(*this);
	v -= other;
	return v;
}

template<typename T>
T Vector2<T>::operator *(const Vector2& other) const
{
	Vector2 v(*this);
	v *= other;
	return (v.m_x + v.m_y);
}

template<typename T>
Vector2<T> Vector2<T>::operator *(const T& other) const
{
	Vector2 v(*this);
	v *= other;
	return v;
}

template<typename T>
void Vector2<T>::operator +=(const Vector2& other)
{
	m_x += other.m_x;
	m_y += other.m_y;
}

template<typename T>
void Vector2<T>::operator -=(const Vector2& other)
{
	m_x -= other.m_x;
	m_y -= other.m_y;
}

template<typename T>
void Vector2<T>::operator *=(const Vector2& other)
{
	m_x *= other.m_x;
	m_y *= other.m_y;
}

template<typename T>
void Vector2<T>::operator *=(const T& other)
{
	m_x *= other;
	m_y *= other;
}


template<typename T>
T Vector2<T>::x() const
{
	return m_x;
}

template<typename T>
void Vector2<T>::setX(T x)
{
	m_x = x;
}

template<typename T>
T Vector2<T>::y() const
{
	return m_y;
}

template<typename T>
void Vector2<T>::setY(T y)
{
	m_y = y;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector2<T>& vec)
{   
   os << "(" << vec.m_x << "|" << vec.m_y << ")";
   return os;
}

template<typename T>
T& Vector2<T>::operator[](const int i)
{
    if(i == 0) return &m_x;
    if(i == 1) return &m_y;
    return NULL;
    
}


