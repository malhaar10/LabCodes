# Note: Install matplotlib

from sklearn.cluster import KMeans
import numpy as np
import matplotlib.pyplot as plt

# Generate sample data
X = np.array([[1, 2], [1.5, 1.8], [5, 8], [8, 8], [1, 0.6], [9, 11]])

# Train K-Means model
kmeans = KMeans(n_clusters=2, random_state=42)
kmeans.fit(X)

# Get cluster centers and labels
centers = kmeans.cluster_centers_
labels = kmeans.labels_

# Plot the clusters
colors = ['r', 'g']
for i in range(len(X)):
    plt.scatter(X[i, 0], X[i, 1], c=colors[labels[i]], marker='o')

# Plot the cluster centers
plt.scatter(centers[:, 0], centers[:, 1], c='blue', marker='x', s=200, label='Centroids')
plt.legend()
plt.show()

# Print results
print(f"Cluster Centers: {centers} \nLabels: {labels}")