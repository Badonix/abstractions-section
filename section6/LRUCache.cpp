// not complete
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
      if(m.count(key) == 0) return -1;        
      Node* curr_node = m[key];
      remove(curr_node);
      addToTail(curr_node);
      return curr_node->val;
    }
    
    void put(int key, int value) {
      if(size == cap){
        remove(head->next);
        size--;
      }

      if(m.count(key) != 0){
        Node* curr = m[key];
        curr->val = value;
        remove(curr);
        addToTail(curr);
        return;
      }

      Node* new_node = new Node(value);
      addToTail(new_node);
      size++;
    }

private:

void addToHead(Node* node){
  Node* temp = head->next;
  head->next = node;
  node->next = temp;
  node->prev = head;
  temp->prev = node;
}

void remove(Node* node){
  node->next->prev = node->prev;
  node->prev->next = node->next;
  delete node;
}



struct Node{
  int val;
  Node* next;
  Node* prev;
  Node(){
    val = 0;
    next = nullptr;
    prev = nullptr;
  }

  Node(int new_val){
    val = new_val;
    next = nullptr;
    prev = nullptr;
  }
}
int size, cap;
unordered_map<int, Node*> m;

Node* head;
Node* tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

