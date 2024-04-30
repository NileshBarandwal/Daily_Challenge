# Square Root Calculation

## Intuition
The square root of a number is the value that, when squared, equals the original number. To find this value, iterative approaches like the Babylonian Method are commonly used. This method starts with a guess and refines it until it converges to the desired result.

## Approach
The Babylonian Method (also known as Heron's Method) is an iterative approach to calculate square roots. It uses an averaging formula to update the guess at each step, gradually converging to the correct square root. The formula is as follows:

x_new = 0.5 * (x_old + x / x_old)

The process continues until the change between successive approximations is within a predefined tolerance, indicating convergence.

### Tolerance
Tolerance refers to the acceptable level of error in an iterative algorithm. In the context of square root calculations, tolerance determines when to stop iterating. When the absolute difference between consecutive guesses is smaller than the tolerance, the algorithm is considered to have converged.

For example, if the tolerance is 0.0001, the iterations stop when the difference between successive guesses is less than 0.0001. This provides a balance between computational efficiency and accuracy.

### Example
To calculate the square root of 8 using the Babylonian Method, consider these steps:

1. **Initial Guess**: Start with a guess, typically half of the original number. For 8, the initial guess is 4.
2. **First Iteration**: Apply the iterative formula to get a new guess:
   - x_1 = 0.5 * (4 + (8 / 4)) = 3
3. **Second Iteration**: Continue refining the guess:
   - x_2 = 0.5 * (3 + (8 / 3)) ≈ 2.8333
4. **Third Iteration**: Further refine the guess to converge to the correct answer:
   - x_3 = 0.5 * (2.8333 + (8 / 2.8333)) ≈ 2.8289

With this approach, the guesses converge to a value around 2.828, which is approximately the square root of 8. Convergence is achieved when the change between successive iterations is within the specified tolerance.

## Why This Method?
The Babylonian Method is popular because it is straightforward to implement, converges quickly, and provides a reasonable degree of accuracy. The use of tolerance ensures that the result is accurate within a defined range, making the method both efficient and reliable.

## Complexity
- **Time Complexity**: The time complexity of the Babylonian Method is O(log(x)), due to the iterative nature of the algorithm. It usually takes only a few iterations to reach the desired level of accuracy.
- **Space Complexity**: The space complexity is O(1) because the algorithm uses a constant amount of memory to store the guesses, regardless of the size of the input.

## These characteristics make the Babylonian Method a popular choice for calculating square roots in various software and hardware applications.


# Code
```cpp
class Solution {
public:
    int mySqrt(int x) {
     if (x == 0) return 0; // Base case for 0
        double x0 = x / 2.0;  // Initial guess
        double x1 = 0;        // To hold the new guess
        const double tolerance = 0.0001; // Tolerance for convergence

        // Loop until convergence
        do {
            x1 = 0.5 * (x0 + x / x0); // New guess using Babylonian Method
            if (abs(x1 - x0) < tolerance) {
                break; // Convergence achieved
            }
            x0 = x1; // Update the guess for the next iteration
        } while (true);

        return static_cast<int>(x1); // Return the integer square root
    }
};
```