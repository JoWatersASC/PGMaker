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
            void updateNode(node_ptr n);

            std::unordered_set<node_ptr> getParents(node_ptr n) noexcept;
    };
}

#endif