class KthLargest {
public:

    // Min Heap to store the k largest elements seen so far
    priority_queue<int, vector<int>, greater<int>> p;

    // Stores the value of k
    int k;

    // Constructor
    KthLargest(int k, vector<int>& nums) {

        // Initialize class variable k
        this->k = k;

        // Insert all elements into the min heap
        for(int x : nums) {

            p.push(x);

            // If heap size becomes greater than k,
            // remove the smallest element
            // This ensures only k largest elements remain
            if(p.size() > k)
                p.pop();
        }
    }

    // Function to add a new element to the stream
    int add(int val) {

        // Insert the new element
        p.push(val);

        // If heap size exceeds k,
        // remove the smallest element
        if(p.size() > k)
            p.pop();

        // The top of the min heap is the kth largest element
        return p.top();
    }
};