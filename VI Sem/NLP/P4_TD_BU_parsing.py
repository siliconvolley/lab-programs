# 4) Implement top-down and bottom-up parsing using python NLTK

import nltk
from nltk.grammar import CFG
from nltk.parse.chart import TopDownChartParser, BottomUpChartParser

# define a grammer
grammar = CFG.fromstring('''
    S -> NP VP
    VP -> V NP | V NP PP
    PP -> P NP
    V -> "saw" | "are"
    NP -> "rishabh" | "achal" | Det N | Det N PP
    Det -> "a" | "an" | "the"
    N -> "man" | "earth"
    P -> "with" | "under"
''')

# function to parse a sentence using top-down and bottom-up parsers
def parse_sentence(sentence):
    # Tokenize the sentence
    tokens = sentence.split()
    
    # Top Down Parsing
    top_down_parser = TopDownChartParser(grammar)
    print("Top Down parsing results: ")
    top_down_results = list(top_down_parser.parse(tokens))
    if top_down_results:
        for tree in top_down_results:
            print(tree)
    else:
        print("No parse tree found using top-downn parsing")

    # Bottom Up Parsing
    bottom_up_parser = BottomUpChartParser(grammar)
    print("Bottom Up parsing results: ")
    bottom_up_results = list(bottom_up_parser.parse(tokens))
    if bottom_up_results:
        for tree in bottom_up_results:
            print(tree)
    else:
        print("No parse tree found using bottom up parsing")

# Get user input and pass into the function
user_input = input("Enter a sentence to parse: ")
parse_sentence(user_input)