#ifndef GA_STRUCT
#define GA_STRUCT

#include <iostream>
#include <string.h>

#define PROTEIN_MAX_SIZE = 1000

struct aminoacid {
    int x; // = 0;
    int y; // = 0;
    int z; // = 0;
    int leter01;
    char RULD; // = 'R';
    char SRL; // = 'S';
};

struct coord {
    int x; // = 0;
    int y; // = 0;
    int z; // = 0; 
};

// struct chromosome {
//     int energy = 0;
//     double fitness = 0;
//     int colisions = 0;

//     char* SRL_letters; //char: SRL
//     int* SRL_letters_int; //int: -1, 0, 1
//     //std::string SRL_letters_s;// e posibil ca astea doua siruri sa nu fie necesare
//     //std::string RULD_letters;
//     // char* SRL_letters = malloc(10000);
//     int* x_string; //pt ficare coordonata
//     int* y_string;
//     int* z_string;
//     //sau (de vazut care e mai rapid)
//     //coord coord_stirng[6];
//     int* leter01; // HP convertit in 01
// }Chromosomes;

typedef struct chromosome {
    int energy;// = 0;
    double fitness;// = 0;
    int colisions;// = 0;

    char SRL_letters[1000]; //char: SRL,F,B
    int SRL_letters_int[1000]; //int: 0, 1, 3, 4, 5
    char RULD_letters[1000]; //char: RULD,F,B
    int RULD_letters_int[1000]; //int: 0, 1, 2, 3, 4, 5
    //std::string SRL_letters_s;// e posibil ca astea doua siruri sa nu fie necesare
    //std::string RULD_letters;
    // char* SRL_letters = malloc(10000);
    int x_string[1000]; //pt ficare coordonata
    int y_string[1000];
    int z_string[1000];
    //sau (de vazut care e mai rapid)
    //coord coord_stirng[6];
    //int leter01[1000]; // HP convertit in 01
    bool changed;
}Chromosomes;

struct genetic_algorithm {
    std::string latticeType; //cred ca nu-l mai folosesc
    int nr_litere; // 4 - pt 2D; 6 - pt 3D - absolute
    int generations;// = 20;
    int population_size;// = 1;
    int chromosome_size;// = 20; //protein size
    std::string sequence01; // secventa in lucru
    double selection_elite_percent; //= 0.10;  // elitePercent
    double crossover_percent; //= 0.15;   // crossoverPercent
    double mutation_percent; //= 0.15;   // mutationPercent
};

struct index_fitness {
    int index;
    int fitness;
};

#endif