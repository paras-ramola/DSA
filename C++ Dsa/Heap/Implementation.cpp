#include <iostream>
#include <queue>
using namespace std;

// Heap class definition
class heap
{
public:
    int arr[100]; // Array to store heap elements
    int size;     // Current size of the heap

    // Constructor to initialize heap
    heap()
    {
        arr[0] = -1; // Dummy value at index 0 (heap starts from index 1)
        size = 0;    // Heap is initially empty
    }

    // Function to insert a new value into the heap
    void insert(int val)
    {
        size = size + 1;  // Increase heap size
        int index = size; // Position to insert new value
        arr[index] = val; // Insert value at the end

        // Move the new value up until the heap property is restored
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                // Swap if parent is smaller
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                // Heap property satisfied
                return;
            }
        }
    }

    // Function to delete the root element (maximum in max-heap)
    void deletion()
    {
        if (size == 0)
        {
            cout << "Nothing to delete!!!" << endl;
            return;
        }

        // Replace root with last element
        arr[1] = arr[size];
        size--; // Reduce heap size

        int i = 1;

        // Move the new root down until the heap property is restored
        while (i < size)
        {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;

            // Swap with larger child if needed
            if (leftChild <= size && arr[i] < arr[leftChild])
            {
                swap(arr[i], arr[leftChild]);
                i = leftChild;
            }
            else if (rightChild <= size && arr[i] < arr[rightChild])
            {
                swap(arr[i], arr[rightChild]);
                i = rightChild;
            }
            else
            {
                // Heap property satisfied
                return;
            }
        }
    }

    // Function to print the heap elements
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << "  ";
        }
        cout << endl;
    }
};

// For Max Heap
void heapify(int arr[], int n, int i)
{
    int largest = i;            // Assume current node is largest
    int leftChild = 2 * i;      // Index of left child
    int rightChild = 2 * i + 1; // Index of right child

    // If left child exists and is greater than current largest
    if (leftChild <= n && arr[largest] < arr[leftChild])
    {
        largest = leftChild;
    }

    // If right child exists and is greater than current largest
    if (rightChild <= n && arr[largest] < arr[rightChild])
    {
        largest = rightChild;
    }

    // If largest is not the parent node, swap and heapify affected subtree
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest); // Recursively heapify the affected child
    }
}

// Function to build a max-heap from an unsorted array
void buildMaxHeap(int arr[], int n)
{
    // Start heapifying from the last non-leaf node down to the root
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n; i >= 2; i--)
    {
        swap(arr[1], arr[i]);
        heapify(arr, i - 1, 1);
    }
}


int main()
{
    heap h;

    // Inserting elements into the heap
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    // Display heap elements
    h.print();

    // Delete root element (max element)
    h.deletion();

    // Display updated heap
    h.print();

    int arr[6] = {-1, 53, 50, 55, 54, 52};
    buildMaxHeap(arr, 5);

    for (int i = 1; i <= 5; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;

    cout << "sorting";
    int num[9] = {3, 3, 7, 4, 8, 6, 0, 1, 4};
    heapSort(num, 8);
    for (int i = 0; i < 9; i++)
    {
        cout << num[i] << "  ";
    }
    cout << endl;

    // using priority_queue

    cout << "Max_heap:" << endl;
    priority_queue<int> pq;
    pq.push(10);
    pq.push(5);
    pq.push(30);

    while (pq.size() != 0)
    {
        cout << pq.top() << "   ";
        pq.pop();
    }
    cout << endl;

    cout << "Min_heap:" << endl;
    priority_queue<int, vector<int>, greater<int> > minpq;
    minpq.push(10);
    minpq.push(5);
    minpq.push(30);

    while (minpq.size() != 0)
    {
        cout << minpq.top() << "   ";
        minpq.pop();
    }

    //Sort an array
    cout<<endl;
    int nums[5]={2,7,4,5,1};

    priority_queue<int,vector<int>, greater<int> > p;

    for(int i=0;i<5;i++){
        p.push(nums[i]);
    }

    int i=0;
    while(p.size()!=0){
        nums[i++]=p.top();
        p.pop();
    }

    for(int i=0;i<5;i++){
        cout<<nums[i]<<" ";
    }

}
