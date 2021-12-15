// Class Declarations
class Node;
class Linked_list;
class Sized_linked_list;

// Define the base class
class Linked_list
{
public:
    Linked_list();
    virtual ~Linked_list(); // Declare all member functions
                            // and the destructor to be virtual

    // What is this?
    Linked_list(Linked_list const &original) = delete;
    Linked_list(Linked_list const &&original) = delete;

    virtual Linked_list &operator=(Linked_list const &rhs) = delete;
    virtual Linked_list &operator=(Linked_list &&rhs) = delete;

    virtual double front() const;
    virtual bool empty() const;
    virtual std::size_t size() const;

    virtual void push_front(double new_value);
    virtual void pop_front();
    virtual void clear();

private:
    Node *p_list_head_;
    friend std::ostream &operator<<(std::ostream &out, Linked_list const &list);
};

// Define the "derived class"
// Indicate it's derived from another class
// Add new variables
// Re-declare member functions you want to change
// Don't introduce new member functions

class Sized_linked_list : public Linked_list
{
public:
    // Continue adding virtual and also override at the end.
    // No need for virtual for member vars
    Sized_linked_list(); // Constructor is a must

    virtual double back() const; // Define function you intend to add onto this class

    virtual std::size_t size() const override;
    virtual void push_front(double new_value) override;
    virtual void pop_front() override;

protected:
    std::size_t list_size_ const; // Cant change it now
}

// Must initialize constructor of the base class
Sized_linked_list::Sized_linked_list() : Linked_list{}, list_size_{0}
{
}

// Override the size member function
// by completely rewriting it
std::size_t Sized_linked_list::size() const
{
    return list_size_;
}
// Describe new member functions

// Note that derived classes cant access private members
// label them protected instead
