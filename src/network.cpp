#include"..\include\network.h"

namespace pgm{
    Network::Network(){
        name = "Network";
    }
    Network::Network(std::string name) : name(name){}
    Network::Network(std::unordered_set<node_ptr> nodeList) : nodes(nodeList){
        name = "Network";
    }

    std::unordered_set<node_ptr> Network::getParents(node_ptr n) noexcept{
        if(!nodes.count(n)){
            std::string error_message = "Node " + n->getName() + " is not in network " + name;
            throw std::runtime_error(error_message);
        }

        std::unordered_set<node_ptr> output;

        for(node_ptr np : nodes){
            if(np->getChildren().count(n)){
                output.insert(np);
            }
        }

        return output;
    }
}