#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<set>
#include<vector>
#include<memory>

namespace pgm{
    class ProbabilityDistribution;
    typedef std::shared_ptr<ProbabilityDistribution> pDist_ptr;
}

namespace pgm{
    class Node{          
        private:
            std::string name;
            std::set<Node*> children;
            std::vector<std::string> values;
            pDist_ptr pDist;
            friend bool operator<(const Node& a, const Node& b);
            friend bool operator==(const Node& a, const Node& b);

        public:
            Node();
            Node(std::string name);

            std::string getName();
            std::vector<std::string>& getValues();

            // void print();

            int state;
    };
}

#endif