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

const int N = 21, M = 7;

struct Event {
    int time, id;
    bool isReq;
    
    Event(int t, int i, bool r = true) : time(t), id(i), isReq(r) {}
    
    bool operator < (const Event& o) const {
        return time > o.time;
    }
};

struct ReqInfo {
    int tid, num, t0, t, dt;
};

struct StaffInfo {
    int pid, k, tid[N], idx, last;
    
    bool operator < (const StaffInfo& o) const {
        return last < o.last || (last == o.last && pid < o.pid);
    }
};

priority_queue<Event> eheap;
ReqInfo reqs[N];
StaffInfo staffs[M];
multiset<int> rqs;
set<int> freeStaffs;

struct StaffComp {
    bool operator () (int i1, int i2) const {
        return staffs[i1] < staffs[i2];
    }
};
set<int, StaffComp> rq_wait[N];
int n, m, kase;

void solve() {
    int time = eheap.top().time;
    while (!eheap.empty() && eheap.top().time == time) {
        const Event& e = eheap.top(); 
        if (e.isReq) rqs.insert(e.id);
        else freeStaffs.insert(e.id);
        eheap.pop();
    }
    
    while (!rqs.empty() && !freeStaffs.empty()) {
        for (int i = 0; i < n; i++) rq_wait[i].clear();
        
        bool canAssign = false;
    
        for (auto& i : freeStaffs) {
            auto& fs = staffs[i];
            for (int j = 0; j < fs.k; j++) {
                int tid = fs.tid[j];
                if (!rqs.count(tid)) continue;
                canAssign = true;
                rq_wait[tid].insert(fs.idx);
                break;
            }
        }
        
        if (!canAssign) break;
        
        for (int i = 0; i < n; i++) {
            
            auto& ss = rq_wait[i];
            while (rqs.count(i) && !ss.empty()) {
                rqs.erase(rqs.find(i));
                int staff_idx = *(ss.begin());
                freeStaffs.erase(staff_idx);
                ss.erase(staff_idx);
                eheap.push(Event(time + reqs[i].t, staff_idx, false));
            }
        }
    }
    
    if (eheap.empty()) {
        cout << "Scenario " << kase++ << ": All requests are serviced within " << time << " minutes." << endl;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    kase = 1;
    map<int, int> rq_map;
    while (cin >> n && n) {
        rq_map.clear(), rqs.clear(), freeStaffs.clear();
        for (int i = 0; i < n; i++) {
            ReqInfo& r = reqs[i];
            cin >> r.tid >> r.num >> r.t0 >> r.t >> r.dt;
            rq_map[r.tid] = i;
            r.tid = i;
            for (int j = 0; j < r.num; j++) eheap.push(Event(r.t0 + r.dt * j, i));
        }
        
        cin >> m;
        for (int i = 0; i < m; i++) {
            StaffInfo& s = staffs[i];
            cin >> s.pid >> s.k;
            for (int j = 0; j < s.k; j++) {
                cin >> s.tid[j];
                s.tid[j] = rq_map[s.tid[j]];
            }
            s.idx = i;
            s.last = 0;
            eheap.push(Event(s.last, i, false));
        }
        
        while (!eheap.empty()) solve();
    }
    
  
    return 0;
}