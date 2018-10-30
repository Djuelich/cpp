#ifndef PIXEL_HPP_
#define PIXEL_HPP_

#include <iostream>

using namespace std;

/***
 * Object to represent a pixel
 */
class Pixel
{
private:
    /// X coordinate
    int m_x_coord;
    
    /// Y coordinate
    int m_y_coord;

public:
    /***
     * Default constructor 
     */
	Pixel (int x = 0, int y = 0);
	
	/***
     * Copy constructor 
     */
	Pixel (const Pixel &pSource);
	
	/***
     * Getter 
     */
    int getX() const;
    int getY() const;
    
    /***
     * Setter 
     */
    void setX(const int x);
    void setY(const int y);
    
    /***
     * Destructor 
     */
    ~Pixel();
    
    /***
     * "==" operator
     */
    bool operator==(const Pixel &p) const;
    
    /***
     * "!=" operator
     */
    bool operator!=(const Pixel &p) const;
    
    /***
     * Assignment operator
     */
    Pixel& operator=(const Pixel &p);
    
    /***
     * Addition and assignment operator
     */
    Pixel& operator+=(const Pixel &p);
    
    /***
     * Addition operator
     */
    Pixel operator+(const Pixel &p) const; 
    
    
      
};

/* "<<" operator (out of class) */
ostream& operator<<(ostream& os, const Pixel& pi);

#endif
