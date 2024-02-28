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

const int N = 10010;
struct Order {
    bool buy;
    int size, price;
};

int n, kase, orderIndice[N], canceled[N];
vector<Order> orders;

template<typename Compare> 
struct OrderQueue {
    typedef set<int, Compare> _IntSet;
    _IntSet eles;
    bool empty() const { return eles.empty(); }
    void push(int i) { eles.insert(i); }
    void erase(int i) { eles.erase(eles.find(i)); }
    int top() { return *eles.begin(); }
    int pop() {
        int t = *eles.begin();
        eles.erase(eles.begin());
        return t;
    }
    int topPrice() { Order& o = orders[top()]; return o.price; }
    int topSize() { 
        int tp = orders[top()].price;
        int ans = 0;
        for (auto i : eles) {
            const Order& o = orders[i];
            if (tp == o.price) ans += o.size;
            else break;
        }
        return ans;
    }
    void clear() { eles.clear(); }
    
};

struct buyCompare {
    bool operator () (int i1, int i2) const {
        const Order &o1 = orders[i1], &o2 = orders[i2];
        return o1.price > o2.price || (o1.price == o2.price && i1 < i2);
    }
};

struct sellCompare {
    bool operator () (int i1, int i2) const {
        const Order &o1 = orders[i1], &o2 = orders[i2];
        return o1.price < o2.price || (o1.price == o2.price && i1 < i2);
    }
};

OrderQueue<buyCompare> buyQueue;
OrderQueue<sellCompare> sellQueue;

void cancel(int i) {
    int oi = orderIndice[i];
    if (canceled[oi]) return;
    Order& o = orders[oi];
    if (o.buy) buyQueue.erase(oi);
    else sellQueue.erase(oi);
    canceled[oi] = 1;
}

void quote() {
    int bidSize = 0, bidPrice = 0, sellSize = 0, sellPrice = 99999;
    if (!buyQueue.empty()) { bidSize = buyQueue.topSize(); bidPrice = buyQueue.topPrice(); }
    if (!sellQueue.empty()) { sellSize = sellQueue.topSize(); sellPrice = sellQueue.topPrice(); }
    cout << "QUOTE " << bidSize << " " << bidPrice << " - " << sellSize << " " << sellPrice << endl;
}

void trade(int oi) {
    Order& o = orders[oi];
    
    if (o.buy) {
        if (sellQueue.empty() || sellQueue.topPrice() > o.price) {
            buyQueue.push(oi);
            return;
        }
        
        int sellPrice;
        while (!sellQueue.empty() && o.size > 0 && 
            o.price >= (sellPrice = sellQueue.topPrice())) {
            int t = sellQueue.top();
            Order& to = orders[t];
            int num = min(o.size, to.size);
            cout << "TRADE " << num << " " << sellPrice << endl; 
            o.size -= num;
            to.size -= num;
            sellQueue.pop();
            if (to.size) sellQueue.push(t);
            else canceled[t] = 1;
        }
        if (o.size) buyQueue.push(oi);
        else canceled[oi] = 1;
        return;
    }
    
    
    if (buyQueue.empty() || buyQueue.topPrice() < o.price) {
        sellQueue.push(oi);
        return;
    }
    int buyPrice;
    while (!buyQueue.empty() && o.size > 0 && 
        o.price <= (buyPrice = buyQueue.topPrice())) {
        int t = buyQueue.top();
        Order& to = orders[t];
        int num = min(o.size, to.size);
        cout << "TRADE " << num << " " << buyPrice << endl; 
        o.size -= num;
        to.size -= num;
        buyQueue.pop();
        if (to.size) buyQueue.push(t);
        else canceled[t] = 1;
    }
    if (o.size) sellQueue.push(oi);
    else canceled[oi] = 1;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    
    bool first = true;
    string cmd;
    while (cin >> n) {
        if (first) first = false;
        else cout << endl;
        fill_n(orderIndice, n, -1); 
        fill_n(canceled, n, 0);
        orders.clear(); buyQueue.clear(); sellQueue.clear(); 
        for (int i = 0; i < n; i++) {
            cin >> cmd;
            if (cmd == "CANCEL") {
                int x; cin >> x;
                cancel(x - 1);
                quote();
                continue;
            } 
            
            Order o;
            cin >> o.size >> o.price;
            o.buy = cmd == "BUY";
            orderIndice[i] = orders.size();
            orders.push_back(o);
            trade(orderIndice[i]);
            quote();
        }
    }
    
  
    return 0;
}