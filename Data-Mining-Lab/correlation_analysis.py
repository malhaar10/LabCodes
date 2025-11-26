import numpy as np
import pandas as pd

# Creating a new dataset
data = {
    'Category1': [5, 7, 8, 9, 10],
    'Category2': [10, 12, 15, 18, 20]
}
df = pd.DataFrame(data)

# Pearson Correlation Coefficient
pearson_correlation = df.corr().iloc[0, 1]
print(f"Pearson Correlation Coefficient: {pearson_correlation}")

# Creating a contingency table for chi-square test
observed = df.to_numpy()

# Calculate row and column sums
row_sum = np.sum(observed, axis=1)
col_sum = np.sum(observed, axis=0)
total = np.sum(observed)

# Calculate expected frequencies
expected = np.outer(row_sum, col_sum) / total

# Calculate Chi-Square statistic
chi2_statistic = np.sum((observed - expected)**2 / expected)
print(f"Chi-Square Statistic: {chi2_statistic}")
