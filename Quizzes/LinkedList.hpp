#include <iostream>

class Node
{ // Individual objects in linked list
public:
    // Constructor takes in value, initializes member variable "value" with parameter "value"
    Node(int value);
    // Empty Destructor
    ~Node();

    // Getters and setters
    int get_value() const;
    void set_value(int value);
    Node *get_next() const;
    void set_next(Node *p_next);

private:
    // Integer stored by Node
    int value;
    // Next Node in LinkedList
    Node *p_next;
};

class LinkedList
{ // Linked list itself
public:
    // Constructor initializes new LinkedList with p_head = nullptr
    LinkedList();
    // Deallocate all nodes within LinkedList
    ~LinkedList();
    // Insert new Node at end of LinkedList, set p_next of the Node to nullptr
    void insert(Node *new_node);
    // Print out LinkedList
    void print();
    // Get head of LinkedList
    Node *get_head();
    // Set head of LinkedList
    void set_head(Node *new_head);
    // IMPLEMENT THIS FUNCTION
    void delete_insts(int num);

private:
    // LinkedList head (first Node in LinkedList)
    Node *p_head;
};

// FUNCTION DEFINITIONS

Node::Node(int value)
{
    this->value = value;
    this->p_next = nullptr;
}
Node::~Node()
{
}
int Node::get_value() const
{
    return this->value;
}
void Node::set_value(int value)
{
    this->value = value;
}
Node *Node::get_next() const
{
    return this->p_next;
}
void Node::set_next(Node *p_next)
{
    this->p_next = p_next;
}

//---------------------------------------

LinkedList::LinkedList()
{
    p_head = nullptr;
}

LinkedList::~LinkedList()
{

    if (this->p_head == nullptr)
    {
    }
    else
    {

        Node *p_curr = p_head;
        Node *p_next = p_head;

        while (p_curr != nullptr)
        {
            p_next = p_curr;
            p_curr = p_curr->get_next();
            delete p_next;
            p_next = nullptr;
        }
        delete p_curr;
        p_curr = nullptr;
    }
}

void LinkedList::print()
{

    if (this->p_head == nullptr)
    {
    }
    else
    {
        Node *p_next = p_head;
        while (p_next != nullptr)
        {
            std::cout << "Value at this node! : " << p_next->get_value() << std::endl;
            p_next = p_next->get_next();
        }
    }
}

void LinkedList::insert(Node *new_node)
{
    if (p_head == nullptr)
    {
        new_node->set_next(p_head);
        p_head = new_node;
    }

    else
    {
        Node *i{p_head};

        for (; i->get_next() != nullptr; i = i->get_next())
        {
        }
        i->set_next(new_node);
    }
    new_node->set_next(nullptr);
}

Node *LinkedList::get_head()
{
    return p_head;
}

void LinkedList::set_head(Node *new_head)
{
    p_head = new_head;
}