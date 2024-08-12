// 703. Kth Largest Element in a Stream

class KthLargest {
public:
    // Constructor initializes the object with k and a list of numbers
    KthLargest(int k, std::vector<int>& nums) : k_(k) {
        // Add each number from the input vector to the min-heap
        for (int num : nums) {
            add(num);
        }
    }
    
    // Function to add a new element to the stream and return the kth largest element
    int add(int val) {
        // If the heap size is less than k, just push the new element
        if (min_heap_.size() < k_) {
            min_heap_.push(val);
        } else if (val > min_heap_.top()) {
            // If the heap is already of size k and the new element is larger than the smallest in the heap
            min_heap_.pop();  // Remove the smallest element
            min_heap_.push(val);  // Add the new element
        }
        // The root of the heap is the kth largest element
        return min_heap_.top();
    }

private:
    int k_;  // The kth largest element to find
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap_;  // Min-heap to maintain the k largest elements
};
