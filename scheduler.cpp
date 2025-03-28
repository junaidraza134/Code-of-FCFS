#include "scheduler.h"
#include <iostream>
using namespace std;

void fcfs(vector<Process> &procs) {
    int currentTime = 0;
    for (auto &p : procs) {
        if (currentTime < p.arrival) {
            currentTime = p.arrival;
        }
        p.waiting = currentTime - p.arrival;
        p.turnaround = p.waiting + p.burst;
        currentTime += p.burst;
    }
}

void display(const vector<Process> &procs) {
    cout << "\nPID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (const auto &p : procs) {
        cout << p.id << "\t" << p.arrival << "\t" << p.burst
             << "\t" << p.waiting << "\t" << p.turnaround << endl;
    }
}

void displayGanttChart(const vector<Process> &procs) {
    cout << "\nGantt Chart:\n";
    for (const auto &p : procs) {
        cout << "| P" << p.id << " ";
    }
    cout << "|\n";
}