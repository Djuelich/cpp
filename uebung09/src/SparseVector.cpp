/**
 * A class representing a vector. Non-Zero Entries are saved in a linked list,
 *
 * @author Jan Elseberg
 */

#include "SparseVector.hpp"

#include <cmath>
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;

SparseVector::SparseVector(int s)
{
	m_size = s;
	m_start = new node(-1,0,0);
}


SparseVector::SparseVector(const SparseVector &c)
{
	copy(c);
}

SparseVector::~SparseVector()
{
	clear();
}

void SparseVector::setElem(int i, int val)
{   
    try
    {
	if (i >= getSize())
	{
		return;
	}

	if (val != 0)
	{
		setNonzeroElem(i, val);
		return;
	}
	removeElem(i);
	}
	catch(std::invalid_argument &ia)
	{
	    cout << ia.what() << endl;
	    throw;
	}
}

int SparseVector::getElem(int i) const
{   
    try
    {
	    node *elem = getPrevElem(i);

    	if (elem != 0 && elem->next != 0 && elem->next->index == i)
	    {
		    return elem->next->value;
	    }
	    return 0.0;
	}
	catch(std::out_of_range &our)
	{
	    cout << "Out of range error when getting Elem!" << endl;
	    throw;
	}
}

int SparseVector::getSize() const
{
	return m_size;
}

void SparseVector::clear()
{
	node *elem;

	while (m_start != 0)
	{
		elem = m_start;
		m_start = m_start->next;
		delete elem;
	}
}

void SparseVector::copy(const SparseVector &c)
{
	m_size = c.getSize();
	node *celem = c.m_start;
	m_start = new node(*celem);
	node *elem = m_start;

	while (celem->next != 0)
	{
		celem = celem->next;
		elem->next = new node(*celem);
		elem = elem->next;
	}
}

/**
 * Sets an element to a non-zero value.
 *
 * @param index The index of the entry.
 * @param value The non zero-value to set.
 */
void SparseVector::setNonzeroElem(int index, int value)
{   
    if(value < 0)
    {
        throw std::invalid_argument("No negative element values allowed!");
    }
     
    try
    {   
	    node *elem = getPrevElem(index);

	    // No preceeding element found!
	    if (elem == 0)
	    {
		    return;
	    }

	    // element with index already exists
	    if (elem->next != 0 && elem->next->index == index)
	    {
		    elem->next->value = value;
		    return;
	    }
	    // create new node
	    elem->next = new node(index, value, elem->next);
	}
    catch(std::out_of_range &our)
	{
	    cout << "Out of range error when setting Elem!" << endl;
	    throw;
	}	
}


void SparseVector::removeElem(int index)
{   
    try
    {
        node *elem = getPrevElem(index);
	    if (elem == 0 || elem->next == 0)
	    {
		    return;
	    }
	    node * tmp = elem->next;
	    elem->next = elem->next->next;
	    delete tmp;
	}
	catch(std::out_of_range &our)
	{
	    cout << our.what() << endl;
	}
}


SparseVector::node * SparseVector::getPrevElem(int i) const
{
    if (i >= getSize() || i < 0)
    {
        throw std::out_of_range("Index is out of range!");
   	}
    	
	node *elem ;
	elem = m_start;

	while (elem != 0 && elem->next != 0 && elem->next->index < i)
	{
		elem = elem->next;
	}
	return elem;
}


SparseVector & SparseVector::operator=(const SparseVector &b)
{
	// Check for Self-Assignement
	if (this == &b)
	{
		return *this;
	}

	// destroy old values
	clear();

	copy(b);

	return *this;
}  


bool SparseVector::operator==(const SparseVector &b) const
{
	if (getSize() != b.getSize())
	{
		return false;
	}

	node *elem = m_start;
	node *elemb = b.m_start;

	while (true)
	{
		if ( elem->index != elemb->index || elem->value != elemb->value)
		{
			return false;
		}

		// end of both SparseVectors
		if (elem->next == 0 && elemb->next == 0)
		{
			return true;
		}
		// only reached the end of one SparseVector
		if (elem->next == 0 || elemb->next == 0)
		{
			return false;
		}

		//iterate otherwise
		elem = elem->next;
		elemb = elemb->next;
	}
}

bool SparseVector::operator!=(const SparseVector &b) const
{
	return !(*this == b);
}

