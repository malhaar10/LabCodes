import math

# Min-Max Normalization
def min_max_normalization(data):
    min_val = min(data)
    max_val = max(data)
    return [(x - min_val) / (max_val - min_val) for x in data]

# Z-Score Normalization
def z_score_normalization(data):
    mean = sum(data) / len(data)
    variance = sum((x - mean) ** 2 for x in data) / len(data)
    std_dev = math.sqrt(variance)
    return [(x - mean) / std_dev for x in data]

# Decimal Scaling Normalization
def decimal_scaling_normalization(data):
    max_val = max(abs(x) for x in data)
    j = 0
    while max_val >= 1:
        max_val /= 10
        j += 1
    return [x / (10 ** j) for x in data]

# Example usage
if __name__ == "__main__":
    data = [10, 20, 30, 40, 50]
    
    # Min-Max Normalization
    print("Min-Max Normalized Data:", min_max_normalization(data))
    
    # Z-Score Normalization
    print("Z-Score Normalized Data:", z_score_normalization(data))
    
    # Decimal Scaling Normalization
    print("Decimal Scaling Normalized Data:", decimal_scaling_normalization(data))