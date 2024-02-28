// Joker
#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator << (ostream& os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << ' ';
    }
    return os;
}

enum eventType { opFree = 0, opPre = 1, reFree = 3, rePre = 4 };

struct Room {
    int pat, minutes;
    void init() { pat = -1; minutes = 0; }
};

struct Event {
    int time, id, type;
    Event(int t, int id, int type) : time(t), id(id), type(type) {}
    bool operator < (const Event& e) const { return time > e.time; }
};

struct Patient {
    string name;
    int surgeryTime, recoveryTime, opRoomId, opBeginTime, opEndTime, reRoomId, reBeginTime, reEndTime;
};

priority_queue<Event> em;
int nOp, nRe, T0, tTrans, tPreOp, tPreRe, nPat, allTime;
Room opRooms[11], reRooms[31];
Patient pats[101];
struct patComp {
    bool operator () (int i1, int i2) const {
        const Patient &p1 = pats[i1], &p2 = pats[i2];
        return p1.opRoomId < p2.opRoomId;
    }
};

set<int> opQueue, freeOpRooms, freeReRooms;
set<int, patComp> reQueue;

void writeTime(char* buf, int time) {
    int h = time / 60 + T0, m = time % 60;
    sprintf(buf, "%2d:%02d", h, m);
}

ostream& operator << (ostream& os, const Patient& p) {
    char buf[16];
    sprintf(buf, "  %-10s%2d   ", p.name.c_str(), p.opRoomId+1); os<<buf;
    writeTime(buf, p.opBeginTime); os<<buf<<"   ";
    writeTime(buf, p.opEndTime); os<<buf;
    sprintf(buf, "%7d", p.reRoomId+1); os<<buf<<"   ";
    writeTime(buf, p.reBeginTime); os<<buf<<"   ";
    writeTime(buf, p.reEndTime); os<<buf;
    return os;
}

ostream& operator<<(ostream& os, const Room& r) {
    double p = r.minutes * 100;
    p /= allTime;
    char buf[64];
    sprintf(buf, "%8d   %5.2lf", r.minutes, p);
    return os<<buf;
}

void solve() {
    int time = em.top().time;
    while (!em.empty() && em.top().time == time) {
        Event e = em.top();
        em.pop();
        int pid;
        switch(e.type) {
            case opFree:
                freeOpRooms.insert(e.id);
                break;
            case opPre:
                pid = opRooms[e.id].pat;
                reQueue.insert(pid);
                opRooms[e.id].pat = -1;
                em.push(Event(time + tPreOp, e.id, opFree));
                break;
            case reFree:
                freeReRooms.insert(e.id);
                break;
            case rePre:
                reRooms[e.id].pat = -1;
                em.push(Event(time + tPreRe, e.id, reFree));
                break;
            default:
                break;
        }
    }
    
    int opSz = min(opQueue.size(), freeOpRooms.size());
    for (int i = 0; i < opSz; i++) {
        int pid = *(opQueue.begin());
        opQueue.erase(opQueue.begin());
        int rid = *(freeOpRooms.begin());
        freeOpRooms.erase(freeOpRooms.begin());
        
        Room& r = opRooms[rid];
        r.pat = pid;
        Patient& p = pats[pid];
        p.opRoomId = rid;
        p.opBeginTime = time;
        p.opEndTime = time + p.surgeryTime;
        r.minutes += p.surgeryTime;
        em.push(Event(p.opEndTime, rid, opPre));
    }
    
    int reSz = min(reQueue.size(), freeReRooms.size());
    for (int i = 0; i < reSz; i++) {
        int pid = *(reQueue.begin()); reQueue.erase(reQueue.begin());
        int rid = *(freeReRooms.begin()); freeReRooms.erase(freeReRooms.begin());
        Room& r = reRooms[rid];
        r.pat = pid;
        Patient& p = pats[pid];
        p.reRoomId = rid;
        p.reBeginTime = time + tTrans;
        p.reEndTime = p.reBeginTime + p.recoveryTime;
        r.minutes += p.recoveryTime;
        em.push(Event(p.reEndTime, rid, rePre));
        allTime = max(allTime, p.reEndTime);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    while (cin >> nOp) {
        freeOpRooms.clear();
        freeReRooms.clear();
        allTime = 0;
        cin >> nRe >> T0 >> tTrans >> tPreOp >> tPreRe >> nPat;
        for (int i = 0; i < nOp; i++) {
            em.push(Event(0, i, opFree));
            opRooms[i].init();
        }
        for (int i = 0; i < nRe; i++) {
            em.push(Event(0, i, reFree));;
            reRooms[i].init();
        }
        
        for (int i = 0; i < nPat; i++) {
            Patient& p = pats[i];
            p.opRoomId = p.reRoomId = -1;
            cin >> p.name >> p.surgeryTime >> p.recoveryTime;
            opQueue.insert(i);
        }
        
        while (!em.empty()) solve();
        cout<<" Patient          Operating Room          Recovery Room"<<endl;
        cout<<" #  Name     Room#  Begin   End      Bed#  Begin    End"<<endl;
        cout<<" ------------------------------------------------------"<<endl;
        for(int i = 0; i < nPat; i++) cout<<setw(2)<<i+1<<pats[i]<<endl;
        cout<<endl;
        cout<<"Facility Utilization"<<endl;
        cout<<"Type  # Minutes  % Used"<<endl;
        cout<<"-------------------------"<<endl;
        for(int i = 0; i < nOp; i++) cout<<"Room "<<setw(2)<<i+1<<opRooms[i]<<endl;
        for(int i = 0; i < nRe; i++) cout<<"Bed  "<<setw(2)<<i+1<<reRooms[i]<<endl;
        cout<<endl;
        
    }
  
    return 0;
}
```


```cpp
// Joker
#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator << (ostream& os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v[i] << ' ';
    }
    return os;
}

int nOp, nRe, T0, tTrans, tOpPre, tRePre, nPat;
int all_time;

enum roomType { opFree = 0, opPre = 1, reFree = 2, rePre = 3 };

struct Event {
    int time, id, type;
    Event(int t, int id, int type) : time(t), id(id), type(type) {}
    bool operator < (const Event& e) const {
        return time > e.time;
    }
};
priority_queue<Event> em;

struct Room {
    int pid, minutes;
    void init() { pid = -1, minutes = 0; }
};
Room opRooms[11], reRooms[31];

struct Pat {
    string name;
    int opTime, reTime, opRoom, opBegin, opEnd, reRoom, reBegin, reEnd;
};
Pat pats[101];

struct reComp {
    bool operator () (int i1, int i2) const {
        const Pat &p1 = pats[i1], &p2 = pats[i2];
        return p1.opRoom < p2.opRoom;
    }
};
set<int> opQueue, freeOpRooms, freeReRooms;
set<int, reComp> reQueue;

void solve() {
    int time = em.top().time;
    while (!em.empty() && em.top().time == time) {
        Event e = em.top(); em.pop();
        int rid;
        switch (e.type) {
            case opFree:
                freeOpRooms.insert(e.id);
                break;
            case opPre:
                rid = e.id;
                reQueue.insert(opRooms[rid].pid);
                opRooms[rid].pid = -1;
                e.time += tOpPre;
                e.type = opFree;
                em.push(e);
                break;
            case reFree:
                freeReRooms.insert(e.id);
                break;
            case rePre:
                rid = e.id;
                reRooms[rid].pid = -1;
                e.time += tRePre;
                e.type = reFree;
                em.push(e);
                break;
            default:
                break;
        }
    }
    
    int opSz = min(opQueue.size(), freeOpRooms.size());
    for (int i = 0; i < opSz; i++) {
        int rid = *(freeOpRooms.begin()); freeOpRooms.erase(freeOpRooms.begin());
        int pid = *(opQueue.begin()); opQueue.erase(opQueue.begin());
        
        Pat& p = pats[pid];
        p.opRoom = rid;
        p.opBegin = time;
        p.opEnd = time + p.opTime;
        
        Room& r = opRooms[rid];
        r.pid = pid;
        r.minutes += p.opTime;
        em.push(Event(p.opEnd, rid, opPre));
    }
    
    int reSz = min(reQueue.size(), freeReRooms.size());
    for (int i = 0; i < reSz; i++) {
        int rid = *(freeReRooms.begin()); freeReRooms.erase(freeReRooms.begin());
        int pid = *(reQueue.begin()); reQueue.erase(reQueue.begin());
        
        Pat& p = pats[pid];
        p.reRoom = rid;
        p.reBegin = time + tTrans;
        p.reEnd = p.reBegin + p.reTime;
        Room& r = reRooms[rid];
        r.pid = pid;
        r.minutes += p.reTime;
        em.push(Event(p.reEnd, rid, rePre));
        all_time = max(all_time, p.reEnd);
    }
}

void writeTime(char* buf, int time) {
    int h = time / 60 + T0, m = time % 60;
    sprintf(buf, "%2d:%02d", h, m);
}

ostream& operator << (ostream& os, const Pat& p) {
    char buf[60];
    sprintf(buf, "  %-10s%2d   ", p.name.c_str(), p.opRoom + 1); os << buf;
    writeTime(buf, p.opBegin); os << buf << "   ";
    writeTime(buf, p.opEnd); os << buf;
    sprintf(buf, "%7d", p.reRoom + 1); os << buf << "   ";
    writeTime(buf, p.reBegin); os << buf << "   ";
    writeTime(buf, p.reEnd); os << buf;
    return os;
}

ostream& operator << (ostream& os, const Room& r) {
    double p = r.minutes * 100;
    p /= all_time;
    char buf[60];
    sprintf(buf, "%8d   %5.2lf", r.minutes, p);
    return os << buf;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    while (cin >> nOp) {
        freeOpRooms.clear(); freeReRooms.clear();
        all_time = 0;
        cin >> nRe >> T0 >> tTrans >> tOpPre >> tRePre >> nPat;
        
        for (int i = 0; i < nOp; i++) {
            opRooms[i].init();
            em.push(Event(0, i, opFree));
        }
        
        for (int i = 0; i < nRe; i++) {
            reRooms[i].init();
            em.push(Event(0, i, reFree));
        }
        
        for (int i = 0; i < nPat; i++) {
            Pat& p = pats[i];
            cin >> p.name >> p.opTime >> p.reTime;
            p.opRoom = p.reRoom = -1;
            opQueue.insert(i);
        }
        
        while (!em.empty()) solve();
        
        cout << " Patient          Operating Room          Recovery Room" << endl;
        cout << " #  Name     Room#  Begin   End      Bed#  Begin    End" << endl;
        cout << " ------------------------------------------------------" << endl;
        for (int i = 0; i < nPat; i++) 
            cout << setw(2) << i + 1 << pats[i] << endl;
        cout << endl;
        cout << "Facility Utilization" << endl;
        cout << "Type  # Minutes  % Used" << endl;
        cout << "-------------------------" << endl;
        for (int i = 0; i < nOp; i++) 
            cout << "Room " << setw(2) << i + 1 << opRooms[i] << endl;
        for (int i = 0; i < nRe; i++) 
            cout << "Bed  " << setw(2) << i + 1 << reRooms[i] << endl;
        cout << endl;
    }
  
    return 0;
}