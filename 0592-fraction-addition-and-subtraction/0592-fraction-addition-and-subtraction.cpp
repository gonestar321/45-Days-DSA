
class Solution {
public:
    string fractionAddition(string expression) {
        // Step 1: Initialize the result numerator and denominator.
        // Start with the fraction 0/1 because any number added to 0 doesn't change its value.
        int resultNumerator = 0;
        int resultDenominator = 1;
        
        // Step 2: Use a loop to parse the input expression and extract each fraction.
        // We'll need variables to keep track of the current numerator and denominator.
        int index = 0;
        while (index < expression.length()) {
            // Step 3: Extract the sign of the current fraction (positive or negative).
            int sign = 1;
            if (expression[index] == '-' || expression[index] == '+') {
                sign = (expression[index] == '-') ? -1 : 1;
                index++;
            }
            
            // Step 4: Parse the numerator.
            int currentNumerator = 0;
            while (isdigit(expression[index])) {
                currentNumerator = currentNumerator * 10 + (expression[index] - '0');
                index++;
            }
            currentNumerator *= sign; // Apply the sign to the numerator.
            
            // Step 5: Skip the '/' character to move to the denominator.
            index++; // Move past the '/'
            
            // Step 6: Parse the denominator.
            int currentDenominator = 0;
            while (isdigit(expression[index])) {
                currentDenominator = currentDenominator * 10 + (expression[index] - '0');
                index++;
            }
            
            // Step 7: Find the least common denominator (LCD) of the current result denominator and the current fraction's denominator.
            // We do this because fractions need a common denominator to be added.
            int commonDenominator = resultDenominator * currentDenominator;
            
            // Step 8: Adjust the numerators to the common denominator.
            resultNumerator = resultNumerator * currentDenominator + currentNumerator * resultDenominator;
            
            // Step 9: Set the result denominator to the common denominator.
            resultDenominator = commonDenominator;
            
            // Step 10: Simplify the fraction (reduce it to its lowest terms).
            // Find the greatest common divisor (GCD) of the numerator and denominator.
            int gcd = abs(__gcd(resultNumerator, resultDenominator));
            resultNumerator /= gcd;
            resultDenominator /= gcd;
        }
        
        // Step 11: Convert the result numerator and denominator to a string in the form "numerator/denominator".
        return to_string(resultNumerator) + "/" + to_string(resultDenominator);
    }
};
