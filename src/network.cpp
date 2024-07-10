#include"..\include\network.h"

namespace pgm{
    Network::Network() { name = "Network"; }
    Network::Network(std::string name) : name(name) {}
    Network::Network(std::unordered_set<node_ptr> nodeList) : nodes(nodeList) { name = "Network"; }


    void Network::updateNetwork() {}
    void Network::addNode() {}
    void Network::addNode(node_ptr node) {}
    void Network::updateNode(node_ptr node) {}


    std::string&                 Network::getName() { return name; }
    std::unordered_set<node_ptr> Network::getParents(node_ptr n) noexcept {
        try {
            if(!nodes.count(n)){
                std::string error_message = "Node " + n->getName() + " is not in network " + name;
                throw std::runtime_error(error_message);
            }
        } catch(const std::exception& e){
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }

        std::unordered_set<node_ptr> output;

        for(node_ptr np : nodes){
            if(np->getChildren().count(n)){
                output.insert(np);
            }
        }

        return output;
    }

    std::ostream& Network::print(std::ostream& out) { return out; }
}