/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

Node* removeKthNode(Node* head, int n)
{
    // Write your code here.
    Node *start = new Node();

        start->next = head;

        Node *slow = start;
        Node *fast = start;

        for(int i=1;i<=n;i++)
        {
            fast = fast->next;
        }

        while(fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        } 
        slow -> next = slow->next->next;

        return start->next;
        
}
