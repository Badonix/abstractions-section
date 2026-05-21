// complete
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
      if(m.count(key) != 0){
        Node* curr = m[key];
        curr->val = value;
        remove(curr);
        addToTail(curr);
        return;
      }

      if(size == cap){
        int temp_key = head->next->key;
        remove(head->next);
        m.erase(temp_key);
        size--;
      }


      Node* new_node = new Node(key, value);
      addToTail(new_node);
      m[key] = new_node;
      size++;
    }

private:

struct Node{
  int key, val;
  Node* next;
  Node* prev;
  Node(){
    val = 0;
    key = 0;
    next = nullptr;
    prev = nullptr;
  }

  Node(int new_key, int new_val){
    val = new_val;
    key = new_key;
    next = nullptr;
    prev = nullptr;
  }
};

void addToTail(Node* node){
  Node* temp = tail->prev;
  tail->prev->next = node;
  node->prev = temp;
  node->next = tail;
  tail->prev = node;
}

void remove(Node* node){
  node->next->prev = node->prev;
  node->prev->next = node->next;
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

