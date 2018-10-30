/*
 * Camera.cpp
 *
 *  Created on: Nov 13, 2015
 *      Author: twiemann
 */

#include "Camera.hpp"

namespace jumper
{

Camera::Camera(int x, int y) : m_pi(x, y)
{

}

void Camera::move(const Pixel& offset)
{
    m_pi += offset;
}


int Camera::x()
{
	return m_pi.getX();
}

int Camera::y()
{
	return m_pi.getY();
}

Camera::~Camera()
{
	// Nothing to do yet
}

} /* namespace jumper */
