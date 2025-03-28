#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int id, arrival, burst, waiting, turnaround;
};

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
    vector<Process> procs = {{1, 0, 4}, {2, 1, 3}, {3, 2, 2}};
    fcfs(procs);
    display(procs);
    return 0;
}