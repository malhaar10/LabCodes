import numpy as np
import pandas as pd

# Example data
data1 = np.array([[1, 2], [3, 4]])
data2 = np.array([[5, 6], [7, 8]])
data3 = pd.DataFrame({'ID': [1, 2, 3], 'Name': ['Alice', 'Bob', 'Charlie']})
data4 = pd.DataFrame({'ID': [1, 2, 4], 'Age': [25, 30, 40]})

# Union (stacking vertically)
union_data = np.vstack((data1, data2))
print(f"Union:\n{union_data}")

# Intersection (finding common rows)
intersection_data = np.intersect1d(data1, data2)
print(f"Intersection:\n{intersection_data}")

# Join operation (merge on 'ID')
merged_data = pd.merge(data3, data4, on='ID', how='inner')
print(f"Merged Data:\n{merged_data}")

# Transformation example (renaming columns)
data3 = pd.DataFrame({'Identifier': [1, 2, 3], 'Height': [165, 170, 175]})
data3.rename(columns={'Identifier': 'ID'}, inplace=True)

# Merging after transformation
transformed_merged_data = pd.merge(data3, data4, on='ID', how='inner')
print(f"Transformed Merged Data:\n{transformed_merged_data}")
