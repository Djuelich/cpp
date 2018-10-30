#include "GraphicsTileItem.hpp"
#include <iostream>

GraphicsTileItem::GraphicsTileItem(QPixmap* tileset, const QRect& rect, int index) : m_index(index)
{
    setPixmap(tileset->copy(rect));
}

GraphicsTileItem::GraphicsTileItem(QColor* color, int w, int h) : m_index(0)
{
    QPixmap qp(w, h);
    qp.fill(*color); 
    
    setPixmap(qp);
}

void GraphicsTileItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{   
    //Prints the index of the pressed tile to the terminal
    std::cout << m_index << std::endl;
}

GraphicsTileItem::~GraphicsTileItem()
{

}
