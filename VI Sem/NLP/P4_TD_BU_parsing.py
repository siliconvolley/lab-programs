# 4) Implement top-down and bottom-up parsing using python NLTK

import nltk
import sys
from nltk import CFG
from nltk.parse import RecursiveDescentParser, ShiftReduceParser

# Setting the recursion limit
sys.setrecursionlimit(100)

# ! Un-comment the following lines to download the required packages if not download
# nltk.download('punkt')
# nltk.download('averaged_perceptron_tagger')
# nltk.download('maxent_ne_chunker')
# nltk.download('words')

# Define a simple context-free grammar
grammar = CFG.fromstring("""
    S -> NP VP
    NP -> Det N | Det N PP
    VP -> V NP | VP PP
    PP -> P NP
    Det -> 'a' | 'the'
    N -> 'man' | 'park' | 'dog' | 'telescope'
    V -> 'saw'
    P -> 'in' | 'with'
""")

# Function to parse a sentence using Recursive Descent Parser
def top_down_parsing(sentence):
    rd_parser = RecursiveDescentParser(grammar)
    print("Parsing with Recursive Descent Parser (Top-Down):")
    for tree in rd_parser.parse(sentence):
        print(tree)
        tree.pretty_print()

# Function to parse a sentence using Shift-Reduce Parser
def bottom_up_parsing(sentence):
    sr_parser = ShiftReduceParser(grammar)
    print("Parsing with Shift-Reduce Parser (Bottom-Up):")
    for tree in sr_parser.parse(sentence):
        print(tree)
        tree.pretty_print()
        return
    
def main():
    # Input sentence
    sentence = "the man saw the dog in the park".split()

    # Parse the sentence using both approaches
    top_down_parsing(sentence)
    bottom_up_parsing(sentence)
    
if __name__ == "__main__":
    main()
