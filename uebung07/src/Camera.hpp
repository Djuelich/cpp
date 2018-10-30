/*
 * Camera.hpp
 *
 *  Created on: Nov 13, 2015
 *      Author: twiemann
 */

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include "Pixel.hpp"

namespace jumper
{

/***
 * A camera object to scroll within a level
 */
class Camera
{
public:

	/***
	 * Constructs a camera with the given pixel offsets
	 */
	Camera(int x = 0, int y = 0);
    
    /***
	 * Move the camera by adding given offset pixel
	 */
    void move(const Pixel& offset);
    

	/// Returns the current x-position
	int x();

	/// Returns the current y-position
	int y();

	/// Destructor
	virtual ~Camera();

private:

	Pixel m_pi;
};

} /* namespace jumper */

#endif /* CAMERA_HPP_ */
