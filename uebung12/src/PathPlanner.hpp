#ifndef PATH_H_
#define PATH_H_

#include <string>
#include <list>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/astar_search.hpp>

#include "Network.hpp"
#include "Vector.hpp"

using namespace boost;

namespace jumper
{


typedef adjacency_list<vecS, vecS, undirectedS,
        no_property,
        property<edge_weight_t, float > > Graph;
        
typedef typename graph_traits<Graph>::vertex_descriptor Vertex;


template <class Graph, class CostType, class NodeVec>
class distance_heuristic : public astar_heuristic<Graph, CostType>
{
  public:
    
  
    distance_heuristic(NodeVec l, Vertex goal)
        : m_nodes(l), m_goal(goal) {}
    
    CostType operator()(Vertex u)
    {
        CostType distance = m_nodes[u].distanceTo(m_nodes[m_goal]);
        return distance;
    }
  
  private:
    NodeVec m_nodes;
    Vertex m_goal;
};

struct found_goal {};

template <class Vertex>
class astar_goal_visitor : public boost::default_astar_visitor
{
  public:
    astar_goal_visitor(Vertex goal) : m_goal(goal) {}
    template <class Graph>
    void examine_vertex(Vertex u, Graph& g) {
        if(u == m_goal)
        throw found_goal();
    }
  private:
    Vertex m_goal;
};

/***
 * A class to plan shortest paths in a graph using the A* algorithm
 */
class PathPlanner
{
  public:

	/// Creates a path planner instance for the given graph
    PathPlanner(Network* net);

    /// Plans a path from \ref startIndex to \ref endIndex.
    /// The generated path can by extracted with \ref getSolution().
    void planPath(int startIndex, int endIndex);

    /// Returns the computed solution path
    const std::list<Vector2f>& getSolution();

  private:

    /// TODO: Add graph structure etc.
    std::list<Vector2f> m_solutionPath;
    
    Graph m_graph;
    
    vector<Vector2f> m_node_vec;
};
    
}

#endif
