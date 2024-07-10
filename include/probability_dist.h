#ifndef PROBDIST_H
#define PROBDIST_H

#include<map>
#include"forward_dec.h"
namespace pgm{

    class ProbabilityDistribution : public std::enable_shared_from_this<ProbabilityDistribution> {
        public:
            ProbabilityDistribution();
            ProbabilityDistribution(node_ptr n);
            virtual ~ProbabilityDistribution() = default;
            virtual std::ostream& print(std::ostream &out) = 0;
            virtual void reset() = 0;
            
            void     setNode(node_ptr n);
            node_ptr getNode();

            friend std::ostream& operator<<(std::ostream& out, ProbabilityDistribution& pDist){
                return pDist.print(out);
            }
        
        protected:
            node_ptr node;
    };

    class MarginalProbabilityDistribution : public ProbabilityDistribution{
        private:
            std::vector<float> MPD;

        public:
            MarginalProbabilityDistribution();
            MarginalProbabilityDistribution(node_ptr n);

            std::vector<float>& getMPD();
            
            //void reset();
            void reset() override;
            
            std::ostream& print(std::ostream &out) override;

            const static ProbabilityDistributionType pdType = ProbabilityDistributionType::MARGINAL;
    };




    class ConditionalProbabilityDistribution : public ProbabilityDistribution {
        private:
            std::map<std::vector<int>, std::vector<float>> CPD;
            std::vector<node_ptr> dependencies;

        public:
            ConditionalProbabilityDistribution();
            
            std::map<std::vector<int>, std::vector<float>>& getCPD();
            void reset(std::vector<node_ptr> dependencyList, node_ptr n);
            void reset() override;

            std::ostream& print(std::ostream &out) override;

            const static ProbabilityDistributionType pdType = ProbabilityDistributionType::CONDITIONAL;
    };
}

#endif