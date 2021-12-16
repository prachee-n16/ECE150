#include "LinkedList.hpp" // This imports the linkedlist
#ifndef MARMOSET_TESTING
int main();
#endif
void LinkedList::delete_insts(int num)
{
    // This function takes in an integer and deletes all instances of it within the LinkedList, keeping the
    // LinkedList in the same order, and ensuring no memory leaks occur.

    // You wanna make sure to start with your extruding cases/any cases that is outside the normal

    // p_head == nullptr; check!
    // Front of LinkedList
    // Processing in the middle
    // End of LinkedList

    if (p_head == nullptr)
    {
        return;
    }
    // Recall that a destructor needs at least 2 temporary nodes
    Node *p_temp = p_head;
    while (p_head != nullptr && p_head->get_value() == num)
    {
        p_temp = p_head;
        p_head = p_head->get_next();
        delete p_temp;
        // For any assignment you do, it is best to visualize with an example
    }
    p_temp = p_head;
    while (p_head != nullptr && p_temp->get_next() != nullptr)
    {
        if (p_temp->get_next()->get_value() == num)
        {
            Node *p_iterate = p_temp->get_next(); // Work for singular instance
            while (p_iterate != nullptr && p_iterate->get_value() == num)
            {
                Node *p_delete = p_iterate;
                p_iterate = p_iterate->get_next();
                delete p_delete;
            }
            p_temp->set_next(p_iterate);
        }
        if (p_temp->get_next() != nullptr)
            p_temp = p_temp->get_next();
    }
}
#ifndef MARMOSET_TESTING
int main()
{
    // 1,3,2,3,3,3,5,1
    LinkedList list{};
    list.insert(new Node(3));
    list.insert(new Node(3));
    list.insert(new Node(3));
    list.insert(new Node(3));

    list.delete_insts(3);

    list.print();

    return 0;
}
#endif
