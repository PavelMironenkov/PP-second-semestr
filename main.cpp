#include <iostream>
#include <vector>
#include <cstdlib>
#include <random>
#include <ctime>
//#include <stdio.h>
/*
struct gene {
    int alleles[4];
    int fitness;
    float likelihood;

    // Test for equality.
    operator==(gene gn) {
        for (int i = 0; i < 4; i++) {
            if (gn.alleles[i] != alleles[i]) return false;
        }

        return true;
    }
};

class CDiophantine {
public:
    CDiophantine(int, int, int, int, int);// Constructor with coefficients for a,b,c,d.
    int Solve();// Solve the equation.

    // Returns a given gene.
    gene GetGene(int i) { return population[i]; }

protected:
    int ca, cb, cc, cd;// The coefficients.
    int result;
    gene population[MAXPOP];// Population.

    int Fitness(gene &);// Fitness function.
    void GenerateLikelihoods();    // Generate likelihoods.
    float MultInv();// Creates the multiplicative inverse.
    int CreateFitnesses();

    void CreateNewPopulation();

    int GetIndex(float val);

    gene Breed(int p1, int p2);

};

CDiophantine::CDiophantine(int a, int b, int c, int d, int res) : ca(a), cb(b), cc(c), cd(d), result(res) {}

int CDiophantine::Solve() {
    int fitness = -1;

    // Generate initial population.
    srand((unsigned) time(NULL));

    for (int i = 0; i < MAXPOP; i++) {// Fill the population with numbers between
        for (int j = 0; j < 4; j++) {// 0 and the result.
            population[i].alleles[j] = rand() % (result + 1);
        }
    }

    if (fitness = CreateFitnesses()) {
        return fitness;
    }

    int iterations = 0;// Keep record of the iterations.
    while (fitness != 0 || iterations < 50) {// Repeat until solution found, or over 50 iterations.
        GenerateLikelihoods();// Create the likelihoods.
        CreateNewPopulation();
        if (fitness = CreateFitnesses()) {
            return fitness;
        }

        iterations++;
    }

    return -1;
}

int CDiophantine::Fitness(gene &gn) {
    int total = ca * gn.alleles[0] + cb * gn.alleles[1] + cc * gn.alleles[2] + cd * gn.alleles[3];

    return gn.fitness = abs(total - result);
}

int CDiophantine::CreateFitnesses() {
    float avgfit = 0;
    int fitness = 0;
    for (int i = 0; i < MAXPOP; i++) {
        fitness = Fitness(population[i]);
        avgfit += fitness;
        if (fitness == 0) {
            return i;
        }
    }

    return 0;
}

float CDiophantine::MultInv() {
    float sum = 0;

    for (int i = 0; i < MAXPOP; i++) {
        sum += 1 / ((float) population[i].fitness);
    }

    return sum;
}

void CDiophantine::GenerateLikelihoods() {
    float multinv = MultInv();

    float last = 0;
    for (int i = 0; i < MAXPOP; i++) {
        population[i].likelihood = last = last + ((1 / ((float) population[i].fitness) / multinv) * 100);
    }
}

int CDiophantine::GetIndex(float val) {
    float last = 0;
    for (int i = 0; i < MAXPOP; i++) {
        if (last <= val && val <= population[i].likelihood) return i;
        else last = population[i].likelihood;
    }

    return 4;
}

gene CDiophantine::Breed(int p1, int p2) {
    int crossover = rand() % 3 + 1;// Create the crossover point (not first).
    int first = rand() % 100;// Which parent comes first?

    gene child = population[p1];// Child is all first parent initially.

    int initial = 0, final = 3;// The crossover boundaries.
    if (first < 50) initial = crossover;    // If first parent first. start from crossover.
    else final = crossover + 1;// Else end at crossover.

    for (int i = initial; i < final; i++) {// Crossover!
        child.alleles[i] = population[p2].alleles[i];
        if (rand() % 101 < 5) child.alleles[i] = rand() % (result + 1);
    }

    return child;// Return the kid...
}

void CDiophantine::CreateNewPopulation() {
    gene temppop[MAXPOP];

    for (int i = 0; i < MAXPOP; i++) {
        int parent1 = 0, parent2 = 0, iterations = 0;
        while (parent1 == parent2 || population[parent1] == population[parent2]) {
            parent1 = GetIndex((float) (rand() % 101));
            parent2 = GetIndex((float) (rand() % 101));
            if (++iterations > 25) break;
        }

        temppop[i] = Breed(parent1, parent2);// Create a child.
    }

    for (int i = 0; i < MAXPOP; i++) population[i] = temppop[i];
}
*/

using namespace std;
class Task {
public:
    int complexity;
    int Priority;
    int waiting;

    void gspd() {//5 приоритетов
        random_device a;
        mt19937 gen(a());
        uniform_int_distribution<int> uid(0, 50);
       // cout << uid(gen) << "\n";
        complexity = 0;
        if (uid(a) <= 10) {
            Priority = 1;
        } else if (10 < uid(a) && uid(a) <= 17) {
            Priority = 2;
        } else if (17 < uid(a) && uid(a) <= 23) {
            Priority = 3;
        } else if (23 < uid(a) && uid(a) <= 27) {
            Priority = 4;
        } else if (27 < uid(a) && uid(a) <= 30) {
            Priority = 5;
        }

        complexity += (rand() % 10000) + 600;
        /// int n = n+1;
        // return n;
    }
};
class Individ {
public:
    int priority;
    int instructions[1000];
    int place;
    int ptr;
    int goals;
    double goalssum;

    static void array_with_random_actions(Individ *ind) {
        for (int i = 0; i <= 999; ++i) {
            ind->instructions[i] = 1 + rand() % 124;
        }
        //return array;
    }


    static void jump(Individ *ind) {
        if (ind->instructions[ind->ptr] == 1) {
            ind->priority = 1;
        } else if (ind->instructions[ind->ptr] == 2) {
            ind->priority = 2;
        } else if (ind->instructions[ind->ptr] == 3) {
            ind->priority = 3;
        } else if (ind->instructions[ind->ptr] == 4) {
            ind->priority = 4;
        } else if (ind->instructions[ind->ptr] == 5) {
            ind->priority = 5;
        }
        ind->place = 0;
    }

    static void make(Individ *ind, vector<Task> *vect, int *sum) {
        if (vect->empty()) {
            *sum += 3;
            return;
        }
        (*vect)[ind->place].complexity = (*vect)[ind->place].complexity - 20;
        *sum += 20;
        if ((*vect)[ind->place].complexity <= 0) {
            vect->erase(vect->begin() + ind->place - 1);
            ind->place = 0;
            ind->goals+=1;
            *sum += 3;
        }
    }

    static void go_forward(Individ *ind, vector<Task> *vect, int *sum) {
        if (vect->empty()) {
            *sum += 3;
            return;
        }
        if (vect->size() <= ind->place) { return; }
        ind->place += 1;
        *sum += 3;
    }

    static void go_back(Individ *ind, vector<Task> *vect, int *sum) {
        if (vect->empty()) {
            *sum += 3;
            return;
        }
        if (ind->place == 0) { return; }
        ind->place -= 1;
        *sum += 3;
    }

    static void read_inst(Individ *ind, vector<Task> *vect, int *sum) { ///1-5. переход на один из приоритетов(5 чисел); 6. выполнение задачи(100);
        /// 7-8. переход между задачами внутри приоритета(20);
        if (0 < ind->instructions[ind->ptr] && ind->instructions[ind->ptr] <= 5) {
            jump(ind);
            return;
        }
        if ( (5 < ind->instructions[ind->ptr] && ind->instructions[ind->ptr] <= 105) || ind->instructions[ind->ptr] == 0 ) {
            make(ind, vect, sum);
            return;
        }
        if (105 < ind->instructions[ind->ptr] && ind->instructions[ind->ptr] <= 115) {
            go_forward(ind, vect, sum);
            return;
        }
        if (115 < ind->instructions[ind->ptr] && ind->instructions[ind->ptr] <= 125) {
            go_back(ind, vect, sum);
            return;
        }
    }

    void mutation(Individ* ind){
        for(ind->ptr = 0; ind->ptr < 1000; ind->ptr++) {
            if(rand()%1000 < 200) {
                ind->instructions[ptr] = rand()%124 + 1;
            }
        }

    }

/*vector<Task> sum_takts(vector<Task> number,int *flag, int *sum,int number_of_vector ) {
    Task t;
    if (!number.empty()) {
        if (*flag != number_of_vector) {
            cout << "5 size = " << number.size() << endl;
            *sum += 3;
            *flag = number_of_vector;
        }
        t = number.back();
//five.pop();
        if (t.complexity != 0) {
            t.complexity = t.complexity - 1;
            *sum++;
        } else {
            *flag = 0;
            number.pop_back();
        }
        return number;
    }
}*/
};
int main() {
    Individ** result = (Individ**)calloc(200, sizeof(Individ*));
    Individ *ind;
    int flag_2 = 0;
    for (int l = 0; l < 200; l++) {
        ind = (Individ *) calloc(1, sizeof(Individ));
        Individ::array_with_random_actions(ind);
        ind->ptr = 0;
        ind->priority = 5;
        ind->place = 0;
        ind->goals = 0;
        result[l] = ind;
    }
    int a;
    cout<<"Введите число популяций, на которых будет обучаться генетический алгоритм\n";
    cin>> a;
    for(int u = 0; u < a; u++) {
        if(flag_2 == 1){
            for(int v = 0; v < 30; v++){
                Individ::array_with_random_actions(result[v]);
                result[v]->ptr = 0;
                result[v]->place = 0;
                result[v]->goals = 0;
                result[v]->priority = 5;
            }
        }
        for (int k = 0; k < 200; ++k) {
            //FILE *instructions=fopen("individs.bin", "a+");
            int max;
            int number = 0, j = 0, tasks = 50, l;
            int sum = 0, min = 0, flag = 1;
            Task t;
            //int ptr = 0;

            vector<Task> one;
            vector<Task> two;
            vector<Task> three;
            vector<Task> four;
            vector<Task> five;

            for (int i = 0; i < 50; i++) {
                t.gspd();
                min += t.complexity;
                //t.Name = i;
                if (t.Priority == 5) {
                    five.insert(five.begin(), t);
                } else if (t.Priority == 4) {
                    four.insert(four.begin(), t);
                } else if (t.Priority == 3) {
                    three.insert(three.begin(), t);
                } else if (t.Priority == 2) {
                    two.insert(two.begin(), t);
                } else if (t.Priority == 1) {
                    one.insert(one.begin(), t);
                }
            }
            /*
            do {
                cout << "Enter max size of task number\n";
                cin >> max;
                if (min >= max) {
                    cout << "Error. Repeat enter, on completing tasks need more tacts of processor\n";
                }
            } while (min >= max);
            */
            while ((!one.empty() || !two.empty() || !three.empty() || !four.empty() || !five.empty()) &&
                   result[k]->ptr <= 1000) {
                /*  if (!four.empty()) {
                      for (int j = 0; j < four.size(); j++) {
                          four.at(j).waiting += 1;
                          if (four.at(j).waiting == 10000) {
                              four.at(j).waiting = 0;
                              four.at(j).Priority += 1;
                              buf = four.at(j);
                              four.erase(j);
                          }
                      }
                  }
                  if (!three.empty()) {

                  }
                  if (!two.empty()) {

                  }
                  if (!one.empty()) {

                  }*/
                /* five=sum_takts(five,&flag,&sum,5);
                 four=sum_takts(four,&flag,&sum,4);
                 three=sum_takts(three,&flag,&sum,3);
                 two=sum_takts(five,&flag,&sum,2);
                 one=sum_takts(five,&flag,&sum,1);*/
                if (result[k]->goals % 15 != 0) {
                    flag = 1;
                }
                if (result[k]->goals % 15 == 0 && flag == 1) {
                    printf("VKID\n");               //VKID FUNCTION
                    for (int i = 0; i < 7; i++) {
                        t.gspd();
                        min += t.complexity;
                        //t.Name = i;
                        if (t.Priority == 5) {
                            five.insert(five.begin(), t);
                        } else if (t.Priority == 4) {
                            four.insert(four.begin(), t);
                        } else if (t.Priority == 3) {
                            three.insert(three.begin(), t);
                        } else if (t.Priority == 2) {
                            two.insert(two.begin(), t);
                        } else if (t.Priority == 1) {
                            one.insert(one.begin(), t);
                        }
                        ++(result[k]->goals);
                        flag = 0;
                    }
                    /*do {
                        if(min>=max) {
                            cout << "Error. Repeat enter, on completing tasks need more tacts of processor\n";
                            cout << "Enter max size of task number\n";
                            cin >> max;
                        }
                    }while(min>=max);*/
                }
                j = 0;
                if (!five.empty()) {
                    while (j < five.size()) {
                        five[j].waiting += 1;
                        if (!(five[j].waiting % 5)) {
                            five[j].complexity += 1;
                        }
                        j++;
                    }
                    j = 0;
                }
                if (!four.empty()) {
                    while (j < four.size()) {
                        four[j].waiting += 1;
                        if (!(four[j].waiting % 10)) {
                            four[j].complexity += 1;
                        }
                        if (four[j].waiting == 1000000) {
                            four[j].Priority += 1;
                            four[j].waiting = 0;
                            t = four[j];
                            four.erase(four.begin() + j);
                            five.insert(five.begin(), t);
                        }
                        j++;
                    }
                    j = 0;
                }
                if (!three.empty()) {
                    while (j < three.size()) {
                        three[j].waiting += 1;
                        if (!(three[j].waiting % 20)) {
                            three[j].complexity += 1;
                        }
                        if (three[j].waiting == 800000) {
                            three[j].Priority += 1;
                            three[j].waiting = 0;
                            t = three[j];
                            three.erase(three.begin() + j);
                            four.insert(four.begin(), t);
                        }
                        j++;
                    }
                    j = 0;
                }
                if (!two.empty()) {
                    while (j < two.size()) {
                        two[j].waiting += 1;
                        if (!(two[j].waiting % 40)) {
                            two[j].complexity += 1;
                        }
                        if (two[j].waiting == 500000) {
                            two[j].Priority += 1;
                            two[j].waiting = 0;
                            t = two[j];
                            two.erase(two.begin() + j);
                            three.insert(three.begin(), t);
                        }
                        j++;
                    }
                    j = 0;
                }
                if (!one.empty()) {
                    while (j < one.size()) {
                        one[j].waiting += 1;
                        if (!(one[j].waiting % 80)) {//Каждый 80 тактов сложность в первом приоритете увндичивается на 1
                            one[j].complexity += 1;
                        }
                        if (one[j].waiting == 300000) {
                            one[j].Priority += 1;
                            one[j].waiting = 0;
                            t = one[j];
                            one.erase(one.begin() + j);
                            two.insert(two.begin(), t);
                        }
                        j++;
                    }
                    j = 0;
                }
                if (result[k]->priority == 1) {
                    cout << "priority = 1, instruction =" << result[k]->instructions[result[k]->ptr];
                    cout << " sum = " << sum;
                    cout << " place = " << result[k]->place;
                    cout << " size one = " << one.size();
                    cout << " ptr = " << result[k]->ptr << endl;
                    Individ::read_inst(result[k], &one, &sum);
                }
                if (result[k]->priority == 2) {
                    cout << "priority = 2, instruction =" << result[k]->instructions[result[k]->ptr];
                    cout << " sum = " << sum;
                    cout << " place = " << result[k]->place;
                    cout << " size two = " << two.size();
                    cout << " ptr = " << result[k]->ptr << endl;
                    Individ::read_inst(result[k], &two, &sum);
                }
                if (result[k]->priority == 3) {
                    cout << "priority = 3, instruction =" << result[k]->instructions[result[k]->ptr];
                    cout << " sum = " << sum;
                    cout << " place = " << result[k]->place;
                    cout << " size three = " << three.size();
                    cout << " ptr = " << result[k]->ptr << endl;
                    Individ::read_inst(result[k], &three, &sum);

                }
                if (result[k]->priority == 4) {
                    cout << "priority = 4, instruction =" << result[k]->instructions[result[k]->ptr];
                    cout << " sum = " << sum;
                    cout << " place = " << result[k]->place;
                    cout << " size four = " << four.size();
                    cout << " ptr = " << result[k]->ptr << endl;
                    Individ::read_inst(result[k], &four, &sum);
                }
                if (result[k]->priority == 5) {
                    cout << "priority = 5, instruction =" << result[k]->instructions[result[k]->ptr];
                    cout << " sum = " << sum;
                    cout << " place = " << result[k]->place;
                    cout << " size five = " << five.size();
                    cout << " ptr = " << result[k]->ptr << endl;
                    Individ::read_inst(result[k], &five, &sum);
                }
                result[k]->ptr++;
                //ind->ptr+=1;
                /*if (!five.empty()) {
                    if (flag != 5) {
                        cout << "5 size = " << five.size() << endl;
                        sum += 3;
                        flag = 5;
                    }
                    t = five.back();
                    five.pop_back();
                    if (t.complexity != 0) {
                        t.complexity = t.complexity - 1;
                        five.push_back(t);
                        sum++;
                    } else {
                        flag = 0;
                    }
                } else if (!four.empty()) {     ///
                    if (flag != 4) {
                        cout << "4 size = " << four.size() << endl;
                        flag = 4;
                        sum += 3;
                    }
                    t = four.back();
                    four.pop_back();
                    if (t.complexity != 0) {
                        t.complexity = t.complexity - 1;
                        four.push_back(t);
                        sum++;
                    } else {
                        flag = 0;
                    }
                } else if (!three.empty()) {
                    if (flag != 3) {
                        cout << "3 size = " << three.size() << endl;
                        flag = 3;
                        sum += 3;
                    }
                    t = three.back();
                    three.pop_back();
                    if (t.complexity != 0) {
                        t.complexity = t.complexity - 1;
                        three.push_back(t);
                        sum++;
                    } else {
                        flag = 0;
                    }
                } else if (!two.empty()) {
                    if (flag != 2) {
                        cout << "2 size = " << two.size() << endl;
                        flag = 2;
                        sum += 3;
                    }
                    t = two.back();
                    two.pop_back();
                    if (t.complexity != 0) {
                        t.complexity = t.complexity - 1;
                        two.push_back(t);
                        sum++;
                    } else {
                        flag = 0;
                    }

                } else if (!one.empty()) {
                    if (flag != 1) {
                        cout << "1 size = " << one.size() << endl;
                        flag = 1;
                        sum += 3;
                    }
                    t = one.back();
                    one.pop_back();
                    if (t.complexity != 0) {
                        t.complexity = t.complexity - 1;
                        one.push_back(t);
                        sum++;
                    } else {
                        flag = 0;
                    }
                }
                 */
            }

            double goalssum = (double) result[k]->goals / (double) sum;
            if(sum == 0){
                goalssum = 0;
            }
            result[k]->goalssum = goalssum;
            printf("sum = %d\nmin = %d\ntasks = %d\ngoals/sum = %.16lf\n", sum, min, result[k]->goals, goalssum);
        }
        int pass, j;
        Individ *hold;
        for (pass = 0; pass < 200 - 1; pass++) {
            for (j = pass + 1; j < 200; j++) {
                if (result[pass]->goalssum > result[j]->goalssum) {
                    hold = result[j];
                    result[j] = result[pass];
                    result[pass] = hold;
                }
            }
        }
        int h;
        for (h = 0; h < 200; h++) {
            printf("%.16lf\n", result[h]->goalssum);
        }

        int d;
        /*for(d = 0; d < 40; d++){
            free(result[d]);
            result[d] = NULL;
        }*/
        FILE* fp = fopen("statistics.txt", "a");
        fprintf(fp, "%.16lf %d\n", result[199]->goalssum, result[199]->goals);
        fclose(fp);
        for(d = 0; d < 159; d++){
            if(rand()%100 < 5){
                result[d+40]->mutation(result[d+40]);
            }
        }
        for(int q = 199; q > 180 && result[q-1]; q-=2){
            for(d = 0; d < 1000; d++) {
                ind = (Individ*)calloc(1, sizeof(Individ));
                if(rand()%2) {
                    ind->instructions[d] = result[q]->instructions[d];
                }
                else{
                    ind->instructions[d] = result[q-1]->instructions[d];
                }
                ind->ptr = 0;
                ind->goals = 0;
                ind->priority = 5;
                ind->goalssum = 0;
                result[200 - q + 30] = ind;
            }
        }
        for(d = 40; d < 200; d++){
            result[d]->ptr = 0;
            result[d]->place = 0;
            result[d]->priority = 5;
        }
        flag_2 = 1;
    }
    FILE* fp2 = fopen("result.txt", "w");
    for(int z = 0; z <= 1000-1; z++) {
        fprintf(fp2, "%d ", result[199]->instructions[z]);
    }
    fclose(fp2);
    return 0;
}