from collections import Counter

def max_string_with_limit(s: str, k: int) -> str:
    count = Counter(s)
    available = {d: min(count[d], k) for d in count}
    result = []
    
    for digit in sorted(available.keys(), reverse=True):  # Process digits in descending order
        result.extend([digit] * available[digit])
    
    return "".join(result)

# Example usage
s = "987789765543332221111"
k = 2
print(max_string_with_limit(s, k))