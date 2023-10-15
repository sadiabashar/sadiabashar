#include <iostream>
#include <cstring>

using namespace std;

// Function to find the smallest multiple of N composed of 9s and 0s
char* findSmallestMultiple(int N) {
    // Dynamic memory allocation for the result string
    char* multiple = new char[N + 1];  // +1 for the null terminator
    memset(multiple, '0', N);  // Initialize all digits to '0'
    multiple[N] = '\0';  // Null-terminate the string

    int remainder = 0;  // Initialize the remainder

    // Iterate in reverse to find the smallest multiple
    for (int i = N - 1; i >= 0; i--) {
        remainder = (remainder * 10 + 9) % N;  // Calculate the remainder when appending '9'
        if (remainder == 0) {
            multiple[i] = '9';  // Set the digit to '9' if the remainder is 0
            break;  // Exit the loop when a multiple is found
        }
    }

    return multiple;  // Return the smallest multiple as a character array
}

int main() {
    int T;
    cin >> T;

    // Use a for loop to iterate through the test cases
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        // Call the findSmallestMultiple function to get the result
        char* result = findSmallestMultiple(N);
        cout << result << endl;

        // Free the dynamically allocated memory to prevent memory leaks
        delete[] result;
    }

    return 0;
}
