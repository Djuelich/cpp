#include "LevelScene.hpp"
#include "GraphicsTileItem.hpp"

#include <fstream>
#include <iostream>

LevelScene::LevelScene(QString filename, MainWindow* window) 
{
    m_mainWindow = window;
    
    
    // Set all default values
	m_tileWidth 	= 0;
	m_tileHeight	= 0;
	m_tileOffset 	= 0;
	m_numRows = 0;
	m_keyR = 0;
	m_keyG = 0;
	m_keyB = 0;
	m_tilesPerRow = 0;
	m_levelWidth = 0;
	m_levelHeight = 0;
    
    
    string fname = filename.toStdString();
	// Read meta data from level file
	std::ifstream in(fname.c_str());

	int ir, ig, ib;

	if(in.good())
	{
		in >> m_texFileName;
		in >> m_tileWidth >> m_tileHeight >> m_tilesPerRow >> m_numRows;
		in >> m_tileOffset >> ir >> ig >> ib;
		in >> m_levelWidth >> m_levelHeight;
	}
	else
	{
		std::cout << "Unable to open file " << filename.toStdString() << std::endl;
	}
	
	// Cast keying colors manually!
	m_keyR = (unsigned char)ir;
	m_keyG = (unsigned char)ig;
	m_keyB = (unsigned char)ib;
    
    //Using Path of the .lvl file to find the texfile
    std::size_t pos = fname.find_last_of("/");
    m_pixmap = new QPixmap(QString::fromStdString(fname.substr(0, pos) + "/" + m_texFileName));
    
	//Set transparency mask
	QColor color(m_keyR, m_keyG, m_keyB);
	m_pixmap->setMask(m_pixmap->createMaskFromColor(color));
	
	
	GraphicsTileItem* gi;
	
	// Alloc tile set memory
	m_tiles = new int*[m_levelHeight];
	for(int i = 0; i < m_levelHeight; i++)
	{
		m_tiles[i] = new int[m_levelWidth];
	}
 
	// Read tile indices
	for(int i = 0; i < m_levelHeight; i++)
	{
		for(int j = 0; j < m_levelWidth; j++)
		{
			int tileID;
			in >> tileID;
			m_tiles[i][j] = tileID;

			/* addItem */
			//Compute position of source tiles 
			int ID = tileID - 1;
		  	int row = ID / m_tilesPerRow;
		    int col = ID % m_tilesPerRow;

			int x = col * m_tileWidth;

			if(col > 0)
			{
			    x += col * m_tileOffset;
			}


			int y = row * m_tileHeight;
			if(row > 0)
			{
				y += row * m_tileOffset;
			}

			//Make new GraphicsTileItem and add it
			if(x >= 0 && y >= 0)
			{
			    gi = new GraphicsTileItem(m_pixmap, 
			                              QRect(x, y , m_tileWidth, m_tileHeight), 
			                              ID);
			    //Set target Position
			    gi->setPos(j * m_tileWidth, i * m_tileHeight);
 	            addItem(gi);
 	        }
		}
	}

	in.close();
	
	
	/* MainWindow level information display */
	
	m_mainWindow->label_6->setText(QString::fromStdString(m_texFileName));
	m_mainWindow->lcdNumber->display(m_levelWidth);
	m_mainWindow->lcdNumber_2->display(m_levelHeight);
	m_mainWindow->lcdNumber_3->display(m_tileWidth);
	m_mainWindow->lcdNumber_4->display(m_tileHeight);
}

void LevelScene::mousePressEvent(QGraphicsSceneMouseEvent * event)
{

}

