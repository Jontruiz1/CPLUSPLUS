#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<ListNode*> yes;
    ListNode* curr = head;
    int size = 0;

    while(curr != nullptr){
        size++;
        yes.push_back(curr);
        curr = curr->next;
    }
    n = (size - n) + 1;

    if(n == 1){
        return yes.size() > 1 ? yes[1] : nullptr;
    }
    else if(n == size){
        yes[n-2]->next = nullptr;
    }
    else{
        yes[n-2]->next = yes[n-1]->next;
    }

    return yes[0];



}

int main(){
    ListNode* n = new ListNode(10, new ListNode(5, nullptr));
    ListNode* woo = new ListNode(0, n);

    cout << "help";
    removeNthFromEnd(woo, 2);

    woo = woo->next;
    cout << woo->val;
    
    delete woo;
    delete n;
}