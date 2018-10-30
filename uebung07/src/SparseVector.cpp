/**
 *@author Daniel Kliewer
 *@author Dominik Juelich
 */

#include "SparseVector.hh"
#include <iostream>

/* Node constructor */
node::node(int idx, int val, node *nxt)
{
    index = idx;
    value = val;
    next  = nxt;
}
/* SparseVector constructor */
SparseVector::SparseVector(int size) : m_size(size) , m_start(new node(0, 0, 0))
{ 
    
}
/*Copy constructor */
SparseVector::SparseVector(const SparseVector& spa) : m_size(spa.getSize()) , m_start(new node(0, 0, 0))
{   
    int i;
    /* Sets Elements. Elements with value 0 will be skipped in setElem */
    for (i = 0; i < m_size; i++)
    {
        setElem(i, spa.getElem(i));
    }
}
/* GetSize */
int SparseVector::getSize() const
{
    return m_size;
}
/* Clear: deletes all nodes from the list */
void SparseVector::clear()
{   
    node* todelete = m_start;
    
    while(todelete->next != 0)
    {
        m_start = m_start->next;
        delete todelete;
        todelete = m_start;
    }
    
    /* Make sure start node next is 0 */    
    delete m_start;
    m_start = new node(0, 0, 0);   
}

/* Set Element */
void SparseVector::setElem(const int index,const int value)
{
    /* Skip 0 values */
    if (value == 0) return;

    node* current = m_start;
    node* temp;
    node* temp2;

    /* Set to start if start has no value yet */
    if (m_start->value == 0)
    {
        m_start->index = index;
        m_start->value = value;
        m_start->next  = 0;
        return;
    }
    /* If index is == start index */
    if (m_start->index == index)
    {
        m_start->value = value;
        return;
    }        
    
    /* If index ist smaller than start, start is set to new node */
    if(index < m_start->index)
    {
        temp = new node(index, value, m_start);
        temp->next = m_start;
        m_start = temp;
        return;    
    }      

    /* Go through loop while given index is bigger */
    while (current->index < index && current->next != 0)
    {
        temp = current->next;
        /* Check for equality */
        if(temp->index == index)
        {
            temp->value = value;
            return;
        }
        /* Check if given index is smaller */
        if(temp->index > index)
        {
            temp2 = new node(index, value, temp);
            current->next = temp2;
            return;
        }
        else
        {
            current = current->next;

        }
    }        
    if(current->next == 0)
    {   
        temp2 = new node(index, value, 0); 
        current->next = temp2; 
        return;
    }
    
}

bool SparseVector::operator==(const SparseVector &sp) const
{  
    if(m_size != sp.getSize()) return false;
    
    int i;
    for (i = 0; i <= m_size; i++)
    {
       if(this->getElem(i) != sp.getElem(i)) return false;
    }
    return true;

}

bool SparseVector::operator!=(const SparseVector &sp) const
{   
    return (!( (*this) == sp) );
}

SparseVector& SparseVector::operator=(const SparseVector &sp)
{

    // Check for self-assignment.
    if (this == &sp)
        return *this; // Skip assignment.

    clear();

    int i;
    for (i = 0; i < m_size; i++)
    {
        setElem(i, sp.getElem(i));
    }

    return *this;
}

/* Destructor */
SparseVector::~SparseVector()
{ 
    clear();
    delete m_start;
}


int SparseVector::getElem(const int index) const
{ 
     node* current = m_start;
    /* Go through loop until current index is not smaller anymore */
    while (current->index < index && current->next != 0)
    {
        current = current->next;
    }
    /* Now check if current index equals given index  */
    if(current->index == index) 
    {
        return current->value;
    }
    else return 0;
}

int& SparseVector::operator[] (const int index)
{   
    /*
    return *(this->getElem(index)); 
    */
}





