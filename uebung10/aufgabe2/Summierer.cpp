#include "Summierer.hpp"

Summierer::Summierer () : m_summe(0) 
{

}

int Summierer::operator() (int y)
{ 
    m_summe += y;
}

int Summierer::getSumme()
{
    return m_summe;
}
