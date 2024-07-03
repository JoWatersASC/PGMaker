#ifndef PROBDIST_H
#define PROBDIST_H

#include<set>
#include<map>
#include<vector>
#include<memory>

namespace pgm{
    class Node;
    typedef std::unique_ptr<Node> node_ptr;
    typedef std::set<std::pair<node_ptr, int>> condition;
}

namespace pgm{
    class ProbabilityDistribution {
        public:
            ProbabilityDistribution();
            virtual ~ProbabilityDistribution() = default;     
    };

    class ConditionalProbabilityDistribution : public ProbabilityDistribution {
        private:
            std::map<condition, std::vector<float>> func;
            void set(int index, condition c);

        public:

            void set(std::map<condition, std::vector<float>> conditionFunction);
            void reset(std::vector<Node*> dependencies, Node* n);

            void print();
    };
}

#endif