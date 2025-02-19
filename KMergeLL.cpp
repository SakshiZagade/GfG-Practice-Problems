class Solution{
  public:
          struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;  // Min heap based on node values
        }
    };

    Node* mergeKLists(vector<Node*>& lists) {
        priority_queue<Node*, vector<Node*>, Compare> pq;

        // Push the head of each list into the priority queue
        for (auto list : lists) {
            if (list)
                pq.push(list);
        }

        Node* dummy = new Node(0);
        Node* tail = dummy;

        // Process the priority queue
        while (!pq.empty()) {
            Node* minNode = pq.top();
            pq.pop();

            tail->next = minNode;
            tail = tail->next;

            if (minNode->next)
                pq.push(minNode->next);
        }

        return dummy->next;
    }
};
