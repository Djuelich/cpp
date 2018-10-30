#ifndef SPARSEVECTOR_HH_
#define SPARSEVECTOR_HH_

/// A linked-list node for our sparse vector elements.
struct node
{
    int index;  /// Element number, in the range [0, size)
    int value;  /// The value of this element.
    node *next; /// A pointer to the next node in the linked-list.
    
    /// Node constructor - simply initializes the data-members.
    node(int idx, int val, node *nxt);
};

class SparseVector
{
private:
    
    node* m_start;
    
    int m_size;
    
    void clear();
        
public:
    /* Constructor */
    SparseVector(int size);
    
    /* Copy constructor */
    SparseVector(const SparseVector& spa);
    
    /* Return size */
    int getSize() const;
    
    void setElem(const int index,const int value);
    
    int getElem(const int index) const; 
    
    int& operator[] (const int index);
    
    ~SparseVector();
    
    bool operator==(const SparseVector &sp) const;
    bool operator!=(const SparseVector &sp) const;
    SparseVector& operator=(const SparseVector &sp);
    
};

#endif
