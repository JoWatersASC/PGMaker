#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<unordered_set>
#include<vector>

#include"forward_dec.h"

namespace pgm{
    class Node{          
        private:
            std::string                  name;
            std::unordered_set<node_ptr> children;
            std::vector<std::string>     values;
            pDist_ptr                    definition;

            friend bool operator<(const Node& a, const Node& b);
            friend bool operator==(const Node& a, const Node& b);

        public:
            Node();
            Node(std::string name);

            std::string                  getName();
            std::unordered_set<node_ptr> getChildren();
            std::vector<std::string>&    getValues();
            pDist_ptr                    getDefinition();

            int state;
    };
}

#endif