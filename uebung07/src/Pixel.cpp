#include "Pixel.hpp"

/* Default constructor */
Pixel::Pixel(int x, int y) : m_x_coord(x), m_y_coord(y)
{ }

/* Copy constructor */
Pixel::Pixel (const Pixel &pSource) : m_x_coord(pSource.getX()), m_y_coord(pSource.getY())
{ }

/* Destructor */
Pixel::~Pixel()
{ }

/* Get X */
int Pixel::getX() const
{
    return m_x_coord;
}

/* Get Y */
int Pixel::getY() const
{
    return m_y_coord;
}
/* Set X */
void Pixel::setX(const int x)
{
    m_x_coord = x;
}

/* Set Y */
void Pixel::setY(const int y)
{
    m_y_coord = y;
}

/* "==" operator */
bool Pixel::operator==(const Pixel &p) const
{
    return (( m_x_coord == p.getX() ) && ( m_y_coord == p.getY() ));
}

/* "!=" operator */
bool Pixel::operator!=(const Pixel &p) const
{
    return (!( (*this) == p) );
}

/* Assignment operator */
Pixel& Pixel::operator=(const Pixel &p)
{
    // Check for self-assignment.
    if (this == &p)
        return *this; // Skip assignment.

    m_x_coord = p.getX();
    m_y_coord = p.getY();
    
    return *this;
}

/* Addition and assignment operator */
Pixel& Pixel::operator+=(const Pixel &p)
{
    m_x_coord = m_x_coord + p.getX();
    m_y_coord = m_y_coord + p.getY();
    
    return *this;
}

/* Addition operator */
Pixel Pixel::operator+(const Pixel &p) const
{   
    Pixel temp(*this); // Copy constructor being used    
    temp += p;
    return temp;
}



/***************************************************************/
/* Out of class                                                 /
/***************************************************************/

/* "<<" Operator */
ostream& operator<<(ostream& os, const Pixel& pi)
{   
    /* Prints coordinates in (X|Y) format */
    os << "(" << pi.getX() << "|" <<pi.getY() << ")";
}









