from collections import Counter

def max_string_with_limit(s: str, k: int) -> str:
    count = Counter(s)
    available = {d: min(count[d], k) for d in count}
    result = []
    
    sorted_digits = sorted(available.keys(), reverse=True) 
    
    while len(result) < len(s):
        for digit in sorted_digits:
            if available[digit] > 0 and len(result) < len(s):
                result.append(digit)
                available[digit] -= 1
    
    return "".join(result)

# Example usage
s = "987789765543332221111"
k = 2
print(max_string_with_limit(s, k))
