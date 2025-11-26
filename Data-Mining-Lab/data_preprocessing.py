import pandas as pd

#for csv files
data = pd.read_csv('iris.csv')

# Example data
# data = pd.DataFrame({
#     'Name': ['Alice', 'Bob', None, 'Charlie'],
#     'Age': [25, None, 30, 35],
#     'City': ['New York', 'Los Angeles', 'Chicago', None]
# })

# Remove rows with any empty cells
data_cleaned = data.dropna()

print("Data after removing rows with empty cells:")
print(data_cleaned)

#########################################
# Example data
data = pd.DataFrame({
    'Name': ['Alice', 'Bob', 'Charlie', 'Alice'],
    'Age': [25, 30, 35, 25],
    'City': ['New York', 'Los Angeles', 'Chicago', 'New York']
})

# Remove duplicate rows
data_no_duplicates = data.drop_duplicates()

print("Data after removing duplicates:")
print(data_no_duplicates)

###################################
# Example data
data = pd.DataFrame({
    'Name': ['Alice', 'Bob', 'Charlie'],
    'Age': ['25', 'thirty', '35'],
    'Joining Date': ['2020-01-01', '01-02-2021', '2021-03-01']
})

# Convert 'Age' to numeric, coercing errors to NaN
data['Age'] = pd.to_numeric(data['Age'], errors='coerce')

# Standardize 'Joining Date' format
data['Joining Date'] = pd.to_datetime(data['Joining Date'], errors='coerce')

print("Data after handling wrong format:")
print(data)
######################################
# Example data
data = pd.DataFrame({
    'Name': ['Alice', 'Bob', 'Charlie', 'Dave'],
    'Age': [25, 150, -10, 35],  # Age values that don't make sense
    'Salary': [50000, 60000, None, 70000]
})

# Filter out rows with invalid 'Age' values
data_valid_age = data[(data['Age'] > 0) & (data['Age'] < 120)]

# Use .loc to modify the 'Salary' column
data_valid_age.loc[:, 'Salary'] = data_valid_age['Salary'].fillna(data_valid_age['Salary'].mean())

print("Data after handling wrong data:")
print(data_valid_age)
