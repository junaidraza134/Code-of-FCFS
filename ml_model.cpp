#include "scheduler.h"
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int predictSchedule(const vector<Process> &procs) {
    srand(time(0));
    return rand() % procs.size();
}