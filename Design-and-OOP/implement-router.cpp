class Node {
public:
    int source, destination, timestamp;
    Node* next;
    Node(int s=0, int d=0, int t=0) 
        : source(s), destination(d), timestamp(t), next(nullptr) {}
};

class Router {
public:
    Node *head, *tail;
    int len, curr;
    set<pair<pair<int, int>, int>> seen; // example duplicate check by timestamp

    Router(int memoryLimit) {
        head = tail = nullptr;
        len = memoryLimit;
        curr = 0;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if (seen.count({{source, destination}, timestamp})) return false;
        seen.insert({{source, destination}, timestamp});

        Node* newnode = new Node(source, destination, timestamp);

        if (!head) { // first packet
            head = tail = newnode;
            curr++;
            return true;
        }

        if (curr == len) { // remove oldest
            Node* temp = head;
            head = head->next;
            seen.erase({{temp->source, temp->destination}, temp->timestamp});
            delete temp;
            curr--;
        }

        tail->next = newnode;
        tail = newnode;
        curr++;
        return true;
    }
    
    vector<int> forwardPacket() {
        if (!head) return {};
        Node* temp = head;
        head = head->next;
        
        vector<int> ans = {temp->source, temp->destination, temp->timestamp};
        seen.erase({{temp->source, temp->destination}, temp->timestamp});
        delete temp;
        curr--;
        return ans;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        
    }
};
