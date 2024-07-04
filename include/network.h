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
            std::vector<node_ptr> parents(node_ptr n);
    };
}

#endif