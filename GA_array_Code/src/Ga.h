#ifndef ALG_GA
#define ALG_GA

#include <string>
//#include <iostream>
#include "structures.h"

// std::string generate_init_population(int population_size, int chromosome_size);
//char* generate_init_population(int population_size, int chromosome_size);
void generate_init_population(struct chromosome init_population[], genetic_algorithm GA_param);
//void generate_init_SRL(struct chromosome init_population[], int population_size, int chromosome_size);
// void transform_SRL_RULD(struct chromosome init_population[], int population_size, int chromosome_size);

void generate_init_RULD(struct chromosome init_population[],genetic_algorithm GA_param);
void transform_int_to_RULD(struct chromosome init_population[],genetic_algorithm GA_param);
void transform_RULD_to_xyz(struct chromosome init_population[],genetic_algorithm GA_param);
void compute_fitness(struct chromosome init_population[],genetic_algorithm GA_param);

// void selection(chromosome population[], genetic_algorithm GA_param, int best);
// bool compare( index_fitness a, index_fitness b);
int compare( index_fitness a, index_fitness b);
void elitism_selection(chromosome population[], genetic_algorithm GA_param, int best);
Chromosomes tournament_selection(chromosome population[], genetic_algorithm GA_param, int best);
void tournament_selection_Jo(chromosome population[], genetic_algorithm GA_param, int best);

void crossover(chromosome population[], genetic_algorithm GA_param, int best);
void mutation(chromosome population[], genetic_algorithm GA_param, int best);
void re_compute(chromosome population[], genetic_algorithm GA_param);

int find_best(chromosome population[], genetic_algorithm GA_param);

#endif