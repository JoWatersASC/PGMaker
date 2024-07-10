#include"..\include\node.h"
#include"..\include\probability_dist.h"
namespace pgm{
    Node::Node() {
        name = "Variable";
        values = { "true", "false" };
        std::shared_ptr<MarginalProbabilityDistribution> m = std::make_shared<MarginalProbabilityDistribution>(shared_from_this());
        state = -1;
    }
    Node::Node(std::string nodeName) : name(nodeName) {
        values = { "true", "false" };
        definition = std::make_shared<MarginalProbabilityDistribution>(shared_from_this());
        state = -1;
    }

    std::string                  Node::getName()      { return name; }
    std::unordered_set<node_ptr> Node::getChildren()  { return children; }
    std::vector<std::string>&    Node::getValues()    { return values; }
    pDist_ptr                    Node::getDefinition(){ return definition; }
    
    void Node::setDefinition(pDist_ptr pDist) {
        pDist->setNode(shared_from_this());
        definition = pDist;
    }
}