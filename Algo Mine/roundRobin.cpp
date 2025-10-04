#include <iostream>
#include <queue>
using namespace std;

struct Process {
    int id;         // Process ID
    int arrival;    // Arrival Time
    int burst;      // Burst Time
    int remaining;  // Remaining Burst Time
    int completion; // Completion Time
    int waiting;    // Waiting Time
    int turnaround; // Turnaround Time
};

int main() {
    int n, quantum;
    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter time quantum: ";
    cin >> quantum;

    Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Enter arrival time and burst time for process " << p[i].id << ": ";
        cin >> p[i].arrival >> p[i].burst;
        p[i].remaining = p[i].burst;
    }

    int time = 0, completed = 0;
    queue<int> q;
    bool inQueue[n] = {false};

    // Start with the first process that has arrived
    q.push(0);
    inQueue[0] = true;

    while (completed < n) {
        if (q.empty()) {
            // No process is ready, so jump to next arrival
            for (int i = 0; i < n; i++) {
                if (p[i].remaining > 0) {
                    time = p[i].arrival;
                    q.push(i);
                    inQueue[i] = true;
                    break;
                }
            }
        }

        int i = q.front();
        q.pop();
        inQueue[i] = false;

        // If process has arrived
        if (p[i].arrival <= time) {
            int execTime = min(quantum, p[i].remaining);
            p[i].remaining -= execTime;
            time += execTime;

            // Check if any new process has arrived during this execution
            for (int j = 0; j < n; j++) {
                if (p[j].arrival <= time && p[j].remaining > 0 && !inQueue[j]) {
                    q.push(j);
                    inQueue[j] = true;
                }
            }

            // If the process finished execution
            if (p[i].remaining == 0) {
                p[i].completion = time;
                p[i].turnaround = p[i].completion - p[i].arrival;
                p[i].waiting = p[i].turnaround - p[i].burst;
                completed++;
            } else {
                q.push(i); // Put it back at the end of the queue
                inQueue[i] = true;
            }
        } else {
            // Process hasn’t arrived yet
            q.push(i);
        }
    }

    cout << "\nProcess\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].id << "\t"
             << p[i].arrival << "\t"
             << p[i].burst << "\t"
             << p[i].completion << "\t"
             << p[i].turnaround << "\t"
             << p[i].waiting << "\n";
    }

    float avgTAT = 0, avgWT = 0;
    for (int i = 0; i < n; i++) {
        avgTAT += p[i].turnaround;
        avgWT += p[i].waiting;
    }
    avgTAT /= n;
    avgWT /= n;

    cout << "\nAverage Turnaround Time = " << avgTAT;
    cout << "\nAverage Waiting Time = " << avgWT << endl;

    return 0;
}
