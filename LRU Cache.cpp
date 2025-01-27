//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
  private:
     // Doubly Linked List Node structure
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    // Head and Tail pointers of the doubly linked list
    Node* head;
    Node* tail;

    // Map to store key-node pairs
    unordered_map<int, Node*> cache;
    int capacity;

    // Helper function to add a node to the front of the list
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // Helper function to remove a node from the list
    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Helper function to move a node to the front of the list
    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1); // Dummy head node
        tail = new Node(-1, -1); // Dummy tail node
        head->next = tail;
        tail->prev = head;
    }

    // Destructor to free memory
    ~LRUCache() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // Key not found
        }
        Node* node = cache[key];
        moveToHead(node); // Move the accessed node to the front
        return node->value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value; // Update the value
            moveToHead(node);    // Move the node to the front
        } else {
            if (cache.size() == capacity) {
                // Remove the least recently used node
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
            // Add a new node
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
