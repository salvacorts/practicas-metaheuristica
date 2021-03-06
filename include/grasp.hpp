#include "solver.hpp"
#include "localSearch.hpp"
#include <vector>

#ifndef GRASP__H
#define GRASP__H

class RandomizedGreedy : public Solver {
protected:
   vector<pair<int, int> > clFrequencies;
   vector<pair<int, int> > clDistances;
   double alpha; 
   
public:
   RandomizedGreedy(vector<vector<int> >& distances, vector<vector<int> >& frequencies, double alpha)
   : Solver(distances, frequencies) {
      this->clFrequencies.resize(frequencies.size());   
      this->clDistances.resize(distances.size());
      this->alpha = alpha;

      // Calc potentials
      for (int i = 0; i < frequencies.size(); ++i) {
         int fi = 0, di = 0;

         for (int j = 0; j < frequencies.size(); ++j) {
            fi += this->frequencies[i][j];
            di += this->distances[i][j];
         }

         this->clFrequencies[i] = make_pair(i, fi);
         this->clDistances[i] = make_pair(i, di);
      } 
   }

   Solution Solve() override;
};

class GRASP : public Solver {
protected:
   RandomizedGreedy* randomGreedy;
   LocalSearchSolver* localSearch;
   int maxIterations;

public:
   GRASP(vector<vector<int> >& distances, vector<vector<int> >& frequencies, double alpha, int maxIterations, int maxLocalSearchEvals)
   : Solver(distances, frequencies) {
      this->randomGreedy = new RandomizedGreedy(distances, frequencies, alpha);
      this->localSearch = new LocalSearchSolverDLB(distances, frequencies, maxLocalSearchEvals);
      this->maxIterations = maxIterations;
   }

   Solution Solve() override;
};

#endif