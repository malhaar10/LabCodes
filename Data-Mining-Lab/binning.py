import numpy as np

# Example data
data = np.array([4,8,15,21,21,24,25,34,28])
# Number of bins
bins = 3
# Divide data into bins
data_sorted = np.sort(data)
bin_size = 3

# smoothing by bin means    
smoothing_by_means = np.copy(data_sorted)
for i in range(bins):
    start = i * bin_size
    end = (i + 1) * bin_size if i != bins - 1 else len(data_sorted)
    bin_mean = np.mean(data_sorted[start:end])
    smoothing_by_means[start:end] = bin_mean

# Smoothing by bin medians
smoothing_by_medians = np.copy(data_sorted)
for i in range(bins):
    start = i * bin_size
    end = (i + 1) * bin_size if i != bins - 1 else len(data_sorted)
    bin_median = np.median(data_sorted[start:end])
    smoothing_by_medians[start:end] = bin_median

print(f"Smoothed by Bin Median: {smoothing_by_medians} \nSmoothed by Bin Means: {smoothing_by_means}")
