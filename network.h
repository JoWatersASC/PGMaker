#ifndef NETWORK_H
#define NETWORK_H

#include<map>
#include<vector>

typedef shared_ptr<pgm::definition> defintion_ptr;

namespace pgm{
    class Network{
        private:
            std::map<Node, definition_ptr> nodeList;
        
        public:
            Network();

            void update();
            std::vector<Node*> parents(Node* n);
            std::map<std::string, float> getPDist(Node* n);
    };
}

#endif