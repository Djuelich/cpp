/*
 * GraphConverter.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: twiemann
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	if(argc == 5)
	{
		string infile(argv[1]);
		string outfile(argv[2]);
		int tileWidth = atoi(argv[3]);
		int tileHeight = atoi(argv[4]);
		int num_nodes, x, y;

		ifstream in(infile.c_str());
		ofstream out(outfile.c_str());

		// Parse file if existing
		if(in.good() && out.good())
		{
			cout << "Parsing graph file " << infile << endl;
			cout << "Writing converted coordinates to " << outfile << endl;

			in >> num_nodes;
			out << num_nodes << endl;

			// Read node definitions
			for(int i = 0; i < num_nodes; i++ )
			{
				in >> x >> y;
				out << x * tileWidth + tileWidth << " " << y * tileHeight << endl;
			}

			// Read edge definitions
			while(in.good())
			{
				in >> x >> y;

				// Check if stream is still valid after last
				// read attempt
				if(in.good())
				{
					out << x  << " ";
					out << y  << endl;
				}
			}
		}
	}
	return 0;
}
