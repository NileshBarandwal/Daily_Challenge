/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function(s) {
    let i=0;
    let result=0;
    let sign=1;

    while(i<s.length && s[i]===' '){
        i++;
    }
    if(i<s.length && (s[i]==='+' || s[i]==='-')){
        sign=(s[i]==='-') ? -1:1;
        i++
    }
    while(s.length && (s[i]>='0' && s[i]<='9')){
        result = result * 10 + (s[i] - '0'); // Accumulate the digits

        // Overflow/underflow check
        if (sign * result > 2147483647) { // INT_MAX
            return 2147483647; // Clamp to INT_MAX
        }
        if (sign * result < -2147483648) { // INT_MIN
            return -2147483648; // Clamp to INT_MIN
        }

        i++; // Move to the next digit
    }

    // Return the final integer with correct sign
    return sign * result;
};