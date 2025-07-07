#include <iostream> 

#include <vector> 

  

using namespace std; 

  

// Function to reverse array in place 

void reverseArray(vector<int>& arr) { 

    int start = 0; 

    int end = arr.size() - 1; 

  

    while (start < end) { 

        // Swap the elements at start and end 

        int temp = arr[start]; 

        arr[start] = arr[end]; 

        arr[end] = temp; 

  

        // Move the pointers 

        start++; 

        end--; 

    } 

} 

  

int main() { 

    int n; 

    cout << "Enter the number of elements in the array: "; 

    cin >> n; 

  

    if (n <= 0) { 

        cout << "Invalid size. Exiting." << endl; 

        return 1; 

    } 

  

    vector<int> arr(n); 

  

    cout << "Enter " << n << " integers:" << endl; 

    for (int i = 0; i < n; ++i) { 

        cin >> arr[i]; 

    } 

  

    // Reverse the array in place 

    reverseArray(arr); 

  

    // Output the reversed array 

    cout << "Reversed array:" << endl; 

    for (int i = 0; i < n; ++i) { 

        cout << arr[i] << " "; 

    } 

    cout << endl; 

  

    return 0; 

}