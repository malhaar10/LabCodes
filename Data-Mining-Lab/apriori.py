from mlxtend.frequent_patterns import apriori
from mlxtend.frequent_patterns import fpgrowth
from mlxtend.frequent_patterns import association_rules
import pandas as pd

# Example transaction data
data = pd.read_csv(r"D:\\CodeDump\\Python\\general\\altered.csv")
df = pd.DataFrame(data)
#for FP Growth algorithm
#frequent_itemsets = fpgrowth(df, min_support = 0.4, use_colnames = True)

# Find frequent itemsets
frequent_itemsets = apriori(df, min_support=0.4, use_colnames=True)
print("Frequent Itemsets:")
print(frequent_itemsets)

# Generate association rules
rules = association_rules(frequent_itemsets, metric="confidence", min_threshold=0.7)
print("\nAssociation Rules:")
print(rules)