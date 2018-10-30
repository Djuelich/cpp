#include <iostream>
#include <map>
#include <math.h>
#include <string>

#include "PathPlanner.hpp"

namespace jumper
{



void PathPlanner::planPath(int s, int e)
{
    // TODO: Plan a path from s to e and add
    // path vertices to the list returned by
    // getSolution().
    
    //distance_heuristic<Graph, int, vector<Vector2f> > dh(m_node_vec, e);
    
    
    vector<Graph::vertex_descriptor> p(num_vertices(m_graph));
    vector<int> d(num_vertices(m_graph));
    try {
        // call astar named parameter interface
        astar_search
        (m_graph, s,
        distance_heuristic<Graph, int, vector<Vector2f> >
        (m_node_vec, e),
        predecessor_map(&p[0]).distance_map(&d[0]).
        visitor(astar_goal_visitor<Vertex>(e)));
  
    }   catch(found_goal fg) 
        {   // found a path to the goal
            
            for(Vertex v = e;; v = p[v]) 
            {
                m_solutionPath.push_front(m_node_vec[v]);
                if(p[v] == v)
                break;
            }
    
        }
    
}


PathPlanner::PathPlanner (Network* net)
{
	// Get vertices and edges from network and build
    // a search graph for the A* search.
    
    bool bol;
    
    property_map<Graph, edge_weight_t>::type weightmap = get(edge_weight, m_graph); 
    graph_traits<Graph>::edge_descriptor ed;
    m_node_vec = net->getNodes(); 
    vector<pair<unsigned int, unsigned int> > edge_vec = net->getEdges(); 
    
    
    for(std::vector<pair<unsigned int, unsigned int> >::iterator it = edge_vec.begin(); it != edge_vec.end(); ++it) 
    {   
        int a = get<0>(*it);
        int b = get<1>(*it);
        tie(ed, bol)   = add_edge( a, b, m_graph);
        weightmap[ed] = m_node_vec[a].distanceTo(m_node_vec[b]);
    }
    
}

const std::list<Vector2f>& PathPlanner::getSolution()
{
    return m_solutionPath;
}


}
