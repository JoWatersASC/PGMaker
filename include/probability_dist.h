#ifndef PROBDIST_H
#define PROBDIST_H

#include<iostream>
#include<map>
#include<vector>
#include<memory>

namespace pgm{
    class Node;
    typedef std::shared_ptr<Node> node_ptr;
    
    enum class ProbabilityDistributionType{
        MARGINAL,
        CONDITIONAL
    };
}

namespace pgm{

    class ProbabilityDistribution {
        public:
            virtual ~ProbabilityDistribution() = default;

            virtual std::ostream& print(std::ostream &out) = 0;
            friend std::ostream& operator<<(std::ostream& out, ProbabilityDistribution& pDist){
                return pDist.print(out);
            }
        
        protected:
            node_ptr n;
    };

    class MarginalProbabilityDistribution : public ProbabilityDistribution{
        private:
            std::vector<float> MPD;

        public:
            MarginalProbabilityDistribution();
            
            std::vector<float>& getMPD();
            void reset(node_ptr n);

            static ProbabilityDistributionType pdType;
            std::ostream& print(std::ostream &out) override;
    };

    class ConditionalProbabilityDistribution : public ProbabilityDistribution {
        private:
            std::map<std::vector<int>, std::vector<float>> CPD;
            std::vector<node_ptr> dependencies;

        public:
            ConditionalProbabilityDistribution();
            
            std::map<std::vector<int>, std::vector<float>>& getCPD();
            void reset(std::vector<node_ptr> dependencyList, node_ptr n);

            static ProbabilityDistributionType pdType;
            std::ostream& print(std::ostream &out) override;
    };
}

#endif