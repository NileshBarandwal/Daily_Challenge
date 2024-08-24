// 592. Fraction Addition and Subtraction

class Solution {
public:
    string fractionAddition(string expression) {
        int numerator = 0, denominator = 1; // Start with 0/1 as the initial fraction
        int i = 0, n = expression.size();

        while (i < n) {
            int sign = 1;
            // Handle the sign
            if (expression[i] == '+' || expression[i] == '-') {
                sign = (expression[i] == '-') ? -1 : 1;
                i++;
            }

            // Parse numerator
            int num = 0;
            while (i < n && isdigit(expression[i])) {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            num *= sign;

            i++; // Skip the '/' character

            // Parse denominator
            int den = 0;
            while (i < n && isdigit(expression[i])) {
                den = den * 10 + (expression[i] - '0');
                i++;
            }

            // Update the result with the new fraction num/den
            numerator = numerator * den + num * denominator;
            denominator *= den;

            // Simplify the fraction using gcd
            int gcdVal = gcd(abs(numerator), denominator);
            numerator /= gcdVal;
            denominator /= gcdVal;
        }

        // Final result as a string in "numerator/denominator" format
        return to_string(numerator) + "/" + to_string(denominator);
    }
};