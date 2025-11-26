from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

# Example dataset (spam vs. ham)
texts = ["Free money!!!", "Win a new car!", "Let's meet for lunch", "Call me back", "Congratulations, you won!"]
labels = [1, 1, 0, 0, 1]  # 1 = Spam, 0 = Ham

# Convert text to numerical features
vectorizer = CountVectorizer()
X = vectorizer.fit_transform(texts)

# Split into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, labels, test_size=0.4, random_state=42)

# Train Multinomial Naive Bayes Classifier
clf = MultinomialNB()
clf.fit(X_train, y_train)

# Predict on test data
predictions = clf.predict(X_test)

# Evaluate accuracy
accuracy = accuracy_score(y_test, predictions)
print(f"Accuracy: {accuracy}")