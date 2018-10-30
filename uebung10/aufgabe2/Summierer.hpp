#ifndef SUMMIERER_HPP
#define SUMMIERER_HPP

class Summierer
{
    public:
        Summierer ();
        int operator() (int y);
        int getSumme();
    private:
        int m_summe;
};


#endif 
