#ifndef NETWORK_H
#define NETWORK_H

#include<vector>
#include"node.h"
#include"probability_dist.h"

namespace pgm{
    class Network{
        private:
            std::vector<node_ptr> nodeList;
        
        public:
            Network();

            void update();
            std::vector<Node*> parents(Node* n);
    };
}

#endif