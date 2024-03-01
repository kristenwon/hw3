#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below
  std::vector<T> heapVect;
  int m_; // m ary
  PComparator c_;
  
  // helper functions
  void trickleUp(int index);
  void  trickleDown(int index);
  int child(int index, int k) const;
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T,PComparator>::Heap(int m, PComparator c) : m_(m), c_(c)
{}

template <typename T, typename PComparator>
Heap<T,PComparator>::~Heap()
{}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleUp(int index)
{
  if(index == 0) { return; }
  int parent = (index - 1) / m_;
  if(c_(heapVect[index], heapVect[parent])){
    std::swap(heapVect[index], heapVect[parent]);
    trickleUp(parent);
  }
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
  heapVect.push_back(item);
  trickleUp(heapVect.size()-1);
}

template <typename T, typename PComparator>
void Heap<T,PComparator>::trickleDown(int index)
{
  int bestChild = index;
  for(int i=0; i < m_; i++){
    if(c_(heapVect[index*m_+i], heapVect[bestChild]) && index*m_+i < heapVect.size()-1){
      bestChild = index * m_ + i;
    }
  }

  if(bestChild != index){
    std::swap(heapVect[index], heapVect[bestChild]);
    trickleDown(bestChild);
  }
}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  return heapVect[0];
}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("Empty heap");

  }
  std::swap(heapVect[0], heapVect[heapVect.size()-1]);
  heapVect.pop_back();
  trickleDown(0);
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  return heapVect.size() == 0;
}

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
  return heapVect.size();
}

#endif

