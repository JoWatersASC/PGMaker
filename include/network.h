#ifndef NETWORK_H
#define NETWORK_H

#include"node.h"
#include"probability_dist.h"

namespace pgm{
    class Network{
        private:
            std::string                  name;
            std::unordered_set<node_ptr> nodes;
        
        public:
            Network();
            Network(std::string name);
            Network(std::unordered_set<node_ptr> nodeList);

            void updateNetwork();
            void addNode();
            void addNode(node_ptr);
            void updateNode(node_ptr n);

            std::string&                 getName();
            std::unordered_set<node_ptr> getParents(node_ptr n) noexcept;

            std::ostream& print(std::ostream& out);
    };
}

#endif