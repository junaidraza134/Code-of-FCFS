#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Process {
    int id, arrival, burst, waiting, turnaround, priority;
};

int predictSchedule(const vector<Process> &procs) {
    srand(time(0));
    return rand() % procs.size();
}

void fcfs(vector<Process> &procs) {
    int time = 0;
    for (auto &p : procs) {
        if (time < p.arrival) 
            time = p.arrival;
        p.waiting = time - p.arrival;
        p.turnaround = p.waiting + p.burst;
        time += p.burst;
    }
}

void display(const vector<Process> &procs) {
    cout << "\nPID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (const auto &p : procs) {
        cout << p.id << "\t" << p.arrival << "\t" << p.burst 
             << "\t" << p.waiting << "\t" << p.turnaround << endl;
    }
}

int main() {
    vector<Process> procs = {{1, 0, 4, 0, 0, 0}, {2, 1, 3, 0, 0, 0}, {3, 2, 2, 0, 0, 0}};
    int predicted = predictSchedule(procs);
    cout << "ML Predicted next process: " << procs[predicted].id << endl;
    fcfs(procs);
    display(procs);
    return 0;
}