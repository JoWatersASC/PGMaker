#include"..\include\node.h"

namespace pgm{
    Node::Node(){
        name = "Variable";
        values = { "true", "false" };
        state = -1;
    }
    Node::Node(std::string name) : name(name) {
        values = { "true", "false" };
        state = -1;
    }

    std::string                  Node::getName()      { return name; }
    std::unordered_set<node_ptr> Node::getChildren()  { return children; }
    std::vector<std::string>&    Node::getValues()    { return values; }
    pDist_ptr                    Node::getDefinition(){ return definition; }
}