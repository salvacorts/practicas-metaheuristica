#include "genetic.hpp"

#ifndef AGG_H
#define AGG_H

class AGG : public GeneticAlg {
protected:
   Solution* bestFromLastGeneration;

   Population Replace(const Population& originalP, Population& toReplaceP) override;
   Population Select(const Population& originalP) override;
   Solution Evaluate(Population& population) override;

public:
   AGG(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, double pCross, double pMutate, int maxEvals)
   : GeneticAlg(distances, frequencies, populationSize, pCross, pMutate, maxEvals){
      this->bestFromLastGeneration = NULL;
   }
};

class AGG_OX : public AGG {
protected:
   Population Cross(const Population& originalP) override { return CrossOX(originalP, this->crossProb);}

public:
   AGG_OX(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, double pCross, double pMutate, int maxEvals)
   : AGG(distances, frequencies, populationSize, pCross, pMutate, maxEvals){}
};

class AGG_PMX : public AGG {
protected:
   Population Cross(const Population& originalP) override { return CrossPMX(originalP, this->crossProb);}

public:
   AGG_PMX(vector<vector<int> >& distances, vector<vector<int> >& frequencies, int populationSize, double pCross, double pMutate, int maxEvals)
   : AGG(distances, frequencies, populationSize, pCross, pMutate, maxEvals){}
};

#endif