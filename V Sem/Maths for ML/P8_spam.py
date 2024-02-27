import pandas as pd
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.pipeline import make_pipeline
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report

# Sample dataset
data = {'text': ["Hi, this is a legitimate message.",
                 "Click here to win a free iPhone!",
                 "Congratulations, you've won a lottery!",
                 "Meeting at 3 PM in the conference room.",
                 "Important meeting tomorrow at 10 AM."],
        'label': [0, 1, 1, 0, 0]}  # 0 for ham, 1 for spam

df = pd.DataFrame(data)

# Create and train the model
model = make_pipeline(CountVectorizer(), MultinomialNB()).fit(df['text'], df['label'])

# Get input from the user
user_input = input("Enter a message: ")

# Make a prediction
user_prediction = model.predict([user_input])

# Print the prediction
if user_prediction[0] == 0:
    print("The message is not spam.")
else:
    print("The message is spam.")
